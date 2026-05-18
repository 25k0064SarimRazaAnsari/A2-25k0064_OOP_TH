#include "Listing.h"

int Listing::totalListings = 0;

Listing::Listing() : listingID(0), status("Pending"), managedVehicle(nullptr) {}

Listing::Listing(int id, Vehicle* v) : listingID(id), status("Pending"), managedVehicle(v) { totalListings++; }