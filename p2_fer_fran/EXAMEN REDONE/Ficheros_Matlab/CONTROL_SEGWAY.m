clc
clear
close all
format short e
s=tf('s');
% Período de muestreo
ts = 5e-3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%  PARAMETROS  %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Los parámetros mecánicos están referidos al eje de la rueda
% Gravedad (m/s^2)
g=9.81;
%%%%%%%%%
% Motor %
%%%%%%%%%
% Resistencia en ohmios
Rm=4.5;
% Relacion de engranajes
n=48;
% Constante electrica (V.s)
Ke=0.01; 
% Constante mecanica (N.m/A)
Kt=Ke;
% Momento de inercia del motor (kg.m^2)
Im=3.75e-3;
% Par máximo de friccion (Nm)
Trmax=0.05;
% Friccion viscosa (N.m.s/rad)
Dm=0.0142;
%%%%%%%%%%
% Segway %
%%%%%%%%%%
% Masa del chasis (kg)
M = 0.6;
% Masa de la rueda + rotor (kg)
m = 0.034;
% Momento de inercia de cabeceo (kg.m^2)
Ith = 1.425e-3;
% Momento de inercia de la rueda + rotor (kg.m^2)
Imr = 3.2e-6+Im;
% Distancia vertical al c.d.g. desde el eje de la rueda (m)
h = 0.073;
% Distancia entre ruedas (m)
W = 0.15;
% Radio de la rueda (m)
R = 81.6e-3/2;
% Vector de parametros
param=[M m Ith Imr h W R Ke Rm Trmax Dm n];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Otros parametros del control %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Instante inicial de control (ms)
time_start = 1;
% Factor de filtrado de la medida de la velocidad
alfa1=0.8;
% Factor de filtrado en la calibración del giroscopo
alfa2=0.999;
% offset inicial del giroscopo
gyro0=615;
% Peso del giroscopo en el filtro complementario
Wfc=0.98;
% Frecuencia de la señal sonora (Hz)
sound_freq = 440;
% Duracion de la señal sonora (ms)
sound_dur =	500;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%  LINEALIZACION DEL SISTEMA %%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Añadir al fichero de Matlab (CONTROL_SEGWAY.m) donde se definen los
% parámetros el punto de operación correspondiente a la posición vertical
% del vehículo, con velocidad de avance nula, y linealizar el modelo en 
% dicho punto de operación

%DEfinimos el punto de equilibrio/operacion _0
vo =0; %velocidad de avance (m/s)
wo= 0; %velocidad angular de cabeceo (rad/s)
tho = 0; %ángulo de cabeceo (grados)
X0=[vo wo tho*pi/180]';
U0=0;

% A la hora de linealizar el modelo, es necesario anular el
% par de fricción máximo (parámetro del modelo).
% Par de friccion del motor (N.m) eje externo
param(10)=Trmax;
param(10) = 0;
% Modelo linealizado en el punto X0
[matA,matB,matC,matD] = linmod('segway',X0,U0);
%Planta en sistema de estado dx=Ax+Bu Y=Cx+Du
Pss = ss(matA,matB,matC,matD);

%Como podemos ver las tres comparten los mismos polos(propiedad)
%dichos polos son los autovalores de la matriz de estado
polos=eig(matA);
polos(3),
%Vemos que hay un autovalor positivo, por tanto el sistema es inestable.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%   DISEÑO DE REGULADOR PID  %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% El objetivo de esta parte del proyecto es analizar la posibilidad de
% diseñar un control PID que mantenga la posición vertical del vehículo

% Obtener la matriz de transferencia entre la tensión común de los
% motores y lastres salidas del modelo: velocidad de avance (m/s),
% velocidad angular de cabeceo(rad/s) y ángulo de cabeceo (rad). Aproximar
% la función de transferencia entre latensión común y el ángulo de cabeceo
% mediante la siguiente función detransferencia, estimando los valores
% numéricos de los parámetros KTH, Tv y Tw:
% P(s)= kth*s/((1+Tv*s)*(1-T^2s^2))

%Funciones de transferencia para cada entrada/salida
Pzpk = minreal(zpk(Pss));
set(Pzpk,'DisplayFormat','time constant');%No veo que haga nada pero simplente cambia como se representa por consola
Pv=Pzpk(1),
Pw=Pzpk(2),
Pth=Pzpk(3),
%Convertimos Pth a la aproximacion pedida
[z,p,k]=zpkdata(Pth,'v');
Kth = k/p(1)/p(2)/p(3);%Kth = dcgain(Pth/s); 
Tv = 1/p(1);
Tw = sqrt(1/p(2)*1/p(3));
Pth = minreal(Kth*s/(1+Tv*s)/(1-((Tw^2)*s^2)));

%Utilizando parámetros genéricos (KTH, Tv y Tw), demostrar aplicando el
%criterio de Routh-Hurwitz, que no es posible estabilizar el vehículo
%mediante un control PD sin filtrado.

%hace falta añadir un cero que cancele el polo positivo

%Demostrar mediante el criterio de Routh-Hurwitz que sí es posible diseñar
%un control PID en configuración paralelo y sin filtrado que equilibre
%teóricamente elvehículo.

%ahora si podemos cancelar;

%  Obtener un sistema de ecuaciones que permiten diseñar un control PID
%  sinfiltrado (parámetros K, Ti y Td) suponiendo que el polinomio deseado
%  en lazocerrado es s^3 + a2*s^2 + a1*s +a0

% (s^2 +2*seta*wn *s +wn^2)*(s-p) = s^3 + a2*s^2 + a1*s +a0
s = tf('s');
% diseñamos control:
wn_pid = 4.5;
seta_pid = 0.7;
p_pid = -25;

a3 = 1;
a2 = (2*seta_pid*wn_pid-p_pid);
a1 = (-2*seta_pid*wn_pid*p_pid + wn_pid^2);
a0 = (-p_pid*wn_pid^2);
den = s^3 + a2*s^2 + a1*s +a0
% C = K*(1 + 1/Ti*s + Td*s)
% P = (Kth*s/(1+Tv*s)/(1-Tw^2*s^2))
% den(1+C*P) = s*(s^3 + s^2*(1/Tv) + s*((x(2)*Tv + x(3)*Kth*x(2) + x(3)*Kth*x(1))/(-x(2)*(Tw^2)*Tv)) + ((x(2) + x(3)*Kth)/(-x(2)*(Tw^2)*Tv))

x = fsolve(@(x) [   a2 - (1/Tv) ;
                    a1 - ((x(2)*Tv + x(3)*Kth*x(2) + x(3)*Kth*x(1))/(-x(2)*(Tw^2)*Tv));
                    a0 - ((x(2) + x(3)*Kth)/(-x(2)*(Tw^2)*Tv))] , [1;1;1]);
Td_pid = x(1);
Ti_pid = x(2);
K_pid = x(3);

Td = Td_pid
Ti = Ti_pid
K = K_pid

C_pid = K_pid*(1 + (1/Ti_pid/s) + Td_pid*s);
[zf,pf,kf] = zpkdata(minreal(1+C_pid*Pth),'v');
%Utilizando, los valores numéricos de los parámetros de la planta,
%seleccionar losvalores numéricos de los parámetros del control para
%disponer en lazo cerrado dedos polos complejos con factor de
%amortiguamiento igual a 0.7, pulsación natural igual a 4.5 rad/s y un
%tercer polo real igual a -25.
% Pss_d=c2d(Pss, ts);
% Ad=Pss_d.a;
% Bd=Pss_d.b;
% 
% polos_la=eig(matA);
% w_la=max(polos_la); 
% wn=0.461*w_la;
% seta=0.7;
% polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';
% polos_ad=-5.55*wn;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  PARAMETROS SEGUIMIENTO PARED %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ganancia estática giro (rad/s/V)
Km_w=1;
% Constante de tiempo giro (s)
Tm_w=5e-02;
% Abcisa punto A (m)
xA=0;
% Ordenada punto A (m)
yA=-0.09;
% Vector de parametros
param_pared=[Km_w Tm_w xA yA];
% Distancia pared en el punto de operación (mm)
d0 = 100;
% Velocidad de avance en el punto de operación (m/s)
va0 = 0.15;
% Modelo linealizado seguimiento pared
matAp = [-1/Tm_w 0 0 ; 1 0 0 ; 1000*xA 1000*va0 0];
matBp = [ Km_w/Tm_w 0 0; 0 -1 0; 0 0 0];
matCp = eye(3);
matDp = zeros(3,3);

return