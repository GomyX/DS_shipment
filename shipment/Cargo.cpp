#include "Cargo.h"
#include "Company.h"

int Cargo::ID = 1;

Cargo::Cargo() {

}

Cargo::Cargo(string TYP, int day, int hour, int ID, double DIST, double LT, double COST)
{
	this->setcargoID(ID);
	this->setcargoType(TYP);
	this->setcargoDistance(DIST);
	this->setcargoCost(COST);
	//this->setpreptime(day, hour);
	this->setcargoLoadTime(LT);
}

void Cargo::setcargoID(int id) {
	ID = id;
}

int Cargo::getcargoID() {
	return ID;
}

void Cargo::setcargoType(string typ) {
	TYP = typ;
}
string Cargo::getcargoType() {
	return TYP;
}
void Cargo::setcargoDistance(double dist) {
	DIST = dist;
}
double Cargo::getcargoDistance() {
	return DIST;
}
void Cargo::setcargoLoadTime(double lt) {
	LT = lt;
}
double Cargo::getcargoLoadTime() {
	return LT;
}

void Cargo::setcargoCost(double cost) {
	COST = cost;
}
double Cargo::getcargoCost() {
	return COST;
}

void Cargo::setpreptime(int day, int hour) {
	preptime.Day = day;
	preptime.Hour = hour;
}

int Cargo::getpreptimeday() {
	return preptime.Day;

}
int Cargo::getpreptimehour() {

	return preptime.Hour;
}