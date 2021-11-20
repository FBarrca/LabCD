function analiza_robustez_SFR(Pss_d,Kcd,Ubase,Ybase)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Funciones de sensibilidad
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Matrices de la respresentacion de estado
matAd=Pss_d.a;
matBd=Pss_d.b;
matCd=Pss_d.c;
matDd=Pss_d.d;
ts=Pss_d.Ts;
% Dimensiones
% Numero de variables de estado 
n_x=size(matAd,1);
% Numero de entradas 
n_u=size(matBd,2);
% Numero de medidas 
n_y=size(matCd,1);
% Normalización 
Ubase=Ubase(:);
Ybase=Ybase(:) ;
Kcd=Kcd.*repmat(Ybase',n_u,1).*repmat(1../Ubase,1,n_y); 
matBd=matBd.*repmat(Ubase',n_x,1); 
matCd=matCd.*repmat(1../Ybase,1,n_x);
matDd=matDd.*repmat(Ubase',n_y,1).*repmat(1../Ybase,1,n_u);
% Análisis MIMO de funciones de sensibilidad 
P_mimo=ss(matAd,matBd,matCd,matDd,ts);
C_mimo=ss(0,zeros(1,n_y),0,Kcd,ts);
% Análisis de robustez frente a errores de modelado 
% Función de sensibilidad de la entrada (mando) 
matSi=minreal(inv(1+C_mimo*P_mimo));
% Amplificación del ruido de medida
% Función de sensibilidad complementaria para la salida 
matTo=minreal(P_mimo*C_mimo/(eye(3)+P_mimo*C_mimo));
% Valores máximos de la sensibilidad 
auxSi=norm(matSi,inf);
auxTo=norm(matTo,inf); 
maxSi_dB=20*log10(max(auxSi(:)));
maxTo_dB=20*log10(max(auxTo(:)));
% Resultados por pantalla ele
clc
fprintf('Análisis de la robustez ante errores en el modelo:\n') 
fprintf('Máxima sensibilidad Si en dB: %5.1f \n',maxSi_dB') 
fprintf('La máxima ganancia de S_i  debería estar entre 2.3 y 6 dB\n') 

fprintf('Amplificación del ruido de medida:\n')
fprintf('Máxima sensibilidad complementaria To en dB: %5.1f \n',maxTo_dB')
fprintf('La máxima ganancia de T_o  debería ser lo más baja posible dentro de los límites de las especificaciones\n')

return
