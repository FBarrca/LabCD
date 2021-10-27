clc
clear
load('modeloseg2018.mat')

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

wn=0.675*w_la; %MEJOR: seta=0.7, wn=0.6*w_la, seta=0.7, wn=0.55*w_la
seta=0.75; %tambien bien 0.65wla y 0.75
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j, -seta-sqrt(1-seta^2)*1j].';
polos_ad=-5*wn;
polosd_lc=exp([polos_lc; polos_ad]*ts);
Kcd=place(Ad, Bd, polosd_lc);
