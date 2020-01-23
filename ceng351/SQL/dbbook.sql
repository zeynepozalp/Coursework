--
-- 	Database Table Creation
--
--		This file will create the tables for use with the book 
--  Database Management Systems by Raghu Ramakrishnan and Johannes Gehrke.
--  It is run automatically by the installation script.
--
--	Version 0.1.0.0 2002/04/05 by: David Warden.
--	Copyright (C) 2002 McGraw-Hill Companies Inc. All Rights Reserved.
--
--  First drop any existing tables. Any errors are ignored.
--
drop table student cascade constraints;
drop table faculty cascade constraints;
drop table class cascade constraints;
drop table enrolled cascade constraints;
drop table emp cascade constraints;
drop table works cascade constraints;
drop table dept cascade constraints;
drop table flights cascade constraints;
drop table aircraft cascade constraints;
drop table certified cascade constraints;
drop table employees cascade constraints;
drop table suppliers cascade constraints;
drop table parts cascade constraints;
drop table catalog cascade constraints;
drop table sailors cascade constraints;
--
-- Now, add each table.
--
create table student(
	snum number(9,0) primary key,
	sname varchar2(30),
	major varchar2(25),
	standing varchar2(2),
	age number(3,0)
	);
create table faculty(
	fid number(9,0) primary key,
	fname varchar2(30),
	deptid number(2,0)
	);
create table class(
	name varchar2(40) primary key,
	meets_at varchar2(20),
	room varchar2(10),
	fid number(9,0),
	foreign key(fid) references faculty
	);
create table enrolled(
	snum number(9,0),
	cname varchar2(40),
	primary key(snum,cname),
	foreign key(snum) references student,
	foreign key(cname) references class(name)
	);
create table emp(
	eid number(9,0) primary key,
	ename varchar2(30),
	age number(3,0),
	salary number(10,2)
	);
create table dept(
	did number(2,0) primary key,
	dname varchar2(20),
	budget number(10,2),
	managerid number(9,0),
	foreign key(managerid) references emp(eid)
	);
create table works(
	eid number(9,0),
	did number(2,0),
	pct_time number(3,0),
	primary key(eid,did),
	foreign key(eid) references emp,
	foreign key(did) references dept
	);
create table flights(
	flno number(4,0) primary key,
	origin varchar2(20),
	destination varchar2(20),
	distance number(6,0),
	departs date,
	arrives date,
	price number(7,2)
	);
create table aircraft(
	aid number(9,0) primary key,
	aname varchar2(30),
	crusingrange number(6,0)
	);
create table employees(
	eid number(9,0) primary key,
	ename varchar2(30),
	salary number(10,2)
	);
create table certified(
	eid number(9,0),
	aid number(9,0),
	primary key(eid,aid),
	foreign key(eid) references employees,
	foreign key(aid) references aircraft
	);
create table suppliers(
	sid number(9,0) primary key,
	sname varchar2(30),
	address varchar2(40)
	);
create table parts(
	pid number(9,0) primary key,
	pname varchar2(40),
	color varchar2(15)
	);
create table catalog(
	sid number(9,0),
	pid number(9,0),
	cost number(10,2),
	primary key(sid,pid),
	foreign key(sid) references suppliers,
	foreign key(pid) references parts
	);
create table sailors(
	sid number(9,0) primary key,
	sname varchar2(30),
	rating number(2,0),
	age number(4,1)
	);
--
-- Exit the Script.
--
quit;
