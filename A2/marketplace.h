#pragma once

#include <iostream>
using namespace std;

class Marketplace {
private:
    string marketName;
    static int totalUsers;

public:
    Marketplace(string name) : marketName(name) {}
    static void increaseUsers() { totalUsers++; }
    static int getTotalUsers() { return totalUsers; }
    void displayPlatformName() const { cout << "Platform: " << marketName << endl; }
};
int Marketplace::totalUsers = 0;
