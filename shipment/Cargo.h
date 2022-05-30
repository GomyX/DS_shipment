#pragma once
#include <iostream>
//#include"Company.h"
using namespace std;


struct cTime {
	int Day;
	int Hour;
};


class Cargo {
private:
	cTime preptime;
	string TYP;
	double DIST; // cargo distance in KM
	double LT;   // time to load or unload a cargo in hours
	double COST;
	double extramoney;

protected:
	static int ID;
	int TruckID;
	cTime waitingtime;
	cTime deliverytime;
public:
	Cargo();
	Cargo(string TYP, cTime time, int ID, double DIST, double LT, double COST);


	void setcargoID(int);
	int getcargoID();
	void setcargoType(string);
	string getcargoType();
	void setcargoDistance(double);
	double getcargoDistance();
	void setcargoLoadTime(double);
	double getcargoLoadTime();
	void setcargoCost(double);
	double getcargoCost();
	void setpreptime(cTime);
	cTime getpreptime();
	double calculatePriorty();
	int calculatehours(cTime time);

	double getExtramoney();

	void setExtramoney(double amount);
	

	void setwaitingtime(cTime Movetime);
	cTime getwaitingtime();
	void setTruckID(int id);
	int getTruckID();
	/*void setPTruck(Truck *t);
	Truck* getPTruck();*/
	void setdeliverytime(cTime Movetime, int speed);
	cTime getdeliverytime();


};