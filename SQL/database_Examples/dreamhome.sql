create database dreamhome;
USE dreamhome;
-- Eliminar base de datos : DROP DATABASE dreamhome;

create table Branch(
branchNo varchar(6),
street varchar(45),
city varchar(15), 
postcode varchar(10),
primary key(branchNo)
);

create table Staff(
staffNo varchar(6),
fName varchar(45),
lName varchar (45),
position varchar(20),
sex varchar(1),
DOB date,
salary double,
branchNo varchar(6),
primary key (staffNo),
constraint fk_branch_Staff1
foreign key(branchNo) references Branch(branchNo)  
);

create table PrivateOwner(
ownerNo varchar(6),
fName varchar(45),
lName varchar(45),
adress varchar(60),
tellNo varchar(45),
eMail varchar(45),
password varchar(45),
primary key (ownerNo)
);

create table PropertyForRent(
propertyNo varchar(6),
street varchar(45),
city varchar(15),
postCode varchar(10),
type varchar(15),
rooms int,
rent double,
ownerNo varchar(6),
staffNo varchar(6),
branchNo varchar(6),
primary key(PropertyNo),
constraint fk_privateOwner_propertyForRent1
foreign key(ownerNo) references privateOwner(ownerNo),
constraint fk_staff_propertyForRent1
foreign key(staffNo) references staff(staffNo),
constraint fk_branch_propertyForRent1
foreign key(branchNo) references branch(branchNo)
);

create table Client(
clientNo varchar(6),
fName varchar(45),
lName varchar(45),
tellNo varchar(45),
prefType varchar(15),
maxRent double,
eMail varchar(45),
primary key(clientNo)
);

create table Viewing(
clientNo varchar(6),
propertyNo varchar(6),
viewDate date,
comment varchar(60),
primary key(clientNo, propertyNo),
constraint fk_client_viewing1
foreign key(clientNo) references client(clientNo),
constraint fk_propertyForRent_viewing1
foreign key(propertyNo) references propertyForRent(propertyNo)
);

CREATE TABLE Registration(
clientNo VARCHAR(6), 
branchNo VARCHAR(6), 
staffNo VARCHAR(6),
dateJoined VARCHAR(20),
primary key(clientNo, branchNo, staffNo),
constraint fk_client_viewing1

);
