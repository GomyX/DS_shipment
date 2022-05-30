#include "Cargo.h"
#include "Events.h"
#include "Company.h"
#include "ds/linked list/LinkedList.h"
#include "ds/linked list/Node.h"


preparationEvent::preparationEvent()
{
}


preparationEvent::preparationEvent(string type, cTime et, int id, double distance, int loadtime, double cost)
{
	TYP = type;
	ID = id;
	DIST = distance;
	LT = loadtime;
	COST = cost;
	ET = et;
}

Cargo* preparationEvent::execute() {
	
	Cargo* c = new Cargo(TYP, ET, ID, DIST, LT, COST);
	//pComp->AddWNC(c);
	return c;
}



<<<<<<< Updated upstream
cancelEvent::cancelEvent(int id, cTime et) {
	ET = et;  
	ID = id;  
=======
cancelEvent::cancelEvent(int id,cTime time ,Company* p):Event(p) {
	this->ID = id;
	this->ET = time;
>>>>>>> Stashed changes
}
Cargo* cancelEvent::execute()
{
<<<<<<< Updated upstream
	return nullptr;
=======
	pComp->DeleteNCargoByID(this->ID);
>>>>>>> Stashed changes
}
;

//template <typename T>
//Cargo* cancelEvent::execute() {
//	//pCompany->getHeadWNC()
//	Node<Cargo*> ptr = pCompany->getHeadWNC();
//	LinkedList <Cargo*> ptr2 = pCompany->getWaitingNormalList();
//	for (int i = 0; i < ptr2.getItemcount(); i++) {
//		if ((ptr.getItem())->getcargoID() == ID) {
//	//		ptr2.deleteNode(ptr);
//		}
//
//	//	ptr = ptr->getNext();
//	}
//}



promoteEvent::promoteEvent()
{
}

<<<<<<< Updated upstream
promoteEvent::promoteEvent(int id, cTime et, double extramoney) {
	ID = id;
	ET = et;
	Extramoney = extramoney;
=======
promoteEvent::promoteEvent(int id, double extra, Company* p): Event(p) {
	this->ID = id;
	Extramoney = extra;
>>>>>>> Stashed changes
}
Cargo* promoteEvent::execute()
{
<<<<<<< Updated upstream
	return nullptr;
=======
	pComp->prompoteCargo(this->ID, this->Extramoney);
>>>>>>> Stashed changes
}
;

//Cargo* promoteEvent::execute() {
//	//Node<Cargo>* head= pCompany->getHeadWNC();
//	Node<Cargo*> ptr = pCompany->getHeadWNC();
//	LinkedList <Cargo*> ptr2 = pCompany->getWaitingNormalList();
//
//	for (int i = 0; i < ptr2.getItemcount(); i++) {
//		if ((ptr.getItem())->getcargoID() == ID) {
//		//	Node <Cargo>* newptr = ptr;
//		//	WaitingVipCargo.enqueu(newptr);
//		//	ptr->deletenode();
//		}
//	}
//}



void Event::seteventTime(int d, int h)
{
	ET.Day = d;
	ET.Hour = h;
}

int Event::geteventTimeday()
{
	return ET.Day;
}

int Event::geteventTimehour()
{
	return ET.Hour;
}

string Event::gettype()
{
	return TYP;
}

int Event::getid()
{
	return ID;
}
