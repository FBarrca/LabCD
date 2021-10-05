clc
clear

%% Apartado 1, buscar Ts mínimo por tanteo

Ts=4.5; %buscamos un Ts que haga que Pd sea inversamente estable
s=tf('s');
z=tf('z', Ts);

P=20*(1-s)/(1+2*s)/(1+10*s);
Pd=c2d(P, Ts, 'zoh');

z=zpkdata(Pd, 'v'); %Obtenemos los ceros de Pd, que es lo que nos interesa
z=abs(z) %Miramos que el módulo de todos los ceros sea menor que la unidad

%% Apartado 2, buscar respuesta más rápida (menor Ts mayor rapidez, mayor sobrepaso) cuyo sobrepaso no sea mayor al 20 por ciento
%Como el sobrepaso inicial que hay hacia abajo por tener un cero positivo
%es mucho menor que el segundo sobrepaso, nos centraremos en el segundo
Ts=9.5; 

z=tf('z', Ts);

Pd=c2d(P, Ts, 'zoh'); %Cada vez que cambia el Ts, cambia Pd, hay que recalcularlo

F=1/z; %Control Dead Beat de orden 1

Cd=minreal(F/(Pd-F*Pd)); %simular en el modelo mixto para ver el sobrepaso
Crd=Cd;


Fa=tf(1,1);
C=Fa;
Cr=C;
ret=0;

sim('modelo_generico.slx');



%% Apartado 3, buscar respuesta más rápida (menor Ts mayor rapidez, mayor sobrepaso) cuyo sobrepaso no sea mayor al 20 por ciento

Ts=4.5;

z=tf('z', Ts);

Pd=c2d(P, Ts, 'zoh');

alpha=zpkdata(Pd, 'v');


F=(z-alpha)/(1-alpha)/z^2; %control Dead Beat de 2º orden donde el cero es el cero de la planta en tiempo discreto (se conserva)

Cd=minreal(F/(Pd-F*Pd)); %simular en el modelo mixto para ver el sobrepaso, en este caso, el único sobrepaso que hay es el inicial 
%que provoca el cero positivo, es en el que nos tenemos que fijar. Con el
%Ts mínimo(4.5), el sobrepaso es menor del 20%, es la solución válida más
%rápida
Crd=Cd;


Fa=tf(1,1);
C=Fa;
Cr=C;
ret=0;

sim('modelo_generico.slx');

%para comparar simulaciones de simulink con simulaciones anteriores, poner en el command
%window plot(sim('nombre_fichero.slx')), en el plot darle a Compare y
%seleccionar las simulaciones que queremos comparar. No hace falta runear
%otra vez la simulación antigua, está guardada en matlab, hay como un
%historial de simulaciones