#include<iostream>
#include <fstream>
using namespace std;


class REGISTRATION{
	private:
		
		string user_name;
		double user_cell_number;
		string user_pass;
		string gender;
       
		public:
	   
		string user_ID;
		string confirm_pass;

		void registration_info(){
			
			cout<<"\t\t\t----------------------------------------\n";
       		cout<<"\t\t\t\tREGISTRATION   INFO   \n";
       		cout<<"\t\t\t----------------------------------------\n\n";

			cout<<"\t\t\tName = " ;
			cin>>user_name;
			
			cout<<endl<<"\t\t\tID = " ;
			cin>> user_ID;
			
			cout<<endl<<"\t\t\tPhone Number = " ;
			cin>>user_cell_number;
			
			cout<<endl<<"\t\t\tGender (m/f) = " ;
			cin>>gender;
			
			cout<<endl<<"\t\t\tNew Password = " ;
			cin>>user_pass;
			
			cout<<endl<<"\t\t\tConfirm Password = ";
			cin>>confirm_pass;
			
			
			if(user_pass==confirm_pass){				 
				cout<<"\n\n\t\t\tYOUR REGISTERATION HAS BEEN CONFIRMED!"<<endl;
				cout<<"\t\t\t   THANKYOU FOR REGISTRATION"<<endl;
			system("PAUSE");
			}

			else {
				cout<<"\t\t\tINVALID PASSWORD RETRY!"<<endl;
				registration_info();
			system("PAUSE");	 				
			}
		}	
		
};


class LOGIN_PAGE : public REGISTRATION{
	private:
		string 	user_password="maju";
	public:
		REGISTRATION b1; //association
	    registration_info();
	    
	void login_info(){
    
   string ch ; 
   cout <<"\n\n\n\n\t\t\t\t\t****  Car Rental System  ****";
   cout <<" \n\t\t\t\t\t\t                          BY YAMAAN ULLAH KHAN FA23-BSCS-0162 ";
   cout <<" \n\t\t\t\t\t\t                                BY ALISHBA IRFAN FA23-BSCS-0168   ";
   cout<<"   \n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ** LOGIN *** ";
   cout << "\n\t\t\t\t\t\tEnter Password: ";
   
   cin>>ch ;
   user_password = ch  ; 
    if(user_password== "maju"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      system("CLS");
}
	else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login_info();
   }
}
};





int main(){
	REGISTRATION r1;
	LOGIN_PAGE l1;
	
	
	cout<<"\t\t\t||-----------------------------------------------------------||"<<endl;
	cout<<"\t\t\t||-----------[WELCOME TO CAR RENTAL MANAGEMENT]--------------||"<<endl;
	cout<<"\t\t\t||-----------------------------------------------------------||"<<endl;
	cout<<"\t\t\tPRESS 1 FOR REGISTRATION  \t  PRESS 2 FOR LOGIN"<<endl;
	int choice;
	char select;
    cout<<"\n\n\t\t\t\t\t\t ENTER = ";
	cin>>choice;
	system("CLS");
	
	
	switch (choice){
		case 1:
			r1.registration_info();
			system("CLS");
				cout<<"\n\n\n\n\t\t\tPRESS y/Y TO CONTINUE OR PRESS  n/N TO CLOSE PROGRAM " ;
				cout<<"\n\n\t\t\t\tENTER = ";
				cin>>select;
				system("PAUSE") ; 
				system("CLS") ;
				
				if(select=='y' || select=='Y'){
					l1.login_info();
				}
				
				if(select=='n'||select=='N'){
					cout<<"\t\t\tTHANK YOU! :) \n\n\t YOU ARE BEING REDIRECTED TO THE LOGIN PAGE.. "<<endl;
						l1.login_info();
				}
				
		case 2:
			l1.login_info();
			cout<<"\n\n\n\n\n\n\n\n\t\t\tENTER 1 FOR BOOKING CARS OR ANY NUMBER FOR LIST OF AVAILABLE CARS ";
				cout<<"\n\n\n\t\t\t\t\tENTER = " ; 
				cin>>choice;
				system("PAUSE") ; 
				system("CLS") ;
	}
}
























