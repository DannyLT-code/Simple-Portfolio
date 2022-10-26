-- BASE DE DATOS: PÁGINAS WEB
CREATE DATABASE paginasweb;
USE paginasweb;
-- Crear tablas 
CREATE TABLE webpage(
	webID INT(5),
    webTitle VARCHAR(50),
    url VARCHAR(50),
    base INT(5),
    hits INT(3),
    PRIMARY KEY(webID)
);

CREATE TABLE graphic(
	gID INT(5),
    gName VARCHAR(50),
    gType VARCHAR(5),
    gLocation VARCHAR(50),
    PRIMARY KEY(gID)
);

CREATE TABLE courseware(
	cID VARCHAR(10),
    cDescription VARCHAR(50),
    ftpLocation VARCHAR(60),
    category VARCHAR(1),
    PRIMARY KEY(cID)
);

CREATE TABLE display(
	webID INT(5),
    gID INT(5),
    PRIMARY KEY(webID, gID),
    CONSTRAINT fk_webpage_display1
		FOREIGN KEY(webID) REFERENCES webpage(webID),
	CONSTRAINT fk_graphic_display1
		FOREIGN KEY (gID) REFERENCES graphic(gID)
);

CREATE TABLE sourceWebID(
	sourceWebID INT(5),
    targetWebID INT(5),
    PRIMARY KEY(sourceWebID, targetWebID)
);

CREATE TABLE ftpLink(
	webID INT(5),
    cID VARCHAR(10),
    PRIMARY KEY(webID, cID),
    CONSTRAINT fk_webpage_ftpLink1
		FOREIGN KEY(webID) REFERENCES webpage(webID),
	CONSTRAINT fk_courseware_ftpLink1
		FOREIGN KEY (cID) REFERENCES courseware(cID)
);