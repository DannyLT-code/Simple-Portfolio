from pygame import *
import pygame, sys, math, random

pygame.init()
pygame.font.init()

#Cargando texturas, fotos y graficas
volcan = pygame.image.load("D:\Reto\Volcan.png")
volcan = pygame.transform.scale(volcan, (400,500))
nube1 = pygame.image.load("D:\Reto\cloud1.png")
nube2 = pygame.image.load("D:\Reto\cloud2.png")
nube3 = pygame.image.load("D:\Reto\cloud3.png")
bosque = pygame.image.load("D:\Reto\porest.png")
bosque = pygame.transform.scale(bosque, (50,50))
bosque2 = pygame.image.load("D:\Reto\porest.png")
bosque2 = pygame.transform.scale(bosque, (50,50))
bosque3 = pygame.image.load("D:\Reto\porest.png")
bosque3 = pygame.transform.scale(bosque, (50,50))
bosque4 = pygame.image.load("D:\Reto\porest.png")
bosque4 = pygame.transform.scale(bosque, (50,50))
bosque5 = pygame.image.load("D:\Reto\porest.png")
bosque5 = pygame.transform.scale(bosque, (50,50))
ciudad = pygame.image.load("D:\Reto\city.png")
ciudad = pygame.transform.scale(ciudad, (1000, 300))

#Colores pre-definidos
black = (0, 0, 0)
white = (255, 255, 255)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 128)

#Valores pre-definidos como tamaño de pantalla, resistencia del aire (El cual toma un valor al azar)
#Gravedad (la cual tambien es al azar pero con mucho menos variacion) el radio de nuestras particulas
#Y el tamaño de nuestro texto
wScreen = 1600
hScreen = 700
resistencia_aire = round(random.uniform(0.24, 0.41), 2)
gravedad = round(random.uniform(-9.81, -9.7), 2)
radio = 12
font = pygame.font.Font(None, 20)
potenciaDeY = 4
velocidadDeSim = 0.01
masaParticula = 100

#Definimos el nombre y las dimensiones de nuestro programa principal
window = pygame.display.set_mode((wScreen, hScreen))

#Clase para objetos de tipo 'particula'
class particula(object):
  #Inicializamos nuestra particula con 4 valores (Pos X, Pos Y, Radio, Color)
    def __init__ (self, x, y, radius, color):
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color
    #Dibuja nuestra particula
    def draw(self,win):
        pygame.draw.circle(win,(0,0,0), (self.x, self.y), self.radius)
        pygame.draw.circle(win, self.color,(self.x, self.y), self.radius - 1)
    #Realiza los calculos para simular la trayectoria de nuestra particula
    @staticmethod
    def particulaPath(startx, starty, power, angle, time):
        velX = math.cos(angle) * power 
        velY = math.sin(angle) * power
        #Aceleracion con resistencia de aire
        aceleracionRes = gravedad*(math.exp(-((resistencia_aire/masaParticula)*time)))

        distX = velX * time 
        #Y con resistencia al aire
        distY = starty + ((masaParticula * gravedad)/resistencia_aire * time) + (masaParticula/resistencia_aire)*(-((masaParticula * gravedad)/resistencia_aire))*(1 - (math.exp((-(resistencia_aire/masaParticula)*time))))
        distY = (velY * time) + ((gravedad * (time) ** 2)/2)
        newX = round(distX + startx)
        newY = round(starty - distY)


        return (newX, newY)
#Dibuja todas nuestras imagenes y graficas
def drawGraphs():
    window.blit(volcan, (400,235))
    window.blit(nube1, (400,0))
    window.blit(nube2, (700,0))
    window.blit(nube3, (1400,0))
    window.blit(bosque, (200, 650))
    window.blit(bosque2, (250, 650))
    window.blit(bosque3, (150, 650))
    window.blit(bosque4, (100, 650))
    window.blit(bosque5, (300, 650))
    window.blit (ciudad, (1050, 450))
#Actualiza la pantalla
def redrawWindow():
    window.fill((117, 191, 255))
    #Dibuja las particulas
    particula1.draw(window)
    particula2.draw(window)
    particula3.draw(window)
    drawGraphs()
    #Muestra las lineas de trayectoria posibles de nuestra particula
    #pygame.draw.line(window, (255,255,255), line[0], line[1])
    pygame.draw.rect(window, (18, 26, 69), [0,0,245,400])
    showPos()
    pygame.display.update()

#Encuentra el ángulo con el cual sera expulsada la particula del volcan
def findAngle(pos, partOrg):
    sX = partOrg.x
    sY = partOrg.y
    try: 
        angle = math.atan((sY - pos[1]) / (sX - pos[0]))
    except:
        angle = math.pi / 2
    #Primer cuadrante
    if pos[1] < sY and pos[0] > sX:
        angle = abs(angle)
    #Segundo cuadrante
    elif pos[1] < sY and pos[0] < sX:
        angle = math.pi - angle
    #Tercer cuadrante
    elif pos[1] > sY and pos[0] < sX:
        angle = math.pi + abs(angle)
    #Cuarto cuadrante
    elif pos[1] > sY and pos[0] > sX:
        angle = (math.pi * 2) - angle 
    return angle

#Muestra la posición, ángulo y velocidad de las particulas junto con la resistencia y la gravedad del area.
#(Tabla de información)
def showPos():
    #Definimos las posiciones de las particulas para poder representarlas
    linea = [(particula1.x, particula1.y)]
    linea2 = [(particula2.x, particula2.y)]
    linea3 = [(particula3.x, particula3.y)]
    #Imprimimos la posición de nuestras 3 particulas
    text1 = font.render("Posición particula 1: " + str(linea[0]), False, white)
    text2 = font.render("Posición particula 2: " + str(linea2[0]), False, white)
    text3 = font.render("Posición particula 3: " + str(linea3[0]), False, white)
    #Definimos los angulos de las particulas para poder representarlas
    text1_1 = font.render("Angulo de la particula 1: " + str(radToDeg(angle)), False, white)
    text2_1 = font.render("Angulo de la particula 2: " + str(radToDeg(angle2)), False, white)
    text3_1 = font.render("Angulo de la particula 3: " + str(radToDeg(angle3)), False, white)
    #Definimos velocidades en vector X
    text1_2 = font.render("Velocidad X de la particula 1: " + str(pwrToVelX(power, angle)) + " m/s.", False, white)
    text2_2 = font.render("Velocidad X de la particula 2: " + str(pwrToVelX(power2, angle2)) + " m/s.", False, white)
    text3_2 = font.render("Velocidad X de la particula 3: " + str(pwrToVelX(power3, angle3)) + " m/s.", False, white)
    #Definimos velocidades en vector Y 
    text1_3 = font.render("Velocidad Y de la particula 1: " + str(pwrToVelY(power, angle)) + " m/s.", False, white)
    text2_3 = font.render("Velocidad Y de la particula 2: " + str(pwrToVelY(power2, angle2)) + " m/s.", False, white)
    text3_3 = font.render("Velocidad Y de la particula 3: " + str(pwrToVelY(power3, angle3)) + " m/s.", False, white)
    gravedad_text = font.render("Gravedad del area: " + str(gravedad), False, white)
    resistencia = font.render("Resistencia del aire: " + str(resistencia_aire), False, white)
    #Posicón
    window.blit(text1, (0, 0))
    window.blit(text2, (0, 20))
    window.blit(text3, (0, 40))
    #Angulos
    window.blit(text1_1, (0, 80))
    window.blit(text2_1, (0, 100))
    window.blit(text3_1, (0, 120))
    #Velocidad X
    window.blit(text1_2, (0, 160))
    window.blit(text2_2, (0, 180))
    window.blit(text3_2, (0, 200))
    #Velocidad Y
    window.blit(text1_3, (0, 240))
    window.blit(text2_3, (0, 260))
    window.blit(text3_3, (0, 280))
    #Gravedad y Resistencia
    window.blit(gravedad_text, (0, 360))
    window.blit(resistencia, (0,380))

#Convierte nuestros radianes a grados
def radToDeg(angleOrg):   
    answer = angleOrg * (180/math.pi)

    return round(answer,2)
#Nos devuelve la velocidad en el vector X
def pwrToVelX(powerOrg, angleOrg):
    VelX = math.cos(angleOrg) * powerOrg

    return abs(round(VelX,2))
#Nos devuelve la velocidad en el vector Y
def pwrToVelY(powerOrg, angleOrg):
    VelY = math.sin(angleOrg) * powerOrg

    return abs(round(VelY,2))


#Objeto particula (Pos X (Aleatoria), Pos Y (redetermindada). Radio (Predeterminado), Color)
particula1 = particula(random.randint(565, 625), 440, radio, white)
particula2 = particula(random.randint(565, 625), 440, radio, white)
particula3 = particula(random.randint(565, 625), 440, radio, white)
#Variables para fisica
x = 0
y = 0
time = 0
power = 0
power2 = 0
power3 = 0
angle = 0 
angle2 = 0
angle3 = 0
shoot = False
#Ciclo para correr el juego 
run = True
while run:
    if shoot:
        #Dispara la primera particula
        if particula1.y < (hScreen + 1) - particula1.radius:
            #Determina la velocidad de la simulacion 
            time += velocidadDeSim
            po = particula.particulaPath(x, y, power, angle, time)
            particula1.x = po[0]
            particula1.y = po[1]
        #Dispara la segunda particula
        if particula2.y < (hScreen + 1) - particula2.radius:
            #Determina la velocidad de la simulacion 
            time += velocidadDeSim
            po2 = particula.particulaPath(x, y, power2, angle2, time)
            particula2.x = po2[0]
            particula2.y = po2[1]
        #Dispara la tercera particula
        if particula3.y < (hScreen + 1) - particula3.radius:
            #Determina la velocidad de la simulacion 
            time += velocidadDeSim
            po3 = particula.particulaPath(x, y, power3, angle3, time)
            particula3.x = po3[0]
            particula3.y = po3[1]

    #Coloca la posición de nuestras particulas dentro del volcan de forma aleatoria
    posicion = (random.randint(410,750), random.randint(0, 10))
    posicion2 = (random.randint(410,750), random.randint(0, 10))
    posicion3 = (random.randint(410,750), random.randint(0, 10))
    #Guarda las posiciones
    line = [(particula1.x, particula1.y), posicion]
    line2 = [(particula2.x, particula2.y), posicion2]
    line3 = [(particula3.x, particula3.y), posicion3]

    #Actualiza pantalla
    redrawWindow()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            if shoot == False:
                shoot = True
                x = particula1.x
                y = particula1.y
                #NO MODIFICAR
                time = 0
                #Determina que tan lejos viaja la pelota, mover a su discresión el divisor. 
                power = math.sqrt((line[1][1] - line [0][1])**2 + (line [1][0] - line [0][0])**2)/potenciaDeY
                angle = findAngle(posicion, particula1)
                power2 = math.sqrt((line2[1][1] - line2 [0][1])**2 + (line2 [1][0] - line2 [0][0])**2)/potenciaDeY
                angle2 = findAngle(posicion2, particula2)
                power3 = math.sqrt((line3[1][1] - line3 [0][1])**2 + (line3 [1][0] - line3 [0][0])**2)/potenciaDeY
                angle3 = findAngle(posicion3, particula3)
pygame.quit()
sys.exit()