clc
clear
% para usar modelo analogico modificado ret=1
% para usar modelo analogico puro ret = 0
ret = 1;

%% CONTROL PID

% definimos s, ts, z
s = tf('s');
ts = 0.015;
Ts = ts;
z = tf('z',ts);
tr=0.005;


% establecemos la planta y el retardo
P = 0.03/(1+0.07*s)/(1+0.2*s);
delay = exp(-ts*s/2);
Pm = P*delay;
Pd = c2d(P,ts);
P_d = -P;
Pd_d = c2d(P_d,ts);

% valores definidos: diseño del PID
Fm = 45;        % margen de fase (grados)
wo_pid = 25;    % pulsación de cruce del control pid
f = 0.1;        % factor de filtrado
fpi = -10;      % desfase de la acción integral (grados)
b = 1.2;        % ponderación a la referencia
Fa=tf(1,1);


% desfases del pid:
fic = -180+Fm-angle(freqresp(Pm,wo_pid))*(180/pi);  
                % desfase total del control
fpd = fic-fpi;  % desfase de la parte diferencial


% parametros en serie:
Ac = 1/abs(freqresp(Pm, wo_pid));
                % calculo del margen de amplitud para el punto de corte
D = ( (1/f-1)/(2*tand(fpd)) - sqrt( (((1/f-1)/(2*tand(fpd)))^2) - 1/f) )/wo_pid;
I = -1/tand(fpi)/wo_pid;
Kp = Ac*cosd(fpi)*sqrt((1+(f*wo_pid*D)^2)/(1+(wo_pid*D)^2));


% parametros en paralelo:
mu=1+(1-f)*D/I;
K=mu*Kp;
Td=((1/mu)-f)*D;
Ti=mu*I;
N=(1/(mu*f))-1;


% establecemos las funciones de transferencia para los controles:
% e = 1 -> derivada al error
% e = 0 -> derivada a la salida
e = 1;

if e == 1
    C_pid=K*(1+1/(Ti*s)+(Td*s)/(1+Td*s/N));
    Cr_pid=K*(b+1/(Ti*s)+(Td*s)/(1+Td*s/N));
        % control analogico
    % reglad derivada en el retraso: 1/s = ts/(1-z^-1)
    % regla trapezoidal : 1/s = ts*(1+z^-1)/2/(1-z^-1)
    sa = (ts*(1+z^-1)/2/(1-z^-1))^(-1);
    Cd_pid = K*(1+1/(Ti*sa)+(Td*sa)/(1+Td*sa/N));
    Crd_pid = K*(b+1/(Ti*sa)+(Td*sa)/(1+Td*sa/N));
        % control digital
        
else
    C_pid=K*(1+1/(Ti*s)+(Td*s)/(1+Td*s/N));
    Cr_pid=K*(b+1/(Ti*s));
        % control analogico
    % reglad derivada en el retraso: 1/s = ts/(1-z^-1)
    % regla trapezoidal : 1/s = ts*(1+z^-1)/2/(1-z^-1)
    sa = (ts*(1+z^-1)/2/(1-z^-1))^(-1);
    Cd_pid = K*(1+1/(Ti*sa)+(Td*sa)/(1+Td*sa/N));
    Crd_pid = K*(b+1/(Ti*sa));
        % control digital
end

C=C_pid;
Cr=Cr_pid;
Cd=Cd_pid;
Crd=Crd_pid;

% funciones analogicas
G_pid=minreal(C_pid*Pm);
F_pid = minreal(Cr_pid*Pm/(1+G_pid));
F_ru_pid=minreal(Cr_pid/(1+G_pid));
F_dy_pid=minreal(P_d/(1+G_pid));
F_du_pid=minreal(Pm*C_pid/(1+G_pid));

% funciones digitales
Gd_pid = minreal(Cd_pid*Pd);
Fd_pid = minreal(Crd_pid*Pd/(1+Gd_pid));
Fd_ru_pid=minreal(Crd_pid/(1+Gd_pid));
Fd_dy_pid=minreal(Pd_d/(1+Gd_pid));
Fd_du_pid=minreal(Pd*Cd_pid/(1+Gd_pid));

        

% ANALISIS:
% zpk(C_pid)
% zpk(Cr_pid)
% zpk(Cd_pid,ts)
% zpk(Crd_pid,ts)

% Margenes de estabilidad de PID
[Am_pid,Fm_pid,wu_pid,wo_pid] = margin(Gd_pid);
% Sensibilidad y maxima sensibilidad
Sd_pid=minreal(1/(1+Gd_pid));
ws_pid=fminsearch(@(w) -abs(freqresp(Sd_pid,w)),1);
Ms_pid=20*log10(abs(freqresp(Sd_pid,ws_pid)));
% Respuesta temporal a analizar en ltiview


% % Pulsacion de resonancia
% wr_pid=fminsearch(@(w) -abs(freqresp(F_pid,w)),1);
% % Pico de resonancia
% Mr_pid=20*log10(abs(freqresp(F_pid,wr_pid)))-20*log10(dcgain(F_pid));
