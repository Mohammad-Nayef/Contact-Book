#include <list>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Contact {
    string name, email, address, phoneNumber;
};

class ContactBook {
private:
    list <Contact> contacts;

public:
    ~ContactBook() {
    
    }
        
    int size() {
        return contacts.size();
    }

    void add(Contact newContact) {
        add(newContact.name, newContact.email, newContact.address, newContact.phoneNumber);
    }

    void add(string name, string email, string address, string phoneNumber) {
        if (name.size() > 50 || email.size() > 50 || address.size() > 50 || phoneNumber.size() > 50) {
            cout << "Invalid inputs!\n";
            return;
        }

        for (char it : name) {
            if (it < 65 || (it > 65 + 26 && it < 97) || it > 97 + 26) {
                cout << "Invalid inputs!\n";
                return;
            }
        }

        bool validEmail = false;

        for (char it : email) {
            if (it == '@') {
                validEmail = true;
                break;
            }
        }

        if (!validEmail) {
            cout << "Invalid inputs!\n";
            return;
        }

        for (char it : phoneNumber) {
            if ((it < 48 || it > 48 + 10) && it != '+') {
                cout << "Invalid inputs!\n";
                return;
            }
        }

        Contact newContact{ name, email, address, phoneNumber };
        contacts.push_back(newContact);
    }

    void print() {
        for (auto it : contacts) {
            cout << it.name << ", " << it.address << ", " << it.phoneNumber << ", " << it.email << endl;
        }
    }

    Contact searchByName(string wantedName) {
        Contact notFound{ "null", "null", "null", "null" };

        for (Contact it : contacts) {
            if (it.name == wantedName)
                return it;
        }

        return notFound;
    }

    void update(string currentName, string newName, string newEmail, string newAddress, string newPhoneNumber) {
        Contact wantedContact = searchByName(currentName);

        if (wantedContact.name == "null")
            cout << "Can't find the wanted contact!\n";

        else {
            wantedContact.name = newName;
            wantedContact.email = newEmail;
            wantedContact.address = newAddress;
            wantedContact.phoneNumber = newPhoneNumber;
        }
    }

    void del(string wantedName) {
        if (contacts.empty()) {
            cout << "Already empty!\n";
            return;
        }

        Contact find = searchByName(wantedName);

        if (find.name == "null")
            cout << "Can't find the wanted contact!\n";
    
        else {
            for (auto it = contacts.begin(); it != contacts.end(); it++) {
                if (it->name == wantedName) {
                    contacts.erase(it);
                    break;
                }
            }
        }
    }
};