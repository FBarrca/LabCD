%% DISEÑO del control PID

% calculamos la planta...
% buscamos seta = 0.7, wn = 4.5 rad/s, p = -25
% (s^2 +2*seta*wn *s +wn^2)*(s-p) = s^3 + a2*s^2 + a1*s +a0
s = tf('s');

wn = 4.5;
seta = 0.7;
p = -0.25;
a3 = 1;
a2 = (2*seta*wn-p);
a1 = (-2*seta*wn+wn^2);
a0 = (-p*wn^2);
denominador = minreal(a3*s^3 + a2*s^2 + a1*s + a0);
P = s/denominador;
[z,p,k] = zpkdata(P, 'v')
