/*
 * NAME: JONATHON HARRIS
 * CLASS: CS163
 * PROJECT 1
 * PURPOSE: This program is a smart home controller where you
 * can add/remove rooms and accessories set up in two linked
 * lists. You can also display all rooms/accessories.
 */

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


/*struct accessories
  {
//put methods in struct add/remove?
char *access_name;
char *category;
char *status;

accessories * next;//does this go in access_node?
};*/
struct Accessories//shell for data entry
{
	char *access_name;
	char *category;
	char *status;
};    
struct Access_node
{
	//figure out what to stick here
	Access_node * next;//next pointer
	Access_node();//default constructor
	~Access_node();//destructor
    Accessories Accessory_info;
        

};
struct Room
{
    int add_accessory( const struct Accessories &to_add);
    int remove_accessory(char * to_remove);
	int display_accessories();
	int display_all_accessories();
	char *name;
	Room * next;
	Room();
	~Room();
    private: 
	Access_node *ahead;
};
class List
{
	public: 
		List();
		void clear();
        void menu(int &user_input);
		int add_room(char *room_name);
    	int remove_room(char *room_name);
		Room*find_room(char *room_name);
	    int add_accessory(char *room_name, const struct Accessories &to_add);
	    int display_accessories(char *room_name);
	    int display_all_accessories();
        int display_all_rooms();
		int remove_accessory(char *room_name, char *to_remove);
		//deep copy method

		~List();
	private: 
		Room * head;
};	
