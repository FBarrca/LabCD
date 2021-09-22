clc

s=tf('s');
format short e
format compact

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Modelo de la planta de velocidad
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Modelo entre uc y la medida de v (m/s):
s=tf('s');
Km=0.049;
Tm= 0.046;
Tf=0.2;
P = Km/(Tm*s+1)/(Tf*s+1);
Pd = -P;

% Planta con retardo
ts=5e-3; %segundos
retardo = 10*ts;    % muestras
Pam = P*exp(-retardo*s);

% Margen de fase
Fm=65;

%% Control P
% Pulsacion de cruce control P
wo_p=fsolve(@(w) -180+Fm-180/pi*angle(freqresp(Pam,w)),1);
% Ganancia de la planta en wo
Ap=abs(freqresp(Pam,wo_p));
% Ganancia del control
K_p=1/Ap;
% Funcion de transferencia del control
% Control de 2 grados de libertad
C_p=tf(K_p,1);
Cr_p=C_p;
% Funcion de transferencia de lazo abierto
G_p=minreal(C_p*Pam);
% Margenes de estabilidad
[Am_p,Fm_p,wu_p,wo_p] = margin(G_p)
% Sensibilidad
S_p=minreal(1/(1+G_p));
% Pulsacion de maxima sensibilidad
ws_p=fminsearch(@(w) -abs(freqresp(S_p,w)),1);
% Maxima sensibilidad
Ms_p=20*log10(abs(freqresp(S_p,ws_p)));
% Funciones de transferencia de lazo cerrado
F_ry_p=minreal(Cr_p*Pam/(1+G_p));
F_ru_p=minreal(Cr_p/(1+G_p));
F_dy_p=minreal(Pd/(1+G_p));
F_du_p=minreal(Pam*C_p/(1+G_p));

% Pulsacion de resonancia
wr_p=fminsearch(@(w) -abs(freqresp(F_ry_p,w)),1);
% Pico de resonancia
Mr_p=20*log10(abs(freqresp(F_ry_p,wr_p)))-20*log10(dcgain(F_ry_p));



%% Control PI eje X
wo_pi=0.7*wo_p;
Fic=-180+Fm-angle(freqresp(Pam, wo_pi))*180/pi;
Ac=1/abs(freqresp(Pam, wo_pi));

I=-1/(wo_pi*tand(Fic));
Kp_pi=Ac*cosd(Fic);

Ti=I;
K_pi=Kp_pi;

C_pi=K_pi*(1+1/(Ti*s));
G_pi=minreal(C_pi*Pam);

%sin ponderación

Cr_pi=C_pi;

%Con ponderación
b=1.3;

Cr_pi=K_pi*(b+1/(Ti*s));

%funciones

F_ry_pi=minreal(Cr_pi*Pam/(1+G_pi));
F_ru_pi=minreal(Cr_pi/(1+G_pi));
F_dy_pi=minreal(Pi/(1+G_pi));
F_du_pi=minreal(Pam*C_pi/(1+G_pi));




%parámetros
[Am_pi,Fm_pi,wu_pi,wo_pi] = margin(G_pi)

% Sensibilidad
S_pi=minreal(1/(1+G_pi));
% Pulsacion de maxima sensibilidad
ws_pi=fminsearch(@(w) -abs(freqresp(S_pi,w)),1);
% Maxima sensibilidad
Ms_pi=20*log10(abs(freqresp(S_pi,ws_pi)));


% Pulsacion de resonancia
wr_pi=fminsearch(@(w) -abs(freqresp(F_ry_pi,w)),1);
% Pico de resonancia
Mr_pi=20*log10(abs(freqresp(F_ry_pi,wr_pi)))-20*log10(dcgain(F_ry_pi));






%% Control PD eje X
f=0.1;
wo_pd=1.5*wo_p;;

fasec=-180+Fm-angle(freqresp(Pam,wo_pd))*180/pi;

fmax=(1-sind(fasec))/(1+sind(fasec));
if f>fmax
    f=fmax;
end

D_pd=((1/f-1)/(2*tand(fasec))-sqrt(((1/f-1)/(2*(tand(fasec))))^2-1/f))/wo_pd;
Ac_pd=1/abs(freqresp(Pam, wo_pd));
Kp_pd=Ac_pd*(sqrt(1+(f*wo_pd*D_pd)^2))/(sqrt(1+(wo_pd*D_pd)^2));

Td_pd=D_pd*(1-f);
N_pd=(1/f)-1;


C_pd=Kp_pd*(1+Td_pd*s/(Td_pd*s/N_pd+1));
G_pd=minreal(C_pd*Pam);


%sobre error
Cr_pd=C_pd;
%sobre salida
Cr_pd=Kp_pd;



%funciones
F_ry_pd=minreal(Cr_pd*Pam/(1+G_pd));
F_ru_pd=minreal(Cr_pd/(1+G_pd));
F_dy_pd=minreal(Pd/(1+G_pd));
F_du_pd=minreal(Pam*C_pd/(1+G_pd));



%parámetros
[Am_pd,Fm_pd,wu_pd,wo_pd] = margin(G_pd)

% Sensibilidad
S_pd=minreal(1/(1+G_pd));
% Pulsacion de maxima sensibilidad
ws_pd=fminsearch(@(w) -abs(freqresp(S_pd,w)),1);
% Maxima sensibilidad
Ms_pd=20*log10(abs(freqresp(S_pd,ws_pd)));




% Pulsacion de resonancia
wr_pd=fminsearch(@(w) -abs(freqresp(F_ry_pd,w)),1);
% Pico de resonancia
Mr_pd=20*log10(abs(freqresp(F_ry_pd,wr_pd)))-20*log10(dcgain(F_ry_pd));





%% Control PID eje X
Fpi=-10;
wo_pid=1.7*wo_p;
f=0.1;
I=-1/(wo_pid*tand(Fpi));
%Hallar ganancia Y fase del control
Fic=-180+Fm-angle(freqresp(Pam,wo_pid))*(180/pi);
Ac=1/abs(freqresp(Pam, wo_pid));
%control PD
Fpd=Fic-Fpi;

fmax=(1-sind(Fpd))/(1+sind(Fpd));
if f>fmax
    f=fmax;
end

D=((1/f-1)/(2*tand(Fpd))-sqrt(((1/f-1)/(2*(tand(Fpd))))^2-1/f))/wo_pid;
Kp=Ac*cosd(Fpi)*(sqrt(1+(f*wo_pid*D)^2))/(sqrt(1+(wo_pid*D)^2));

%conversión modelo serie a paralelo:

mu=1+(1-f)*D/I;
K=mu*Kp;
Td=((1/mu)-f)*D;
Ti=mu*I;
N=(1/(mu*f))-1;
%fórmula para hallar b 
b=1.2;

C_pid=K*(1+1/(Ti*s)+(Td*s)/(1+Td*s/N));
G_pid=minreal(C_pid*Pam);

%sin ponderación y diferencial sobre error
Cr_pid=C_pid;

%ponderación sobre error
Cr_pid=K*(b+1/(Ti*s)+(Td*s)/(1+Td*s/N));

%con ponderación y diferencial sobre salida

Cr_pid=K*(b+1/(Ti*s));

%funciones de transferencia:
F_ry_pid=minreal(Cr_pid*Pam/(1+G_pid));
%da error using minreal ( improper model) F_ru_pid=minreal(Cr_pid/(1+G_pid));
F_dy_pid=minreal(Pd/(1+G_pid));
F_du_pid=minreal(Pam*C_pid/(1+G_pid));



%parámetros

[Am_pid,Fm_pid,wu_pid,wo_pid] = margin(G_pid)


% Sensibilidad
S_pid=minreal(1/(1+G_pid));
% Pulsacion de maxima sensibilidad
ws_pid=fminsearch(@(w) -abs(freqresp(S_pid,w)),1);
% Maxima sensibilidad
Ms_pid=20*log10(abs(freqresp(S_pid,ws_pid)));


% Pulsacion de resonancia
wr_pid=fminsearch(@(w) -abs(freqresp(F_ry_pid,w)),1);
% Pico de resonancia
Mr_pid=20*log10(abs(freqresp(F_ry_pid,wr_pid)))-20*log10(dcgain(F_ry_pid));




return
