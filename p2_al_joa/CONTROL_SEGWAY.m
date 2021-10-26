clear
%clc
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

%% condicion inicial para la simulacion
% angulo de cabeceo inicial:
th0 = 10;
X0=[0 0 th0*pi/180]';
%________________________________________________________________
%               FUNCION DE TRANSFERENCIA DEL MODELO LINEALIZADO
%________________________________________________________________
% lINELAIZACION EN THETA = 0;
% funcion de transferencia uc => theta
param(10) = 0;
[matA, matB, matC, matD] = linmod('segway');
%param(10) = Trmax;
Pss = ss(matA, matB, matC(1,:), matD(1,:));
Pth = minreal(zpk(ss(matA,matB,matC(3,:),matD(3,:))));
Pv = minreal(zpk(ss(matA,matB,matC(1,:),matD(1,:))));
%________________________________________________________________
%               DISCRETIZACION DEL MODELO
%________________________________________________________________
% Periodo de muestreo:
Pssd = c2d(Pss,ts,'zoh');
matAd=Pssd.a;
matBd=Pssd.b;
matCd=Pssd.c;
matDud=Pssd.d;


                    %% CONTROL PID: %%

% simplificamos Planta de theta
[z,p,k] = zpkdata(Pth,'v');
Kth = dcgain(Pth/s);
Tv = 1/p(1);
Tw1 = 1/p(2); Tw2 = 1/p(3);
Tw = sqrt(Tw1*Tw2);
P = minreal(Kth*s/(1+Tv*s)/(1-((Tw^2)*s^2)));

% calculamos la planta...
% buscamos seta = 0.7, wn = 4.5 rad/s, p = -25
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
  
  Td = Td_pid;
  Ti = Ti_pid;
  K = K_pid;
C_pid = K_pid*(1 + (1/Ti_pid/s) + Td_pid*s);
[zf,pf,kf] = zpkdata(minreal(1+C_pid*Pth),'v');
F =minreal(C_pid*P/(1+C_pid*P))
F2 =minreal(C_pid*Pth/(1+C_pid*Pth))





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