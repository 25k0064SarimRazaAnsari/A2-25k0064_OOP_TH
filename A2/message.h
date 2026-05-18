#pragma once

#include <iostream>
using namespace std;

class Message {
private:
    string content;
    int senderID;
    int receiverID;
    string timestamp;

public:
    Message() : content("None"), senderID(0), receiverID(0), timestamp("00:00") {}
    Message(string c, int sID, int rID, string t) 
        : content(c), senderID(sID), receiverID(rID), timestamp(t) {}

    void displayMessage() const {
        cout << "\n--- Transmission [Time: " << timestamp << "] ---\n";
        cout << "From ID: " << senderID << " -> To ID: " << receiverID << "\n";
        cout << "Content: \"" << content << "\"\n";
    }
};
