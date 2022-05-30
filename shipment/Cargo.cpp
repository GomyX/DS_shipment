#include "Cargo.h"
#include "Company.h"

int Cargo::ID = 1;

Cargo::Cargo() {

}

Cargo::Cargo(string TYP, cTime time, int ID, double DIST, double LT, double COST)
{
	this->setcargoID(ID);
	this->setcargoType(TYP);
	this->setcargoDistance(DIST);
	this->setcargoCost(COST);
	this->setpreptime(time);
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

void Cargo::setpreptime(cTime time) {
	preptime.Day = time.Day;
	preptime.Hour = time.Hour;
}

cTime Cargo::getpreptime() {
	return preptime;

}



double Cargo::calculatePriorty()
{
	return this->getcargoCost() * this->getcargoDistance() / calculatehours(this->getpreptime());
}

int Cargo::calculatehours(cTime time)
{
	return time.Day * 24 + time.Hour;
}





cTime Cargo::getwaitingtime()
{
	return waitingtime;
}
void Cargo::setwaitingtime(cTime Movetime)
{
	int x = calculatehours(Movetime) - calculatehours(preptime);
	waitingtime.Day = x / 24;
	waitingtime.Hour = x & 24;
}

void Cargo::setTruckID(int id) {
	TruckID = id;
}
int Cargo::getTruckID() {
	return TruckID;
}

//
//void Cargo::setPTruck(Truck* t) {
//	PTruck = t;
//}
//Truck* Cargo::getPTruck() {
//
//	return PTruck;
//}



cTime Cargo::getdeliverytime()
{
	return deliverytime;
}
void Cargo::setdeliverytime(cTime Movetime, int speed)
{
	int x = calculatehours(Movetime) + getcargoDistance() / (speed)+getcargoLoadTime();

}

