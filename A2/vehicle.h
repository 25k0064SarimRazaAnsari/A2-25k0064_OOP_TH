#pragma once

#include "interface.h"

class Vehicle : public Displayable {
protected:
    string brand;
    string model;
    string year;
    double price;
    double mileage;

public:
    Vehicle();
    Vehicle(string b, string m, string y, double p, double ma);
    virtual ~Vehicle() {}

    string getBrand() const { return brand; }
    double getPrice() const { return price; }

    virtual void displayDetails() const override; 

    bool operator==(const Vehicle& other) const; 
    Vehicle operator+(const Vehicle& other) const; 
    
    // Friend Function declarations
    friend ostream& operator<<(ostream& os, const Vehicle& v);
    friend void applySubsidy(Vehicle& v, double discountAmt);
    friend class Listing;
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car();
    Car(string b, string m, string y, double p, double ma, int doors);
    void displayDetails() const override;
};

class Bike : public Vehicle {
private:
    string startType;

public:
    Bike();
    Bike(string b, string m, string y, double p, double ma, string start);
    void displayDetails() const override;
};

class Truck : public Vehicle {
private:
    double payloadCapacity;

public:
    Truck();
    Truck(string b, string m, string y, double p, double ma, double capacity);
    void displayDetails() const override;
};
