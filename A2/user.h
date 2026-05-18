#pragma once

#include "interface.h"
#include "Listing.h"

class User : public Displayable, public Authenticable {
protected:
    int userID;
    string name;
    string email;
    string password;

public:
    User();
    User(int uID, string n, string e, string p);
    virtual ~User() {}

    int getID() const { return userID; }
    string getName() const { return name; }
    
    bool login(string emailInput, string passwordInput) const override;
    virtual void displayDetails() const override;
};

class Buyer : public User {
private:
    Listing* favourite[5];
    int favCount;

public:
    Buyer();
    Buyer(int uID, string n, string e, string p);
    void addFavrt(Listing* l);
    void viewFavrt() const;
};

class Seller : public User {
private:
    Listing listings[5];
    int listingCount;

public:
    Seller();
    Seller(int id, string n, string e, string pass);
    
    void addListing(Listing l);
    void addListing(Listing l, double promotionalDiscount); 

    void viewListings();
    Listing* getListing(int index);
    int getListingCount() const { return listingCount; }
};

class Admin : public User, public Manageable {
private:
    static int totalAdmins;

public:
    Admin();
    Admin(int id, string n, string e, string ph);
    
    void approveListing(Listing &l);
    void removeListing(Listing &l);
    void performAdminAction() override;

    static int getTotalAdmins() { return totalAdmins; }
};
