#include "user.h"

User::User() : userID(0), name("unknown"), email("unk@gmail.com"), password("1234") {}
User::User(int uID, string n, string e, string p) : userID(uID), name(n), email(e), password(p) {}

bool User::login(string emailInput, string passwordInput) const {
    return (email == emailInput && password == passwordInput);
}

void User::displayDetails() const {
    cout << "User ID: " << userID << " | Name: " << name << " | Email: " << email;
}

Buyer::Buyer() : User(), favCount(0) {}
Buyer::Buyer(int uID, string n, string e, string p) : User(uID, n, e, p), favCount(0) {}

void Buyer::addFavrt(Listing* l) {
    if (favCount < 5) {
        favourite[favCount++] = l;
        cout << "Successfully added to your personal favorites list!\n";
    } else {
        cout << "Favorites limit reached!\n";
    }
}

void Buyer::viewFavrt() const {
    cout << "\n--- Your Favorite Inventory Items ---\n";
    for (int i = 0; i < favCount; i++) {
        favourite[i]->displayDetails();
    }
}

Seller::Seller() : User(), listingCount(0) {}
Seller::Seller(int id, string n, string e, string pass) : User(id, n, e, pass), listingCount(0) {}

void Seller::addListing(Listing l) {
    if (listingCount < 5) {
        listings[listingCount++] = l;
        cout << "Vehicle successfully added to your inventory listings.\n";
    }
}

void Seller::addListing(Listing l, double promotionalDiscount) {
    if (listingCount < 5) {
        double currentPrice = l.getVehiclePrice();
        l.setPriceDirectly(currentPrice - promotionalDiscount);
        listings[listingCount++] = l;
        cout << "Promotional listing added with a discount of Rs. " << promotionalDiscount << "!\n";
    }
}

void Seller::viewListings() {
    for (int i = 0; i < listingCount; i++) {
        listings[i].displayDetails();
    }
}

Listing* Seller::getListing(int index) {
    if (index >= 0 && index < listingCount) return &listings[index];
    return nullptr;
}

int Admin::totalAdmins = 0;
Admin::Admin() : User() { totalAdmins++; }
Admin::Admin(int id, string n, string e, string ph) : User(id, n, e, ph) { totalAdmins++; }

void Admin::approveListing(Listing &l) {
    l.approve();
    cout << "Listing ID [" << l.getListingID() << "] approved by system administration.\n";
}

void Admin::removeListing(Listing &l) {
    l.remove();
    cout << "Listing ID [" << l.getListingID() << "] blacklisted/removed from marketplace views.\n";
}

void Admin::performAdminAction() {
    cout << "Administrative security override clean. Logging system diagnostic logs.\n";
}