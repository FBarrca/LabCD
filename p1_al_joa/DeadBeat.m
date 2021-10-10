%% Diseño Directo: Parecido al problema 4.3

clc
clear

%% buscamos Ts mínimo por tanteo...
tr=0.1;
Ts=4;
ts=Ts;%buscamos un Ts que haga que Pd sea inversamente estable
s=tf('s');
z=tf('z', Ts);

Km=7.7278e-2;
Tm=6.7051e-2;
Roz=7.0803e-1;
Tf=0.2;

P=Km/(Tm*s+1)/(Tf*s+1);
Pd=c2d(P, Ts, 'zoh');

z=zpkdata(Pd, 'v'); %Obtenemos los ceros de Pd, que es lo que nos interesa
z=abs(z) %Miramos que el módulo de todos los ceros sea menor que la unidad

%% buscamos Ts para velocidad y sobrepaso determinados... 20%
Ts=0.16; 
ts = Ts;
z=tf('z', Ts);

Pd=c2d(P, Ts, 'zoh'); %Cada vez que cambia el Ts, cambia Pd, hay que recalcularlo

F=1/z; %Control Dead Beat de orden 1

Cd=minreal(F/(Pd-F*Pd)); %simular en el modelo mixto para ver el sobrepaso
Crd=Cd;


Fa=tf(1,1);
C=Fa;
Cr=C;
ret=0;

load("Velocidad_plano.mat");
load("PruebaDeadbeat2.mat");



% %% Dead beat de 2 orden...
% % Calculamos alpha:
% 
% Ts=0.1;
% 
% z=tf('z', Ts);
% 
% Pd=c2d(P, Ts, 'zoh');
% 
% alpha=zpkdata(Pd, 'v');
% 
% F=(z-alpha)/(1-alpha)/z^2; %control Dead Beat de 2º orden donde el cero es el cero de la planta en tiempo discreto (se conserva)
% 
% Cd=minreal(F/(Pd-F*Pd)); %simular en el modelo mixto para ver el sobrepaso, en este caso, el único sobrepaso que hay es el inicial 
% %que provoca el cero positivo, es en el que nos tenemos que fijar. Con el
% %Ts mínimo(4.5), el sobrepaso es menor del 20%, es la solución válida más
% %rápida
% Crd=Cd;
% 
% 
% Fa=tf(1,1);
% C=Fa;
% Cr=C;
% ret=0;
% 
