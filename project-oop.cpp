#include<iostream>
#include <fstream>
using namespace std;

class management{
	virtual void car_booking() =0;   //abstract
	
};

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
			
			cout<<"\t\t\tID = " ;
			cin>> user_ID;
			
			cout<<"\t\t\tPhone Number = " ;
			cin>>user_cell_number;
			
			cout<<"\t\t\tGender (m/f) = " ;
			cin>>gender;
			
			cout<<"\t\t\tNew Password = " ;
			cin>>user_pass;
			
			cout<<"\t\t\tConfirm Password = ";
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
	    car_booking();
	void login_info(){
    
   string ch ; 
   cout <<"\n\n\n\n\t\t\t\t\t****  Car Rental System  ****";
   cout <<" \n\t\t\t\t\t\t                          BY MOHAMMAD AHMED FA22-BSCS-0194 ";
   cout <<" \n\t\t\t\t\t\t                                BY NOOR FATIMA FA22-BSCS-0186   ";
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

class BOOKING :  public LOGIN_PAGE{
	private:
	friend void car_rental()             // friend function
	{
	} 
	public:
	
	string customer_name;
	string location;
	string Booking_date;
	double customer_phone_number;
	long CNIC;
	string car_type;
	string car_model;
	int days;
	double price;
	string carn;
	string carnumber;
	
	
	 public:
	LOGIN_PAGE p2; 	//association
	login_info();
	
	 	void BOOKING_data(){
	   cout<<"\t\t\t\t\t----------------------------------------\n";
       cout<<"\t\t\t\t\tPlease Provide Your Personal Details  : \n";
       cout<<"\t\t\t\t\t----------------------------------------\n\n";
       
	 		cout<<"\t\t\tCustomer Name = ";
	 		cin>>customer_name;

	 		cout<<"\t\t\tEnter Current Location =" ;
	 		cin>>location;										 	

	 		cout<<"\t\t\tPhone Number = " ;
	 		cin>>customer_phone_number;

	 		cout<<"\t\t\tBooking Date (dd/mm/yy) = " ;
	 		cin>>Booking_date;

	 		cout<<"\t\t\tEnter CNIC = " ;
	 		cin>>CNIC;

	 		cout<<"\t\t\tCar Model = " ;
			cin>>car_model;

			cout<<"\t\t\tCar Type =  " ;
			cin>>car_type;

			cout<<"\t\t\tTotal Number of Booking Days = " ;
			cin>>days;
			system("PAUSE");
			system("CLS") ; 

			
		} 
       
		void car_booking(){
			
		                   //file
			fstream fout;
			fout.open("CAR_BOOKING.TXT",ios::app);
			
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tLIST OF THE CARS \n";
				cout<<"\t\t\t----------------------------------------\n";			
				cout<<"\t\t\tCAR_NAME\t\t\tCAR_PRICE_PERDAY\t "<<endl;
				cout<<"\t\t\t1-ALTO\t\t\t\t5000"	<<endl;
				cout<<"\t\t\t2-KIA\t\t\t\t10000"	<<endl;
				cout<<"\t\t\t3-CORROLLA\t\t\t12000"		<<endl;
				cout<<"\t\t\t4-HONDA CITY\t\t\t7000"		<<endl;
				cout<<"\t\t\t5-FORTUNER\t\t\t15000"		<<endl;
				cout<<"\t\t\t6-REVO\t\t\t\t15000"	<<endl;
				cout<<"\t\t\t7-CIVIC\t\t\t\t11000"	<<endl;
				cout<<"\t\t\t8-LIANA\t\t\t\t8000"	<<endl;
				cout<<"\n\t\t\tPLEASE ENTER THE NUMBER OF CAR YOU WANT TO SELECT = "; 
			
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tLIST OF THE CARS \n";
				fout<<"\t\t\t----------------------------------------\n";			
				fout<<"\t\t\tCAR_NAME\t\t\tCAR_PRICE_PERDAY\t "<<endl;
				fout<<"\t\t\t1-ALTO\t\t\t5000"	<<endl;
				fout<<"\t\t\t2-KIA\t\t\t10000"	<<endl;
				fout<<"\t\t\t3-CORROLLA\t\t\t12000"		<<endl;
				fout<<"\t\t\t4-HONDA CITY\t\t\t7000"		<<endl;
				fout<<"\t\t\t5-FORTUNER\t\t\t15000"		<<endl;
				fout<<"\t\t\t6-REVO\t\t\t15000"	<<endl;
				fout<<"\t\t\t7-CIVIC\t\t\t11000"	<<endl;
				fout<<"\t\t\t8-LIANA\t\t\t8000"	<<endl;
				fout<<"\n\t\t\tPLEASE ENTER THE NUMBER OF CAR YOU WANT TO SELECT = "; 
			
			int choice;
			cin>>choice;
			
			
			switch(choice){
	
				case 1:
					price=5000;					
					carnumber="BG874";	
					price=price*days;
					carn="ALTO";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n";
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				fout<<"\t\t\t----------------------------------------\n";
						break;
						
					case 2:
						price=10000;
						carnumber="CG834";
						price=price*days;					
					carn="KIA";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n";
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				fout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t----------------------------------------\n";
						break;
						
						case 3:
							carnumber="DG8124";
							price=12000;				
							price=price*days;	
					carn="COROLLA";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				fout<<"\t\t\t----------------------------------------\n";
							break;
							
							case 4:
								carnumber="AF774";
								price=7000;	
								price=price*days;				
				carn="HONDA CITY";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				fout<<"\t\t\t----------------------------------------\n";
								break;
									
								case 5:
									carnumber="B7C74";
									price=15000;			
									price=price*days;		
					carn="FORTUNER";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				fout<<"\t\t\t----------------------------------------\n";
									break;
										
									case 6:
										carnumber="AFG874";
										price=15000;			
										price=price*days;		
					carn="HILUX REVO ";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t----------------------------------------\n";
										break;
												
										case 7:
											carnumber="GF278";
											price=11000;
											price=price*days;					
					carn="HONDA CIVIC 1.6V-TEC";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t----------------------------------------\n";
											break;			
										
											case 8:
								 				carnumber="JH374";
												price=8000;					
					carn="LIANA";
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n" ;
				cout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				cout<<"\t\t\t\tCAR NAME = "<<carn<<endl;
				cout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t----------------------------------------\n";
				fout<<"\t\t\t\tCONGRATS YOUR CAR IS BOOKED!\n"<<carn;
				fout<<"\t\t\t\tTOTAL PRICE = "<<price<<endl;
				fout<<"\t\t\t----------------------------------------\n";
												break;
			}
			
			fout.close();
			
		}


			void Recept(){
				cout<<"\t[RECIEPT DETAIL]"			   <<endl;
				cout<<"your car pickup location is\t " <<location<<endl;
				cout<<"your booking  date is  \t"      <<Booking_date<<endl;
				cout<<"car type is  \t"				   <<car_type<<endl;
				cout<<"car model is \t"				   <<car_model<<endl;
				cout<<"car price is \t"				   <<price<<endl;
				cout<<"you booked car in \t"		   <<days<<"days"<<endl;
			}
};

void car_rental(BOOKING b1){ //association
	fstream fout;
		fout.open("RENTAL CAR.txt",ios::app);
	cout<<"\nloading up files....."<<endl;
	 //function which waits for (n) seconds
	
	cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
	cout << "\t\t	///////////////////////////////////////////////////////////"	<<endl;
	cout << "\t\t	| Invoice No. :"<<"------------------|"<<"#Cnb81353"<<" |"		<<endl;
	cout << "\t\t	| Customer Name:"<<"-----------------|"<<b1.customer_name<<" |"	<<endl;
	cout << "\t\t	| Car Model :"<<"--------------------|"<<b1.car_model<<" |"		<<endl;
	cout << "\t\t	| Car No. :"<<"----------------------|"<<b1.carnumber<<" |"		<<endl;
	cout << "\t\t	| Number of days :"<<"---------------|"<<b1.days<<" |"				<<endl;
	cout << "\t\t	| booking  date  :"<<"---------------|"<<b1.Booking_date<<" |"		<<endl;
	cout << "\t\t	| Your Rental Amount is :"<<"--------|"<<b1.price<<" |"			<<endl;
	cout << "\t\t	| Caution Money :"<<"----------------|"<<"0"<<" |"				<<endl;
	cout << "\t\t	| Advanced :"<<"---------------------|"<<"0"<<" |"				<<endl;
	cout << "\t\t	 ____________________"		<<endl;
	cout <<"\n";
	cout << "\t\t	| Total Rental Amount is :"<<"-------|"<<b1.price*0.10<<" |"		<<endl;
	cout << "\t\t	 ____________________"		<<endl;
	cout << "\t\t	 # This is a computer generated invoce and it does not"			<<endl;
	cout << "\t\t	 require an authorised signture #"<<endl;
	cout <<"  "<<endl;
	cout << "\t\t	///////////////////////////////////////////////////////////"	<<endl;
	cout << "\t\t	You are advised to pay up the amount before due date."			<<endl;
	cout << "\t\t	Otherwise penelty fee will be applied"							<<endl;
	cout << "\t\t	///////////////////////////////////////////////////////////"	<<endl;
	
	
	fout<<"\nloading up files....."<<endl;
	
	fout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
	fout << "\t\t	///////////////////////////////////////////////////////////"	<<endl;
	fout << "\t\t	| Invoice No. :"<<"------------------|"<<"#Cnb81353"<<" |"		<<endl;
	fout << "\t\t	| Customer Name:"<<"-----------------|"<<b1.customer_name<<" |"	<<endl;
	fout << "\t\t	| Car Model :"<<"--------------------|"<<b1.car_model<<" |"		<<endl;
	fout << "\t\t	| Car No. :"<<"----------------------|"<<b1.carnumber<<" |"		<<endl;
	fout << "\t\t	| Number of days :"<<"---------------|"<<b1.days<<" |"				<<endl;
	fout << "\t\t	| booking  date  :"<<"---------------|"<<b1.Booking_date<<" |"		<<endl;
	fout << "\t\t	| Your Rental Amount is :"<<"--------|"<<b1.price<<" |"			<<endl;
	fout << "\t\t	| Caution Money :"<<"----------------|"<<"0"<<" |"				<<endl;
	fout << "\t\t	| Advanced :"<<"---------------------|"<<"0"<<" |"				<<endl;
	fout << "\t\t	 ____________________"		<<endl;
	fout <<"\n";
	fout << "\t\t	| Total Rental Amount is :"<<"-------|"<<b1.price*0.10<<" |"		<<endl;
	fout << "\t\t	 ____________________"		<<endl;
	fout << "\t\t	 # This is a computer generated invoce and it does not"			<<endl;
	fout << "\t\t	 require an authorised signture #"<<endl;
	fout <<"  "<<endl;
	fout << "\t\t	///////////////////////////////////////////////////////////"	<<endl;
	fout << "\t\t	You are advised to pay up the amount before due date."			<<endl;
	fout << "\t\t	Otherwise penelty fee will be applied"							<<endl;
	fout << "\t\t	///////////////////////////////////////////////////////////"	<<endl;
	fout.close();
}
 
int main(){

	REGISTRATION r1;
	LOGIN_PAGE l1;
	BOOKING B1;
	
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
				cout<<"\n\n\n\n\n\n\n\n\t\t\tENTER 1 FOR BOOKING CARS OR ANY NUMBER FOR LIST OF AVAILABLE CARS ";
				cout<<"\n\n\n\t\t\t\t\tENTER = " ; 
				cin>>choice;
				system("PAUSE") ; 
				system("CLS") ;
				if(choice==1){
					B1.BOOKING_data();
					B1.car_booking();
				}
	
				else{
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tLIST OF THE CARS \n";
				cout<<"\t\t\t----------------------------------------\n";			
				cout<<"CAR_NAME\t CAR_PRICE_PERDAY\t "<<endl;
				cout<<"ALTO \t         5000"	<<endl;
				cout<<"KIA \t         10000"	<<endl;
				cout<<"CORROLLA\t 12000"		<<endl;
				cout<<"HONDA CITY\t 7000"		<<endl;
				cout<<"FORTUNER\t 15000"		<<endl;
				cout<<"REVO \t         15000"	<<endl;
				cout<<"CIVIC\t         11000"	<<endl;
				cout<<"LIANA \t         8000"	<<endl;
				cout<<"\t\t\tDo you want to book car if yes press y/n = ";
				cin>>select;
				if(select=='y'||'Y'){
					B1.BOOKING_data();
					B1.car_booking();
				cout<<"\t\t\tDo you want Reciept (y/n) = " ;
					cin>>select;
					if(select=='y'||'Y'){
					car_rental(B1); //association
					}
					
				}
				
				
				

	
			else{
					cout<<"program closed "<<endl;
				}
			break;
			}
		
		 case 2:
			l1.login_info();
			cout<<"\n\n\n\n\n\n\n\n\t\t\tENTER 1 FOR BOOKING CARS OR ANY NUMBER FOR LIST OF AVAILABLE CARS ";
				cout<<"\n\n\n\t\t\t\t\tENTER = " ; 
				cin>>choice;
				system("PAUSE") ; 
				system("CLS") ;
				if(choice==1){
					B1.BOOKING_data();
					B1.car_booking();	
				}				
		
				else{
				cout<<"\t\t\t----------------------------------------\n";
				cout<<"\t\t\t\tLIST OF THE CARS \n";
				cout<<"\t\t\t----------------------------------------\n";			
				cout<<"\t\t\tCAR_NAME\t \t\t\tCAR_PRICE_PERDAY\t "<<endl;
				cout<<"\t\t\tALTO \t         5000"	<<endl;
				cout<<"\t\t\tKIA \t         10000"	<<endl;
				cout<<"\t\t\tCORROLLA\t 12000"		<<endl;
				cout<<"\t\t\tHONDA CITY\t 7000"		<<endl;
				cout<<"\t\t\tFORTUNER\t 15000"		<<endl;
				cout<<"\t\t\tREVO \t         15000"	<<endl;
				cout<<"\t\t\tCIVIC\t         11000"	<<endl;
				cout<<"\t\t\tLIANA \t         8000"	<<endl;
				cout<<"\n\t\t\tDo you want to book car if yes press y/n = ";
				cin>>select;
				if(select=='y'||'Y'){
					B1.BOOKING_data();
					B1.car_booking();
				cout<<"\t\t\tDo you want Reciept (y/n) = " ;
					cin>>select;
					if(select=='y'||'Y'){
					car_rental(B1);
					}
					else{
						cout<<"thank you for booking rental car"<<endl;
					}
				
				}
				else{
					cout<<"thank you for visit the car rental systam"<<endl;
				}		
	}
}
}
