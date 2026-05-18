#include "Marketplace.h"
#include "User.h"
#include "Vehicle.h"
#include "Listing.h"
#include "Message.h"

//to run multiple cpp files= cd A2 ; g++ main.cpp user.cpp vehicle.cpp listing.cpp -o main ; if ($?) { .\main }

int main() {
    Marketplace myPlatform("Sasta Pakwheels");

    Seller registeredSellers[10];
    Buyer registeredBuyers[10];
    Admin systemAdmins[2];

    Vehicle* globalInventory[30];
    Listing globalListings[30];

    int sellerCount = 0, buyerCount = 0, vehicleCount = 0, listingCount = 0;

    systemAdmins[0] = Admin(777, "Root Admin", "admin@pakwheels.com", "securepass");

    int userInterfaceChoice = 0;

    while (true) {
        cout << "\n==================================================\n";
        cout << "      SASTA PAKWHEELS  \n";
        cout << "==================================================\n";
        cout << "1. Seller Sub-System Interface\n";
        cout << "2. Buyer Sub-System Interface\n";
        cout << "3. Administrative Dashboard Access\n";
        cout << "4. Verify Operator Overloading & Friends\n";
        cout << "5. System Core Analytics\n";
        cout << "6. Exit\n";
        cout << "Select Operation Vector [1-6]: ";
        cin >> userInterfaceChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            
            continue;
        }

        if (userInterfaceChoice == 6) {
            cout << "\nExiting...\n";
            for(int i = 0; i < vehicleCount; i++) {
                delete globalInventory[i];
            }
            break;
        }

        switch (userInterfaceChoice) {
            case 1: {
                cout << "\n1. Register Seller Profile\n2. Log In & Manage Listings\nChoice: ";
                int sOpt; 
                cin >> sOpt;
                if (sOpt == 1) {
                    if (sellerCount >= 10) { cout << "Database allocations full.\n"; break; }
                    int id; string name, email, pass;
                    cout << "Enter ID: "; cin >> id; cin.ignore();
                    cout << "Enter full display name: "; getline(cin, name);
                    cout << "Account Email: "; cin >> email;
                    cout << "Password string: "; cin >> pass;
                    registeredSellers[sellerCount++] = Seller(id, name, email, pass);
                    Marketplace::increaseUsers();
                } else if (sOpt == 2) {
                    if (sellerCount == 0) { cout << "No accounts exist.\n"; break; }
                    for (int i=0; i<sellerCount; i++) cout << i << ". ID: " << registeredSellers[i].getID() << " Name: " << registeredSellers[i].getName() << "\n";
                    int idx; cin >> idx;
                    if (idx < 0 || idx >= sellerCount) break;

                    cout << "\n1. Add Standard Vehicle Listing\n2. Add Discounted Promotional Listing\nChoice: ";
                    int lOpt; cin >> lOpt;

                    int lid; string b, m, y; double p, mil;
                    cout << "Listing Reference Code ID: "; cin >> lid; cin.ignore();
                    cout << "Brand: "; getline(cin, b);
                    cout << "Model Name: "; getline(cin, m);
                    cout << "Year: "; cin >> y;
                    cout << "Base Price: Rs. "; cin >> p;
                    cout << "Mileage (km): "; cin >> mil;

                    cout << "Class Type Selection: (1. Car  2. Bike  3. Truck): ";
                    int typeOpt; cin >> typeOpt;

                    Vehicle* vPtr = nullptr;
                    if (typeOpt == 1) {
                        int doors; cout << "Doors: "; cin >> doors;
                        vPtr = new Car(b, m, y, p, mil, doors);
                    } else if (typeOpt == 2) {
                        string ignition; cout << "Ignition Type (Self/Kick): "; cin >> ignition;
                        vPtr = new Bike(b, m, y, p, mil, ignition);
                    } else {
                        double pay; cout << "Payload limit: "; cin >> pay;
                        vPtr = new Truck(b, m, y, p, mil, pay);
                    }

                    globalInventory[vehicleCount++] = vPtr;
                    Listing newListing(lid, vPtr);

                    if (lOpt == 2) {
                        double discount; cout << "Enter structural discount markdown: Rs. "; cin >> discount;
                        registeredSellers[idx].addListing(newListing, discount);
                    } else {
                        registeredSellers[idx].addListing(newListing);
                    }
                    globalListings[listingCount++] = newListing;
                }
                break;
            }
            case 2: {
                cout << "\n1. Register Buyer\n2. View Public Directory Marketplace\nChoice: ";
                int bOpt; cin >> bOpt;
                if (bOpt == 1) {
                    if (buyerCount >= 10) break;
                    int id; string name, email, pass;
                    cout << "Enter ID: "; cin >> id; cin.ignore();
                    cout << "Name: "; getline(cin, name);
                    cout << "Email: "; cin >> email;
                    cout << "Pass: "; cin >> pass;
                    registeredBuyers[buyerCount++] = Buyer(id, name, email, pass);
                    Marketplace::increaseUsers();
                } else if (bOpt == 2) {
                    if (listingCount == 0) { cout << "The public stream registry is currently empty.\n"; break; }
                    for (int i=0; i < listingCount; i++) {
                        cout << "Index Target Matrix [" << i << "] -> ";
                        globalListings[i].displayDetails();
                    }
                }
                break;
            }
            case 3: { 
                cout << "\nSystem Authenticated into Active Master Root Admin Console Vector.\n";
                if(listingCount == 0) { cout << "No items are pending processing pipelines.\n"; break; }
                for (int i = 0; i < listingCount; i++) {
                    cout << "Index [" << i << "] Current Verification Matrix Status: " << globalListings[i].getStatus() << "\n";
                }
                cout << "Target operational index selection: ";
                int target; cin >> target;
                if(target >= 0 && target < listingCount) {
                    cout << "1. Issue Active Approval Token\n2. Issue System Flag/Removal Notice\nChoice: ";
                    int decision; cin >> decision;
                    if(decision == 1) systemAdmins[0].approveListing(globalListings[target]);
                    else systemAdmins[0].removeListing(globalListings[target]);
                }
                break;
            }
            case 4: {
                cout << "\n--- Running Structural Criteria Verification Suite ---\n";
                if (vehicleCount >= 2) {
                    cout << "Testing Overloaded Equality Operator == (Car vs Bike matching criteria):\n";
                    if (*globalInventory[0] == *globalInventory[1]) {
                        cout << "Assertion Output: Items evaluate as structurally identical duplicates.\n";
                    } else {
                        cout << "Assertion Output: Unique elements tracked.\n";
                    }

                    cout << "\nTesting Overloaded Binary Addition Operator + (Aggregating pricing vectors):\n";
                    Vehicle combinationResult = *globalInventory[0] + *globalInventory[1];
                    combinationResult.displayDetails();

                    cout << "\n\nTesting Stream Operator << Out Binding (Friend 1 implementation):\n";
                    cout << *globalInventory[0] << "\n";

                    cout << "\nApplying Direct Global Regulatory Subsidy (Friend Function 2 validation):\n";
                    cout << "Before Price Modification Rule: "; globalInventory[0]->displayDetails();
                    applySubsidy(*globalInventory[0], 25000.0);
                    cout << "\nAfter Direct Friend Variable Modification Shift: "; globalInventory[0]->displayDetails();
                    cout << "\n";
                } else {
                    cout << "Please populate at least 2 system vehicle types inside the seller menu option to execute diagnostic assertions.\n";
                }
                break;
            }
            case 5: {
                cout << "\n===== GLOBAL STATE ANALYTICS MONITOR =====\n";
                myPlatform.displayPlatformName();
                cout << "Active System Profiles Bound: " << Marketplace::getTotalUsers() << "\n";
                cout << "Total Active Administrators Verified: " << Admin::getTotalAdmins() << "\n";
                cout << "Aggregate Listing Instances Created: " << Listing::getTotalListings() << "\n";
                break;
            }
            default:
                cout << "Operational parameter mapping fallback. Select a sequence value between [1-6].\n";
        }
    }
    return 0;
}