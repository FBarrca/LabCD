clc 
clear
runTime=2.5; %Tiempo que dura la simulacion de Simulink


Ts=0.055; %buscamos un Ts que haga que Pd sea inversamente estable
ts=Ts;

%%Modelado
s=tf('s');
z=tf('z', Ts);
Km=8.2897e-02;
Tm= 6.0718e-02;
Tf=0.18;
P = Km/(Tm*s+1)/(Tf*s+1);
Pd=c2d(P, Ts, 'zoh')
%pzmap(Pd)% O dentro del circulo unidad -> estable


[zPd,pPd,kPd]=zpkdata(Pd,'v')
alfa=zPd(1);
Fd=(z-alfa)/(1-alfa)/z^2;
% Fd=Cd*Pd/(1+Cd*Pd) ==> Cd=Fd/Pd/(1-Fd)
Cd=minreal(Fd/Pd/(1-Fd));
Crd=Cd