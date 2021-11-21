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

param(10)=0;

uo=0;
xo=zeros(3,1);

[matA, matB, matC, matD]=linmod('segway_2015', xo, uo);


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

%Control PID:

p=-25;
seta=0.7;
wn=4.5;

a2=-p+2*seta*wn;
a1=wn^2-2*seta*wn*p;
a0=-p*wn^2;




%hallar los parámetros del control
%den=-Tv*Tw^2;

%resolver estas ecuaciones para Ti, Td, K. Los demás parámetros son
%conocidos
%a2=(-Tw+Ti*Td*k*kth)/den/Ti;
%a1=(Tv+k*kth*Ti)/den/Ti;
%a0=(Ti+k*kth)/den/Ti;

%x=fsolve(@(x) [a2-(-Tw+x(2)*x(3)*x(1)*kth)/den/x(3), a1-(Tv+x(1)*kth*x(2))/den/x(3), a0-(x(3)+x(2)*kth)/den/x(3)], [0.1,0.05,0.03]);
x=fsolve(@(x) [a2-((1-x(1)*kth*x(2)/Tw^2)/Tv), a1+(1+x(1)*kth/Tv)/Tw^2, a0+(1+x(1)*kth/x(3))/Tw^2/Tv], [0.1,0.05,0.03]);

K=x(1);
Td=x(2);
Ti=x(3);

%Para configurar la simulación:

th0=5;
X0 = [0, 0, th0*pi/180]';

%%Regulador: 
%Para que funcione bien hay que comentar el control integral para no
%sobreescribir Kcd

Pss_d=c2d(Pss, ts);
Ad=Pss_d.a;
Bd=Pss_d.b;
Cd=Pss_d.c(1,:);
Dd=Pss_d.d(1,:);

polos_la=eig(matA);
w_la=max(polos_la);

wn=1.1*w_la;
seta=0.7;
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';
polos_ad=-5*wn;
polosd_lc=exp([polos_lc; polos_ad]*ts);
Kcd=place(Ad, Bd, polosd_lc);

param(10) = 0.05;  %para meterle par de rozamiento a la simulación

%%Control Integral

matAad = [Ad zeros(3, 1) ; -Ts*Cd eye(1)];
matBad = [Bd ; -Dd*Ts];
wn=1.1*w_la*0.7;
seta=0.7;
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';
polos_ad=[-5*wn ; -5.01*wn];


polosd_lc=exp([polos_lc; polos_ad]*ts);
Ka=place(matAad, matBad, polosd_lc);
Kcd=Ka(1, 1:3);
Kid=Ka(1,4);
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


%%Control seguimiento de pared:




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