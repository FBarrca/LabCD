plot(Velocidad(:,2:4))
grid
disp('Hacer zoom en la zona de interés de la figura')
disp('Después, pulsar cualquier tecla')
pause
[aux1,aux2]=ginput(2);
aux1=round(aux1);
time=Velocidad(aux1(1):aux1(2),1)-Velocidad(aux1(1),1);
ent=Velocidad(aux1(1):aux1(2),4);
%ent=ent-ent(1);
%ent=ent-mean(ent(1:30));
sal=Velocidad(aux1(1):aux1(2),3);
%sal=sal-sal(1);
%sal=sal-mean(sal(1:30));
plot(time,[sal ent])
xlabel('Tiempo (s)')
ylabel('y(t) y u(t)')
grid
