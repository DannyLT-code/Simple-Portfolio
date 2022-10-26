-- BASE DE DATOS: EQUIPOS 
CREATE DATABASE equipos;
USE equipos;
-- Tablas 
CREATE TABLE equipo(
	idEquipo INT(5),
    numeroJugadores INT(5),
    nombre VARCHAR(50),
    PRIMARY KEY (idEquipo)
);

CREATE TABLE jugador(
	idJugador INT(6),
    idEquipo INT(5),
    nombre VARCHAR(50),
    PRIMARY KEY(idJugador, idEquipo),
	CONSTRAINT fk_equipo_display1
		FOREIGN KEY(idEquipo) REFERENCES equipo(idEquipo)
);

CREATE TABLE logro(
	idLogro INT(5),
    idEquipo INT (5),
    nombre VARCHAR(50),
    PRIMARY KEY(idLogro),
    CONSTRAINT fk_equipo_display1
		FOREIGN KEY(idEquipo) REFERENCES equipo(idEquipo)
);

CREATE TABLE partido(
	idPartido INT (5),
	idVisitante INT(5),
    idLocal INT(5),
    golLocal INT(5),
    golVisitante INT(5),
    PRIMARY KEY(idPartido),
    CONSTRAINT fk_equipo_display1
		FOREIGN KEY(idLocal) REFERENCES equipo(idEquipo),
    CONSTRAINT fk_equipo_display1
		FOREIGN KEY(idVisitante) REFERENCES equipo(idEquipo)
);

CREATE TABLE estadistica(
	idJugador INT(5),
    idPartido INT(5),
    goles VARCHAR(50),
    asistencias VARCHAR(50), 
    amarillas VARCHAR(50),
    expulsado VARCHAR(50),
    PRIMARY KEY(idJugador),
    CONSTRAINT fk_partido_display1
		FOREIGN KEY(idPartido) REFERENCES partido(idPartido)
);

