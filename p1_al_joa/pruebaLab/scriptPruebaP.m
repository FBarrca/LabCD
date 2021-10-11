clc
clear
% para usar modelo analogico modificado ret=1
% para usar modelo analogico puro ret = 0
ret = 1;

%% CONTROL P:
% definimos s, ts, z
s = tf('s');
ts = 0.025;
Ts = ts;
z = tf('z',ts);

% establecemos la planta y el retardo
P = 0.03/(1+0.07*s)/(1+0.2*s);
delay = exp(-ts*s/2);
Pm = P*delay;
Pd = c2d(P,ts);

% establecemos los valores de margen de fase y pulsaicones
Fm = 50; %grados
Fa = tf(1,1);
wo_p = fsolve(@(wo) -180+Fm-180/pi*angle(freqresp(P,wo)),1);
Ap = abs(freqresp(P,wo_p));
Kp = 1/Ap;

K = Kp;
C_p = tf(K,1);
Cr_p = C_p;

Cd_p = c2d(C_p,ts);
Crd_p = Cd_p;


% Funciones de transferencia de los controles:
F_p = minreal(C_p*Pm/(C_p*Pm+1));
G_p = minreal(C_p*Pm);

Fd_p = minreal(Cd_p*Pd/(Cd_p*Pd+1));
Gd_p = minreal(Cd_p*Pd);

% Margenes de estabilidad de P
[Am_p,Fm_p,wu_p,wo_p] = margin(G_p);
% Sensibilidad y maxima sensibilidad
S_p=minreal(1/(1+G_p));
ws_p=fminsearch(@(w) -abs(freqresp(S_p,w)),1);
Ms_p=20*log10(abs(freqresp(S_p,ws_p)));
% Repsuesta temporal a analizar en ltiview



