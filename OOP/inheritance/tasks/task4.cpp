#include <iostream>
#include <vector>

using namespace std;

/*
    Exercise Description:
    In this exercise, you will explore the concepts of public, protected, and private inheritance in C++. 
    You'll be presented with a scenario involving different classes and their relationships, 
    and you'll need to decide which type of inheritance 
    should be used in each case to achieve the desired behavior and access levels.

    Scenario:
    Imagine you are developing a software system to model various types of vehicles for a transportation company. 
    You need to create a hierarchy of classes to represent different types of vehicles and their attributes. 
    Additionally, there will be a Manager class that handles the management of these vehicles.
*/

/*
    Classes:

    1. Vehicle: This is the base class that will hold common attributes of all vehicles, 
    such as the vehicle's identification number (id), maximum speed (maxSpeed), 
    and a function to display information about the vehicle (display()).
    
    2. Car: This class represents a car and should inherit from the Vehicle class. 
    It will have additional attributes like the number of doors (numDoors)
     and a function to calculate fuel efficiency (calculateFuelEfficiency()).

    3. Bus: This class represents a bus and should also inherit from the Vehicle class. 
    It will have attributes like the maximum passenger capacity (maxPassengers) 
    and a function to announce the next bus stop (announceNextStop()).

    4. Manager: This class is responsible for managing the fleet of vehicles. 
    It should have a collection of vehicles, a function to add vehicles to the fleet (addVehicle()), 
    and a function to display information about all vehicles in the fleet (displayFleet()).
*/
class vehicle {
    private:
    int id;
    int maxspeed;
    friend class Manager;
    protected:
  virtual void displayinfo(){
        cout<<"Vehicle ID: "<<id<<endl;
          cout<<"Max Speed: "<<maxspeed<<" km/h"<<endl;
    }
    vehicle(int idd,int speed):id(idd),maxspeed(speed){};
    
};
class Car:public vehicle {
    private:
    int numdoors;
    protected:
    //replaced calculateFuelEfficiency
    void displayinfo() {
           vehicle::displayinfo();
         int x = numdoors;
         if(numdoors>2){
            x=75;
         }else{
            x=90;
         }
      
           cout<<"Fuel effiency is: "<<x<<"%"<<endl;

    }
    public:
    Car(int idd,int speed,int doors): vehicle (idd,speed),numdoors(doors){};

 Car(): vehicle(0,0), numdoors(0) {};

};
class Bus :public vehicle{
    private:
    int maxPassengers;
    protected:
    //replaced announceNextStop
    void  displayinfo() override {
        vehicle::displayinfo();
        int x = maxPassengers;
        cout<<"max passanger capacity is: "<<x<<endl;
    }
    public:
    Bus(int idd,int speed,int passengers): vehicle(idd,speed), maxPassengers(passengers) {};

     Bus(): vehicle(0,0), maxPassengers(0) {};

};
class Manager {
    private:
    vector <vehicle*> items;
    public:
    void addVehicle(vehicle* item){
        items.push_back(item);
    }
    void displayFleet(){
        for ( vehicle* item : items)
        {
            item->displayinfo();
             cout<<"-------------------"<<endl;
        }
        
    }
};
/*
    Instructions:

    1. Determine the appropriate type of inheritance (public, protected, or private) between the Vehicle, Car, and Bus classes.
    2. Decide which attributes and functions should be accessible from the Manager class and other derived classes.
    3. Implement the necessary inheritance relationships and access specifiers to achieve the desired behavior.
    
    Discussion Points:
    Why would you choose public inheritance for certain classes?
    When is protected inheritance useful and in what scenarios should it be avoided?
    How does private inheritance restrict access compared to public and protected inheritance?
    
    Note: This exercise is designed to encourage understanding of inheritance types and their implications. 
    It does not involve actual coding, but rather requires conceptual analysis 
    and decision-making regarding inheritance relationships and access specifiers in C++.
*/


/*  Solution  */




int main() {

    /*    Example Usage    */
    Car car1(1, 150, 1);
    Car car2(3, 180, 4);
    Bus bus1(2, 80, 40);

    Manager manager;

    manager.addVehicle(&car1);
    manager.addVehicle(&car2);
    manager.addVehicle(&bus1);

    manager.displayFleet();

    /*
        [Output]

        Vehicle ID: 1, Max Speed: 150 km/h
        Vehicle ID: 2, Max Speed: 80 km/h
    */

    return 0;
}
