#pragma once
#include"DataBase.h"

struct PassengerGateway {

	virtual void loginPassenger() = 0; 
	virtual void OrderHistoryPassenger() = 0;
	virtual void PayMethod() = 0; 
	virtual void UpdPayMethod(Payment a) = 0; 
	virtual void PinAdress() = 0;	
	virtual void UpdPinAdress(Adress a) = 0;  
	virtual void CheckPrice(CarType cur, Adress a = Adress()) = 0; 
	virtual void OrderRide(CarType cur, Adress a = Adress(), Payment p = NO) = 0; 
	virtual void BillOfRide() = 0;

protected:
	Adress pined;
	Payment pay = NO;

};