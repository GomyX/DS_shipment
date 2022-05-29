#pragma once
#include <iostream>
using namespace std;
//a struct for time
//struct Time {
//	int Day;
//	int Hour;
//};

class Event {
protected:
	string TYP;
	double DIST;
	int LT;
	double COST;
	cTime ET; //event time
	int ID;	//cargo id 
public:
	
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
	preparationEvent(string type, cTime et, int id, double distance, int loadtime, double cost);
	void execute()override;
};

class cancelEvent : public Event
	// cargo must be a normal cargo
{
public:
	cancelEvent(int ID, cTime et);
	void execute()override;

};

class promoteEvent : public Event
	// cargo must be a normal cargo
{
protected:
	double Extramoney;
public:
	promoteEvent();
	promoteEvent(int ID, cTime et, double extra);

	void execute()override;

};