// .h file
// Aqdas Juya , 10/10/2024 ,≈ ajuya@pdx.edu ,  program # 1 , cs 163
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

struct activity
{
	char * name_activity;
	char * rules;
	char * information; 
};
struct activity_node
{
	activity activities;
	activity_node * next;
};
struct venue
{
	char * name;
	char * description; 
	char * hours;
	char  * informations;
};
struct venue_node 
{
	venue a_venue;
	venue_node * next;
	activity_node * head;
};
//int CS_fun::add_place(const venue& to_add)
class CS_fun
{
	public:
		CS_fun();
		~CS_fun();

		int add_place(const venue& to_add);
		int display_all() const;
		int add_activity(char name_venue[], const activity & activity_to_add);
		int display_activities (char name_venue[]) const;
		int display_places(char week_day[]) const;
		bool remove_place(char  name_venue[]);
	private:
	
		venue_node * head;

		int display_venue_recursive( const venue_node * head, const char  * week_day) const;

};

