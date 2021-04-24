#include"User.h"

int main() {

	// First Launch

	User *a = new User("Artem"); // The user has been successfully registered

	a->loginPassenger(); // You are logged in passenger mobile app

	a->CheckPrice(Economy, Adress(Point(0, 0), Point(2, 3))); // The cost of ride: 5

	a->UpdPinAdress(Adress(Point(2, 2), Point(10, 10))); // Pinned adress has been updated

	a->CheckPrice(Business); // The cost of ride: 64

	a->SeeDevice(); // MobilePhone

	a->ChangeDevice(Tablet); // Your gadget has been changed

	a->SeeDevice(); // Tablet

	a->UpdPayMethod(CASH); // Pinned pay method has been updated

	a->OrderRide(Economy); // Now the drivers sees your order

	User *b = new User("Roman"); // The user has been successfully registered
	    
	b->loginDriver(); // You are logged in driver mobile app
	
	b->RegisterCar("Porshe", "Red", Economy); // Car has been registered

	User *d = new User("Mikhail"); // The user has been successfully registered

	d->loginAdmin(); // You are logged in admin mobile app

	b->TakeOrder(1, 0); // First, the administrator must confirm that you can take orders

	d->Valid(b, 0); // Now this machine can be used for orders

	b->SeeAvailableOr(); // 1: Payment method: Cash; Adress: from (2;2) to (10;10) ; Time: 16

	b->TakeOrder(1, 0); // You are successfully take order

	a->MyLoc(); // Coordinates: (6;2)

	b->MyLoc(); // Coordinates: (8;2)

	a->BillOfRide(); // You must first get to your destination

	a->MyLoc(); // Coordinates: (10;2)

	b->MyLoc(); // Coordinates: (10;6)

	a->MyLoc(); // Coordinates: (10;8)

	a->MyLoc(); // Coordinates: (10;10)

	b->BillOfRide(); // Firstly you should login to Passenger mobile app

	a->BillOfRide(); // Your ride is over

	a->seeCar(0); // Firstly you should login to Driver mobile app

	b->seeCar(0); // Model: Porshe; Colour: Red; Type: Economy

	User *c = new User("Vladimir"); // The user has been successfully registered

	c->loginDriver(); // You are logged in driver mobile app

	c->seeCar(0); // No car with such number

	c->loginPassenger(); // You are logged in passenger mobile app

	a->loginDriver(); // You are logged in driver mobile app

	a->RegisterCar("Mazda", "Green", Business); // Car has been registered

	b->RegisterCar("Kalina", "Blue", Business); // Car has been registered

	c->OrderRide(Business, Adress(Point(5, 5), Point(2, 7)), CARD); // Now the drivers sees your order

	b->loginPassenger(); // You are logged in passenger mobile app

	b->OrderRide(Business, Adress(Point(8, 8), Point(14, 19)), CASH); // Now the drivers sees your order

	a->SeeAvailableOr(); // 1: Payment method: Card; Adress: from (5;5) to (2;7) ; Time: 5 
	                    // 2: Payment method : Card; Adress: from(8; 8) to(14; 19); Time: 17

	a->TakeOrder(0, 0); // First, the administrator must confirm that you can take orders

	d->Valid(a, 0); // Now this machine can be used for orders

	a->TakeOrder(1, 0); // You are successfully take order

	a->seeCar(0); // Model: Mazda; Colour: Green; Type: Business

	a->TakeOrder(2, 0); // You cannot take order during another ride

	a->MyLoc(); // Coordinates: (2;5)

	a->MyLoc(); // Coordinates: (2;7)

	c->BillOfRide(); // Your ride is over

	a->OrderHistoryDriver(); // 1: Payment method: Card; Adress: from (5;5) to (2;7) ; Time: 5

	a->loginPassenger(); // You are logged in passenger mobile app

	a->OrderHistoryPassenger(); // 1: Payment method: Card; Adress: from (2;2) to (10;10) ; Time: 16

	a->loginDriver(); // You are logged in driver mobile app

	a->NumberOfWater(0); // 6

	a->SeeAvailableOr(); // 1: Payment method: Card; Adress: from (8;8) to (14;19) ; Time: 17

	a->TakeOrder(1, 0); // You are successfully take order

	a->parkRightInFrontOfTheEntrance(); // Your ride is over

	a->NumberOfWater(0); // 5

	a->OrderHistoryDriver(); // 1: Payment method: Card; Adress: from (5;5) to (2;7) ; Time: 5
							// 2: Payment method : Card; Adress: from(8; 8) to(14; 19); Time: 17

	a->loginPassenger(); // You are logged in passenger mobile app

	a->OrderRide(Economy, Adress(Point(2, 3), Point(10, 20)), CASH); // Now the drivers sees your order

	b->loginPassenger(); // You are logged in passenger mobile app

	b->OrderRide(Comfort, Adress(Point(10, 10), Point(30, 40)), CARD); // Now the drivers sees your order

	c->loginPassenger(); // You are logged in passenger mobile app

	d->Ban(c, 1); // Now this user cannot use Passenger's functions

	c->OrderRide(Business, Adress(Point(1, 2), Point(3, 4)), CASH); // Your passenger account has been banned	

	delete a; delete b;
	delete c; delete d;

	system("pause"); // =)

	/*Second launch (First launch should be commented)
		
		Launch();

		User *f = new User("Renata"); //The user has been successfully registered

		f->loginDriver(); // You are logged in driver mobile app

		f->RegisterCar("Audi", "Blue", Comfort); // Car has been registered

		Get(2)->Valid(f, 0); // Now this machine can be used for orders

		f->RegisterCar("Acura", "Purple", Economy); // Car has been registered

		f->SeeAvailableOr(); // 1: Payment method: Card; Adress: from (10;10) to (30;40) ; Time: 50

		Get(2)->Valid(f, 1); // Now this machine can be used for orders

		f->SeeAvailableOr(); // 1: Payment method: Card; Adress: from (10;10) to (30;40) ; Time: 50
							 // 1: Payment method: Cash; Adress: from (2;2) to (10;10) ; Time: 16 
							 // 2: Payment method : Cash; Adress: from(2; 3) to(10; 20); Time: 25
		
		f->TakeOrder(1, 0); // You are successfully take order

		Get(1)->MyLoc(); // Coordinates: (20;10)
		Get(1)->MyLoc(); // Coordinates: (25;10)
		Get(1)->MyLoc(); // Coordinates: (27;10)
		Get(1)->MyLoc(); // Coordinates: (28;10)
		Get(1)->MyLoc(); // Coordinates: (30;10)
		Get(1)->MyLoc(); // Coordinates: (30;25)
		Get(1)->MyLoc(); // Coordinates: (30;32)
		Get(1)->MyLoc(); // Coordinates: (30;36)
		Get(1)->MyLoc(); // Coordinates: (30;38)
		Get(1)->MyLoc(); // Coordinates: (30;40)

		Get(1)->BillOfRide(); // Your ride is over

		Get(2)->getInfo(Get(1)); // Name: Roman
								 // Gateway: Passenger
								 // Status: Not in Ride

		Get(2)->Ban(f, 2); // Now this user cannot use Driver's functions

		f->TakeOrder(0, 1); // One of the admins has blocked you

		system("pause");
	
	*/



}