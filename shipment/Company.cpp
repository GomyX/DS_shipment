#include <fstream>
#include <iostream>
#include "Company.h"
//#include "Events.h"
#include "Cargo.h"
#include "Truck.h"
#include"UI.h"

using namespace std;


Company::Company()
{
	UI* Ui=new UI();
	this->LoadingInFile();
	now.Day = 0;
	now.Hour = 0;
	//this->LoadingInFile();
	this->countAutoPromote = 0;
}

void Company::incrementNow()
{
	if (now.Hour < 24)
		this->now.Hour += 1;
	else
	{
		this->now.Day += 1;
	}
}

int Company::calcTotHours()
{
	return now.Day * 24 + now.Hour;
}

void Company::simulation()
{	
	this->incrementNow();
	while (checkOnHours()) {

		this->runEvent();
		this->LoadvipCargos();
		this->LoadspecialCargos();
		this->LoadnormalCargos();


	}
	//contnue delviery and maitenace

}

void Company::LoadvipCargos() {
	if (this->EmptyVIPTruck.GetCount() != 0) {
		LoadVCargos();
	}
	if (this->EmptyVIPTruck.GetCount() == 0) {
		if (this->EmptyNormalTruck.GetCount() != 0) {
			LoadNCargos();
		}

		if (this->EmptyNormalTruck.GetCount() == 0) {
			if (this->EmptySpecialTruck.GetCount() != 0) {
				LoadSCargos();
			}
			if (this->EmptySpecialTruck.GetCount() == 0) {
				exit;
			}
		}
	}



}

void Company::LoadspecialCargos()
{
	if (this->EmptySpecialTruck.GetCount() != 0) {
		LoadSCargos();
	}
	if (this->EmptySpecialTruck.GetCount() == 0) {
		exit;
	}
}

void Company::LoadnormalCargos()
{
	if (EmptyNormalTruck.GetCount() != 0) {
		this->LoadNCargos();
	}
	if (EmptyNormalTruck.GetCount() == 0) {
		if (EmptyVIPTruck.GetCount() != 0) {
			this->LoadVCargos();
		}
		if (EmptyVIPTruck.GetCount() == 0) {
			exit;
		}
	}
}

void Company::LoadVCargos() {


		Truck* vipT=nullptr;
		
		this->EmptyVIPTruck.peek(vipT);
		this->AssignLoadingVIPTruck(vipT);   
		if (vipT->getTruck_Capacity() != 0&&this->checkloadvip()/*checkavailtruck()*/) {
			if (vipT != nullptr) {
				Cargo* c = new Cargo();
				this->WaitingVipCargo.dequeue(c);
				vipT->AssignCargo(c);

				delete c;
				delete vipT;
			}
		}
	
}

void Company::LoadSCargos() {
	

		Truck* T = nullptr;

		this->EmptySpecialTruck.peek(T);
		this->AssignLoadingSpecialTruck(T);
		if (T->getTruck_Capacity() != 0 && this->checkloadspecial()/*checkavailtruck()*/) {
			if (T != nullptr) {
				Cargo* c = nullptr;
				this->WaitingSpecialCargo.dequeue(c);
				T->AssignCargo(c);

				delete c;
				delete T;
			}
		}
	
}

void Company::LoadNCargos()
{
		Truck* T = nullptr;

		this->EmptyNormalTruck.peek(T);
		this->AssignLoadingNormalTruck(T);
		if (T->getTruck_Capacity() != 0 && this->checkloadnormal()/*checkavailtruck()*/) {
			if (T != nullptr) {
				Cargo* c = new Cargo();
				this->WaitingNormalCargo;/*->search();*/
				T->AssignCargo(c);

				delete c;
				delete T;
			}
		}
}

//void Company::maxW()
//{
//	if (calcTotHours() = MaxW);
//
//}


void Company::runEvent()
{
	Event* E = nullptr;
	this->EventList.peek(E);
	if (E != nullptr) {
		if (E->geteventTimehour() == now.Hour && E->geteventTimeday() == now.Day) {
			E->execute();
			EventList.dequeue(E);
			delete E;
		}
	}
}

bool Company::checkOnHours()
{
	if (now.Hour >= 6 || now.Hour <= 23)
		return true;
	else
		return false;
}




void Company::LoadingInFile()
{
	ifstream file;
	file.open("ayyad.txt");
	int N, S, V; //go back to project document to know the shortcuts
	file >> N >> S >> V; //reading the number of trucks 
	int NS, SS, VS;
	file >> NS >> SS >> VS; //reading the speed of the trucks
	int NTC, STC, VTC;
	file >> NTC >> STC >> VTC; // reading the capicty of the trucks hhtsgl 
	int J;
	int CN, CS, CV;
	file >> J >> CN >> CS >> CV; //reading no. of journeys and checkup durations

	int AutoP, MaxW;
	file >> AutoP >> MaxW; //reading the promotion time and the maximum wait time
	setMaxW(MaxW);
	setAutoP(AutoP);
	

	for (int i = 0; i < N; i++) {
		Truck* pTruck = new Truck("Normal",CN ,NTC,NS,J);
		AddENT(pTruck);
	}

	for (int i = 0; i < S; i++) {
		Truck* pTruck = new Truck("Special",CS, STC,  SS, J);
		AddEST(pTruck);
	}

	for (int i = 0; i < V; i++) {
		Truck* pTruck = new Truck("VIP", CV,VTC, VS, J);
		AddEVT(pTruck);
	}

	int E;
	file >> E; //reading number of events
	//setnumEvents(E);
	string Status, TYP;
	cTime x;
	int ID, DIST, LT;
	double COST, extramoney;
	char drop_it;

	for (int i = 0; i < E; i++) {
		file >> Status;

		if (Status == "R") {
			file >> TYP >> x.Day >> drop_it >> x.Hour >> ID >> DIST >> LT >> COST;
			//setMaxDay(x.Day);
			//setMaxHour(x.Hour);
			//calculatePriorty();
			/*Cargo* m = new Cargo(TYP, x, ID, DIST, LT, COST);
			cout << m->calculatePriorty() << endl;
			AddWVC(m);*/

			preparationEvent* PpreparationEvent= new preparationEvent(TYP,x,ID,DIST,LT,COST,this);
			EventList.enqueue(PpreparationEvent);
			PpreparationEvent->execute();

		}
		if (Status == "X") {
			file >> x.Day >> drop_it >> x.Hour >> ID;
			//setMaxDay(x.Day);
			//setMaxHour(x.Hour);
			cancelEvent* PcancelEvent = new cancelEvent(ID , x,this);
			EventList.enqueue(PcancelEvent);
			PcancelEvent->execute();

		}
		if (Status == "P") {
			file >> x.Day >> drop_it >> x.Hour >> ID >> extramoney;
			//setMaxDay(x.Day);
			//setMaxHour(x.Hour);
			promoteEvent* PpromoteEvent = new promoteEvent(ID,  extramoney,this);
			EventList.enqueue(PpromoteEvent);
			PpromoteEvent->execute();
		}
	}
}


void Company::SavingOutfile()
{
	ofstream file;
	file.open("ayyad2.txt");
	file << "CDT" << "\t" << "CID" << "\t" << "PT" << "\t" << "WT" << "\t" << "TID";

	Cargo* c = nullptr;
	file << "---------------------------------";
	for (int i = 0; i < DeliveredCargos.GetCount(); i++) {
		DeliveredCargos.dequeue(c);

	   file << c->getdeliverytime().Day << ":" << c->getdeliverytime().Hour << "\t"
			<< c->getcargoID() << "\t"
			<< c->getpreptime().Day << ":" << c->getpreptime().Day << "\t"
			<< c->getwaitingtime().Day << ":" << c->getwaitingtime().Hour << "\t"
			<< c->getTruckID();
	}

	file << "---------------------------------";
	file << "---------------------------------";
	
	file <<"Cargos: " <<Cargo::getTotalNumCargos 
		 << "[N: " << Cargo::getTotalNum_normal_Cargos()
		 << ",S: " << Cargo::getTotalNum_special_Cargos()
		 << ", V: " << Cargo::getTotalNum_VIP_Cargos()<<"]";



	file << "cargos Avg Wait = " 
		 << get_Cargo_Average_Wait().Day <<":"
		 << get_Cargo_Average_Wait().Hour;

	file << "Auto-promoted Cargos:";
	file << "Trucks: ";
	file << "Avg Active time =";
	file << "Avg utilization";

}


double Company::calculateInterval() {
	/*double interval;
	Node<Cargo*>* ptr = WaitingNormalCargo->getHead();
	while (ptr) {
		Cargo* pCargo = ptr->getItem();
		interval = (this->now.Day) - pCargo->getpreptime().Day;
	}
	return interval;*/
	return 0.0;
}

void Company::AutoPromotion()
{
	/*Node<Cargo*>* ptr = WaitingNormalCargo->getHead();
	while (ptr) {
		Cargo* pCargo = ptr->getItem();
		double interval = calculateInterval();
		if (interval >= this->getAutoP()) {
			WaitingNormalCargo->DeleteNode(pCargo);
			WaitingVipCargo.insert(pCargo, pCargo->calculatePriorty());
		}
		ptr = ptr->getNext();
		countAutoPromote += 1;
	}*/
}

/////////////////////////////////////////////////////////////////////////


void Company::AssignLoadingVIPTruck(Truck* name)
{
	this->loadingvip = name;
}

void Company::AssignLoadingNormalTruck(Truck* name) {
	this->loadingnormal = name;
}

void Company::AssignLoadingSpecialTruck(Truck* name) {
	this->loadingspecial = name;
}

/////////////////////////////////////////////////////////////////////////

bool Company::checkloadvip()
{
	if (this->loadingvip != nullptr)
		return true;
	else
		return false;
}

bool Company::checkloadspecial()
{
	if (this->loadingspecial != nullptr)
		return true;
	else
		return false;
}
bool Company::checkloadnormal()
{
	if (this->loadingnormal != nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////

int Company::getMaxW()
{
	return this->MaxW;
}

void Company::setMaxW(int max) {
	this->MaxW = max;
}

int Company::getAutoP()
{
	return this->AutoP;
}

void Company::setAutoP(int hour) {
	this->AutoP = hour;
}

//int Company::getAutoP()
//{
//	return AutoP;
//}
//int Company::getMaxW()
//{
//	return MaxW;
//}
//int Company::getN()
//{
//	return 0;
//}
//int Company::getS()
//{
//	return 0;
//}
//int Company::getV()
//{
//	return 0;
//}
//int Company::getNTC()
//{
//	return 0;
//}
//int Company::getSTC()
//{
//	return 0;
//}
//int Company::getVTC()
//{
//	return 0;
//}
//void Company::setAutoP(int number)
//{
//}
//void Company::setMaxW(int number)
//{
//}
//void Company::simulation()
//{
//	int day, hour;
//
//	for (int i = 0; i <(getMaxDay()*24 +getMaxHour() ); i++) {
//		hour++;
//		if (hour == 24) { day++; hour = 1; }
//		promoteEvent* ne = nullptr;
//		//promEventsList.dequeue(ne);
//		if (ne->geteventTimeday() == day && ne->geteventTimehour() == hour) {
//			ne->execute();
//		}
//		else {
//			promEventsList.enqueue(ne);
//		}
//
//		preparationEvent* e = nullptr;
//		//prepEventsList.dequeue(e);
//		if (e->geteventTimeday() == day && e->geteventTimehour() == hour) {
//			e->execute();
//		}
//		else {
//			prepEventsList.enqueue(e);
//		}
//
//
//		cancelEvent* x = nullptr;
//		cancEventsList.dequeue(x);
//		if (x->geteventTimeday() == day && x->geteventTimehour() == hour) {
//			x->execute();
//		}
//		else {
//			cancEventsList.enqueue(x);
//		}
//		setTime(day, hour);
//	}
//
//
//}
////////////////////////////////////////////////////////////////////////
////////////////////////Adding waiting cargo list
//
//void Company::setMaxDay(int d)
//{
//	if (d > maxDay) {
//		maxDay=d;
//	}
//}
//
//int Company::getMaxDay( )
//{
//
//	return maxDay;
//}
//
//void Company::setMaxHour(int d)
//{
//	if (maxHour < d)maxHour=d;
//
//}
//
//int Company::getMaxHour()
//{
//	return maxHour;
//}
//
//
//void Company::setnumEvents(int g)
//{
//	numEvents = g;
//}
//
//int Company::getnumEvents()
//{
//	return numEvents;
//}
//
//int Company::getTime()
//{
//	return t.Day, t.Hour;
//}
//
//void Company::setTime(int s, int d)
//{
//	t.Day = s; t.Hour = d;
//}
//
//bool Company::isWorking()
//{
//	int d, h = getTime();
//	if (h > 5 && h < 23) { return true; }
//}
//
//void Company::assigning()
//{
//	if (this->isWorking()) {
//		if (this->getV()>this->getVTC()) {
//			Truck t;
//			for (int i = 0; i < getVTC(); i++) {
//				t.getCargos(i);
//			}
//		}
//	}
//}
//
//Node<Cargo*> Company::getHeadWNC()
//{
//	return WaitingNormalCargo.getHead();
//}
//
void Company::AddWNC(Cargo* name)
{
	if (name != nullptr)
		WaitingNormalCargo.InsertBeg(name);
}
void Company::AddWSC(Cargo* name)
{
	WaitingSpecialCargo.enqueue(name);
}

void Company::AddWVC(Cargo* name )
{
	WaitingVipCargo.insert(name , name->calculatePriorty());
}

//////////////////////////////////////////////////////////////////////
////////////////////////Adding delivered cargo list
void Company::AddCTD(Cargo* name)
{
	DeliveredCargos.enqueue(name);
}


//////////////////////////////////////////////////////////////////////
//////////////////////Adding maintance truck list
void Company::AddMNT(Truck* name)
{
	if (name)
		MaintNormalTruck.enqueue(name);
}
void Company::AddMST(Truck* name)
{
	if (name)
		MaintSpecialTruck.enqueue(name);
}
void Company::AddMVT(Truck* name)
{
}

/// ////////////////////////////////////////////////////////////////
/// 


//////////////////////////////////////////////////////////////////////
//////////////////////Adding Empty truck list
void Company::AddENT(Truck* name)
{
	if (name)
		EmptyNormalTruck.enqueue(name);
}
void Company::AddEST(Truck* name)
{
	if (name)
		EmptySpecialTruck.enqueue(name);
}
void Company::AddEVT(Truck* name)
{
	if (name)
		EmptyVIPTruck.enqueue(name);
	
}
////////////////////////////////////////////////////////
int Company::calculatehours(cTime time)
{
	return time.Day * 24 + time.Hour;
}


cTime Company::get_Cargo_Average_Wait() {
	int h = 0;
	Cargo* c = nullptr;
	for (int i = 0; i < DeliveredCargos.GetCount(); i++) {
		DeliveredCargos.dequeue(c);

		h = h + calculatehours(c->getwaitingtime());
		
	}
	h =  h / DeliveredCargos.GetCount();
	cargoaveragewait.Day = h / 24;
	cargoaveragewait.Hour = h % 24;
	return cargoaveragewait;
}




void Company::DeleteNCargoByID(int id)
{
	/*Node<Cargo*>* ptr;
	ptr = WaitingNormalCargo->getHead();
	while (ptr) {
		if (ptr->getItem()->getcargoID() == id) {
			WaitingNormalCargo->DeleteNode(ptr);
		}
		else {
			ptr = ptr->getNext();
		}
	}*/
}


void Company::prompoteCargo(int id, double amount)
{
	/*Node<Cargo*>* ptr =WaitingNormalCargo->getHead();
	while (ptr) {
		if (ptr->getItem()->getcargoID() == id) {
			ptr->getItem()->setcargoType("V");
			ptr->getItem()->setExtramoney(amount);
			WaitingNormalCargo->DeleteNode(ptr);
			WaitingVipCargo.insert(ptr->getItem(), ptr->getItem()->calculatePriorty());
		}
		else
			ptr->getNext();
	}*/
}