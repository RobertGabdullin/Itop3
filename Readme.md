
#PSS Homework 5. Robert Gabdullin
================================

##How to run code:
----------------

1.  Download Visual Studio 2015 (or a later version)
2.  Download archive from GitHub.
2.  Unzip the archive
3.  Move the ItopHM5 folder to the "Projects" folder (located where visual studio is installed)
4.  Open Visual Studio
5.  File -> Open -> Open project/solution -> ItopHM5 -> ItopHM4.sln
6.  Compiler code

##Program discription
-------------------

1.  This program implements two gateways: passenger mobile app and driver mobile app.
2.  A Passenger has name, rating, order history, payment methods, pinned addresses, gadgets. He can: 
2.1 Login. Switches from Driver account to Passenger. (.loginPassenger()) 
2.2 See order history. Displays all rides including including starting point, finishing point and payment method for this ride. (.OrderHistoryPassenger()) 
2.3 See pinned pay method. Displays current pay method or reports about its absence. (.PayMethod()) 
2.4 Update pay method. Changes the pinned payment method to the specified one. (.UpdPayMethod(Payment)) 
2.5 See pinned adress. Displays current pinned adress (start point and finish point) (.PinAdress) 
2.6 Update pinned adress. Changes the pinned adress to the specified one. (.UpdPinAdress(Adress())) 
2.7 Check price for some ride (By specifying the address and type of the desired machine). If no address is specified, the pinned one is used. (.CheckPrice(Payment, Adress(optional))) 
2.8 To order ride. If you won't specify payment method or adress, pinned will be used. All drivers with specified carType will see this order as available. (.OrderRide(CarType, Adress(optional), Payment(optional))) 
2.9 Get location(only during ride). Displays your current coordinates. (.MyLoc()) 
2.10 Bill of ride (available only in the end of the ride). Pay the driver and end the ride. It also removes the status "In ride" from the passenger and driver. (.BillOfRide()) 
2.11 See the history of the rides. The current ride will be able to see only after the ride (after asking a bill). (.OrderHistoryPassenger())
2.12 See current Gadget. .SeeDevice()
2.13 Change current Gadget. .ChangeGadget(Gadget). There are three possible gadgets: MobilePhone, Tablet, iPad.
3.  A driver has name, rating, order history, one car, status. He can:
3.1 login. Change Passenger account to Driver. (.loginDriver()) 
3.2 See available orders. He will see the number of order, the adress, payment method and time of ride. (.SeeAvailableOr()) 
3.3 Take order. (He can only see orders with the carType he has) Change status of driver and passenger to "In ride" (will be available some methods). (.TakeOrder(number of ride)) 
3.4 See his car. Displays model of car, colour and its type (Economy, Comfort, ComfortPlus, Business). 
3.5 Register the Car. The way to specify model of car, colour and its type. (.RegisterCar(Model, Colour, CarType)) 
3.6 See History of rides. Displays all riders of current driver. (.OrderHistoryDriver()) 
3.7 Get location (available only during the ride). Displays current coordinates of driver. (.OrderHistoryDriver()) 
3.8 Park right in Front of the entrance. (Available only for business car owners). Remove status "InRide" from driver and his passenger (.parkRightInFrontOfTheEntrance()) 
3.9 See number of bottles of water (available only for comfort/comfortPlus/business car owners). Displays number of bottles with water (It decrease after the ride)
4. Admin has name. He can:
4.1 Get full information about user. (.getInfo(User *))
4.2 Ban some user (one of his gateways) (.Ban(User *, int GatewayNumber)) PassengerGateway = 1, DriverGateway = 2, AdminGateway = 3.
4.3 Validate car of some driver (.Valid(User *, int numOfCar)) 


##Remarks
-------

1.  If user login into driver account, he won't be able to use passengers methods. (And vice versa).
2.  To use BillOfRide () you have to use MyLoc() until your position is equal to your destination.
3.  By using MyLoc() you always approach() to the destination (There cannot be such a situation that you drift away from the destination over time.)
4.  The address means a pair of coordinate points. The address is set as Adress(Point(a, b), Point(c, d))
5.  There are two payment method: Cash and card;
6.  The main function shows an example of interacting with the system. The comments show the output of the program. (You can check it byrunning the program).
7.  Information is not lost from launch to launch. You can see the orders from the previous run.
8.  The main function contains all the existing methods in the project.
9.  The main function deliberately contains incorrect requests to show how the system handles them.
10. The example function shows an example of how the two launches interact. To check the correctness of work, after the first launch, it is worth commenting out the piece of code responsible for the first launch.
11. All the necessary files are present in the project, you do not need to install / download anything additionally.