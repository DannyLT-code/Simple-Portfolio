% ENTREGABLE 2
% Axel Daniel Corona Ibarra - A01425010
% Emiliano Vivas Rodriguez - A01424732
% Axel Espinoza Sebastián - A01425004
% 04 / 05 / 2022

clear;
clc;

% ecuaciones                                                                                                                                                                        
% E = K * (g/r^2) * u
% E = Intensidad del campo eléctrico [Newton/Coulomb = N/M]
% K = Constante de coulomb [Newton*metro^2 /Coulomb^2]
% q = Carga eléctrcia [Coulomb]
% r = Distancia entre las cargas [metros]
% u = Vector unitario o normalizado

% Constante
K = 8.987551787e9;

% Punto inicial
P0 = 0;

% Ingreso de datos
prompt = "Ingrese la longitud de la barra 1 [m]: \n";
Lb1 = input(prompt);

prompt= "Ingrese la longitud de la barra 2 [m]: \n";
Lb2 = input(prompt);

prompt = "Ingrese el valor de la carga, q1 [C] de b1: \n ";
q1 = input(prompt);

prompt= "Ingrese el valor de la carga, q2 [C] de b2: \n ";
q2 = input(prompt);

prompt = "Ingrese el número de intervalos para formar las barras NI[-]: \n";
NI = input(prompt);

prompt = "Ingrese el número de intervalos para la separación entre barras NSB [-]: \n";
NSB = input(prompt);

%
lmax = max(Lb1,Lb2);
sep = 2.*lmax;
%

% Crear los vectores que describan espacialmente las barras
sb1 = linspace(P0,Lb1,NI);
sb2 = linspace(P0,Lb2,NI);

% Obtener la variable de carga uniforme ditribuida
Gq1 = q1./(Lb1./2);
Gq2 = q2./(Lb2./2);

% Crear vectores
vb1 = zeros(1,NI);
vb2 = zeros(1,NI);
vq1 = zeros(1,NI);
vq2 = zeros(1,NI);

for i=1:NI

    vb1(i)=P0;
    vb2(i)=P0 + sep;
    vq1(i)=-abs(Gq1);
    vq2(i)=Gq2;
    
end

if Lb1 > Lb2
    %Caso 1 cuando la b1 es mayor que la b2
    %Barras verticales
    x = [vb1, vb2];
    y = [sb1,(Lb1-Lb2).*0.5 + sb2];
    q = [vq1,vq2];
    xi = linspace(P0 - sep, P0 + sep.*2,NSB);
    yi = linspace(-lmax, lmax .*2,NSB);
    
    [XI,YI]= meshgrid(xi,yi);
    zi=complex(XI,YI);
    z = complex(x,y);
    [ZI,Z]=ndgrid(zi(:),z(:));
    dZ = ZI - Z;
    
    Zn = abs(dZ);
    E = (dZ./Zn.^3)*(q(:)*K);
    E = reshape(E,size(XI));
    En = abs(E);
    
    Ex = real(E);
    Ey = imag(E);
    
    fig1 = figure(1);
    fig1.OuterPosition = [200 200 450 450];
    quiver(XI, YI,Ex./En,Ey./En);
    axis([P0-sep P0+sep.*2 -lmax lmax.*2]);
    grid on;
    hold on;
    
    plot(P0,sb1,'or');
    plot(P0 + sep, (Lb1-Lb2).*0.5 + sb2, 'ok');
    PuntoCentralVertiY = lmax.*0.5;
    plot(P0 + sep.*0.5, lmax.*0.5, 'y*');
    plot(P0, lmax.*0.5,'b*');
    plot(P0 + sep, lmax.*0.5,'g*');
    title('Gráfica vertical');
    xlabel('Eje x');
    ylabel('Eje y');
    
    %Barras horizontales
    x = [sb1,(Lb1-Lb2).*0.5 + sb2];
    y = [vb1, vb2];
    xi = linspace(-lmax, lmax .*2,NSB);
    yi = linspace(P0 - sep, P0 + sep.*2,NSB);
    
    [XI,YI]= meshgrid(xi,yi);
    zi=complex(XI,YI);
    z = complex(x,y);
    [ZI,Z]=ndgrid(zi(:),z(:));
    dZ = ZI - Z;
    
    Zn = abs(dZ);
    E = (dZ./Zn.^3)*(q(:)*K);
    E = reshape(E,size(XI));
    En = abs(E);
    
    Ex = real(E);
    Ey = imag(E);
    
    fig2 = figure(2);
    fig2.OuterPosition = [200 200 450 450];
    quiver(XI, YI,Ex./En,Ey./En);
    axis([-lmax lmax.*2 P0-sep P0+sep.*2]);
    grid on;
    hold on;
    
    plot(sb1,P0,'or');
    plot((Lb1-Lb2).*0.5 + sb2, P0 + sep, 'ok');
    plot(lmax.*0.5, P0 + sep.*0.5, 'y*');
    plot(lmax.*0.5, P0,'b*');
    plot(lmax.*0.5, P0 + sep,'g*');
    title('Gráfica horizontal');
    xlabel('Eje x');
    ylabel('Eje y');
    
else 
    %Caso 1 cuando la b2 es mayor a b1
    %Barras verticales
    x = [vb1, vb2];
    y = [(Lb2-Lb1).*0.5 + sb1,sb2];
    q = [vq1,vq2];
    xi = linspace(P0 - sep, P0 + sep.*2,NSB);
    yi = linspace(-lmax, lmax .*2,NSB);
    
    [XI,YI]= meshgrid(xi,yi);
    zi=complex(XI,YI);
    z = complex(x,y);
    [ZI,Z]=ndgrid(zi(:),z(:));
    dZ = ZI - Z;
    
    Zn = abs(dZ);
    E = (dZ./Zn.^3)*(q(:)*K);
    E = reshape(E,size(XI));
    En = abs(E);
    
    Ex = real(E);
    Ey = imag(E);
    
    fig1 = figure(1);
    fig1.OuterPosition = [200 200 450 450];
    quiver(XI, YI,Ex./En,Ey./En);
    axis([P0-sep P0+sep.*2 -lmax lmax.*2]);
    grid on;
    hold on;
    
    plot(P0,sb2,'or');
    plot(P0 + sep, (Lb2-Lb1).*0.5 + sb1, 'ok');
    PuntoCentralVertiY = lmax.*0.5;
    plot(P0 + sep.*0.5, lmax.*0.5, 'y*');
    plot(P0, lmax.*0.5,'b*');
    plot(P0 + sep, lmax.*0.5,'g*');
    title('Gráfica vertical');
    xlabel('Eje x');
    ylabel('Eje y');
    
    %Barras horizontales
    x = [(Lb2-Lb1).*0.5 + sb1,sb2];
    y = [vb1, vb2];
    xi = linspace(-lmax, lmax .*2,NSB);
    yi = linspace(P0 - sep, P0 + sep.*2,NSB);
    
    [XI,YI]= meshgrid(xi,yi);
    zi=complex(XI,YI);
    z = complex(x,y);
    [ZI,Z]=ndgrid(zi(:),z(:));
    dZ = ZI - Z;
    
    Zn = abs(dZ);
    E = (dZ./Zn.^3)*(q(:)*K);
    E = reshape(E,size(XI));
    En = abs(E);
    
    Ex = real(E);
    Ey = imag(E);
    
    fig2 = figure(2);
    fig2.OuterPosition = [200 200 450 450];
    quiver(XI, YI,Ex./En,Ey./En);
    axis([-lmax lmax.*2 P0-sep P0+sep.*2]);
    grid on;
    hold on;
    
    plot(P0,sb2,'or');
    plot((Lb2-Lb1).*0.5 + sb1, P0 + sep, 'ok');
    plot(lmax.*0.5, P0 + sep.*0.5, 'y*');
    plot(lmax.*0.5, P0,'b*');
    plot(lmax.*0.5, P0 + sep,'g*');
    title('Gráfica horizontal');
    xlabel('Eje x');
    ylabel('Eje y');
end

% Calcular los efectos
HCx1 = (2.*K.*(Gq1./(sep.*0.5))).*(Lb1.*0.5) / (sqrt((sep/2)^2 + (Lb1.*0.5)^2));
HCx2 = (2.*K.*(Gq2./(sep.*0.5))).*(Lb2.*0.5) / (sqrt((sep/2)^2 + (Lb2.*0.5)^2));

HT = HCx1 + HCx2;