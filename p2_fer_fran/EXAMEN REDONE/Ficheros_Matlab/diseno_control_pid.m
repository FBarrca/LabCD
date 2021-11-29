clear
%clc
format short e
s=tf('s');
% Período de muestreo
ts = 5e-3;
Ts=ts;

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


%%Obtención del modelo linealizado
param(10)=0;

uo=0;
xo=zeros(3,1);

[matA, matB, matC, matD]=linmod('segway', xo, uo);


Pss=ss(matA, matB, matC, matD);
Pzpk=minreal(zpk(Pss));
set(Pzpk, 'DisplayFormat', 'timeconstant')

Pv=Pzpk(1);
Pw=Pzpk(2);
Pth=Pzpk(3);

%%Parametros planta

% K1=0.005;
% T1=0.05;
% K2=0.1;
% T2=0.104;
% Kth=K1*K2;
% Tv=T1;
% Tw=T2;
kth=0.0074649;
Tv=0.05708;
Tw=sqrt(0.1114*0.1026);

P=kth*s/((1+Tv*s)*(1-(Tw*s)^2));


%%ObtenciÓn parámetros

p=-25;
seta=0.7;
wn=4.5;

a2=-p+2*seta*wn;
a1=wn^2-2*seta*wn*p;
a0=-p*wn^2;

x=fsolve(@(x) [a2-((1-x(1)*kth*x(2)/Tw^2)/Tv), ...
               a1+(1+x(1)*kth/Tv)/Tw^2, ...
               a0+(1+x(1)*kth/x(3))/Tw^2/Tv], ...
               [0.1,0.05,0.03]);

K=x(1);
Td=x(2);
Ti=x(3);


%%Configuración simulación

th0=5;
X0 = [0, 0, th0*pi/180]';


param(10)=0; %por si acaso hay que poner par de rozamiento máximo

sim('SEGWAY_SIM_PID.slx');






% b=1;
% 
% Cd=minreal(K*(1+1/(Ti*s)+(Td*s)/(1+Td*s/N)));
% 
% 
% %sin ponderación y diferencial sobre error
% Crd=Cd;
% 
% %ponderación sobre error
% Crd=minreal(K*(b+1/(Ti*s)+(Td*s)/(1+Td*s/N)));
% 
% %con ponderación y diferencial sobre salida
% 
% Crd=minreal(K*(b+1/(Ti*s)));