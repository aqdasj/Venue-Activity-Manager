// Aqdas Juya , 10/10/2024 , ajuya@pdx.edu ,  Program # 1, cs 163
// program_one.cpp

#include "program_one.h"
using namespace std;

//defult constructor
CS_fun::CS_fun()
{
	head = nullptr;
}
//add the list for the place
int CS_fun::add_place(const venue& to_add)
{
	venue_node * temp = new venue_node;
	

	temp->a_venue.name = new char[strlen(to_add.name) +1];
	strcpy(temp->a_venue.name, to_add.name);
 
  	temp->a_venue.description = new char[strlen(to_add.description)+1];
	strcpy(temp->a_venue.description, to_add.description);

	temp->a_venue.hours = new char[strlen(to_add.hours) +1];
	strcpy(temp->a_venue.hours,to_add.hours);

	temp->a_venue.informations = new char[strlen(to_add.informations) + 1];
 	strcpy(temp->a_venue.informations, to_add.informations);
	
	temp ->next = head;
	head = temp;

	return 1;

	       

}

int CS_fun::display_all() const{

	if (!head) {
	
		cout << "\nNo places to display.\n" << endl;
		return 0;
	}
	
	venue_node * current = head;
	while(current) {
		cout << "\nVenue name: " << current -> a_venue.name << endl;
		cout << "Descriptiom: " << current -> a_venue.description<< endl;
		cout << "Hours of operation: " << current -> a_venue.hours << endl;
		cout << "Other Information: "<< current -> a_venue.informations<< endl;
		current = current -> next;
	}
	return 1;
}
int CS_fun::add_activity(char venue_name[], const activity & activity_to_add){
	venue_node * current = head;
	
	while(current != nullptr && strcmp(current -> a_venue.name, venue_name) != 0) {
		current = current -> next;
		
	}
	if(current == nullptr) {
		cout << "\nvenue not found." << endl;
		return 0;
	}

        activity_node * temp = new activity_node;

        temp->activities.name_activity = new char[strlen(activity_to_add.name_activity) +1];
        strcpy(temp->activities.name_activity, activity_to_add.name_activity);

        temp->activities.rules = new char[strlen(activity_to_add.rules)+1];
        strcpy(temp->activities.rules,activity_to_add.rules);


        temp->activities.information = new char[strlen(activity_to_add.information) + 1];
        strcpy(temp->activities.information,activity_to_add.information);

        temp-> next = current -> head;
	current -> head = temp;

	return 1;
}

int CS_fun::display_activities (char name_venue[]) const
{
        if (!head) {    
        
                cout << "No activites to display." << endl;
                return 0;
        }               
        
        venue_node* current = head;
	while (current != nullptr && strcmp( current -> a_venue.name, name_venue) != 0 ) {
		current = current -> next;
	}
	
	if(!current) {
		cout <<"The place is not found. So, please add a place first." << endl;
	       return 0;
	}

	if(!current -> head) {
		cout << " No activites to display for this venue." << endl;
		return 0;
	}
	activity_node * current_a = current->head;

        while(current_a) {
                cout << "Activity name: " << current_a -> activities.name_activity << endl;
                cout << "What are rules: " << current_a -> activities.rules << endl;
                cout << "Other Information: "<< current_a -> activities.information << endl;
                current_a = current_a -> next;
        }
	return 1;

}
int CS_fun::display_places(char week_day[]) const{

	if(!head) { 
		cout << "\nThere was no places to display.\n"<< endl;
		return 0;
	}
	int count = display_venue_recursive(head, week_day);

	if(count == 0) {
		cout << "No places are going to be open on the "<< week_day << "0" << endl;
		return 0;
	}
	return 1;
}

int CS_fun::display_venue_recursive(const venue_node * head, const char * week_day) const {
	if (!head) {
		return 0;
	}
	
	char * venue_day = new char[strlen(head ->a_venue.hours) +1];
	strcpy(venue_day, head -> a_venue.hours);

	char * user_day = new char[strlen(week_day) +1];
	strcpy(user_day, week_day);
	int i = 0;

//	tolower(venue_day[i]);
//	tolower(week_day[i]);


	for(int i = 0; i < sizeof(venue_day); ++i) {
		tolower(venue_day[i]);
	}
	
	for(int i = 0; i < sizeof(week_day); ++i) {
		tolower(week_day[i]);
	}
	
	int count = 0;

	if(strcmp(venue_day, week_day) == 0) {
		cout << "venue name: " << head -> a_venue.name << endl;
		cout << "description: " << head -> a_venue.description<< endl;
		cout << "Hours of operation: " << head -> a_venue.hours << endl;
		cout << "other information: "<< head -> a_venue.informations << endl;
		count = 1;
	}
	return count + display_venue_recursive (head->next, week_day);
}
bool CS_fun::remove_place(char name_venue[]){
	if(!head) {
		cout <<" Error: no venues exist." << endl;
		return false;
	}
	venue_node * current = head;
	venue_node * previous = nullptr;

	while (current) {
		if(strcmp(current-> a_venue.name, name_venue) == 0) {
			if( previous == nullptr) {
				head = current ->next;
			} else {
				previous-> next = current -> next;
			}
			current -> next = nullptr;
			cout << "venue " << name_venue << " has been removed." << endl;
			return true;
		}
		previous = current;
		current = current->next;
	}
	cout <<"venue" << name_venue << " does not exist." << endl;
	return false;




}
CS_fun::~CS_fun(){
		
		
	while(head != NULL) {
		venue_node* temp_venue = head;
		head = head-> next;

		activity_node * current_activity = temp_venue->head;

		while(current_activity != NULL) {
			activity_node * temp_activity = current_activity->next;

			delete[] current_activity ->activities.name_activity;
			delete[] current_activity ->activities.rules;
			delete[] current_activity ->activities.information;

			delete current_activity;
			current_activity = temp_activity;
		}	
		delete[] temp_venue->a_venue.name;
		delete[] temp_venue-> a_venue.description;
		delete[] temp_venue-> a_venue.hours;
		delete[] temp_venue -> a_venue.informations;

		delete temp_venue;

	}
	
}

