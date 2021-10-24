%Control pd y pid


%Hallar las a:

% p<0
p=-25;
seta=0.7;
wn=4.5;

a2=-p+2*seta*wn;
a1=wn^2-2*seta*wn*p;
a0=-p*wn^2;




%hallar los parámetros del control
den=-Tv*Tw^2;

%resolver estas ecuaciones para Ti, Td, K. Los demás parámetros son
%conocidos
%a2=(-Tw+Ti*Td*k*kth)/den/Ti;
%a1=(Tv+k*kth*Ti)/den/Ti;
%a0=(Ti+k*kth)/den/Ti;

x=fsolve(@(x) [a2-(-Tw+x(2)*x(3)*x(1)*kth)/den/x(3), a1-(Tv+x(1)*kth*x(2))/den/x(3), a0-(x(3)+x(2)*kth)/den/x(3)], [0.1,0.05,0.03]);







