#include <iostream>
#include <vector> 
#include <string>
#include <iomanip> 
#include <fstream>

using namespace std;

void generateCustomerReports(const vector<Customer>& customers);

class Contact {
private:
    string date;
    string summary;
public:
    Contact(string d, string s) {
		date = d;
		summary = s;
	}

    string getDate() const {
        return date;
    }

    string getSummary() const {
        return summary;
    }

    void display() const {
        cout << "Date: " << date << ", Summary: " << summary << endl;
    }
};

class SalesOpportunity {
private:
    string description;
    double value;
    string stage;
public:
    SalesOpportunity(string desc, double val, string st){
		description = desc;
		value = val;
		stage = st;
		
	}

    string getDescription() const {
        return description;
    }

    double getValue() const {
        return value;
    }

    void display() const {
        cout << "Description: " << description << ", Value: " << value << ", Stage: " << stage << endl;
    }
};

class Customer {
private:
    string name;
    string contactInfo;
    vector<Contact> contacts;
    vector<SalesOpportunity> salesOpportunities;
    
    friend void generateCustomerReports(const vector<Customer>& customers);
public:
    Customer(string n, string info){
		name = n;
		contactInfo = info;
	}

    string getName() const {
        return name;
    }

    vector<Contact>& getContacts() {
        return contacts;
    }

    const vector<SalesOpportunity>& getSalesOpportunities() const {
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
        if(!contacts.empty()){
		    for (size_t i = 0; i < contacts.size(); ++i) {
		        contacts[i].display();
		    }	
		}else{
			cout<<"No Contact Information Found!!!";
		}
        
    }

    void viewSalesOpportunityDetails() const {
        cout << "\nSales Opportunity Details for " << name << ":" << endl;
        if(!salesOpportunities.empty()){
		    for (size_t i = 0; i < salesOpportunities.size(); ++i) {
            salesOpportunities[i].display();
        	}	
		}else{
			cout<<"No Sales Opportunities Found!!!";
		}
		
    }

    void deleteContact(size_t index) {
        if (index >= 0 && index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
            cout << "Contact deleted successfully." << endl;
        } else {
            cout << "Invalid contact index." << endl;
        }
    }

    void deleteSalesOpportunity(size_t index) {
        if (index >= 0 && index < salesOpportunities.size()) {
            salesOpportunities.erase(salesOpportunities.begin() + index);
            cout << "Sales opportunity deleted successfully." << endl;
        } else {
            cout << "Invalid sales opportunity index." << endl;
        }
    }
	
	void editContact(size_t index, const Contact& newContact) {
        if (index >= 0 && index < contacts.size()) {
            contacts[index] = newContact;
            cout << "Contact edited successfully." << endl;
        } else {
            cout << "Invalid contact index." << endl;
        }
    }
	
	void editSalesOpportunity(size_t index, const SalesOpportunity& newOpportunity) {
        if (index >= 0 && index < salesOpportunities.size()) {
            salesOpportunities[index] = newOpportunity;
            cout << "Sales opportunity edited successfully." << endl;
        } else {
            cout << "Invalid sales opportunity index." << endl;
        }
    }
};

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
    if (choice >= 1 && choice <= customer.getContacts().size()) {
        customer.deleteContact(choice - 1);
    } else {
        cout << "Invalid contact number." << endl;
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
    if (choice >= 1 && choice <= customer.getSalesOpportunities().size()) {
        customer.deleteSalesOpportunity(choice - 1);
    } else {
        cout << "Invalid sales opportunity number." << endl;
    }
}

void editCustomer(vector<Customer>& customers) {
    cout << "Select a customer to edit:" << endl;
    int index;
    if(!customers.empty()){
    	for (size_t i = 0; i < customers.size(); ++i) {
	        cout << i + 1 << ". " << customers[i].getName() << endl;
	    }	
	}else{
		cout<<"No Customer Found!!!";
		return;
	}
	
    cout << "Enter customer number: ";
    cin >> index;
    if (index >= 1 && index <= customers.size()) {
        string newName, newContactInfo;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        cout << "Enter new contact information: ";
        getline(cin, newContactInfo);
        customers[index - 1] = Customer(newName, newContactInfo);
        cout << "Customer edited successfully." << endl;
    } else {
        cout << "Invalid customer number." << endl;
    }
}

void editContact(Customer& customer) {
    cout << "Select a contact to edit:" << endl;
    if(!customer.getContacts().empty()){
	    for (size_t i = 0; i < customer.getContacts().size(); ++i) {
	        cout << i + 1 << ". " << customer.getContacts()[i].getDate() << ": " << customer.getContacts()[i].getSummary() << endl;
	    }
	}else{
		cout<<"No Contact Details Found!!!";
		return;
	}
    int choice;
    cout << "Enter contact number to edit: ";
    cin >> choice;
    
    	if (choice >= 1 && choice <= customer.getContacts().size()) {
	        string newDate, newSummary;
	        cout << "Enter new date: ";
	        cin.ignore();
	        getline(cin, newDate);
	        cout << "Enter new summary: ";
	        getline(cin, newSummary);
	        customer.editContact(choice - 1, Contact(newDate, newSummary));
	    } else {
	        cout << "Invalid contact number." << endl;
	    }
	
	    
}

void editSalesOpportunity(Customer& customer) {
    cout << "Select a sales opportunity to edit:" << endl;
    if(!customer.getSalesOpportunities().empty()){
	    for (size_t i = 0; i < customer.getSalesOpportunities().size(); ++i) {
	        cout << i + 1 << ". " << customer.getSalesOpportunities()[i].getDescription() << endl;
	    }
	}else{
		cout<<"No Sales Opportunity Found!!!";
		return;
	}
    int choice;
    cout << "Enter sales opportunity number to edit: ";
    cin >> choice;
    if (choice >= 1 && choice <= customer.getSalesOpportunities().size()) {
        string newDescription, newStage;
        double newValue;
        cout << "Enter new description: ";
        cin.ignore();
        getline(cin, newDescription);
        cout << "Enter new value: ";
        cin >> newValue;
        cout << "Enter new stage: ";
        cin.ignore();
        getline(cin, newStage);
        customer.editSalesOpportunity(choice - 1, SalesOpportunity(newDescription, newValue, newStage));
    } else {
        cout << "Invalid sales opportunity number." << endl;
    }
}


// apko is pr kaam krna hai ab file handling wala
void generateCustomerReports(const vector<Customer>& customers) {
    cout << "\nCustomer Reports:" << endl;
    for (size_t i = 0; i < customers.size(); ++i) { //size vector ka builtin function hai ok
        customers[i].display();
        customers[i].viewContactDetails();
        customers[i].viewSalesOpportunityDetails();
        cout << endl;
    } // is jga tm file handle or data insert karo gi file mai same goes to nichy wali filyyyyy sory fucntionsss do jo hain sirf ok ab bndh krdo ya jo smjh nhi aya vo pucholoooo 
}

void generateSalesReports(const vector<Customer>& customers) {
    double totalSales = 0.0;
    cout << "\nSales Reports:" << endl;
    for (size_t i = 0; i < customers.size(); ++i) {
        const vector<SalesOpportunity>& opportunities = customers[i].getSalesOpportunities();
        for (size_t j = 0; j < opportunities.size(); ++j) {
            totalSales += opportunities[j].getValue();
        }
    }
    cout << "Total Sales: $" << fixed << setprecision(2) << totalSales << endl;
}

void generateActivityReports(const vector<Customer>& customers) {
    cout << "\nActivity Reports:" << endl;
    cout << "No activity data available." << endl;
}

// in teen fucntions pr jismy sy ( generateCustomerReports) ka friend fucntion bny ga customer ki class mai or sales ka sale ki class mai or contact ka contact ki class ab ye 


void login(string& username, string& password) {
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"------------------CRM (Client Relation Managemnet)------------------"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tMEMBERS:"<<endl;
    cout<<"\t\tNAME:YAMAAN ULLAH KHAN - FA23-BSCS-0162"<<endl;
    cout<<"\t\t  NAME:ALISHBA IRFAN - FA23-BSCS-0168"<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
    
	cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
}

void displayMenu() {
	cout<<""<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
    cout << "--------------------------------Menu:-------------------------------" << endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout << "1. Add Customer\n2. Add Contact\n3. Add Sales Opportunity\n";
    cout << "4. View Customer Details\n5. View Contact Details\n6. View Sales Opportunity Details\n";
    cout << "7. Generate Customer Reports\n8. Generate Sales Reports\n9. Generate Activity Reports\n";
    cout << "10. Delete Customer\n11. Delete Contact\n12. Delete Sales Opportunity\n";
    cout << "13. Edit Customer\n14. Edit Contact\n15. Edit Sales Opportunity\n16. Exit\n";
}

int main() {
    string username, password;
    login(username, password);
    if (username != "admin" || password != "admin") {
        cout << "Invalid username or password. Exiting..." << endl;
        return 1;
    }else{
    	cout<<"\n-Account Logged in Successfully!!!"<<endl;
	}

    vector<Customer> customers;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, contactInfo;
                cout<<"--------------------------------------------------------------------"<<endl;
				cout<<"Enter customer name:";
                cin.ignore();
                getline(cin, name);
                cout << "Enter contact information: ";
                getline(cin, contactInfo);
                customers.push_back(Customer(name, contactInfo));
                break;
            }
           case 2: {
			    cout << "Select a customer to add a contact:" << endl;
			    int index;
			    if(!customers.empty()){
				    for (size_t i = 0; i < customers.size(); ++i) {			    	
						cout << i + 1 << ". " << customers[i].getName() << endl;
				    }
			    }else{
			    	cout<<"No Customer Found Please Add Customer";
						break;
					}
			    cout << "Enter customer number: ";
			    cin >> index;
			    if (index >= 1 && index <= customers.size()) {
			        string date, summary;
			        cout << "Enter contact date: ";
			        cin.ignore();
			        getline(cin, date);
			        cout << "Enter contact summary: ";
			        getline(cin, summary);
			        customers[index - 1].addContact(Contact(date, summary));
			        cout << "Contact added successfully." << endl;
			    } else {
			        cout << "Invalid customer number." << endl;
			    }
			    break;
			}
            case 3: {
			    cout << "Select a customer to add a sales opportunity:" << endl;
			    int index;
			    if(!customers.empty()){
				    for (size_t i = 0; i < customers.size(); ++i) {
				        cout << i + 1 << ". " << customers[i].getName() << endl;
				    }
				}else{
					cout<<"No Customer Found Please Add Customer";
					break;
				}
			    cout << "Enter customer number: ";
			    cin >> index;
			    if (index >= 1 && index <= customers.size()) {
			        string description, stage;
			        double value;
			        cout << "Enter sales opportunity description: ";
			        cin.ignore();
			        getline(cin, description);
			        cout << "Enter sales opportunity value: ";
			        cin >> value;
			        cout << "Enter sales opportunity stage: ";
			        cin.ignore();
			        getline(cin, stage);
			        customers[index - 1].addSalesOpportunity(SalesOpportunity(description, value, stage));
			        cout << "Sales opportunity added successfully." << endl;
			    } else {
			        cout << "Invalid customer number." << endl;
			    }
			    break;
			}

            case 4: {
                cout << "\nCustomer Details:" << endl;
                if(!customers.empty()){
                	for (size_t i = 0; i < customers.size(); ++i) {
	                    customers[i].display();
	                }
				}else{
					cout<<"No Customer Found!!!";
				}
	                
                break;
            }
            case 5: {
            	cout << "Select a customer to view contact details:" << endl;
				int index;
            	if(!customers.empty()){
            		
				    for (size_t i = 0; i < customers.size(); ++i) {
				        cout << i + 1 << ". " << customers[i].getName() << endl;
				    }
				}else{
					cout<<"No Customer Found!!!";
					break;
				}
				    
			    cout << "Enter customer number: ";
			    cin >> index;
			    if (index >= 1 && index <= customers.size()) {
			        customers[index - 1].viewContactDetails();
			    } else {
			        cout << "Invalid customer number." << endl;
			    }
			    break;
			}

            case 6: {
			    cout << "Select a customer to view sales opportunity details:" << endl;
			    int index;
			    if(!customers.empty()){
				    for (size_t i = 0; i < customers.size(); ++i) {
				        cout << i + 1 << ". " << customers[i].getName() << endl;
				    }
				}else{
					cout<<"No Customer Found!!!";
					break;
				}
			    cout << "Enter customer number: ";
			    cin >> index;
			    if (index >= 1 && index <= customers.size()) {
			        customers[index - 1].viewSalesOpportunityDetails();
			    } else {
			        cout << "Invalid customer number." << endl;
			    }
			    break;
			}

            case 7: {
                generateCustomerReports(customers);
                break;
            }
            case 8: {
                generateSalesReports(customers);
                break;
            }
            case 9: {
                generateActivityReports(customers);
                break;
            }
            case 10: {
                deleteCustomer(customers);
                break;
            }
            case 11: {
                cout << "Select a customer to delete contact:" << endl;
                int index;
                for (size_t i = 0; i < customers.size(); ++i) {
                    cout << i + 1 << ". " << customers[i].getName() << endl;
                }
                cout << "Enter customer number: ";
                cin >> index;
                if (index >= 1 && index <= customers.size()) {
                    deleteContact(customers[index - 1]);
                } else {
                    cout << "Invalid customer number." << endl;
                }
                break;
            }
            case 12: {
                cout << "Select a customer to delete sales opportunity:" << endl;
                int index;
                for (size_t i = 0; i < customers.size(); ++i) {
                    cout << i + 1 << ". " << customers[i].getName() << endl;
                }
                cout << "Enter customer number: ";
                cin >> index;
                if (index >= 1 && index <= customers.size()) {
                    deleteSalesOpportunity(customers[index - 1]);
                } else {
                    cout << "Invalid customer number." << endl;
                }
                break;
            }
            case 13: {
                editCustomer(customers);
                break;
            }case 14: {
                cout << "Select a customer to edit contact:" << endl;
                int index;
				if(!customers.empty()){
					for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
				}else{
					cout<<"No Customer Found!!!";
					break;
				}
	                
                cout << "Enter customer number: ";
                cin >> index;
                if (index >= 1 && index <= customers.size()) {
                    editContact(customers[index - 1]);
                } else {
                    cout << "Invalid customer number." << endl;
                }
                break;
            }
            case 15: {
                cout << "Select a customer to edit sales opportunity:" << endl;
                int index;
                if(!customers.empty()){
	                for (size_t i = 0; i < customers.size(); ++i) {
	                    cout << i + 1 << ". " << customers[i].getName() << endl;
	                }
                }else{
					cout<<"No Customer Found!!!";
					break;
				}
                cout << "Enter customer number: ";
                cin >> index;
                if (index >= 1 && index <= customers.size()) {
                    editSalesOpportunity(customers[index - 1]);
                } else {
                    cout << "Invalid customer number." << endl;
                }
                break;
            }
            case 16: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 16);

    return 0;
}
