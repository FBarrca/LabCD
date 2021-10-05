clc

s=tf('s');
format short e
format compact

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Modelo de la planta de velocidad
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Modelo entre uc y la medida de v (m/s):
s=tf('s');
Km=0.077871;
Tm= 0.067567;
Tf=0.2;
P = Km/(Tm*s+1)/(Tf*s+1);
Pd = -P;

% Planta con retardo
ts=2e-3; %segundos
retardo = 10*ts;    % muestras
Pam = P*exp(-retardo*s);

% Margen de fase
Fm=65;

%% Control P:
% Pulsacion de cruce control P
wo_p=fsolve(@(w) -180+Fm-180/pi*angle(freqresp(Pam,w)),1);
% Ganancia de la planta en wo
Ap=abs(freqresp(Pam,wo_p));
% Ganancia del control
K=1/Ap;
% Funcion de transferencia del control
% Control de 2 grados de libertad
C_p=tf(K,1);
Cr_p=C_p;
