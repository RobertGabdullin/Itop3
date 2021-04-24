#pragma once
#include"DataBase.h"

struct DriverGateway {

	virtual void loginDriver() = 0; 
	virtual void seeCar(int num) = 0;
	virtual void MyLoc() = 0;
	virtual void SeeAvailableOr() = 0;
	virtual void TakeOrder(int num, int CarNum) = 0;
	virtual void RegisterCar(string Model, string Colour, CarType t) = 0;
	virtual void OrderHistoryDriver() = 0;
	virtual void parkRightInFrontOfTheEntrance() = 0;
	virtual void NumberOfWater(int num) = 0;

protected:
	int state;
	vector <Car> car;
	Car* CurCar;
};

