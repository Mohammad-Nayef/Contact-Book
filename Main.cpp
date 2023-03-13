#include "Contact.cpp"
#include <iostream>
using namespace std;

ContactBook cb;

void add() {
	string name, phoneNumber, address, email;
	cout << "Adding a new contact:\n\n";
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the email: ";
	cin >> email;
	cout << "Enter the phone number: ";
	cin >> phoneNumber;
	cout << "Enter the address: ";
	cin >> address;

	cb.add(name, email, address, phoneNumber);
}

void del() {
	string name;
	int n;

	cout << "Deleting contacts:\n\n";
	cout << "Enter the number of contacts you want to delete: ";
	cin >> n;
	
	while (n--) {
		cout << "Enter the name of the contact: ";
		cin >> name;
		cb.del(name);
	}
}

void update() {
	string name, newName, newAddress, newEmail, newPhoneNumber;
	cout << "Updating contact:\n\n";
	cout << "Enter the name of the contact: ";
	cin >> name;
	cout << "Enter the new name: ";
	cin >> newName;
	cout << "Enter the new address: ";
	cin >> newAddress;
	cout << "Enter the new email: ";
	cin >> newEmail;
	cout << "Enter the new phone number: ";
	cin >> newPhoneNumber;

	cb.update(name, newName, newEmail, newAddress, newPhoneNumber);
}

void details(Contact contact) {
	cout << "Name: " << contact.name << endl;
	cout << "Email: " << contact.email << endl;
	cout << "Address: " << contact.address << endl;
	cout << "Phone number: " << contact.phoneNumber<< endl;
}

void srchByName() {
	string name;
	cout << "Searching by name:\n\n";
	cout << "Enter the contact name: ";
	cin >> name;

	Contact wantedContact = cb.searchByName(name);

	details(wantedContact);
}

int main() {
	int option;

	cb.add("One", "@email1", "address1", "1");
	cb.add("Two", "@email2", "address2", "2");
	cb.add("Three", "@email3", "address3", "3");
	cb.add("Four", "@email4", "address4", "4");

	do {
		cb.print();
		cout << endl;
		cout << "1. Add a contact.\n";
		cout << "2. Delete contacts.\n";
		cout << "3. Update a contact.\n";
		cout << "4. Search for a contact by its name.\n";
		cout << "0. Exit.\n\n";
		cout << "Choose an option: ";

		cin >> option;
		system("cls");
		cb.print();
		cout << endl;

		switch (option) {
		case 0:
			return 0;

		case 1:
			add();
			break;

		case 2:
			del();
			break;

		case 3:
			update();
			break;

		case 4:
			srchByName();
			break;

			system("pause");
			system("cls");
		}
	} while (1);
}