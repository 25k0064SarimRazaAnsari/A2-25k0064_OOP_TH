#pragma once

#include "vehicle.h"

class Listing : public Displayable {
private:
    int listingID;
    string status;
    Vehicle* managedVehicle;
    static int totalListings;

public:
    Listing();
    Listing(int id, Vehicle* v);
    
    void approve() { status = "Approved"; }
    void remove() { status = "Removed"; }
    
    int getListingID() const { return listingID; }
    string getStatus() const { return status; }
    double getVehiclePrice() const { return managedVehicle ? managedVehicle->getPrice() : 0.0; }
    
    void setPriceDirectly(double newP) { if(managedVehicle) managedVehicle->price = newP; }

    void displayDetails() const override {
        cout << "Listing ID: " << listingID << " | Status: " << status << " | Specs: ";
        if(managedVehicle) managedVehicle->displayDetails();
        else cout << "No Vehicle Bound.\n";
    }

    static int getTotalListings() { return totalListings; }
};