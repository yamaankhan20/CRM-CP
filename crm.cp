#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>  // For exception handling

using namespace std;

class Customer; // Forward declaration

class Contact {
private:
    string date;
    string summary;
public:
    Contact(string d, string s) : date(d), summary(s) {}

    string getDate() const {
        return date;
    }

    string getSummary() const {
        return summary;
    }

    void display() const {
        cout << "Date: " << date << ", Summary: " << summary << endl;
    }

    friend void generateActivityReports(const vector<Customer>& customers);
};

class SalesOpportunity {
private:
    string description;
    double value;
    string stage;
public:
    SalesOpportunity(string desc, double val, string st) : description(desc), value(val), stage(st) {}

    string getDescription() const {
        return description;
    }

    double getValue() const {
        return value;
    }
	
	string getStage() const {
		return stage;
	}
	
    void display() const {
        cout << "Description: " << description << ", Value: " << value << ", Stage: " << stage << endl;
    }

    friend void generateSalesReports(const vector<Customer>& customers);
};

class Customer {
private:
    string name;
    string contactInfo;
    vector<Contact> contacts;
    vector<SalesOpportunity> salesOpportunities;

    friend void generateCustomerReports(const vector<Customer>& customers);
public:
    Customer(string n, string info) : name(n), contactInfo(info) {}

    string getName() const {
        return name;
    }

    vector<Contact>& getContacts() {
        return contacts;
    }
    
    const vector<Contact>& getContacts() const {  // Add this const version of getContacts
        return contacts;
    }

     vector<SalesOpportunity>& getSalesOpportunities() {
        return salesOpportunities;
    }

    const vector<SalesOpportunity>& getSalesOpportunities() const {  // Add this const version of getSalesOpportunities
        return salesOpportunities;
    }

    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void addSalesOpportunity(const SalesOpportunity& opportunity) {
        salesOpportunities.push_back(opportunity);
    }

    void display() const {
        cout << "Customer Name: " << name << ", Contact Info: " << contactInfo << endl;
    }

    void viewContactDetails() const {
        cout << "\nContact Details for " << name << ":" << endl;
        if (!contacts.empty()) {
            for (const auto& contact : contacts) {
                contact.display();
            }
        } else {
            cout << "No Contact Information Found!!!" << endl;
        }
    }

    void viewSalesOpportunityDetails() const {
        cout << "\nSales Opportunity Details for " << name << ":" << endl;
        if (!salesOpportunities.empty()) {
            for (const auto& opportunity : salesOpportunities) {
                opportunity.display();
            }
        } else {
            cout << "No Sales Opportunities Found!!!" << endl;
        }
    }

    void deleteContact(size_t index) {
        if (index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
            cout << "Contact deleted successfully." << endl;
        } else {
            throw out_of_range("Invalid contact index.");
        }
    }

    void deleteSalesOpportunity(size_t index) {
        if (index < salesOpportunities.size()) {
            salesOpportunities.erase(salesOpportunities.begin() + index);
            cout << "Sales opportunity deleted successfully." << endl;
        } else {
            throw out_of_range("Invalid sales opportunity index.");
        }
    }

    void editContact(size_t index, const Contact& newContact) {
        if (index < contacts.size()) {
            contacts[index] = newContact;
            cout << "Contact edited successfully." << endl;
        } else {
            throw out_of_range("Invalid contact index.");
        }
    }

    void editSalesOpportunity(size_t index, const SalesOpportunity& newOpportunity) {
        if (index < salesOpportunities.size()) {
            salesOpportunities[index] = newOpportunity;
            cout << "Sales opportunity edited successfully." << endl;
        } else {
            throw out_of_range("Invalid sales opportunity index.");
        }
    }
};

void deleteContact(Customer& customer);

void deleteSalesOpportunity(Customer& customer);

void editContact(Customer& customer);

void editSalesOpportunity(Customer& customer);

void generateCustomerReports(const vector<Customer>& customers);

void generateSalesReports(const vector<Customer>& customers);

void generateActivityReports(const vector<Customer>& customers);

void login(string& username, string& password) {
    cout << "--------------------------------------------------------------------" << endl;
    cout << "------------------CRM (Client Relation Management)------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "\t\t\t\tMEMBERS:" << endl;
    cout << "\t\tNAME: YAMAAN ULLAH KHAN - FA23-BSCS-0162" << endl;
    cout << "\t\t  NAME: ALISHBA IRFAN - FA23-BSCS-0168" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
}

void displayMenu() {
    cout << "\n--------------------------------------------------------------------" << endl;
    cout << "--------------------------------Menu:-------------------------------" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "1. Add Customer\n2. Add Contact\n3. Add Sales Opportunity\n";
    cout << "4. View Customer Details\n5. View Contact Details\n6. View Sales Opportunity Details\n";
    cout << "7. Generate Customer Reports\n8. Generate Sales Reports\n9. Generate Activity Reports\n";
    cout << "10. Delete Customer\n11. Delete Contact\n12. Delete Sales Opportunity\n";
    cout << "13. Edit Customer\n14. Edit Contact\n15. Edit Sales Opportunity\n16. Exit\n";
}

void deleteCustomer(vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "No customers to delete." << endl;
        return;
    }

    cout << "Select a customer to delete:" << endl;
    for (size_t i = 0; i < customers.size(); ++i) {
        cout << i + 1 << ". " << customers[i].getName() << endl;
    }

    int choice;
    cout << "Enter customer number to delete: ";
    cin >> choice;
    if (choice >= 1 && choice <= customers.size()) {
        customers.erase(customers.begin() + choice - 1);
        cout << "Customer deleted successfully." << endl;
    } else {
        cout << "Invalid customer number." << endl;
    }
}

void deleteContact(Customer& customer) {
    if (customer.getContacts().empty()) {
        cout << "No contacts to delete for this customer." << endl;
        return;
    }

    cout << "Select a contact to delete:" << endl;
    for (size_t i = 0; i < customer.getContacts().size(); ++i) {
        cout << i + 1 << ". " << customer.getContacts()[i].getDate() << ": " << customer.getContacts()[i].getSummary() << endl;
    }

    int choice;
    cout << "Enter contact number to delete: ";
    cin >> choice;
    try {
        if (choice >= 1 && choice <= customer.getContacts().size()) {
            customer.deleteContact(choice - 1);
        } else {
            cout << "Invalid contact number." << endl;
        }
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

void deleteSalesOpportunity(Customer& customer) {
    if (customer.getSalesOpportunities().empty()) {
        cout << "No sales opportunities to delete for this customer." << endl;
        return;
    }

    cout << "Select a sales opportunity to delete:" << endl;
    for (size_t i = 0; i < customer.getSalesOpportunities().size(); ++i) {
        cout << i + 1 << ". " << customer.getSalesOpportunities()[i].getDescription() << endl;
    }

    int choice;
    cout << "Enter sales opportunity number to delete: ";
    cin >> choice;
    try {
        if (choice >= 1 && choice <= customer.getSalesOpportunities().size()) {
            customer.deleteSalesOpportunity(choice - 1);
        } else {
            cout << "Invalid sales opportunity number." << endl;
        }
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

void editCustomer(vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "No customers to edit." << endl;
        return;
    }

    cout << "Select a customer to edit:" << endl;
    for (size_t i = 0; i < customers.size(); ++i) {
        cout << i + 1 << ". " << customers[i].getName() << endl;
    }

    int choice;
    cout << "Enter customer number to edit: ";
    cin >> choice;
    if (choice >= 1 && choice <= customers.size()) {
        string newName, newContactInfo;
        cout << "Enter new name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, newName);
        cout << "Enter new contact info: ";
        getline(cin, newContactInfo);
        customers[choice - 1] = Customer(newName, newContactInfo);
        cout << "Customer edited successfully." << endl;
    } else {
        cout << "Invalid customer number." << endl;
    }
}

void editContact(Customer& customer) {
    if (customer.getContacts().empty()) {
        cout << "No contacts to edit for this customer." << endl;
        return;
    }

    cout << "Select a contact to edit:" << endl;
    for (size_t i = 0; i < customer.getContacts().size(); ++i) {
        cout << i + 1 << ". " << customer.getContacts()[i].getDate() << ": " << customer.getContacts()[i].getSummary() << endl;
    }

    int choice;
    cout << "Enter contact number to edit: ";
    cin >> choice;
    try {
        if (choice >= 1 && choice <= customer.getContacts().size()) {
            string newDate, newSummary;
            cout << "Enter new date: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, newDate);
            cout << "Enter new summary: ";
            getline(cin, newSummary);
            customer.editContact(choice - 1, Contact(newDate, newSummary));
        } else {
            cout << "Invalid contact number." << endl;
        }
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

void editSalesOpportunity(Customer& customer) {
    if (customer.getSalesOpportunities().empty()) {
        cout << "No sales opportunities to edit for this customer." << endl;
        return;
    }

    cout << "Select a sales opportunity to edit:" << endl;
    for (size_t i = 0; i < customer.getSalesOpportunities().size(); ++i) {
        cout << i + 1 << ". " << customer.getSalesOpportunities()[i].getDescription() << endl;
    }

    int choice;
    cout << "Enter sales opportunity number to edit: ";
    cin >> choice;
    try {
        if (choice >= 1 && choice <= customer.getSalesOpportunities().size()) {
            string newDescription, newStage;
            double newValue;
            cout << "Enter new description: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, newDescription);
            cout << "Enter new value: ";
            cin >> newValue;
            cout << "Enter new stage: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, newStage);
            customer.editSalesOpportunity(choice - 1, SalesOpportunity(newDescription, newValue, newStage));
        } else {
            cout << "Invalid sales opportunity number." << endl;
        }
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

void generateCustomerReports(const vector<Customer>& customers) {
    try {
        ofstream outFile("customer_reports.txt");
        if (!outFile) throw runtime_error("Failed to open file for writing.");
        
        for (const auto& customer : customers) {
            outFile << "Customer Name: " << customer.getName() << "\n";
            outFile << "Contact Info: " << customer.contactInfo << "\n";
            outFile << "--------------------------\n";
        }
        cout << "Customer reports generated successfully and saved to customer_reports.txt" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void generateSalesReports(const vector<Customer>& customers) {
    try {
        ofstream outFile("sales_reports.txt");
        if (!outFile) throw runtime_error("Failed to open file for writing.");
        
        for (const auto& customer : customers) {
            outFile << "Customer Name: " << customer.getName() << "\n";
            for (const auto& opportunity : customer.getSalesOpportunities()) {
                outFile << "Description: " << opportunity.getDescription() << "\n";
                outFile << "Value: " << opportunity.getValue() << "\n";
                outFile << "Stage: " << opportunity.getStage() << "\n";
                outFile << "--------------------------\n";
            }
        }
        cout << "Sales reports generated successfully and saved to sales_reports.txt" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void generateActivityReports(const vector<Customer>& customers) {
    try {
        ofstream outFile("activity_reports.txt");
        if (!outFile) throw runtime_error("Failed to open file for writing.");
        
        for (const auto& customer : customers) {
            outFile << "Customer Name: " << customer.getName() << "\n";
            for (const auto& contact : customer.getContacts()) {
                outFile << "Date: " << contact.getDate() << "\n";
                outFile << "Summary: " << contact.getSummary() << "\n";
                outFile << "--------------------------\n";
            }
        }
        cout << "Activity reports generated successfully and saved to activity_reports.txt" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

int main() {
    vector<Customer> customers;
    string username, password;

    login(username, password);

    if (username == "admin" && password == "admin") {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    string name, contactInfo;
                    cout << "Enter customer name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter contact info: ";
                    getline(cin, contactInfo);
                    customers.push_back(Customer(name, contactInfo));
                    break;
                }
                case 2: {
                    if (customers.empty()) {
                        cout << "No customers available. Add a customer first." << endl;
                        break;
                    }
                    
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    string date, summary;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        cout << "Enter contact date: ";
                        cin.ignore();
                        getline(cin, date);
                        cout << "Enter contact summary: ";
                        getline(cin, summary);
                        customers[customerIndex - 1].addContact(Contact(date, summary));
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 3: {
                    if (customers.empty()) {
                        cout << "No customers available. Add a customer first." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    string description, stage;
                    double value;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        cout << "Enter opportunity description: ";
                        cin.ignore();
                        getline(cin, description);
                        cout << "Enter opportunity value: ";
                        cin >> value;
                        cout << "Enter opportunity stage: ";
                        cin.ignore();
                        getline(cin, stage);
                        customers[customerIndex - 1].addSalesOpportunity(SalesOpportunity(description, value, stage));
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 4: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (const auto& customer : customers) {
                        customer.display();
                    }
                    break;
                }
                case 5: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        customers[customerIndex - 1].viewContactDetails();
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 6: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        customers[customerIndex - 1].viewSalesOpportunityDetails();
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 7:
                    generateCustomerReports(customers);
                    break;
                case 8:
                    generateSalesReports(customers);
                    break;
                case 9:
                    generateActivityReports(customers);
                    break;
                case 10:
                    deleteCustomer(customers);
                    break;
                case 11: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        deleteContact(customers[customerIndex - 1]);
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 12: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        deleteSalesOpportunity(customers[customerIndex - 1]);
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 13:
                    editCustomer(customers);
                    break;
                case 14: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        editContact(customers[customerIndex - 1]);
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 15: {
                    if (customers.empty()) {
                        cout << "No customers available." << endl;
                        break;
                    }
                    for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                    int customerIndex;
                    cout << "Enter customer number: ";
                    cin >> customerIndex;
                    if (customerIndex >= 1 && customerIndex <= customers.size()) {
                        editSalesOpportunity(customers[customerIndex - 1]);
                    } else {
                        cout << "Invalid customer number." << endl;
                    }
                    break;
                }
                case 16:
                    cout << "Exiting the program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 16);
    } else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}
