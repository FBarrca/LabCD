clc;
clear;
s=tf('s');

kth=0.0074649;
Tv=0.05708;
Tw=sqrt(0.1114*0.1026);

P=kth*s/((1+Tv*s)*(1-(Tw*s)^2));


p=-25;
seta=0.7;
wn=4.5;

a2=-p+2*seta*wn;
a1=wn^2-2*seta*wn*p;
a0=-p*wn^2;
x=fsolve(@(x) [a2-((1-x(1)*kth*x(2)/Tw^2)/Tv), ...
               a1+(1+x(1)*kth/Tv)/Tw^2, ...
               a0+(1+x(1)*kth/x(3))/Tw^2/Tv], ...
               [0.1,0.05,0.03]);

K=x(1);
Td=x(2);
Ti=x(3);


C=K*(1+1/Ti/s+Td*s);

F=minreal(C*P/(1+C*P));

[num den] = tfdata(F);