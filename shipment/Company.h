#pragma once
#include <fstream>
#include <iostream>
#include "Truck.h"
#include "Cargo.h"
#include "ds/stack/ArrayStack.h"
//#include "UI.h"
#include "ds/stack/StackADT.h"
#include "Events.h"
#include "ds/queue/LinkedQueue.h"
#include "ds/linked list/LinkedList.h"
#include "ds/Pri Q/priQ.h"


using namespace std;


class Company
{
private:

	int maxDay;
	int maxHour;
	int numEvents;
	int waitingCargoTime;
	cTime now;
	//int totalnumofcargos;

	/// <summary>
	/// To check if any another truck is loading or not
	/// </summary>

	int countAutoPromote;

	cTime  cargoaveragewait;

	int AutoP, MaxW, N, S, V, NTC, STC, VTC ,J;
	//maint_time check_up;

protected:

	
	Truck* loadingvip = nullptr;
	Truck* loadingspecial = nullptr;
	Truck* loadingnormal = nullptr;

	
	LinkedQueue<Event*> EventList;

	//waiting cargos vip priQueue
	priQ <Cargo*> WaitingVipCargo;
	LinkedList <Cargo*> WaitingNormalCargo;
	LinkedQueue <Cargo*> WaitingSpecialCargo;

	
	LinkedQueue <Cargo*> DeliveredCargos;
	
	LinkedQueue <Truck*> EmptyNormalTruck;
	LinkedQueue <Truck*> EmptySpecialTruck;
	LinkedQueue <Truck*> EmptyVIPTruck;

	//moving trucks priQueue
	priQ <Truck*> MovingTrucks;

	LinkedQueue <Truck*> MaintNormalTruck;
	LinkedQueue <Truck*> MaintSpecialTruck;
	LinkedQueue <Truck*> MaintVIPTruck;

public:
	
	Company();
	void incrementNow();
	int calcTotHours();

	void simulation();
	void runEvent();
	bool checkOnHours();


	void LoadvipCargos();
	void LoadspecialCargos();
	void LoadnormalCargos();

	void LoadVCargos();
	void LoadSCargos();
	void LoadNCargos();

	void maxW();
	/*
	-at start ,it loads the available trucks form the file
	-and make a list of cargos based on the TC of each type
	-to check if a truck is available	(maintenence or delivary)
	-if the company is during its working hours ,then do the coming #maintenece and delivary duting the off-hours
	*make a num of available cargos in the cargo calss
	-max of loading trucks is 3 ,one for each type
	--maxW->non-vip cargos only
	-assignment order ->vip ->special-> normal
	-vip assignment order -> (delv_dest*cost)/prep_time   <---priQ equ
	-cargo promotion or cancelation 
	-auto promotion of normal cargos


*/
	
	//void setMaxDay(int d);
	//int getMaxDay();

	//void setMaxHour(int d);
	//int getMaxHour();

	//void setnumEvents(int g);
	//int getnumEvents();
	//
	//int getTime();
	//void setTime(int s, int d);

	//bool isWorking();
	// 
	//void assigning();

	////Node<Cargo*> getHeadWNC();
	////LinkedList <Cargo*>getWaitingNormalList();


	int getMaxW();
	void setMaxW(int max);

	int getAutoP();
	void setAutoP(int hour);

	void AddWNC(Cargo* name); //adding to waiting normal waiting list
	void AddWSC(Cargo* name); //adding to waiting special waiting list
	void AddWVC(Cargo* name); //adding to waiting vip cargo list
	//adding to waiting VIP waiting list priQueue

	
	void AddCTD(Cargo* name); //adding to Deliverd cargos list
	

	void AddENT(Truck* name); //adding to Empty normal truck
	void AddEST(Truck* name); //adding to Empty Special truck
	void AddEVT(Truck* name); //adding to Empty VIP truck

	//adding to moving trucks list priQueue

	void AddMNT(Truck* name); //adding to Maintance normal truck
	void AddMST(Truck* name); //adding to Maintance Special truck
	void AddMVT(Truck* name); //adding to Maintance VIP truck
	

	void AssignLoadingVIPTruck(Truck* name);
	void AssignLoadingNormalTruck(Truck* name);
	void AssignLoadingSpecialTruck(Truck* name);

	bool checkloadvip();
	bool checkloadnormal();
	bool checkloadspecial();

	void LoadingInFile();
	void SavingOutfile();

	void AutoPromotion();
	double calculateInterval();


	void DeleteNCargoByID(int id);
	void prompoteCargo(int id, double amount);

	//int getAutoP();
	//int getMaxW();	
	//int getN();
	//int getS();
	//int getV();
	//int getNTC();
	//int getSTC();
	//int getVTC();


	//void setAutoP(int number) {
	//	this->AutoP = number;
	//}
	//void setMaxW(int number) {
	//	this->MaxW = number;
	//}

	//void simulation();

	//int CalculateTotalNoOfcCargos();

	cTime get_Cargo_Average_Wait();
	int calculatehours(cTime time);
	void moveAtruck();
	void deliver_cargos();
};


