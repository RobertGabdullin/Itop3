#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct Point {
	int x, y;
	Point();
	Point(int a, int b);
};

ostream& operator << (ostream& out, Point const& p);

enum CarType {
	Economy = 1,
	Comfort = 2,
	ComfortPlus = 3,
	Business = 4
};

enum Device {
	MobilePhone = 1,
	Tablet = 2,
	Ipad = 3
};

enum Payment {

	CASH = 0,

	CARD = 1,

	NO = 2

};

struct Adress {
	Point start, finish;
	bool exist;
	Adress();
	Adress(Point a, Point b);
};

struct Order {
	Order();
	Order(Adress a, int i, Payment PAY);
	Adress cur;
	Payment p;
	bool state;
	int id;
};

ostream& operator << (ostream& out, Order const& cur);

int Range(Adress a);

string Out(Payment a);

string Out(CarType a);

string Out(int a);

string Out(bool a);

string Out(Device a);

struct Car {
	string colour, model;
	CarType type;
	bool Validate;
	int BottlesOfWater;
	Car() : colour(""), model(""), type(Economy), BottlesOfWater(7), Validate(false) {}
};

struct User;

void Launch();

bool f();

User * Get(int num);

struct DataBase {

	friend struct User;
	friend void Launch();
	friend bool f();
	friend User* Get(int num);

	map <int, vector <Order> > Or, HistoryPassenger, HistoryDriver;

	map <int, bool> BanDriver, BanPassenger;

	vector <User*> List;

	bool flag = true;

private:
	DataBase() {}
	DataBase operator= (DataBase const& cur);

	static DataBase& instance() {
		static DataBase ans;
		return ans;
	}

	static int GetId() {
		static int id = -1;
		id++;
		return id;
	}

};