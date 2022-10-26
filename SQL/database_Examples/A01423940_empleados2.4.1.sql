
create database entrenamientoEmpleados;
use entrenamientoEmpleados;

create table employee(
eID int,
eLast varchar(10),
eFisrt varchar(10),
eTitle varchar(40),
eSalary int,
primary key (eID)
);

create table trainingCourse(
cID varchar(6),
cTitle varchar(40),
cHour int,
areaID varchar(3),
primary key(ciD)
);

create table takes(
eID int,
cID varchar(6),
tYear int,
tMonth int,
tDay int,
primary key (eID, cID),
constraint fk_employee_takes1
foreign key (eID) references employee(eID),
constraint fk_trainingCourse_takes1
foreign key (cID) references trainingCourse(cID)
);

create table technologyArea(
aID varchar(3),
aTitle varchar(40),
aURL varchar(50),
leadID int,
primary key (aID)
);