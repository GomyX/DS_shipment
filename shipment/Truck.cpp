#include "Truck.h"

int Truck::total_number_of_normaltrucks = 0;
int Truck::total_number_of_specialtrucks = 0;
int Truck::total_number_of_VIPtrucks = 0;

int Truck::total_number_of_trucks = 0;



Truck::Truck()
{
}

Truck::Truck(string TYP,int maint_time, int CPT, int speed, int J)
{
    this->setTruck_TYP(TYP);
    this->setTruck_Capacity(CPT);
    this->setMaint_time(maint_time);  //supporsed to be taken from the file 
    this->setSpeed(speed);
    this->J = J;
   // Cargo c[getTruck_Capacity()];
    total_number_of_trucks++;
    if (TYP == "N") { total_number_of_normaltrucks++; }
    if (TYP == "S") { total_number_of_specialtrucks++; }
    if (TYP == "V") { total_number_of_VIPtrucks++; }
}

void Truck::setTruck_TYP(string t)
{
    TYP = t;
}

string Truck::getTruck_TYP() const
{
    return TYP;
}

void Truck::setTruck_Capacity(int t)
{
    TruckCapacity = t;
}

int Truck::getTruck_Capacity() const
{
    return TruckCapacity;
}

void Truck::setMaint_time(int n)
{
    maint_time = n;

}

int Truck::getMaint_time() const
{
    return maint_time;
}

//void Truck::setDeliv_int()
//{
//    if (this->getTruck_Capacity() == 0) { this->deliv_int = 0; }
//    else {
//        deliv_int = 2 * (this->farthest_dest() / speed) + sum_load();
//    }
//}

int Truck::getDeliv_int() const
{
    return deliv_int;
}

void Truck::AssignCargo(Cargo* name)
{
    if (CargoList->GetCount() < this->getTruck_Capacity()) {
        CargoList->insert(name, name->calculatePriorty());
    }
    else
        cout << "Truck is fully loaded";
}

//int Truck::farthest_dest()
//{
//    if (this->getTruck_Capacity() == 0) { return -1; }
//    int x = c[0].getcargoDistance();
//    for (int i = 0; i < this->getTruck_Capacity(); i++) {
//        if (x < c[i].getcargoDistance()) x = c[i].getcargoDistance();
//    }
//    return x;
//}
//
//int Truck::sum_load()
//{
//    int sum = 0;
//    for (int i = 0; i < this->getTruck_Capacity(); i++) {
//        sum += c[i].getcargoLoadTime();
//    }
//    return sum;
//}
//

int Truck::getSpeed() const
{
    return speed;
}

void Truck::setSpeed(int s)
{
    this->speed = s;
}

void Truck::setTruck_ID(int id)
{
    ID = id;
}


int Truck::getTruck_ID() const
{
    return ID;
}



//
//int Truck::getSpeed() const
//{
//    return speed;
//}
//
//Cargo Truck::getCargos(int i)
//{
//    return c[i];
//}

 int  Truck::get_num_Of_normalTrucks ()
{
    return total_number_of_normaltrucks;
}
int  Truck:: get_num_Of_specialTrucks()
{
    return total_number_of_specialtrucks;
}
int Truck::get_num_Of_VIPTrucks() 
{
    return total_number_of_VIPtrucks ;
}
int Truck::get_total_num_Of_Trucks() 
{
    return total_number_of_trucks ;
}

double Truck::calculateP()
{
    Cargo* pCargo;
    CargoList->peek(pCargo);
    if (pCargo) {
        return  pCargo->calculatePriorty();
    }
    else return 0.0;
}
bool Truck::isloaded() {

    if (getTruck_Capacity() == Tuck_cargos->GetCount()) {

        return true;
    }
    return false;

}




