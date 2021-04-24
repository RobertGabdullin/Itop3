#include"User.h"

ofstream out("Base.txt", ios_base::app);

void User::loginDriver() {
	User::Gateway = 2;
	if (f()) {
		cout << "You are logged in driver mobile app" << endl;
		out << "lD " << this->id << endl;
	}
}


void User::loginPassenger() {
	User::Gateway = 1;

	if (f()) {
		cout << "You are logged in passenger mobile app" << endl;
		out << "lP " << this->id << endl;
	}
}

void User::PayMethod() {
	if (!Check(1)) return;
	if (User::pay == NO) cout << "No pinned payment method" << endl;
	else if (User::pay == CASH) cout << "Attached payment method: cash" << endl;
	else cout << "Attached payment method: card" << endl;
}

void User::PinAdress() {
	if (!Check(1)) return;
	if (!pined.exist) {
		cout << "No pinned adress" << endl;
		return;
	}
	cout << "Pinned adress: from " << User::pined.start << " to" << User::pined.finish << endl;
}

void User::CheckPrice(CarType cur, Adress a) {
	if (!Check(1)) return;
	if (!a.exist && !pined.exist) {
		cout << "First you need to pin the address, or enter the address manually" << endl;
		return;
	}

	if (!a.exist) a = pined;

	cout << "The cost of ride: " << (int)cur * Range(a) << endl;

}

void User::UpdPayMethod(Payment a) {
	if (!Check(1)) return;
	pay = a;
	if (f()) {
		cout << "Pinned pay method has been updated" << endl;
		out << "UpdM " << this->id << ' ' << (int)a << endl;
	}
}

void User::UpdPinAdress(Adress a) {
	if (!Check(1)) return;
	pined = a;
	if (f()) {
		cout << "Pinned adress has been updated" << endl;
		out << "UpdA " << this->id << ' ' << a.start.x << ' ' << a.start.y << ' ' << a.finish.x << ' ' << a.finish.y << endl;
	}
}

void User::OrderRide(CarType cur, Adress a, Payment p) {
	if (!Check(1)) return;
	if (!a.exist) a = pined;
	if (!a.exist) {
		cout << "You have neither a pinned adress method nor a manual adress set" << endl;
		return;
	}
	if (pay == NO && p == NO) {
		cout << "You have neither a pinned payment method nor a manual payment method set" << endl;
		return;
	}
	if (DataBase::instance().BanPassenger[id]) {
		cout << "Your passenger account has been banned" << endl;
		return;
	}

	if (p == NO) p = pay;
	DataBase::instance().Or[(int)cur].push_back(Order(a, id, p));
	if (f()) {
		cout << "Now the drivers sees your order" << endl;
		out << "OrdR " << this->id << ' ' << (int)cur << ' ' << a.start.x << ' ' << a.start.y << ' ' << a.finish.x << ' ' << a.finish.y << ' ' << (int)p << endl;
	}
}

void User::SeeAvailableOr() {
	if (!Check(2)) return;
	for (int z = 0; z < car.size(); z++) {
		if (!car[z].Validate) continue;
		vector <Order> temp = DataBase::instance().Or[(int)car[z].type];
		int pos = 1;
		for (int i = 0; i < temp.size(); i++)
			if (temp[i].state)
				cout << pos++ << ": " << temp[i];
	}
}

void User::TakeOrder(int num, int CarNum) {
	if (!Check(2)) return;
	if (DataBase::instance().BanDriver[id]) {
		cout << "One of the admins has blocked you" << endl;
		return;
	}
	if (CarNum < 0 || CarNum >= car.size()) {
		cout << "There is no car with such number" << endl;
		return;
	}
	if (!car[CarNum].Validate) {
		cout << "First, the administrator must confirm that you can take orders" << endl;
		return;
	}
	if (InRide) {
		cout << "You cannot take order during another ride" << endl;
		return;
	}
	if (DataBase::instance().BanDriver[id]) {
		cout << "Your driver's account has been banned" << endl;
		return;
	}


	int p = 0, loc = 0;
	for (int i = 0; i < DataBase::instance().Or[(int)car[CarNum].type].size(); i++) {
		if (DataBase::instance().Or[(int)car[CarNum].type][i].state) p++;
		loc = i;
		if (p == num) break;
	}
	if (p != num) {
		cout << "There are no order with such nubmer" << endl;
		return;
	}

	vector <User*> temp = DataBase::instance().List;
	Order& t = DataBase::instance().Or[(int)car[CarNum].type][loc];

	CurCar = &car[CarNum];

	pos = t.cur.start;
	temp[t.id]->pos = t.cur.start;
	InRide = true;
	temp[t.id]->InRide = true;
	To = t.cur.finish;
	temp[t.id]->To = t.cur.finish;
	with = temp[t.id];
	temp[t.id]->with = this;
	curOrder = &t;
	with->curOrder = &t;

	if (f()) {
		cout << "You are successfully take order" << endl;
		out << "TO " << this->id << ' ' << num << ' ' << CarNum << endl;
	}
}

void User::MyLoc() {
	if (!InRide) {
		cout << "You can get your location only during ride" << endl;
		return;
	}

	if (pos.x != To.x) {
		pos.x = (To.x + pos.x) / 2;
		if (abs(pos.x - To.x) == 1) pos.x = To.x;
		with->pos.x = pos.x;
	}

	else if (pos.y != To.y) {
		pos.y = (To.y + pos.y) / 2;
		if (abs(pos.y - To.y) == 1) pos.y = To.y;
		with->pos.y = pos.y;
	}

	if (f()) {
		cout << "Coordinates: " << pos << endl;
		out << "ML " << this->id << endl;
	}
}

void User::BillOfRide() {
	if (!Check(1)) return;
	if (!InRide) {
		cout << "You are not going anywhere" << endl;
		return;
	}
	if (pos.x != To.x || pos.y != To.y) {
		cout << "You must first get to your destination" << endl;;
		return;
	}
	
	InRide = false;
	with->InRide = false;
	DataBase::instance().HistoryPassenger[id].push_back(*curOrder);
	DataBase::instance().HistoryDriver[with->id].push_back(*curOrder);
	curOrder->state = false;
	with->curOrder->state = false;

	with->CurCar->BottlesOfWater -= rand() % 2 + 1;

	if (f()) {
		cout << "Your ride is over" << endl;
		out << "BR " << this->id << endl;
	}
}


User::User(string n) : Gateway(0), with(0), InRide(false), Register(false), name(n), rating(rand() % 100 + 1) {
	pos = Point();
	To = Point();
	id = DataBase::GetId();
	DataBase::instance().List.push_back(this);
	pay = NO;
	D = MobilePhone;

	if (f()) {
		cout << "The user has been successfully registered" << endl;
		out << "u " << n << endl;
	}
}

void User::OrderHistoryPassenger() {
	if (!Check(1)) return;
	vector <Order> temp = DataBase::instance().HistoryPassenger[id];

	for (int i = 0; i < temp.size(); i++) 
		cout << i + 1 << ": " << temp[i];

}

void User::seeCar(int num){
	if (!Check(2)) return;
	if (num < 0 || num >= car.size()) {
		cout << "No car with such number" << endl;
		return;
	}
	cout << "Model: " << car[num].model << "; Colour: " << car[num].colour << "; Type: " << Out(car[num].type) << endl;
}

void User::RegisterCar(string Model, string Colour, CarType t) {
	if (!Check(2)) return;
	Car temp;
	temp.model = Model, temp.colour = Colour, temp.type = t;
	car.push_back(temp);
	
	if (f()) {
		cout << "Car has been registered" << endl;
		out << "RC " << this->id << ' ' << Model << ' ' << Colour << ' ' << (int)t << endl;
	}
}

void User::OrderHistoryDriver()
{
	if (!Check(2)) return;
	
	vector <Order> temp = DataBase::instance().HistoryDriver[id];

	for (int i = 0; i < temp.size(); i++)
		cout << i + 1 << ": " << temp[i];
}

void User::parkRightInFrontOfTheEntrance() {
	if (!Check(2)) return;
	if (!InRide) {
		cout << "You are not going anywhere" << endl;
		return;
	}
	if (CurCar->type != Business) {
		cout << "Your car should business" << endl;
		return;
	}

	pos = To;
	with->pos = To;

	if (f()) {
		with->BillOfRide();
		out << "pRE " << this->id << endl;
	}
}

void User::NumberOfWater(int num) {
	if (!Check(2)) return;
	if (num < 0 || num >= car.size()) {
		cout << "No car with such number" << endl;
		return;
	}
	if ((int)car[num].type < 2) {
		cout << "Only Comfort, ComfortPlus and Business cars can have bottles of water" << endl;
		return;
	}
	cout << car[num].BottlesOfWater << endl;
}

void User::Ban(User *a, int type) {
	if (!Check(3)) return;
	if (type == 2) DataBase::instance().BanDriver[a->id] = true;
	if (type == 1) DataBase::instance().BanPassenger[a->id] = true;
	if (type == 3) {
		cout << "You cannot block function of admins" << endl;
		return;
	}

	string temp;
	if (type == 1) temp = "Passenger's ";
	else temp = "Driver's ";
	if (f()) {
		cout << "Now this user cannot use " << temp << "functions" << endl;
		out << "B " << this->id << ' ' << a->id << ' ' << type << endl;
	}
}

void User::getInfo(User * a) {
	if (!Check(3)) return;
	cout << "Name: " << a->name << endl << "Gateway: " << Out(a->Gateway) << endl << "Status: " << Out(a->InRide) << endl;
	if (a->InRide) cout << "Current coordinates: " << a->pos << endl;
	cout << Out(a->D) << endl;
}

void User::Valid(User * a, int CarNum) {
	if (!Check(3)) return;
	if (CarNum < 0 || CarNum >= a->car.size()) {
		cout << "There are no car with such number" << endl;
		return;
	}
	a->car[CarNum].Validate = true;
	
	if (f()) {
		cout << "Now this machine can be used for orders" << endl;
		out << "V " << this->id << ' ' << a->id << ' ' << CarNum << endl;
	}
}

void User::SeeDevice() {
	cout << Out(D) << endl;
}

void User::ChangeDevice(Device a) {
	D = a;
	cout << "Your gadget has been changed" << endl;
}

void User::loginAdmin() {
	Gateway = 3;
	if (f()) {
		cout << "You are logged in admin mobile app" << endl;
		out << "lA " << this->id << endl;
	}
}
