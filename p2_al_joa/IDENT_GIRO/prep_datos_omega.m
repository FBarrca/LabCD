plot(Y2(:,2:3))
grid
disp('Hacer zoom en la zona de interés de la figura')
disp('Después, pulsar cualquier tecla')
pause
[aux1,aux2]=ginput(2);
aux1=round(aux1);
time=Y2(aux1(1):aux1(2),1)-Y2(aux1(1),1);
ent=Y2(aux1(1):aux1(2),2);
ent=ent-ent(1);
sal=Y2(aux1(1):aux1(2),3);
sal=sal-sal(1);
plot(time,[sal ent])
xlabel('Tiempo (s)')
ylabel('y(t) y u(t)')
grid
