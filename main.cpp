#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


//Function prototypes
void showRoomMenu();  
void getChoice(int &);
int roomcharges(int typeRoom, int patients_num, int Duration_Stay[]);
void showFoodMenu();
double foodcharges(double FoodSet,int patients_num, int DaysOfOrder[]);
void surgeryMenu();
void getChoiceSurgery(int &);
void showMedicationMenu();
double Medication_Rate(int);
void showServiceMenu();

// main function
int main()
{
    cout << "\t\t\t\t-----------------------------------------------"<< endl;
    cout << "\t\t\t\t     THOMAS MEDICAL CENTER ADMINISTRATION " 	 << endl;
    cout << "\t\t\t\t           Press 'ENTER' to proceed "       	 << endl;
    cout << "\t\t\t\t-----------------------------------------------"<< endl;
    cout << endl;
    cout << endl;
    
    getchar();
    //variable declaratiom
    const int perDay_single = 1500, perDay_double = 800, perDay_four = 500, perDay_genWard = 300;

    double total_bill,medication_price,service_price,avg_days,sum=0.0, sum_room=0.0, sum_food=0.0, sum_surgery=0.0;

	double sum_medication = 0.0, sum_service =0.0,sum_days=0.0; 

    int choice, choice_food,choice_surgery,choice_medication, medication, choice_services, services_code;

	int hours,frequency_xray,frequency_MRI,number,patients, RoomChoice, highest, lowest; 
    
    const double price_Set1 = 30.99,  price_Set2 = 40.99 , price_Set3 = 50.99;

    const int price_Appen = 10000, price_Caesa = 13000, 
	        price_Mas = 25000, price_Part = 40000, 
		    price_Ton = 15000, price_Catar = 16000, price_NoSurgery = 0;

    const double price_Metformin = 35.80, price_Amlodipine = 22.80,
			 price_Metoprolol = 78.90, price_Omeprazole = 40.00,
			 price_Losartan = 45.60,  price_Focalin = 46.40;

    const double price_Urine = 90.00, price_Blood = 110.00,
			 price_PhysioPerHour = 120.00, price_XrayF1 = 150.00,
			 price_XrayF2 = 190.00, price_MriF1 = 3000.00,price_MriF2 = 4000.00;

    cout << "\tEnter the number of patients admitted : " ;
    cin >> patients; //Get number of patients admitted
	cout << endl;

	//array declaration
    int charges[patients];
	double Total_bill[patients];
	double total_room_charges[patients];
	double total_food_charges[patients];
	double surgery_charges[patients];
	double service_rate[patients];
	double medication_rate[patients];
	string name[patients];
    int days[patients];

    for(int i=0; i<patients ;i++)
    {
        //Hospital admin enters of the patient
        cout << "\tEnter the name of patient " << (i+1) << " : " ;
        cin.ignore();
        getline(cin,name[i]); //Get the name of the patient 
        cout << endl;
        showRoomMenu();// call showRoomMenu
        getChoice(choice);// Get a choice and store it in a value
        

    if (choice == 1)//if choice = 1, display single room price according to the days 
    {
	cout << "\tRoom Charges = " << perDay_single << " per day" << endl;
	cout << endl;
	cout << "\tDuration of stay (in days). Enter 0 if no rooms taken. = " ;
    cin >> days[i]; //get the number of days
	// Call the roomcharges function, passing the contents of perDay_single and days as arguments
	// Assign the return value to total_room_charges variable
	total_room_charges[i] = roomcharges(perDay_single,patients,days); 
	cout << "\tTotal Room Charges : " << total_room_charges[i] << endl; //display the total room charges
	cout << endl;
	showFoodMenu(); //call showFoodMenu
	cout << "\tEnter food set number : " ; 
    cin >> choice_food; //get the meal set number
			if (choice_food==1)
			{
				cout << "\tFood charges : " << price_Set1 << endl;
				// Call the foodcharges function, passing the contents of price_Set1 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set1,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;
				
			}
			else if(choice_food==2)
			{
				cout << "\tFood charges : " << price_Set2 << endl;
				// Call the foodcharges function, passing the contents of price_Set2 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set2,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;
			}
			else if (choice_food==3)
			{
				cout << "\tFood charges : " << price_Set3 << endl;
				// Call the foodcharges function, passing the contents of price_Set3 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set3,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;
			}
			else 
			{					
			cout << "\tEnter a valid input." << endl;
			}
			 
	
				
				
}
else if(choice==2) //if choice = 2, display double bed room price according to the days
{
	cout << "\tRoom Charges = " << perDay_double << " per day" << endl;
	cout << endl;
	cout << "\tDuration of stay (in days). Enter 0 if no rooms taken. = " ;
    
	cin >> days[i];//get the number of days
	// Call the roomcharges function, passing the contents of perDay_double and days as arguments
	// Assign the return value to total_room_charges variable
	total_room_charges[i] = roomcharges(perDay_double,patients,days);
	cout << "\tTotal Room Charges : " << 	total_room_charges[i] << endl;//display the total room charges
	cout << endl;
	showFoodMenu();//call showFoodMenu
	cout << "\tEnter food set number : " ;
    cin >> choice_food;//get the meal set number
			if (choice_food==1)
			{
				cout << "\tFood charges : " << price_Set1 << endl;
				// Call the foodcharges function, passing the contents of price_Set1 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set1,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;
			
			}
			else if(choice_food==2)
			{
				cout << "\tFood charges : " << price_Set2 << endl;
				
				// Call the foodcharges function, passing the contents of price_Set2 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set2,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
			}
			else if (choice_food==3)
			{
				cout << "\tFood charges : " << price_Set3 << endl;
				// Call the foodcharges function, passing the contents of price_Set3 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set3,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
			
			}
			else 
			{
				cout << "\tEnter a valid input." << endl;
				
			}
	
				
	
}
else if(choice==3)//if choice = 3, display double bed room price according to the days
{
	cout << "\tRoom Charges = " << perDay_four << " per day" << endl;
	cout << endl;
	cout << "\tDuration of stay (in days). Enter 0 if no rooms taken. = " ;
    
	cin >> days[i];//get the number of days
	// Call the roomcharges function, passing the contents of perDay_four and days as arguments
	// Assign the return value to total_room_charges variable
	total_room_charges[i] = roomcharges(perDay_four,patients,days);
	cout << "\tTotal Room Charges : " << total_room_charges[i] << endl;//display the total room charges
	cout << endl;
	showFoodMenu();//call showFoodMenu
	cout << "\tEnter food set number : " ;
    cin >> choice_food;//get the meal set number
			if (choice_food==1)
			{
				cout << "\tFood charges : " << price_Set1 << endl;
				// Call the foodcharges function, passing the contents of price_Set1 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set1,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
	
			}
		else if(choice_food==2)
			{
				cout << "\tFood charges : " << price_Set2 << endl;
				// Call the foodcharges function, passing the contents of price_Set2 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set2,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	

			}
			else if (choice_food==3)
			{
				cout << "\tFood charges : " << price_Set3 << endl;
				// Call the foodcharges function, passing the contents of price_Set3 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set3,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
				
			}
			else 
			{
				cout << "\tEnter a valid input." << endl;
			}
	
}
else if (choice==4)//if choice = 4, display double bed room price according to the days
{
	cout << "\tRoom Charges = " << perDay_genWard << " per day" << endl;
	cout << endl;
	cout << "\tDuration of stay (in days). Enter 0 if no rooms taken. = " ;
	cin >> days[i];//get the number of days
	// Call the roomcharges function, passing the contents of perDay_genWard and days as arguments
	// Assign the return value to total_room_charges variable
	total_room_charges[i] = roomcharges(perDay_genWard,patients,days);
	cout << "\tTotal Room Charges : " << 	total_room_charges[i] << endl;//display the total room charges
	cout << endl;
	showFoodMenu();//call showFoodMenu
	cout << "\tEnter food set number : " ;
    cin >> choice_food;//get the meal set number
			if (choice_food==1)
			{
				cout << "\tFood charges : " << price_Set1 << endl;
				
				// Call the foodcharges function, passing the contents of price_Set1 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set1,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
				
			}
			else if(choice_food==2)
			{
				cout << "\tFood charges : " << price_Set2 << endl;
				
				// Call the foodcharges function, passing the contents of price_Set2 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set2,patients,days);
				cout << fixed << showpoint << setprecision(2); 
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
			}
			else if (choice_food==3)
			{
				cout << "\tFood charges : " << price_Set3 << endl;
				
				// Call the foodcharges function, passing the contents of price_Set3 and days as arguments.
				// Assign the return value to total_food_charges variable
				total_food_charges[i] = foodcharges(price_Set3,patients,days);
				cout << fixed << showpoint << setprecision(2);
				//Display the total room and food charges 
				cout << "\tTotal food charges : " << total_food_charges[i] << endl;	
			}
			else 
			{
				cout << "\tEnter a valid input." << endl;
			}
	
}
else 
{
	cout << "\tEnter a valid input." << endl; 
	
}

surgeryMenu(); //call surgeryMenu
getChoiceSurgery(choice_surgery); // Get a choice and store it in a value
	
if (choice_surgery == 1) // if choice of surgery is 1, price of Appendectomy is set to 	surgery_charges variable
{
	surgery_charges[i] = price_Appen;
}
else if (choice_surgery == 2)// if choice of surgery is 2, price of Caesarean Section is set to 	surgery_charges variable
{
	surgery_charges[i] = price_Caesa;
}
else if (choice_surgery == 3)// if choice of surgery is 3, price of Mastectomy is set to 	surgery_charges variable
{
	surgery_charges[i] = price_Mas;
}
else if (choice_surgery == 4)// if choice of surgery is 4, price of Partial Colectomy is set to 	surgery_charges variable
{
	surgery_charges[i] = price_Part;
}
else if (choice_surgery == 5)// if choice of surgery is 5, price of Tonsillectomy is set to 	surgery_charges variable
{
	surgery_charges[i] = price_Ton;
}
else if (choice_surgery == 6)// if choice of surgery is 6, price of Cataract Surgery is set to 	surgery_charges variable
{
	surgery_charges[i] = price_Catar;
}
else if (choice_surgery == 0)//if choice is 0, no surgery occurs and No Surgery is set to surgery_charges variable
{
	surgery_charges[i] = price_NoSurgery; 
}
else 
{
	cout << "\tEnter a valid input." << endl;
	exit(0);
}
	
cout << fixed << showpoint << setprecision(2); // set the surgery charges value to 2 decimal places
cout << "\tSurgery Charges = " << surgery_charges[i] << endl; // Display surgery charges
	
        cout << endl;
		cout << endl;
showMedicationMenu(); //call showMedicationMenu
cout << endl;
//get the number of medications taken by the patient
cout << "\tPlease enter the number of medications taken by the patient : " << endl;
cout << "\tEnter 0 if no medications are taken. " << endl;
cout << "\tSame medications that are taken multiple times has to be input multiple times. ";
cin >> choice_medication; // get the medication choice
cout << "\tPlease enter the medication code number. " << endl; // insert the medication code number displayed
for(int count = 1; count <= choice_medication; count++) // loop starts at count = 1, and goes on until it reaches choice_medication
 {
   cout << "\tEnter medication code: ";
   cin >> medication;//get the medication code number
	
	// keep running the loop while medication is not equals to 101,102,103,104 and 105
	while (medication!=101 && medication!=102 && medication!=103 && medication!=104 && medication!=105 ) 
	{
	cout << "\tPlease enter a valid input. " << endl; 
	cin >> medication;
	}
	if (medication == 101) // if medication is 101, price of Metformin is set to medication_price variable
	{
	medication_price = price_Metformin;
	}
	else if (medication == 102) // if medication is 102, price of Amlodipine is set to medication_price variable
	{
	medication_price = price_Amlodipine;
	}
	else if (medication == 103) // if medication is 103, price of Metoprolol is set to medication_price variable
	{
	medication_price = price_Metoprolol;
	}
	else if (medication == 104) // if medication is 104, price of Omeprazole is set to medication_price variable
	{
	medication_price = price_Omeprazole;
	}
	else if (medication == 105) // if medication is 105, price of Losartan is set to medication_price variable
	{
	medication_price = price_Losartan;
	}
	
	cout << "\tMedication Price : " << medication_price << endl;
	cout << fixed << showpoint << setprecision(2); // set the medication charges value to 2 decimal places
	medication_rate[i] = medication_rate[i] + medication_price; // set the intitial medication_rate to 0 and add with medication price
	cout << "\tTotal medication prices : " << medication_rate[i] << endl; // display the total medication prices
}
	
cout << endl;
cout << endl;

showServiceMenu(); // call showServiceMenu
cout << "\tPlease enter the number of services taken by the patient. " << endl;
cout << "\tEnter 0 if no services are taken. " << endl;
cout << "\tSame services that are taken multiple times has to be input multiple times. " ;
cin >> choice_services; // get the service choice
cout << "\tPlease enter the service code number. " << endl;
for(int count = 1; count <= choice_services; count++) // loop starts at count = 1, and goes on until it reaches choice_services
{
   cout << "\tEnter service code: ";
   cin >> services_code; //get the service code displayed
	
	// keep running the loop while service code is not equals to 201,202,203,204 and 205
    while (services_code!=201 && services_code!=202 && services_code!=203 && services_code!=204 && services_code!=205 )
    {
   	cout << "\tPlease enter a valid input. " << endl; 
	cin >> services_code ; 
    }
    if (services_code == 201) // if services_code is 201, price of Blood Test is set to service_price variable
	{
		service_price = price_Blood;
	}
	else if (services_code == 202) // if services_code is 202, price of Urine Test is set to service_price variable
	{
		service_price = price_Urine;
	}
	else if (services_code == 203) // if services_code is 203, price of Physiotherapy  is set to service_price variable
	{
		cout << "\tEnter the number of hours of physiotherapy performed : ";
		cin >> hours; // get the number hours physiotherapy performed
		cout << endl;	
	  	service_price = price_PhysioPerHour*hours; //calculate the total service price for physiotherapy based on the duration
	}
	else if (services_code == 204) // if services_code is 204, price of X-Ray is set to service_price variable
	{
		cout << "\tThe frequency(THz) of X-Ray performed : " << endl;  
		//Display the types of X-Ray frequencies
        cout << "\t1. 10000 THz " << endl;
        cout << "\t2. 1000000 THz " << endl;
		cout << "\tThe frequency entered : "; 
        cin >> frequency_xray; // get the frequency of the X-Ray
		cout << endl;
		if (frequency_xray == 1)  // if frequency_xray is 1, price of X-Ray is set to service_price variable
		{
			service_price = price_XrayF1 ;
		}
	    else if (frequency_xray == 2) // if frequency_xray is 2, price of X-Ray is set to service_price variable
	    {
	    	service_price = price_XrayF2;
		}
	}
	else if (services_code == 205) // if services_code is 205, price of MRI is set to service_price variable
	{
	  cout << "\tThe frequency(MHz) of MRI performed : " << endl;
	  //Display the types of MRI frequencies
      cout << "\t1. 100 MHz " << endl;
      cout << "\t2. 250 MHz " << endl;
	  cout << "\tThe frequency entered : "; 
      cin >> frequency_MRI; // get the frequency of the X-Ray
	  cout << endl;
	  if (frequency_MRI == 1) // if frequency of MRI is 1, price of MRI is set to service_price variable
	  {
	  	service_price = price_MriF1;
	  }
	  else if (frequency_MRI == 2) // if frequency of MRI is 2, price of MRI is set to service_price variable
	  {
	  	service_price = price_MriF2;
	  }
	  
	}
	
	cout << "\tService Price : " << service_price  << endl;
	cout << fixed << showpoint << setprecision(2); // set the service charges value to 2 decimal place
	service_rate[i] = service_rate[i] + service_price;  // set the intitial service_rate to 0 and add with service price
	cout << "\tTotal service prices : " << service_rate[i] << endl; // display the total service prices
}
cout << fixed << showpoint << setprecision(2); // set the total bill value to 2 decimal place
   	
//Calculate and display the overall hospital charges
Total_bill[i] = total_food_charges[i] + total_room_charges[i] + surgery_charges[i] + medication_rate[i] + service_rate[i];
cout << endl;
//Displaying the name of the patient with their total bill
cout << "\tThe charges of patient " << name[i] << endl;
cout << endl;

 	cout << "\t-------------------------------------------------------------- "<< endl;
 	cout << "\tDays of stay                \t|     " << days[i] << " days" << endl;
	cout << "\t-------------------------------------------------------------- "<< endl;
	cout << "\tTotal room charges 	        |  RM " << total_room_charges[i] << endl;      
	cout << "\t--------------------------------------------------------------"<< endl;
	cout << "\tTotal meal charges 		|  RM " << total_food_charges[i] << endl;      
	cout << "\t--------------------------------------------------------------"<< endl;	
	cout << "\tTotal of surgery charges    \t|  RM " << surgery_charges[i] << endl;
	cout << "\t--------------------------------------------------------------"<< endl;
	cout << "\tTotal of medication prices  \t|  RM " << medication_rate[i] << endl; 
	cout << "\t--------------------------------------------------------------"<< endl;
	cout << "\tTotal of service charges    \t|  RM " << service_rate[i] << endl;
 	cout << "\t--------------------------------------------------------------"<< endl;
	cout << "\tTotal bill                  \t|  RM " << Total_bill[i] << endl;
	cout << "\t--------------------------------------------------------------"<< endl;

cout << endl;
cout << endl;

}

for(int i=0; i<patients ;i++) 
{
	//Calculate the total of all the patients' bill
	sum = sum + Total_bill[i];
	//Calculate the total of all the patients' room charges
	sum_room = sum_room + total_room_charges[i];
	//Calculate the total of all the patients' food charges
	sum_food = sum_food + total_food_charges[i];
	//Calculate the total of all the patients' food charges
	sum_surgery = sum_surgery + surgery_charges[i] ;
	//Calculate the total of all the patients' medication charges
	sum_medication = sum_medication + medication_rate[i];
	//Calculate the total of all the patients' service charges
	sum_service = sum_service + service_rate[i];

}
	cout << "\tTotal bill charges of the day : " << endl;
	cout << endl;
	cout << "\t------------------------------------------------------------------ "<< endl;
	cout << "\t Total charges for all patients                  |  RM " << sum << endl;
	cout << "\t------------------------------------------------------------------ "<< endl;
	cout << "\t Total room charges for all patients             |  RM " << sum_room  << endl;    
	cout << "\t------------------------------------------------------------------ "<< endl;
	cout << "\t Total food charges of all the patients          |  RM " << sum_food << endl;    
	cout << "\t------------------------------------------------------------------ "<< endl;  
	cout << "\t Total surgery charges of all the patients       |  RM " << sum_surgery << endl;
	cout << "\t------------------------------------------------------------------ "<< endl;
	cout << "\t Total medication charges of all the patients    |  RM " << sum_medication << endl; 
	cout << "\t------------------------------------------------------------------ "<< endl;
	cout << "\t Total service charges of all the patients       |  RM " << sum_service << endl;
	cout << "\t------------------------------------------------------------------ "<< endl;

	cout << endl;
	cout << endl;   

for(int i=0; i<patients ;i++) 
{
	//Calculate the total number of hospital stay days of all patients
	sum_days = sum_days+days[i];
}
	//Display the total number of hospital stay days of all patients
	cout << "\tThe total number of days : " << sum_days << " days" << endl;
	cout << endl;
	//Calculate the average hospital stay for a patient
	avg_days = sum_days/patients;
	//Display the average number of hospital stay days of all patients
	cout << "\tThe average hospital stay for a patient : " << avg_days << " days" << endl;
	cout << endl;


//Find the patient's name that pays the highest bill
highest = Total_bill[0];
string highestname; //declare string higestname


for(int i=0; i<patients ;i++) 
{ 
 if(Total_bill[i]>highest) 
     { 
      	highest =  Total_bill[i];
		highestname = name[i];
     } 
} 
//Display the patient's name that pays the Highest bill
cout <<"\tThe patient with the highest bill amount : " << highestname  << endl;
cout << endl;

//Find the patient's name that pays the Lowest bill
lowest = Total_bill[0];
string lowestname;//declare string lowestname

for(int i=0; i<patients ;i++) 
{     
 if(Total_bill[i]<lowest) 
     { 
        lowest = Total_bill[i]; 	
		lowestname = name[i];
     } 	
}

//Display the patient's name that pays the lowest bill
 cout <<"\tThe patient with the lowest bill amount : " << lowestname << endl;
 cout << endl;
 
return 0;
}

//Definition of function showRoomMenu
void showRoomMenu() 
{
	
	cout << "\tTYPE OF ROOMS " << endl;
	cout << "\t-------------------------"<< endl;
	cout << "\t1 : Single Bed Suite \n" 
	     << "\t2 : Double Bed Suite \n" 
		 << "\t3 : Four Bed Room \n" 
		 << "\t4 : General Ward \n" ;
	cout << endl;	 
	cout << endl;
	

}

//Definition of getChoice.
//The parameter RoomChoice is a reference variable.
//The user is asked to enter a number, which is stored in RoomChoice
void getChoice(int &RoomChoice)
{
	cout << "\tEnter type of room : ";
	cin >> RoomChoice;
}


// Definiton of function roomcharges.
// This function returns the product of its two parameters
int roomcharges(int typeRoom, int patients_num, int Duration_Stay[])
{
	for(int j=0; j<patients_num; j++)
	{	
		return typeRoom*Duration_Stay[j];
	}
    	
}

// Definiton of function foodcharges.
// This function returns the product of its two parameters
double foodcharges(double FoodSet,int patients_num, int DaysOfOrder[])
{
	for(int j=0; j<patients_num; j++)
	{	
		return FoodSet*DaysOfOrder[j];
	}
    
}

//Definition of function showFoodMenu
void showFoodMenu()
{
	//variable declaration
	const double price_Set1 = 30.99,  price_Set2 = 40.99 , price_Set3 = 50.99;
	int choice_food, days, total_food_charges;
	//display the meals offered and its prices
	cout << "\t-----------------------------------------------"<< endl;
	cout << "\tMEALS " << endl;
	cout << "\t-----------------------------------------------"<< endl;
	cout << "\tSET 1: RM " << price_Set1 <<  endl;
	cout << "\tBreakfast = Cereal With Milk\n" ;
	cout << "\tLunch     = Chicken Rendang and Salad\n";
	cout << "\tDinner    = White Rice and Steamed Fish\n";
	cout << "\t-----------------------------------------------"<< endl;
	cout << "\tSET 2: RM " << price_Set2 << endl;
	cout << "\tBreakfast = Bread with a variety of spreads\n";
	cout << "\tLunch     = Grilled Fish with Steamed Broccoli\n";
	cout << "\tDinner    = Brown Rice and Stewed Chicken\n";
	cout << "\t-----------------------------------------------"<< endl;	
	cout << "\tSET 3: RM " << price_Set3 << endl; 
	cout << "\tBreakfast = Pancakes and Fruits\n";
	cout << "\tLunch     = Grilled Salmon with Asparagus\n";
	cout << "\tDinner    = Brown Rice and Shark Fin Soup\n";
	cout << "\t-----------------------------------------------"<< endl;
	cout << endl;
		
}	

//Definition of function surgeryMenu
void surgeryMenu()
{
	//variable declaration
	const int price_Appen = 10000, price_Caesa = 13000, 
				 price_Mas = 25000, price_Part = 40000, 
				 price_Ton = 15000, price_Catar = 16000, price_NoSurgery = 0;	
	
	//display the surgery types and its prices
	cout << "\t----------------------------------------"<< endl;
	cout << "\tSURGERY                 PRICE" << endl;
	cout << "\t----------------------------------------"<< endl;
	cout << "\t0.  No Surgery        : " << "------" << endl;
	cout << "\t1.  Appendectomy      : " << price_Appen << endl;
	cout << "\t2.  Caesarean Section : " << price_Caesa << endl;
	cout << "\t3.  Mastectomy        : " << price_Mas << endl;
	cout << "\t4.  Partial Colectomy : " << price_Part << endl;
	cout << "\t5.  Tonsillectomy     : " << price_Ton << endl;
	cout << "\t6.  Cataract Surgery  : " << price_Catar << endl;
	cout << "\t----------------------------------------"<< endl;

}

//Definition of function getChoiceSurgery
//The parameter SurgeryChoice is a reference variable.
//The user is asked to enter a number, which is stored in SurgeryChoice
void getChoiceSurgery(int & SurgeryChoice)
{
	cout << "\tEnter the surgery performed : " ;
	cin >> SurgeryChoice;
}

//Definition of function showMedicationMenu
 void showMedicationMenu() 
 
 { 	
 	//variable declaration
 	const double price_Metformin = 35.80, price_Amlodipine = 22.80, price_Metoprolol = 78.90, price_Omeprazole = 40.00,
				 price_Losartan = 45.60,  price_Focalin = 46.40;
	
	//Display the pharmacy charges and its prices
	cout << "\t-----------------------------------------" << endl;			 
 	cout << "\tMEDICATION	  PRICE 			   " << endl;
 	cout << "\t-----------------------------------------" << endl;
 	cout << "\t101. Metformin     :   " << price_Metformin << endl; 
	cout << "\t102. Amlodipine    :   " << price_Amlodipine << endl;
	cout << "\t103. Metoprolol    :   " << price_Metoprolol << endl;
 	cout << "\t104. Omeprazole    :   " << price_Omeprazole << endl;
	cout << "\t105. Losartan      :   " << price_Losartan << endl;
	cout << "\t-----------------------------------------" << endl;	
	
}

//Definition of function showServiceMenu
void showServiceMenu()
{
	//variable declaration
	const double price_Urine = 90.00, price_Blood = 110.00,
				 price_PhysioPerHour = 120.00, price_XrayF1 = 150.00,
				 price_XrayF2 = 190.00, price_MriF1 = 3000.00,
				 price_MriF2 = 4000.00;
	//Display the service and its prices
	cout << "\t------------------------------------------" << endl;
	cout << "\tSERVICES			PRICE            " << endl;
	cout << "\t------------------------------------------" << endl;
	cout << "\t201. Blood Test          : " << price_Blood << endl;
	cout << "\t------------------------------------------" << endl;
	cout << "\t202. Urine Test          : " << price_Urine << endl;
	cout << "\t------------------------------------------" << endl;
	cout << "\t203. Physiotherapy       : " << price_PhysioPerHour << " per hour " << endl;
	cout << "\t------------------------------------------" << endl;
	cout << "\t204. X-Ray :- " << endl;
	cout << "\t     10000 THz           : " << price_XrayF1 << endl;
	cout << "\t     1000000 THz         : " << price_XrayF2 << endl;
	cout << "\t------------------------------------------" << endl;
	cout << "\t205. Magnetic Resonance Imaging (MRI) :- " << endl;
	cout << "\t     100 MHz             : " << price_MriF1 << endl;
	cout << "\t     250 MHz             : " << price_MriF2 << endl;
	cout << "\t------------------------------------------" << endl;
}
