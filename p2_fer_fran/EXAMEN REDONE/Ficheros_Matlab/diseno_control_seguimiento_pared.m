clear
%clc
format short e
s=tf('s');
% Período de muestreo
ts = 5e-3;
Ts=ts;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  PARAMETROS SEGUIMIENTO PARED %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ganancia estática giro (rad/s/V)
Km_w=5.4411e-01;
% Constante de tiempo giro (s)
Tm_w=6.6258e-02;
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


%%Espacio de estado seguimiento de pared:

Pssp=ss(matAp, matBp, matCp, matDp);

%%Discretización espacio de estado:

Pss_dp=c2d(Pssp, ts);
Adp=Pss_dp.a;
Bdp=Pss_dp.b;
Cdp=Pss_dp.c;
Ddp=Pss_dp.d;

polos_lap=eig(matAp);
w_lap=max(polos_lap);

%%Establecimiento de polos y obtención de Kcd

wnp=1;
setap=0.7;

polos_lcp=wnp*[-setap+sqrt(1-setap^2)*1j, -setap-sqrt(1-setap^2)*1j].';
polos_adp=-5*wnp;

polosd_lcp=exp([polos_lcp; polos_adp]*ts);

Kcd_pared=place(Adp, Bdp(:,1), polosd_lcp);


return