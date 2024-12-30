// Aqdas Juya , 10/10/2024 , ajuya@pdx.edu ,  Program # 1, cs 163
#include "program_one.h"
#include <iostream>

using namespace std;

int main() {

	CS_fun fun_places;
	int option= 0;
	const int SIZE = 100;	
	char week_day[100];
	venue temp_venue;
	activity temp_activity;
	char name[SIZE];	

	cout << "\nThis is Program  assignment number one. In theis program, you can keep track of places that you would like to visit. You can store information such as the name, description, hours of operation, and other details about each place. you can also add the types of activities avalible at each location. once you have added activities and places, you can display them and check which places are open on specific days of the week. additionlly, you can delete a place if you no longer wish to visit it in the future.\n";

	do {
		cout << "\n1. Add a new place\n";
		cout << "2. Display all the places\n";
		cout << "3. Add Activities\n";
		cout << "4. Display Activites\n";
		cout << "5. Display places that are open\n";
		cout << "6. Remove a Place of choice\n";
		cout << "7. Quit\n";
		cout << "\nPlease enter your choice: ";
		cin >> option;
		cin.ignore(100,'\n');
	
		if(option == 1) {
		
			temp_venue.name = new char[SIZE];
			cout << "\nEnter the place is name: ";
			cin.get(temp_venue.name, SIZE, '\n');
			cin.ignore(100,'\n');

			temp_venue.description = new char[SIZE];
			cout << "Enter the description of the place: ";
			cin.get(temp_venue.description, SIZE, '\n');
			cin.ignore(100,'\n');
			
			temp_venue.hours = new char[SIZE];
			cout << "Enter the one day of the week that is open(EX: monday: ";
			cin. get(temp_venue.hours, SIZE, '\n');
			cin.ignore(100, '\n');

			temp_venue.informations = new char[SIZE];
			cout << "Enter some more unknown information that is fun to know: "; 
			cin.get(temp_venue.informations, SIZE, '\n');
			cin.ignore(100,'\n');


			fun_places.add_place(temp_venue);

			cout << "\nThe places are added!\n" << endl;

		} else if(option == 2) {
			fun_places.display_all();
		} else if ( option == 3) {
				
			cout << "\nPlease enter the name of place you want to add more activity to: ";	
			cin.get(temp_venue.name, SIZE, '\n');
			cin.ignore(100,'\n');
 
			temp_activity.name_activity = new char[SIZE];
 			cout << "\nEnter the Activaty name: ";
 			cin.get(temp_activity.name_activity, SIZE, '\n');
                        cin.ignore(100,'\n');
        
			temp_activity.rules = new char [SIZE];
                        cout << "Enter the rule for the activity: ";
                        cin.get(temp_activity.rules, SIZE, '\n');
                        cin.ignore(100,'\n');
                        
			temp_activity.information = new char [SIZE];
                        cout << "Enter the information for the activity: ";
                        cin.get(temp_activity.information, SIZE, '\n');
                        cin.ignore(100, '\n');

			fun_places.add_activity(temp_venue.name, temp_activity);

			cout << "The activity are added\n" << endl;
			
		
		} else if (option == 4) {
			char venue_name[SIZE];
			cout << "\nEnter the name of the place to display it's acttivites: ";
			cin.get(venue_name, SIZE, '\n');
			cin.ignore(100, '\n');

			if (fun_places.display_activities (venue_name) == 0){
				cout << "Failed to display activites or that there is no activities available." << endl;
			}
		} else if ( option == 5) {
			cout << "Enter the day to check for open venues; ";
			cin.get(week_day, SIZE, '\n');
                        cin.ignore(100,'\n');

			fun_places.display_places(week_day);

		} else if(option == 6) {
			cout<< "Enter the name of the venue to remove: ";
			cin.get(name, SIZE, '\n');
			cin.ignore(SIZE, '\n');
			if(fun_places.remove_place(name)) {
				cout << "venue " << name<< " removed seccessfully.\n";
			}else {
				cout<< " Error: venue not found.\n";
			}		

		} else if( option == 7) {
			cout << "\nThank you for using this program. \n" << endl;
		} else {
			cout << "\nPlease enter a valid choice." << endl;
		}
	} while (option != 7);
	
	return 0;

}
