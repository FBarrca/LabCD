clear
%clc
format short e
s=tf('s');
% Per�odo de muestreo
ts = 5e-3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%  PARAMETROS  %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
Trmax=0.0;
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


kth=0.0074649;
Tv=0.05708;
Tw=sqrt(0.1114*0.1026);

P=kth*s/((1+Tv*s)*(1-(Tw*s)^2));


a0=0.0006524;
a1=0.01143;
a2=-0.05708;
a3=-1;
%a3 es menor que 0, no cumple el criterio de Rout-Hurwitz

zpk(P)
%si pintamos los polos de p, todos son reales y uno es positivo, por lo que no es estable 

Pss_d=c2d(Pss, ts);
Ad=Pss_d.a;
Bd=Pss_d.b;

polos_la=eig(matA);
w_la=max(polos_la);

wn=0.55*w_la;
seta=0.7;
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';
polos_ad=-5*wn;
polosd_lc=exp([polos_lc; polos_ad]*ts);
Kcd=place(Ad, Bd, polosd_lc);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  PARAMETROS SEGUIMIENTO PARED %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
% Modelo linealizado seguimiento pared
matAp = [-1/Tm_w 0 0 ; 1 0 0 ; 1000*xA 1000*va0 0];
matBp = [ Km_w/Tm_w 0 0; 0 -1 0; 0 0 0];
matCp = eye(3);
matDp = zeros(3,3);

return