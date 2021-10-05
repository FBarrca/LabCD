clc
clear

% establecemos la variable de LaPlace 
s = tf('s');
% establecemos el modelo de la planta
P = 50/((s+5)*(s+2));
% discretizamos la planta. Para ello establecemos 'z' y Pd
ts = 0.1;
z = tf('z',ts);
Pd = c2d(P,ts);
% establecemos el modelo analogico modificado. Introduciendo el retardo.
Pm = P*exp(-ts/2*s);
% margen de fase
Fm = 50;
