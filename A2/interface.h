#pragma once

#include <iostream>
using namespace std;
//basic c++ interface
class Displayable {
public:
    virtual void displayDetails() const = 0; 
    virtual ~Displayable() {}
};

class Authenticable {
public:
    virtual bool login(string emailInput, string passwordInput) const = 0; 
    virtual ~Authenticable() {}
};

class Manageable {
public:
    virtual void performAdminAction() = 0;
    virtual ~Manageable() {}
};

