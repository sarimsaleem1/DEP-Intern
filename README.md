# DEP-Intern
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Contact {
public:
    string name;
    string phoneNumber;

  
    Contact(string n, string p) : name(n), phoneNumber(p) {}
};


void addContact(vector<Contact>& contacts) {
    string name, phoneNumber;
    cin.ignore(); 
    cout << "Enter contact name: ";
    getline(cin, name);
    cout << "Enter contact phone number: ";
    getline(cin, phoneNumber);

    contacts.push_back(Contact(name, phoneNumber));
    cout << "Contact added successfully!\n";
}


void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display.\n";
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << "Contact " << i + 1 << ": " << contacts[i].name
             << " - " << contacts[i].phoneNumber << endl;
    }
}


void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete.\n";
        return;
    }

    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;

    if (index > 0 && index <= contacts.size()) {
        contacts.erase(contacts.begin() + index - 1);
        cout << "Contact deleted successfully!\n";
    } else {
        cout << "Invalid contact number.\n";
    }
}


int main() {
    vector<Contact> contacts;
    int choice;

    do {
      
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Delete Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

       
        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            viewContacts(contacts);
            break;
            
        case 3:
            deleteContact(contacts);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
