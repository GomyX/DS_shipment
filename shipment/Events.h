#pragma once
#include <iostream>
#include "Cargo.h"


using namespace std;
//a struct for time
//struct Time {
//	int Day;
//	int Hour;
//};

class Company;

class Event {
protected:

	string TYP;
	double DIST;
	int LT;
	double COST;
	cTime ET; //event time
	int ID;	//cargo id 

	Company* pComp;
public:
	Event(){}
	Event(Company *p) {
		pComp = p;
	}
	void seteventTime(int , int);
	int geteventTimeday();
	int geteventTimehour();
	string gettype();
	int getid();

	virtual void execute() = 0;

};

class preparationEvent : public Event
{
protected:
	
public:
	
	preparationEvent();
	preparationEvent(string type, cTime et, int id, double distance, int loadtime, double cost, Company* p);
	void execute()override;
};

class cancelEvent : public Event
	// cargo must be a normal cargo
{
public:

	cancelEvent(int id,cTime time, Company* p);
	void execute()override;


};

class promoteEvent : public Event
	// cargo must be a normal cargo
{
protected:
	double Extramoney;
public:
	promoteEvent();
	promoteEvent(int id, double extra, Company* p);
	void execute()override;

};