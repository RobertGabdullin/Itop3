#pragma once
#include"Driver.h"
#include"Passenger.h"
#include"Admin.h"


struct User : DriverGateway, PassengerGateway, AdminGateway {

	User(string n);

	void loginDriver();
	
	void loginPassenger();

	void PayMethod();

	void PinAdress();

	void CheckPrice(CarType cur, Adress a = Adress());

	void UpdPayMethod(Payment a);

	void UpdPinAdress(Adress a);

	void OrderRide(CarType cur, Adress a = Adress(), Payment p = NO);

	void SeeAvailableOr();

	void TakeOrder(int num, int CarNum);

	void MyLoc();

	void BillOfRide();

	void OrderHistoryPassenger();

	void seeCar(int num);

	void RegisterCar(string Model, string Colour, CarType t);

	void OrderHistoryDriver();

	void parkRightInFrontOfTheEntrance();

	void NumberOfWater(int num);

	void Ban(User *a, int type);

	void getInfo(User *a);

	void Valid(User *a, int CarNum);

	void SeeDevice();

	void ChangeDevice(Device a);

	void loginAdmin();

	string name;
	int rating;

private:

	bool Check(int a) {
		if (a == Gateway) return true;
		if (a == 1) cout << "Firstly you should login to Passenger mobile app" << endl;
		if (a == 2) cout << "Firstly you should login to Driver mobile app" << endl;
		if (a == 3) cout << "Firstly you should login to Admin mobile app" << endl;
		return false;
	}

	int Gateway, id;
	Point pos, To;
	Order* curOrder;
	bool InRide, Register;
	User* with;
	Device D = MobilePhone;
};