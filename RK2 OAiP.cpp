// RK2 OAiP.cpp: определяет точку входа для приложения.
//

#include"RK2 OAiP.h"
#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;


class Vehicle{
protected: string mark; string model;
public:
	Vehicle(const string mark, const string model): mark(mark), model(model) {}
	virtual void display() const{cout<<"Vehicle{mark: "<<mark<<", model: "<<model<<"};"<<endl;}
	virtual ~Vehicle()=default;
	virtual void modify(const string newmark, const string newmodel){mark=newmark; model=newmodel;}
};

class Car: public Vehicle{
private: int doors;
public:
	Car(const string mark, const string model, int doors): Vehicle(mark, model), doors(doors) {}
	void display() const override{cout<<"Car{mark: "<<mark<<", model: "<<model<<", doors: "<<doors<<"};"<<endl;}
	void modify(const string newmark, const string newmodel, int newdoors){Vehicle::modify(newmark, newmodel); doors=newdoors;}
};

class Motorcycle: public Vehicle{
private: string type;
public:
	Motorcycle(const string mark, const string model, const string type): Vehicle(mark, model), type(type) {}
	void display() const override{cout<<"Motorcycle{mark: "<<mark<<", model: "<<model<<", type: "<<type<<"};"<<endl;}
	void modify(const string newmark, const string newmodel, const string newtype){Vehicle::modify(newmark, newmodel); type=newtype;}
};


void modifyVehicle(Vehicle* vehicle, const string newmark, const string newmodel){vehicle->modify(newmark, newmodel);}


int main(){
	list<unique_ptr<Vehicle>> vehicles;
	vehicles.push_back(make_unique<Car>("Toyota", "Camry", 4)); vehicles.push_back(make_unique<Motorcycle>("Yamaha", "YZF-R3", "Sport"));
	vehicles.push_back(make_unique<Car>("Honda", "Civic", 6));
	vehicles.push_back(make_unique<Motorcycle>("Harley-Davidson", "Iron 883", "Cruiser"));
	for(const auto& vehicle: vehicles){vehicle->display();}
	modifyVehicle(vehicles.front().get(), "Ford", "Mustang");
	cout<<"\n######################\n# After modification #\n######################\n\n";// Русский просто поломаться может
	for(const auto& vehicle: vehicles){vehicle->display();}
	return 0;
}
