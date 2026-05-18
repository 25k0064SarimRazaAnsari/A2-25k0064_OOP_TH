#include "vehicle.h"

Vehicle::Vehicle() : brand("xyz"), model("xyz"), year("xyz"), price(0.0), mileage(0.0) {}
Vehicle::Vehicle(string b, string m, string y, double p, double ma) 
    : brand(b), model(m), year(y), price(p), mileage(ma) {}

void Vehicle::displayDetails() const {
    cout << brand << " " << model << " (" << year << ") | Price: Rs." << price << " | Mileage: " << mileage << " km";
}

bool Vehicle::operator==(const Vehicle& other) const {
    return (this->brand == other.brand && this->model == other.model && this->price == other.price);
}

Vehicle Vehicle::operator+(const Vehicle& other) const {
    return Vehicle("Combined Package", this->model + " & " + other.model, this->year, this->price + other.price, 0.0);
}

ostream& operator<<(ostream& os, const Vehicle& v) {
    os << "[STREAM OUT] " << v.brand << " " << v.model << " | Cost: " << v.price;
    return os;
}

void applySubsidy(Vehicle& v, double discountAmt) {
    v.price -= discountAmt; 
}

Car::Car() : Vehicle(), numDoors(4) {}
Car::Car(string b, string m, string y, double p, double ma, int doors) 
    : Vehicle(b, m, y, p, ma), numDoors(doors) {}

void Car::displayDetails() const {
    Vehicle::displayDetails();
    cout << " | Type: Car (" << numDoors << " Doors)\n";
}

Bike::Bike() : Vehicle(), startType("Kick") {}
Bike::Bike(string b, string m, string y, double p, double ma, string start) 
    : Vehicle(b, m, y, p, ma), startType(start) {}

void Bike::displayDetails() const {
    Vehicle::displayDetails();
    cout << " | Type: Bike (Ignition: " << startType << ")\n";
}

Truck::Truck() : Vehicle(), payloadCapacity(0.0) {}
Truck::Truck(string b, string m, string y, double p, double ma, double capacity) 
    : Vehicle(b, m, y, p, ma), payloadCapacity(capacity) {}

void Truck::displayDetails() const {
    Vehicle::displayDetails();
    cout << " | Type: Truck (Max Load: " << payloadCapacity << " Tons)\n";
}