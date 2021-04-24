#pragma once
#include"DataBase.h"

struct AdminGateway {

	virtual void loginAdmin() = 0;

	virtual void getInfo(User* a) = 0;
	
	virtual void Ban(User *a, int type) = 0;

	virtual void Valid(User *a, int CarNum) = 0;

};