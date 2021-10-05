 

clc 
clear
% para usar modelo analogico modificado ret=1
% para usar modelo analogico puro ret = 0
ret = 1;
% declaramos variable de LaPlace y variable z
s = tf('s');
ts = 0.1;
Ts = ts;
z = tf('z',ts);

% establecemos valores de la planta y retardo
Km=0.077871;
Tm= 0.067567;
Tf=0.2;
P = Km/(Tm*s+1)/(Tf*s+1);


delay = exp(-ts*s/2);
Pm = P*delay;
Pd = c2d(P,ts);

% establecemos parametros iniciales
Fm = 60;
Fa = tf(1,1);
% calculamos valores de corte
wo_p = fsolve(@(wo) -180+Fm-180/pi*angle(freqresp(P,wo)),1);
Ap = abs(freqresp(P, wo_p));
Kp = 1/Ap;

% declaramos el control proporcional. K -> C
K = Kp;
C = tf(K,1);
Cr = C;

Cd = c2d(C,ts,'zoh');
Crd = Cd;

F = minreal(C*Pm/(1+C*Pm));

% G = Pm*K;

%% CONTROL pid
% 
% wo_pid = 1.2*wo_p;
% Fpi=-10;
% f=0.1;
% b=1;
% ts = 0.03;
% Ts = ts;
% 
% 
% Fic = -180+Fm-angle(freqresp(Pm,wo_pid))*(180/pi);
% Fpd=Fic-Fpi;
% 
% Ac=1/abs(freqresp(Pm, wo_pid));
% 
% fmax=(1-sind(Fpd))/(1+sind(Fpd));
% if f>fmax
%     f=fmax;
% end
% 
% % formato serie
% D=((1/f-1)/(2*tand(Fpd))-sqrt(((1/f-1)/(2*(tand(Fpd))))^2-1/f))/wo_pid;
% Kp=Ac*cosd(Fpi)*(sqrt(1+(f*wo_pid*D)^2))/(sqrt(1+(wo_pid*D)^2));
% I = fsolve(@(I) wo_pid*I+1/tand(Fpi),1);
% 
% % formato paralelo
% mu=1+(1-f)*D/I;
% K=mu*Kp;
% Td=((1/mu)-f)*D;
% Ti=mu*I;
% N=(1/(mu*f))-1;
% 
% C_pid=K*(1+1/(Ti*s)+(Td*s)/(1+Td*s/N));
% Cr_pid=K*(b+1/(Ti*s)+(Td*s)/(1+Td*s/N));
% % C_pid =Kp*(1+I*s)/(I*s)*(1+D*s)/(1+f*D*s);
% 
% % discretizacion del control:
% % reglad derivada en el retraso: 1/s = ts/(1-z^-1)
% % regla trapezoidal : 1/s = ts*(1+z^-1)/2/(1-z^-1)
% sa = (ts*(1+z^-1)/2/(1-z^-1))^-1;
% Cd_pid = K*(1+1/(Ti*sa)+(Td*sa)/(1+Td*sa/N));
% Crd_pid = K*(b+1/(Ti*sa)+(Td*sa)/(1+Td*sa/N));
% % Cd_pid = Kp*(1+I*sa)/(I*sa)*(1+D*sa)/(1+f*D*sa);
% 
% F= minreal(Cr_pid*Pm/(C_pid+Pm));
% % Fd = minreal(Crd_pid*Pd/(Cd_pid+Pd));
% 
% % F =minreal(C_pid*Pm/(C_pid+Pm));
% % Fd  = minreal(Cd_pid*Pm/(Cd_pid+Pm));
% G = minreal(C_pid*Pm);
