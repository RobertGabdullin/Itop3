#include"User.h"

Point::Point() : x(0), y(0) {}

Point::Point(int a, int b) : x(a), y(b) {}

ostream& operator << (ostream& out, Point const& p) {
	out << '(' << p.x << ';' << p.y << ") ";
	return out;
}

Adress::Adress() : exist(false), start(Point(0, 0)), finish(Point(0, 0)) {}

Order::Order() : id(0), p(NO), state(true) {}
Order::Order(Adress a, int i, Payment PAY) : cur(a), id(i), p(PAY), state(true) {}

string Out(Payment a) {
	if (a == CASH) return "Cash";
	return "Card";
}

string Out(CarType a)
{
	if(int(a) == 1) return "Economy";
	if ((int)a == 2) return "Comfort";
	if ((int)a == 3) return "ComfortPlus";
	return "Business";
}

string Out(int a)
{
	if (a == 0) return "NotLoginYet";
	if (a == 1) return "Passenger";
	if (a == 2) return "Driver";
	return "Admin";
}

string Out(bool a)
{
	if (a) return "In Ride";
	return "Not in Ride";
}

string Out(Device a)
{
	if (a == 1) return "MobilePhone";
	if (a == 2) return "Tablet";
	return "iPad";
}

void Launch(){
	fstream in("Base.txt", ios_base::in);

	DataBase::instance().flag = false;

	while (true) {
		string s; in >> s;
		if (s == "u") {
			string temp; in >> temp;
			User * t = new User(temp);
		}
		if (s == "lP") {
			int a; in >> a;
			DataBase::instance().List[a]->loginPassenger();
		}
		if (s == "lA") {
			int a; in >> a;
			DataBase::instance().List[a]->loginAdmin();
		}
		if (s == "TO") {
			int id, a, b; in >> id >> a >> b;
			DataBase::instance().List[id]->TakeOrder(a, b);
		}
		if (s == "lD") {
			int a; in >> a;
			DataBase::instance().List[a]->loginDriver();
		}
		if (s == "updA") {
			int id, a, b, c, d; in >> id >> a >> b >> c >> d;
			DataBase::instance().List[id]->UpdPinAdress(Adress(Point(a, b), Point(c, d)));
		}
		if (s == "updM") {
			int id, a; cin >> id >> a;
			DataBase::instance().List[id]->UpdPayMethod((Payment)a);
		}
		if (s == "OrdR") {
			int id, ct, ax, ay, bx, by, p; in >> id >> ct >> ax >> ay >> bx >> by >> p;
			DataBase::instance().List[id]->OrderRide((CarType)ct, Adress(Point(ax, ay), Point(bx, by)), (Payment)p);
		}
		if (s == "RC") {
			int id, type; string s1, s2; in >> id >> s1 >> s2 >> type;
			DataBase::instance().List[id]->RegisterCar(s1, s2, (CarType)type);
		}
		if (s == "B") {
			int id, NewId, type; in >> id >> NewId >> type;
			DataBase::instance().List[id]->Ban(DataBase::instance().List[NewId], type);
		}
		if (s == "V") {
			int id, NewId, CarNum; in >> id >> NewId >> CarNum;
			DataBase::instance().List[id]->Valid(DataBase::instance().List[NewId], CarNum);
		}
		if (s == "") break;
	}
	in.close();
	DataBase::instance().flag = true;
}

bool f(){
	return DataBase::instance().flag;
}

User * Get(int num){
	return DataBase::instance().List[num];
}

int Range(Adress a) {
	return abs(a.start.x - a.finish.x) + abs(a.start.y - a.finish.y);
}

Adress::Adress(Point a, Point b) : start(a), finish(b), exist(true) {}

ostream& operator << (ostream& out, Order const& cur) {
	out << "Payment method: " << Out(cur.p) << "; Adress: from " << cur.cur.start << "to " << cur.cur.finish << "; Time: " << Range(cur.cur) << endl;
	return out;
}