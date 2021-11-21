clc
clear
close all
format short e
s=tf('s');
% Per�odo de muestreo
ts = 5e-3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%  PARAMETROS  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Los par�metros mec�nicos est�n referidos al eje de la rueda
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
% Par m�ximo de friccion (Nm)
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Otros parametros del control %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Instante inicial de control (ms)
time_start = 1;
% Factor de filtrado de la medida de la velocidad
alfa1=0.8;
% Factor de filtrado en la calibraci�n del giroscopo
alfa2=0.999;
% offset inicial del giroscopo
gyro0=615;
% Peso del giroscopo en el filtro complementario
Wfc=0.98;
% Frecuencia de la se�al sonora (Hz)
sound_freq = 440;
% Duracion de la se�al sonora (ms)
sound_dur =	500;
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%  LINEALIZACION DEL SISTEMA %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A�adir al fichero de Matlab (CONTROL_SEGWAY.m) donde se definen los
% par�metros el punto de operaci�n correspondiente a la posici�n vertical
% del veh�culo, con velocidad de avance nula, y linealizar el modelo en 
% dicho punto de operaci�n

%__________________________________________________________________________
%                   PUNTO DE OPERCACION SIMULACION
%__________________________________________________________________________

%DEfinimos el punto de equilibrio/operacion _0
vo =0; %velocidad de avance (m/s)
wo= 0; %velocidad angular de cabeceo (rad/s)
tho = 0; %�ngulo de cabeceo (grados)
X0=[vo wo tho*pi/180]';
U0=0;
%__________________________________________________________________________
%                   FUNCION DE TRANSFERENCIA DEL MODELO LINEALIZADO
%__________________________________________________________________________

% A la hora de linealizar el modelo, es necesario anular el
% par de fricci�n m�ximo (par�metro del modelo).
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
%__________________________________________________________________________
%                               DISCRETIZACION DEL MODELO
%__________________________________________________________________________

ts = 5e-3;
Pss_d=c2d(Pss, ts, 'zoh');
matAd=Pss_d.a;
matBd=Pss_d.b;
matCd=Pss_d.c;
matDd=Pss_d.d;
matDud=Pss_d.d;
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%   DISE�O DE REGULADOR PID  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% El objetivo de esta parte del proyecto es analizar la posibilidad de
% dise�ar un control PID que mantenga la posici�n vertical del veh�culo

% Obtener la matriz de transferencia entre la tensi�n com�n de los
% motores y lastres salidas del modelo: velocidad de avance (m/s),
% velocidad angular de cabeceo(rad/s) y �ngulo de cabeceo (rad). Aproximar
% la funci�n de transferencia entre latensi�n com�n y el �ngulo de cabeceo
% mediante la siguiente funci�n detransferencia, estimando los valores
% num�ricos de los par�metros KTH, Tv y Tw:
% P(s)= kth*s/((1+Tv*s)*(1-T^2s^2))

%__________________________________________________________________________
%           Funciones de transferencia para cada entrada/salida
%__________________________________________________________________________
Pzpk = minreal(zpk(Pss));
set(Pzpk,'DisplayFormat','time constant');%No veo que haga nada pero simplente cambia como se representa por consola
Pv=Pzpk(1);
Pw=Pzpk(2);
Pth=Pzpk(3);
%Convertimos Pth a la aproximacion pedida
[z,p,k]=zpkdata(Pth,'v');
Kth = k/p(1)/p(2)/p(3);%Kth = dcgain(Pth/s); 
Tv = 1/p(1);
Tw = sqrt(1/p(2)*1/p(3));
Pth = minreal(Kth*s/(1+Tv*s)/(1-((Tw^2)*s^2)));

%Utilizando par�metros gen�ricos (KTH, Tv y Tw), demostrar aplicando el
%criterio de Routh-Hurwitz, que no es posible estabilizar el veh�culo
%mediante un control PD sin filtrado.

%hace falta a�adir un cero que cancele el polo positivo

%Demostrar mediante el criterio de Routh-Hurwitz que s� es posible dise�ar
%un control PID en configuraci�n paralelo y sin filtrado que equilibre
%te�ricamente elveh�culo.

%ahora si podemos cancelar;

%  Obtener un sistema de ecuaciones que permiten dise�ar un control PID
%  sinfiltrado (par�metros K, Ti y Td) suponiendo que el polinomio deseado
%  en lazocerrado es s^3 + a2*s^2 + a1*s +a0
% Utilizando, los valores num�ricos de los par�metros de la planta,
% seleccionar losvalores num�ricos de los par�metros del control para
% disponer en lazo cerrado dedos polos complejos con factor de
% amortiguamiento igual a 0.7, pulsaci�n natural igual a 4.5 rad/s y un
% tercer polo real igual a -25.

%__________________________________________________________________________
%                           HALLAR PARAMETROS PID
%__________________________________________________________________________

p=-25;
seta=0.7;
wn=4.5;

a2=-p+2*seta*wn;
a1=wn^2-2*seta*wn*p;
a0=-p*wn^2;

%hallar los par�metros del control
%den=-Tv*Tw^2;

%resolver estas ecuaciones para Ti, Td, K. Los dem�s par�metros son
%conocidos
%a2=(-Tw+Ti*Td*k*kth)/den/Ti;
%a1=(Tv+k*kth*Ti)/den/Ti;
%a0=(Ti+k*kth)/den/Ti;

%x=fsolve(@(x) [a2-(-Tw+x(2)*x(3)*x(1)*kth)/den/x(3), a1-(Tv+x(1)*kth*x(2))/den/x(3), a0-(x(3)+x(2)*kth)/den/x(3)], [0.1,0.05,0.03]);
x=fsolve(@(x) [a2-((1-x(1)*Kth*x(2)/Tw^2)/Tv), 
               a1+(1+x(1)*Kth/Tv)/Tw^2, 
               a0+(1+x(1)*Kth/x(3))/Tw^2/Tv], [0.1,0.05,0.03]);

K=x(1);
Td=x(2);
Ti=x(3);
fprintf('__________________________DISE�O PID_________________________________________________________\n',[wn,seta,p]');
fprintf('Dise�o PID: K:%5.3f Td:%5.3f Ti:%5.3f \n',[K,Td,Ti]');
fprintf('Para los parametros: wn:%5.3f seta:%5.3f p:%5.3f \n',[wn,seta,p]');
fprintf('Dise�o PID: K:%5.3f Td:%5.3f Ti:%5.3f \n',[K,Td,Ti]');

%__________________________________________________________________________
%                           Condiciones de simulacion
%__________________________________________________________________________

Trmax=0; %0.05;% Par m�ximo de friccion (Nm)
param(10) = Trmax;
%DEfinimos el punto de equilibrio/operacion _0
vo =0; %velocidad de avance (m/s)
wo= 0; %velocidad angular de cabeceo (rad/s)
tho = 10; %�ngulo de cabeceo (grados)
X0=[vo wo tho*pi/180]';
%%Simula___________________________--


%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%   DISE�O DE UN REGULADOR POR REALIMENTACI�N DE ESTADO  %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%__________________________________________________________________________
%                               DISCRETIZACION DEL MODELO
%__________________________________________________________________________

ts = 5e-3; %Ojo comprobar TS estamos usando el discretizado
Pss_d=c2d(Pss, ts, 'zoh');
matAd=Pss_d.a;
matBd=Pss_d.b;
matCd=Pss_d.c;
matDd=Pss_d.d;
matDud=Pss_d.d;

% OBJETIVO: MANTENER EL PUNTO DE EQUILIBRIO % 
% En el modelo incremental todas las variables de estado valen 0 en el 
% punto de equilibrio 
% Estrategia de control: U=-K*X
% Se aplica sobre el modelo incremental en tiempo discreto 
% % X[k+l] = Ad*X[k] +Bd*U[k]= Ad*X[k] +Bd*K*X[k]=(Ad-Bd*K)*X[k]
% La matriz de estado en lazo cerrado es Ad�Bd*K 
% Se fijan las din�micas en lazo cerrado para que el sistema retorne al 
% punto de equilibrio de forma r�pida y bien amortigada 
% Asignaci�n de polos en lazo cerrado 
% Polos del en lazo abierto y en tiempo continuo 
%__________________________________________________________________________
%                               MATRIZ Kcd del control 
%__________________________________________________________________________

polos_la=eig(matA);
w_la=max(polos_la);% pulsaci�n del polo inestable 
% Polos en lazo cerrado: configuraci�n de Butterworth 
wn=0.461*w_la;
seta=0.7;
polos_ad=-5.55*wn; %polo adicional
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';
% Polos en tiempo discreto 
polosd_lc=exp([polos_lc ; polos_ad]*ts);% z=e^(s*ts)

% C�lculo de la matriz K del control 
Kcd=place (matAd , matBd , polosd_lc) ; 

%__________________________________________________________________________
%                           Condiciones de simulacion
%__________________________________________________________________________

Trmax=0; %0.05;% Par m�ximo de friccion (Nm)
param(10) = Trmax;
%DEfinimos el punto de equilibrio/operacion _0
vo =0; %velocidad de avance (m/s)
wo= 0; %velocidad angular de cabeceo (rad/s)
tho = 10; %�ngulo de cabeceo (grados)
X0=[vo wo tho*pi/180]';
%%Simula___________________________--

%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%   CONTROL INTEGRAL DE LA VELOCIDAD DE AVANCE PI  %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%__________________________________________________________________________
%                        Ampliacion de matrices de estado
%__________________________________________________________________________

matAad = [matAd zeros(3, 1) ; -ts*matCd eye(1)];
matBad = [matBd ; -matDd*ts];
wn=1.1*w_la*0.7;
seta=0.7;
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';

%Se un cuarto polo en tiempo debido a la nueva variable de estado integral. 
polos_ad=[-5*wn ; -5.01*wn];

%__________________________________________________________________________
%                             MATRIZ de ganancias Kad
%__________________________________________________________________________

polosd_lc=exp([polos_lc; polos_ad]*ts);
Kad=place(matAad, matBad, polosd_lc);
Kcd=Kad(1, 1:3);
Kid=Kad(1,4);

%__________________________________________________________________________
%                           Condiciones de simulacion
%__________________________________________________________________________

Trmax=0; %0.05;% Par m�ximo de friccion (Nm)
param(10) = Trmax;
%DEfinimos el punto de equilibrio/operacion _0
vo =0; %velocidad de avance (m/s)
wo= 0; %velocidad angular de cabeceo (rad/s)
tho = 10; %�ngulo de cabeceo (grados)
X0=[vo wo tho*pi/180]';
%%Simula___________________________--

%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  PARAMETROS SEGUIMIENTO PARED %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ganancia est�tica giro (rad/s/V)
Km_w=1;
% Constante de tiempo giro (s)
Tm_w=5e-02;
% Abcisa punto A (m)
xA=0;
% Ordenada punto A (m)
yA=-0.09;
% Vector de parametros
param_pared=[Km_w Tm_w xA yA];
% Distancia pared en el punto de operaci�n (mm)
d0 = 100;
% Velocidad de avance en el punto de operaci�n (m/s)
va0 = 0.15;

%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  CONTROL DE SEGUIMIENTO DE PARED %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%__________________________________________________________________________
%                           Modelo Lienalizado
%__________________________________________________________________________
matAp = [-1/Tm_w 0 0 ; 1 0 0 ; 1000*xA 1000*va0 0];
matBp = [ Km_w/Tm_w 0 0; 0 -1 0; 0 0 0];
matCp = eye(3);
matDp = zeros(3,3);


%__________________________________________________________________________
%                           Discretizacion del sistema
%__________________________________________________________________________
Pssp=ss(matAp, matBp, matCp, matDp);
Pss_dp=c2d(Pssp, ts);
Adp=Pss_dp.a;
Bdp=Pss_dp.b;
Cdp=Pss_dp.c;
Ddp=Pss_dp.d;

polos_lap=eig(matAp);
w_lap=max(polos_lap);

%wnp=1.1*w_lap;
wnp=1;
setap=0.7;
polos_lcp=wnp*[-setap+sqrt(1-setap^2)*1j, -setap-sqrt(1-setap^2)*1j].';
polos_adp=-5*wnp;
polosd_lcp=exp([polos_lcp; polos_adp]*ts);
Kcd_pared=place(Adp, Bdp, polosd_lcp);

return