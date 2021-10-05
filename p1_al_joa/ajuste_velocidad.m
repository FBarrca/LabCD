%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%  ALGORITMO DE ESTIMACION DE PARAMETROS  %%%%%%%%%%%%%%%
%%%%%%%%%%%%%%         POR MINIMOS CUADRADOS           %%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear theta thaux dgn J
format compact
format short e
%set_param('sistema','MaxConsecutiveZCsMsg','none');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%   PARAMETROS Y VALORES INICIALES %%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% modelo motor: th = [Km Tm Offset]
th=[0.05 0.05 0.01];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
theta=th;
Np=length(theta);      % Numero de parametros
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%   PARAMETROS DEL ALGORITMO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ts=time(2)-time(1); % Periodo de muestreo
tfin=time(end);	 % Tiempo final de simulacion
Tsamp=ts;  % Intervalo fijo de integracion
Nd=tfin/Tsamp; % Numero de datos en el ajuste
tol1=1;    % Tolerancia (variacion de la funcion objetivo 'V')
tol2=1;    % Tolerancia (variacion de los parametros 'theta')
V=1;       % Inicializacion del valor anterior la funcion objetivo
Vaux=0.01; % Inicializacion del valor nuevo de la funcion objetivo
dgn=ones(1,Np); % Direccion de Gauss-Newton (incremento de los parametros) 
niter=0;  % Numero de iteraciones
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%  ALGORITMO DE AJUSTE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
% El algoritmo se ejecuta mientras (bucle while) la variacion de
% la funcion objetivo en % es mayor que 'tol1' o el maximo incremento 
% en % de los parametros es mayor que 'tol2'.
% Tambien se puede usar como criterio el numero de iteraciones.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

while (100*(V-Vaux)/Vaux>tol1 || 100*max(abs(dgn./theta))>tol2) %& niter<10
	
	niter=niter+1;	% Se incrementa el numero de iteraciones

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% Actualizacion de los parametros
	th=theta;
	%h0=theta(2);
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Simulacion del sistema	
    %[t,x,ys,ym,error]=sim('sistema',tfin);
    sim('sistema_velocidad')
    ym=ymed(:,2);
    ys=ysim(:,2);    
    error=ys-ym;
	% Funcion objetivo (error cuadratico medio)	
	V=sqrt(sum((error).^2)/Nd);    		
	% Construccion de la matriz Jacobiana por diferencias finitas
	for i=1:Np
		thaux=theta;
		h=.001*abs(theta(i)); % Incremento para las derivadas
		if abs(theta(i))<10*sqrt(eps)
			h=.01*sqrt(eps);
		end
	 	thaux(i)=theta(i)+h;
		% Actualizacion de los parametros		
		th=thaux;
        % Simulacion
        sim('sistema_velocidad')
        ym=ymed(:,2);
        yaux=ysim(:,2);
        error=yaux-ym;
        % Matriz de sensibilidades
	 	J(:,i)=(yaux-ys)/h;
 	end

	% Representacion grafica de 'ys', 'ym' y del error=ys-ym
	clf
	plot(ymed(:,1),ymed(:,2),'-r',ysim(:,1),ysim(:,2),'-b',ysim(:,1),error,'-g')
    xlabel('Tiempo (s)')
    legend('Salida medida','Salida simulada','Error')
    grid
% 	disp('PULSA UNA TECLA PARA CONTINUAR')
% 	pause
		
	dgn=(J\(ym-ys))'; % Direccion de Gauss-Newton	

    % BUSQUEDA DE 'MU' (ajuste del paso en la direccion de Gauss-
	% Newton para garantizar una disminucion de la funcion objetivo
	mu=2;  % Inicializacion de mu
	Vaux=V+10; % Inicializacion de la funcion objetivo en el nuevo punto
	stb=1; % Flag de estabilidad del sistema (0-inestable: 1-estable)

	% Busqueda de 'mu' mientras no se reduzca la funcion objetivo o
	% el sistema sea inestable
    thaux=theta;
	
	while Vaux > V 
		mu=mu/2; % Reduccion del paso
		thaux=theta+mu*dgn; % Actualizacion de parametros

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		% Actualizacion de los parametros del regulador
	 	th=thaux;
		%h0=thaux(2);
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		
		
		% Simulacion con los nuevos parametros

        %[t,x,yaux,ym,error]=sim('sistema',tfin);
        sim('sistema_velocidad')
        ym=ymed(:,2);
        yaux=ysim(:,2);
        error=yaux-ym;


        % Actualizacion de la funcion objetivo
        Vaux=stb*sqrt(sum((yaux-ym).^2)/Nd);
	end

	% Parametros y funcion objetivo en pantalla 
	theta=thaux;
	disp('PARÁMETROS')    
    disp(theta)
    disp('FUNCIÓN DE COSTE')
	disp(Vaux)
	
end

% Matriz de covarianzas de los parametros (Sensibilidades)
%P=Vaux^2*inv(J'*J);
%disp('Coeficientes de dispersión')
%disp(100*sqrt(diag(P)')./theta)



