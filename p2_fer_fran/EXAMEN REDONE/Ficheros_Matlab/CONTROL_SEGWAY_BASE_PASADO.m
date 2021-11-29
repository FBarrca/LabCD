%% CODIGO BASE PARA EXAMEN LAB CONTROL DIGITAL 2
% Borja Baselga Segimon
% Diciembre 2020

%% INDICACIONES ZAMORA PARA EXAMEN:
% El examen de laboratorio de la próxima semana incluye preguntas sobre
% diseño y simulación (lineal y no lineal) de los controles que hemos 
% visto en el laboratorio:
% 1) Control PID de cabeceo 
% 2) Regulador por realimentación de estado por cabeceo 
% 3) Control integral por realimentación de estado del cabeceo para
%   seguimiento de referencia de velocidad 
% 4) Regulador para seguimiento de pared.
% Los ficheros para realizar las simulaciones son los siguientes:
% - SEGWAY_SIM_PID.slx (real el de arriba, lineal el de abajo)
% - SEGWAY_SIM_SFR.slx (real el de arriba, lineal el de abajo)
% - SEGWAY_SIM_SFIC.slx (real el de arriba, lineal el de abajo)
% - PARED_SIM_SFR.slx: aunque este fichero muestra un error en pantalla con
% la versión 2020a de Matlab, sí realiza la simulación. Supongo que es una
% errata de esta versión de Matlab porque el error no es tal error. Por lo
% tanto el examen puede contener preguntas que requieren la simulación con
% este fichero. La simulación puede ser de escalón en la referencia de
% distancia (aplicado a los 5 s), la respuesta a una curva (se aplica a los
% 10 s) o el cambio en la velocidad de avance (se aplica a los 20 s). La
% simulación contiene la respuesta tanto con el modelo no lineal como con
% el linealizado.

% EL MODELO LINEAL ES EL DE LA CAJA CON dX=...
% EL MODELO NO LINEAL/REAL ES EL DE LA CAJA CON MUCHAS COSAS

%% PARAMETROS ORIGINALES (MOODLE) - EJECUTAR

clear
clc
format short e
s=tf('s');
% Período de muestreo
ts = 5e-3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%  PARAMETROS  %%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Los parámetros mecánicos están referidos al eje de la rueda
% Gravedad (m/s^2)
g=9.81;
%%%%%%%%%
% Motor %
%%%%%%%%%
% Resistencia en ohmios
Rm=4.5;
% Relacion de engranajes
n=48;
% Constante electrica (V.s)
Ke=0.01; 
% Constante mecanica (N.m/A)
Kt=Ke;
% Momento de inercia del motor (kg.m^2)
Im=3.75e-3;
% Par máximo de friccion (Nm)
Trmax=0.05;
% Friccion viscosa (N.m.s/rad)
Dm=0.0142;
%%%%%%%%%%
% Segway %
%%%%%%%%%%
% Masa del chasis (kg)
M = 0.6;
% Masa de la rueda + rotor (kg)
m = 0.034;
% Momento de inercia de cabeceo (kg.m^2)
Ith = 1.425e-3;
% Momento de inercia de la rueda + rotor (kg.m^2)
Imr = 3.2e-6+Im;
% Distancia vertical al c.d.g. desde el eje de la rueda (m)
h = 0.073;
% Distancia entre ruedas (m)
W = 0.15;
% Radio de la rueda (m)
R = 81.6e-3/2;
% Vector de parametros
param=[M m Ith Imr h W R Ke Rm Trmax Dm n];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Otros parametros del control %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Instante inicial de control (ms)
time_start = 1;
% Factor de filtrado de la medida de la velocidad
alfa1=0.8;
% Factor de filtrado en la calibración del giroscopo
alfa2=0.999;
% offset inicial del giroscopo
gyro0=615;
% Peso del giroscopo en el filtro complementario
Wfc=0.98;
% Frecuencia de la señal sonora (Hz)
sound_freq = 440;
% Duracion de la señal sonora (ms)
sound_dur =	500;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  PARAMETROS SEGUIMIENTO PARED %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ganancia estática giro (rad/s/V)
Km_w=1;
% Constante de tiempo giro (s)
Tm_w=5e-02;
% Abcisa punto A (m)
xA=0;
% Ordenada punto A (m)
yA=-0.09;
% Vector de parametros
param_pared=[Km_w Tm_w xA yA];
% Distancia pared en el punto de operación (mm)
d0 = 100;
% Velocidad de avance en el punto de operación (m/s)
va0 = 0.15;
% Modelo linealizado seguimiento pared
matAp = [-1/Tm_w 0 0 ; 1 0 0 ; 1000*xA 1000*va0 0];
matBp = [ Km_w/Tm_w 0 0; 0 -1 0; 0 0 0];
matCp = eye(3);
matDp = zeros(3,3);

%%return
disp("0.1. Parametros originales (Moodle) cargados");

%% MODELO MATEMÁTICO DEL VEHÍCULO EQUILIBRISTA

% Anulación del par de fricción máximo (parámetro 10 del modelo)
param(10)=0;
    
% Punto de operacion
Xini=zeros(3,1);
Uini=0;         % Mando inicial entrada inicial
Yini=0;         % Salida inicial
IX=[];          % Ver que parametro queremos fijar de los tres
IU=1;           % P.ej en este caso queremos mantener la entrada a 1
IY=[];
[X0,U0,Y0,DX0]=trim('segway',Xini,Uini,Yini,IX,IU,IY);

% Linealizacion
[matA,matB,matC,matD]=linmod('segway',X0,U0);
matA = [-20 0 0; 200 0 100; 0 1 0]  % COMENTAR SI NO SE USA
matB = [ 1; -10; 0]                 % COMENTAR SI NO SE USA
P_ss=ss(matA,matB,matC,matD);
% Codigo FAR:
%[matA,matB,matC,matD]=linmod('segway'); 
%Pss = ss(matA,matB,matC(1,:),matD(1,:));
%Pth = minreal(zpk(ss(matA,matB,matC(3,:),matD(3,:))));
%Pth.DisplayFormat = 'time constant';

% Función de transfererencia para solo controlar el angulo (variable de
% estado 3)
% matC2=matC(3,:);
% matD2=matD(3,:);
% P_ss=ss(matA,matB,matC2,matD2);
P_tf=tf(P_ss);
P_zpk=minreal(zpk(P_tf));
P_zpk.DisplayFormat='timeconstant';
% Cálculo de los polos de la función de transferencia
eig(P_zpk);
    
% Discretización
Pss_d=c2d(P_ss,ts);

% Discretización de la planta
Pssd=c2d(P_ss,ts,'zoh');
matAd=Pssd.A;
matBd=Pssd.B;
matCd=Pssd.C;
matDd=Pssd.D;

disp("0.2. Modelo matematico creado");
disp("     Creados: (X0, U0, Y0, DX0, P_ss, matA..D, matAd..Dd");
disp("     OJO - ¿Modificar matA, matB, valores iniciales?");

%% CONDICIÓN INICIAL PARA LA SIMULACIÓN

% Ángulo de cabeceo inicial
th0=5; % EN GRADOS
% [velocidad de avance ms, velocidad angular de cabeceo rad/s, angulo de
% cabeceo en rad]
X0=[0 0 th0*pi/180]'; % 15 grados maximo grado inicial para estabilizar

% TEORIA:
% Butterworth tercer orden -> seta = 0.5 (dos polos complejos conjugados)
% Butterworth segundo orden -> seta = 0.7
% Amortiguamiento critico -> seta = 1

disp("0.3. Condicion inicial para simulacion (th0, X0) cargada");
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 1. DISEÑO DE UN REGULADOR PID - CONTROL PID DE CABECEO
% SIMULACION: SEGWAY_SIM_PID.slx 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Parámetros de la planta que relaciona la entrada con el angulo de cabeceo

% Valores por defecto:
Kth=0.007465; % 0.0074649;
Tv=0.05708;
Tw=1.0691e-01;

% Valores del enunciado:
Kth=0.0075;
Tv=0.06;
Tw=0.1;
% K1=0.005;
% T1=0.05;
% K2=0.1;
% T2=0.104;
% Kth=K1*K2;
% Tv=T1;
% Tw=T2;
disp("Cargados valores de Kth, Tv, Tw - ¿Por defecto/cambiar?");

% Calculo de P(s) (=P_pid=Pth)
% P_pid=P_zpk(3);
P_pid=Kth*s/(1+Tv*s)/(1-Tw^2*s^2)
%P_pid=K1*K2*s/(1+T1*s)/(1-T2^2*s^2);

%% Control PID - calculo de los parametros

wn_pid=4.42;
seta=0.5;       % 0.5 si es butterworth de orden 3
p_pid=-wn_pid;  % Polo real de contro PID

% Butterworth tercer orden -> seta = 0.5 (dos polos complejos)
% Butterworth segundo orden -> seta = 0.7
% Amortiguamiento critico -> seta = 1

% Denominador de la función de transferencia
a3=1;
a2=2*seta*wn_pid-p_pid;
a1=wn_pid^2-2*seta*wn_pid*p_pid;
a0=-wn_pid^2*p_pid;
denF=a3*s^3+a2*s^2+a1*s+a0;

% Calculo de los parametros del control conociendo el denominador de la
% función de transferencia
x=fsolve(@(x) [(a2+(Kth*x(2)*x(1)-Tw^2)/(Tv*Tw^2));...
    (a1+(Kth*x(1)+Tv)/(Tv*Tw^2));...
    (a0+(Kth*x(1)/x(3)+1)/(Tv*Tw^2))],[1 ; 1 ; 1]);
K_pid=x(1);
Td_pid=x(2);
Ti_pid=x(3);
b_pid=1; % si nos piden ponderacion cambiamos aqui el valor
%b_pid=0.9;

% Si no funciona el solve (codigo FAR):
% seta = 0.5;
% wn = 4.42;
% polo = -wn;
% K_pid = ((2*seta*wn*polo-wn^2-1/(Tw^2))*Tv*Tw^2)/Kth;
% Td_pid = (((1/Tv)-2*seta*wn+polo)*Tv*Tw^2)/(K_pid*Kth);
% Ti_pid = ((K_pid*Kth/(Tv*Tw^2))/(wn^2*polo-(1/(Tv*Tw^2))));

% En el caso de que nos de K,Ti y Td lo ponemos directamente:
% K=-2.2366e+1;
% Td=1.2696e-1;
% Ti=5.0910e-2;
% b_pid=1;
% K_pid=K;
% Td_pid=Td;
% Ti_pid=Ti;
% P_pid=P_zpk(3);

%% Discretización

z=tf('z',ts);
% Regla de la derivada en retraso
% sa=(z-1)/(z*ts);
sa=ts/(z-1);        % REVISAR
% Regla trapezoidal
%sa=2*(z-1)/(ts*(z+1));

% Forward Euler / Derivada en adelanto / Integral en retraso
% sa=(z-1)/ts;
% Backward Euler / Derivada en retraso / Integral en adelanto
% si hay ringing (Ts mediano y factor filtrado (F) bajo)
% sa=(z-1)/z/ts;
% Regla trapezoidal - Por defecto
% sa=2*(z-1)/ts/(z+1);

% Discretización de la planta
Pd=c2d(P_pid,ts);

%% CONTROLES

% Accion diferencial al error
Cr_pide=(b_pid+(1/(Ti_pid*sa))+(Td_pid*sa))*K_pid;

% Accion diferencial a la salida
Cr_pids=((1/(Ti_pid*sa))+b_pid)*K_pid;

% Control de realimentacion (=con accion diferencial a la salida o al
% error)
C_pide=(1+(1/(Ti_pid*sa))+(Td_pid*sa))*K_pid;
C_pids=(1+(1/(Ti_pid*sa))+(Td_pid*sa))*K_pid;

% Funciones de transferencia

% CASO 1: acción diferencial al error sin filtro
% SALIDA-REFERENCIA
Fry_pide = minreal(Cr_pide*Pd/(1+Pd*C_pide));
damp(Fry_pide)
% SALIDA-PERTURBACIÓN
Fdy_pide=minreal(-Pd/(1+C_pide*Pd));
% MANDO-REFERENCIA
Fru_pide=minreal(Cr_pide/(1+C_pide*Pd));
% MANDO-PERTURBACIÓN
Fdu_pide=minreal(Pd*C_pide/(1+C_pide*Pd));

% CASO 2B: acción diferencial a la salida sin filtro (2)
% SALIDA-REFERENCIA
Fry_pids = minreal(Cr_pids*Pd/(1+C_pids*Pd));
damp(Fry_pids)
% SALIDA-PERTURBACIÓN
Fdy_pids=minreal(-Pd/(1+C_pids*Pd));
% MANDO-REFERENCIA
Fru_pids=minreal(Cr_pids/(1+C_pids*Pd));
% MANDO-PERTURBACIÓN
Fdu_pids=minreal(Pd*C_pids/(1+C_pids*Pd));


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 2. REGULADOR POR REALIMENTACION DE ESTADO (CABECEO)(sin accion integral)
% SIMULACION: SEGWAY_SIM_SFR.slx 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% SI HACE FALTA VOLVER A CARGAR LA PLANTA (descomentar):
% [matA,matB,matC,matD]=linmod('segway2015',X0,th0);
% matA=[-18 0 -1;190 0 95;0 1 0];
% matB=[1;-8;0];
%
% Pss=ss(matA,matB,matC(1,:),matD(1,:));
% Pv=minreal(zpk(ss(matA,matB,matC(1,:),matD(1,:))));
% Pv.DisplayFormat='time constant';
% Pw=minreal(zpk(ss(matA,matB,matC(2,:),matD(2,:))));
% Pw.DisplayFormat='time constant';
% Pth=minreal(zpk(ss(matA,matB,matC(3,:),matD(3,:))));
% Pth.DisplayFormat='time constant';
% Pzkp=minreal(zpk(Pss));
% set(Pzkp,'DisplayFormat','time constant');
%
% %Discretización del modelo
% Pss_d=c2d(Pss, ts, 'zoh');
% matAd=Pss_d.a;
% matBd=Pss_d.b;
% matCd=Pss_d.c;
% matDd=Pss_d.d;


% Polos de la planta - Lazo abierto, tiempo continuo
polosP=eig(matA);
[wnP,setaP]=damp(polosP);
w_la=max(polosP);

% Polos lazo cerrado - Configuracion Butterworth
% Elegimos wn entre 0.5 y 2 veces w_la:
wn_re = 4;
% Seleccionamos seta:
%seta_re = 0.7; % Para Butterworth 2do orden
seta_re = 0.5; % Para Butterworth 3er orden
%seta_re = 0.75 % Si nos dan otra en el enunciado
% Calculamos polos (ponemos al final los adicionales):
polos_lc=wn_re*[-seta_re+sqrt(1-seta_re^2)*1j -seta_re-sqrt(1-seta_re^2)*1j -1].';
% Si los polos de la planta están suficientemente alejados
%   utilizamos esos polos para los polos NO dominantes -wnP()/wn_re
% Si la planta es de 2º orden:
%polos_lc=wn_re*[-seta_re+sqrt(1-seta_re^2)*1j ...
%   -seta_re-sqrt(1-seta_re^2)*1j].';

% Discretizamos polos
polos_lc_d=exp(polos_lc*ts);

% % Discretización de la planta (ya hecho antes)
% Pssd=c2d(P_ss,ts,'zoh');
% matAd=Pssd.A;
% matBd=Pssd.B;
% matCd=Pssd.C;
% matDd=Pssd.D;

% Cálculo de la matriz K del control
Kcd=acker(matAd,matBd,polos_lc_d); % Para 1 entrada: acker o place
%Kcd=place(Adpsi,Bdpsi,polos_lc_d); % Place para 1 o mas entradas
Kid=[ -24  -3  -25]; % COMENTAR SI NO SE USA
%Comprobación que está bien
%eig(Adpsi-Bdpsi*Kcd)=polosd_lc
%eig(Adpsi-Bdpsi*Kcd);

% Calculamos la Kref
Fd0 = (matCd-matDd*Kcd)*inv(eye(3)-matAd+matBd*Kcd)*matBd+matDd;
Kref = inv(Fd0);


% TEORIA:
% Autovalores = polos
% Hay polos dominantes y de relleno
% Num autovals (=polosDominantes) <= 3
% Si solo hay un polo real: los adicionales estaran alejados entre 5 y 10
%   veces respecto al dominante
% Robustez -> Maxima sensibilidad <= 6dB
% Si hay dos polos: se usan dos polos complejos conjugados -> Hay
%   oscilacion, menor wn (=mayor velocidad)
% Si hay 3 polos dominantes: 2 cplx conjugados, 1 en wn, 1 alejado k veces

% Butterworth tercer orden -> seta = 0.5 
%       (1 real + 2 polos complejos conjugados)
% Butterworth segundo orden -> seta = 0.7
%       (2 polos complejos conjugados)
% Amortiguamiento critico -> seta = 1

%%%%%%%%%%%%%%%%%%
% APUNTES ZAMORA %
%%%%%%%%%%%%%%%%%%
% Objetivo: mantener el punto de equilibrio
% En el modelo incremental todas las variables de estado valen 0 en el
% punto de equilibrio
% Estrategia de control: U=-K*X
% Se aplica sobre el modelo incremental en tiempo discreto
% X[k+1] = Ad*X[k] + Bd*U[k] = Ad*X[k] - Bd*K*X[k] = (Ad-Bd*K)*X[k]
% La matriz de estado en el lazo cerrado para que el sistema retorne al
% punto de equilibrio de forma rápida y bien amortiguada

% % PRIMER DISEÑO
% % Asignacion de polos en lazo cerrado
% % Polos en lazo cerrado: configuacion Butterworth
% wn=1;
% seta=0.5;
% polos_lc=wn*[-seta+sqrt(1-seta^2)*1j -seta-sqrt(1-seta^2)*1j -1 -5].';
% % Polos en tiempo discreto
% polosd_lc=exp(polos_lc*ts);
% % Cálculo de la matriz k del control
% Kcd=place(matAd,matBud,polosd_lc);
% 
% % SEGUNDO DISEÑO
% % Pulsacion natural y amortiguamiento de los polos complejos dominantes
% wn=1.6*wnP(1);
% seta=0.7;
% % Polos de lazo cerrado en tiempo continuo
% polos_lc=[wn*(-seta+1j*sqrt(1-seta^2)) wn*(-seta-1j*sqrt(1-seta^2)) -wnP(3)];
% % Polos de lazo cerrado en tiempo discreto
% polosd_lc=exp(ts*polos_lc);
% % Diseño de la matriz en ganancias del regulador
% K=place(matAd,matBud,polosd_lc);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 3. CTRL INTEGRAL POR REALIM. ESTADO (CABECEO) - SEGUIMIENTO REF. VEL
% Control integral por realimentación de estado del cabeceo para
%   seguimiento de referencia de velocidad 
% SIMULACION: SEGWAY_SIM_SFIC.slx
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Seguimiento nulo
% Ampliamos las matrices de la planta con con la accion integral
% Ampliamos con zero(n,m) y eye(m,m) - n:variables de estado - m:entradas
%Amp_n = size(matAd,1);
%Amp_m = size(matBud,2);
matAad = [matAd zeros(3,1); -ts*matCd  eye(1)];
matBad = [matBd; -ts*matDd];

% Seleccionamos los polos
wn = 5;
seta = 0.8;
polos_lc = [wn*(-seta+sqrt(1-seta^2)*1j)  wn*(-seta-sqrt(1-seta^2)*1j) -1*wn -5*wn];
% Discretizamos polos
polosd_lc = exp(polos_lc*ts);

% Calculamos nuestro nuevo regulador
Kad = acker(matAad, matBad, polosd_lc);

% Kcd dimensión mxn - filas como entradas y columnas como estados
Kcd = Kad(:,1:3);
%Kcd = Kad(1:3);

% Kid dimensión mxm - filas como entradas y columnas como entradas
Kid = Kad(:,4);
%Kid = Kad(4);

mando_max = 8.3;
mando_min = -8.3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 4. REGULADOR PARA SEGUIMIENTO DE PARED
% SIMULACION: PARED_SIM_SFR.slx
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Entradas:
%   1- Tensión aplicada a los motores->mando
%   2- Velocidad de giro de la pared(rad/s)->perturbación
%   3- Velocidad de avance (m/s)-> perturbación si se desvía de su valor
%   nominal

% Variables de estado:
%   1- la velocidad angular de rotación (rad/s)
%   2- el ángulo de orientación con respecto a la pared (rad)
%   3- la distancia a la pared (mm)

% Salidas(variables de estado):
%   1- la velocidad angular de rotación (rad/s)
%   2- el ángulo de orientación con respecto a la pared (rad)
%   3- la distancia a la pared (mm)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%  PARAMETROS SEGUIMIENTO PARED %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ganancia estática giro (rad/s/V)
Km_w=1;
% Constante de tiempo giro (s)
Tm_w=5e-02;
% Abcisa punto A (m)
xA=0;
% Ordenada punto A (m)
yA=-0.09;
% Vector de parametros
param_pared=[Km_w Tm_w xA yA];
% Distancia pared en el punto de operación (mm)
d0 = 100;
% Velocidad de avance en el punto de operación (m/s)
va0 = 0.15;
% Modelo linealizado seguimiento pared
matAp = [-1/Tm_w 0 0 ; 1 0 0 ; 1000*xA 1000*va0 0];
matBp = [ Km_w/Tm_w 0 0; 0 -1 0; 0 0 0];
matCp = eye(3);
matDp = zeros(3,3);
% SI NOS DAN LAS MATRICES:
%matAp = [-25 0 0; 1 0 0; 0 125 0];
%matBp = [ 25 0 0; 0 -1 0; 0 0 0];

Pss_w=ss(matAp,matBp,matCp,matDp);
Pss_dp=c2d(Pss_w,ts);
matAdp=Pss_dp.a;
matBdp=Pss_dp.b;
matCdp=Pss_dp.c;
matDdp=Pss_dp.d;

% Seleccionamos los polos:
polos_lc_pared=[-5 -10 -10].'; % Original
%polos_lc_pared=[-2.5 -2.5 -12.5].';
% Discretizamos:
polosd_lc_pared=exp(polos_lc_pared*ts);
Kcd_pared=acker(matAdp,matBdp(:,1),polosd_lc_pared);
Kcd_reg_p=acker(matAdp,matBdp(:,1),polosd_lc_pared);
% Si los polos son diferentes
% Kcd_pared=place(matAdp,matBdp(:,1),polosd_lc_pared);
% Kcd_reg_p=place(matAdp,matBdp(:,1),polosd_lc_pared);

% Si nos dan un Kcd_pared
%Kcd_pared=[-2e-01 4e+00 18e-03];

%% APUNTES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% CODIGO MATLAB APUNTES ONENOTE

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Representacion de estado diagonal %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Dada una funcion de tranferencia Ptf
[R,p]=residue(Ptf.num{1},Ptf.den{1});
matA_diag=[p(1) 0 0; 0 p(2) 0; 0 0 p(3)];
matB_diag=[R(1); R(2); R(3)];
matC_diag=[1 1 1];
matD_diag=0;
% Modelo en espacio de estado
Pss_diag=ss(matA_diag, matB_diag, matC_diag, matD_diag);

% Si tenemos las matrices:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Representacion de estado %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
matA=[-2 -2; 1 -6];
matB=[1; -2];
matC=[1 -2];
matD=2;
Pss=ss(matA, matB, matC, matD);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Funcion de transferencia %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ptf=tf(Pss);
[numPtf,denPtf]=tfdata(Ptf,'v');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Representacion de estado diagonal %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Descomposicion en fracciones parciales
[R1,p1,k1]=residue(numPtf,denPtf);
% 2 + 3.5/(s+5) 1 1.5/(s+3)
% Otra forma:
[polQ,polR]=deconv(numPtf,denPtfd);
[R2,p2,k2]=residue(polR,denPtf);
%%%%%%%%%%%%%%%%%%%%%%
% Punto de operacion %
%%%%%%%%%%%%%%%%%%%%%%
% Entradas
U0=[5 -5];
% Variables de estado
X0=-inv(matA)*matB*U0;
% Salidas
Y0=matC*X0+matD*U0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Discretizacion de la planta %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Periodo de muestreo
ts=0.1;
% Variable z
z=tf('z',ts);
% Respresentacion de estado en tiempo discreto
Pd=c2d(P,ts,'zoh');
% Matrices de la representacion de estado
matAd=Pd.a;
matBd=Pd.b;
matCd=Pd.c;
matDd=Pd.d;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DISEÑO DE UN REGULADOR POR REALIMENTACION DE ESTADO %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Objetivo: mantener el punto de equilibrio
% En el modelo incremental todas las variables de estado valen 0 en el
% punto de equilibrio
% Estrategia de control: U=-K*X
% Se aplica sobre el modelo incremental en tiempo discreto
% X[k+1] = Ad*X[k] + Bd*U[k] = Ad*X[k] - Bd*K*X[k] = (Ad-Bd*K)*X[k]
% La matriz de estado en el lazo cerrado para que el sistema retorne al
% punto de equilibrio de forma rápida y bien amortiguada

% PRIMER DISEÑO
% Asignacion de polos en lazo cerrado
% Polos en lazo cerrado: configuacion Butterworth
wn=1;
seta=0.5;
polos_lc=wn*[-seta+sqrt(1-seta^2)*1j -seta-sqrt(1-seta^2)*1j -1 -5].';
% Polos en tiempo discreto
polosd_lc=exp(polos_lc*ts);
% Cálculo de la matriz k del control
Kcd=place(matAd,matBud,polosd_lc);
% SEGUNDO DISEÑO
% Pulsacion natural y amortiguamiento de los polos complejos dominantes
wn=1.6*wnP(1);
seta=0.7;
% Polos de lazo cerrado en tiempo continuo
polos_lc=[wn*(-seta+1j*sqrt(1-seta^2)) wn*(-seta-1j*sqrt(1-seta^2)) -wnP(3)];
% Polos de lazo cerrado en tiempo discreto
polosd_lc=exp(ts*polos_lc);
% Diseño de la matriz en ganancias del regulador
K=place(matAd,matBud,polosd_lc);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Seguimiento de referencia mediante ajuste de ganancia %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Pulsacion natural y amortiguamiento de los polos complejos dominantes
wn=1.6*wnP(1);
seta=0.7;
% Polos de lazo cerrado en tiempo continuo
polos_lc=[wn*(-seta+1j*sqrt(1-seta^2)) wn*(-seta-1j*sqrt(1-seta^2)) -wnP(3)];
% Polos de lazo cerrado en tiempo discreto
polosd_lc=exp(ts*polos_lc);
% Diseño del control
K=place(matAd,matBud,polosd_lc);
% Calculo e Kref 
Fd0=(matCd-matDd*K)*inv(eye(3)-matAd+matBd*K)*matBd+matDd;
Kref=inv(Fd0);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Seguimiento de referencia mediante control integral %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Matrices ampliadas
matAad=[matAd zeros(3,2); -ts*matCd eye(2)];
matBad=[matBd; -ts*matDd];
% Pulsacion natural y amortiguamiento de los polos complejos dominantes
wn=0.787*wnP(1);
seta=0.7;
% Polos de lazo cerrado en tiempo continuo
polos_lc=[wn*(-seta+1j*sqrt(1-seta^2)) wn*(-seta-1j*sqrt(1-seta^2)) ...
    -5.01*wn -5*wn -wnP(3)];
% Polos de lazo cerrado en tiempo discreto
polosd_lc=exp(ts*polos_lc);
% Diseño del control
Ka=place(matAad,matBad,polosd_lc);
K=Ka(:,1:3);
Ki=Ka(:,4:5);

%% CODIGO MATLAB APUNTES DIAPOSITIVAS LAB
% SESION 1
% MODELO DE LA PLANTA
% Variables de estado:
%   Vr [m/s] - velocidad de avance
%   w_th [rad/s] - velocidad angular de cabeceo
%   th [rad] - angulo de cabeceo
% Funciones de tranferencia:
%   Uc -> Vr => matC, matD (1,:)
%   Uc -> Wth => matC, matD (2,:)
%   Uc -> th => matC, matD (3,:)

% Añadir el punto de operación correspondiente a la posición vertical del
% vehículo, con velocidad de avance nula, y linealizar el modelo en dicho
% punto de operación.
% A la hora de linealizar el modelo, es necesario anular el par de
% fricción máximo (parámetro del modelo). Dar las matrices de la
% representación de estado del modelo linealizado.
% Linealizacion en theta=0
% Funcion de transferencia uc => theta
param(10)=0;
[marA,matB,matC,matD]=linmod('segway');

% Calcular los polos (autovalores de la matriz de estado) del modelo
% linealizado y justificar a partir de ellos el comportamiento inestable
% del vehículo
Pss=ss(matA,matB,matC(1,:),matD(1,:)); 
Pv=minreal(zpk(ss(matA,matB,matC(1,:),matD(1,:)))); 
Pv.DisplayFormat='time constant'; 
Pw=minreal(zpk(ss(matA,matB,matC(2,:),matD(2,:)))); 
Pw.DisplayFormat='time constant'; 
Pth=minreal(zpk(ss(matA,matB,matC(3,:),matD(3,:)))); 
Pth.DisplayFormat='time constant';
% Autovalores -> eig(matA)
