#include "Truck.h"

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
    if (CargoList.GetCount() < this->getTruck_Capacity()) {
        CargoList.insert(name, name->calculatePriorty());
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


void Truck::setSpeed(int s)
{
    this->speed = s;
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






