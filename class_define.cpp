/* NAME: JONATHON HARRIS
 * CLASS: CS163
 * PROJECT 1
 * PURPOSE: This program is a smart home controller where you
 * can add/remove rooms and accessories set up in two linked
 * lists. You can also display all rooms/accessories.
 */

#include "project1_class.h"

//default constructors
Room::Room()
{
    name = NULL;
    ahead = NULL;
    next = NULL;
}

Access_node::Access_node()
{
    Accessory_info.access_name = NULL;
    Accessory_info.category= NULL;
    Accessory_info.status= NULL;
    next = NULL;//next pointer
}
List::List()
{
    head = NULL;
}
//postcondition: this clears the screen with newline characters
//for ease of readability
void List::clear()
{
    for (int i = 0; i < 200; ++i)
        cout << '\n';
}
//menu list for functions
void List::menu(int &user_input)
{
    cout << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl << endl
        << "Please select from the following options: " <<endl
        << "1. Add a new room. " << endl
        << "2. Remove a room." << endl
        << "3. Add accessory to a room" << endl
        << "4. Remove accessory." << endl
        << "5. Display all accessories" <<endl
        << "6. Display all rooms" <<endl
        << "7. Display accessory in a room" << endl
        << "8. Exit the program. " << endl << endl
        << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl; 
    cin >> user_input;
    cin.ignore(100, '\n');
    if(user_input <= 0 || user_input > 6)
    {   
        cout << "----------------------------------------- " << endl
            << "----------------------------------------- " << endl << endl 
            << "Please select A VALID menu option!: " <<endl
            << "1. Add a new room. " << endl
            << "2. Remove a room." << endl
            << "3. Add accessory to a room" << endl
            << "4. Remove accessory." << endl
            << "5. Display all accessories" <<endl
            << "6. Display all rooms" <<endl
            << "7. Display accessory in a room" << endl
            << "8. Exit the program. " << endl << endl
            << "----------------------------------------- " << endl
            << "----------------------------------------- " << endl << endl; 

    }   

}


//precondition: receives name char* from user for room to add
//postcondition: adds room to list
int List::add_room(char *name_to_add)
{
    //check if entries are NULL	
    if(!name_to_add)
        return 0;
    //if first node in list add to beginning
    if(!head)
    {
        Room *newRoom= new Room();
        newRoom->name = new char[strlen(name_to_add)+1]; 
        strcpy(newRoom->name,name_to_add);
        head = newRoom;
        newRoom->next = NULL;
        return 1;
    }
    //there are >1 rooms
    else
    {
        Room * current = head;
        Room * prev = head;
        //allocate memory, deep copy from user input
        Room *newRoom= new Room();
        newRoom->name = new char[strlen(name_to_add)+1]; 
        strcpy(newRoom->name,name_to_add);
        int compare = strcmp(name_to_add,current->name);	
        //if name user entered is less than current->name
        //add node to beginning
        if(compare<0)
        {
            newRoom->next = current;
            head = newRoom;
            return 1;
        }
        //if room needs to be added to middle of the list
        while(current)				
        {
            if(strcmp(name_to_add,current->name)<0)
            {
                prev->next=newRoom;	
                newRoom->next = current;
                return 1;
                break;
            }
            prev = current;
            current = current -> next;
        }
        //if room name has the greatest alphabetical value
        //add to the end of the list
        if(current==NULL)
        {
            current = newRoom;
            newRoom->next = NULL;
            prev->next = newRoom;
            return 1;
        }
    }
}
//precondition: receives char* from user of room to find
//postcondition: returns address of that room
Room* List::find_room(char *room_to_find)
{

    Room *current = head;
    while(current)
    {
        if(strcmp(current->name,room_to_find)==0)
            return current;
        current= current->next;
    }
    return NULL;
}


//precondition: user inputs char* room_name 
//postcondition:return address where target room is located 
int List::add_accessory(char *room_name, const struct Accessories &to_add)
{
    if(!head) //empty list
        return 0;

    Room *finder = find_room(room_name);//find room of interest
    if(!finder)//if cannot find room
        return 0;
    finder->add_accessory(to_add);
}


//precondition:User enters accessory info
//postcondition:Node is inserted with user entered data
int Room::add_accessory(const struct Accessories &to_add)
{

    Access_node * current =ahead;
    Access_node * prev= ahead;//prev for insert middle
    //create new accessory node
    Access_node *newAccess_node= new Access_node;
    //deep copy the name/category/status 
    newAccess_node->Accessory_info.access_name = new char[strlen(to_add.access_name)+1]; 
    strcpy(newAccess_node->Accessory_info.access_name,to_add.access_name);
    newAccess_node->Accessory_info.category = new char[strlen(to_add.category)+1]; 
    strcpy(newAccess_node->Accessory_info.category,to_add.category);
    newAccess_node->Accessory_info.status= new char[strlen(to_add.status)+1]; 
    strcpy(newAccess_node->Accessory_info.status,to_add.status);
    //compare our new nodes category to other nodes in list
    if(!ahead)
    {
        ahead = newAccess_node;
        newAccess_node->next = NULL;
        return 1;
    }
    int compare = strcmp(newAccess_node->Accessory_info.category,current->Accessory_info.category);

    if(compare<0)
    {
        newAccess_node->next = current;
        ahead = newAccess_node;
        return 1;
    }
    while(current)				
    {
        if(strcmp(newAccess_node->Accessory_info.category,current->Accessory_info.category))
        {

            prev->next=newAccess_node;	
            newAccess_node->next = current;
            return 1;
            break;
        }
        prev = current;
        current = current -> next;
    }
    if(current==NULL)
    {
        current=newAccess_node;
        newAccess_node->next = NULL;
        prev->next = newAccess_node;
        return 1;
    }
}
int List::display_accessories(char *room_name)
{
    if(!head) //empty list
        return 0;

    Room *finder = find_room(room_name);//find room of interest
    if(!finder)//if cannot find room
        return 0;
    finder->display_accessories();
}
int Room::display_accessories()
{
    if(!ahead)
        return 0;

    Access_node * current = ahead;
    while(current)
    {
        cout << current->Accessory_info.access_name << " " << endl;
        cout << current->Accessory_info.category<< " " << endl;
        cout << current->Accessory_info.status<< " " << endl << endl;
        current = current->next;
    }

}



//postcondition: displays all rooms and accessories
//associated with those rooms returns count of access
int List::display_all_accessories()
{
    int count = 0;//count for accessories displayed

    if(!head)
        return 0;
    Room * current = head;
    while(current)
    {
        ++count;
        cout << current->name << ' ' << endl;
        current->display_accessories();
        current = current->next;
    }
    return count;

}
//postcondition: Displays all rooms and returns count
//of how many rooms were displayed
int List::display_all_rooms()
{
    int count = 0;//count for rooms displayed
    if(!head)//no list
        return 0;
    Room *current = head;
    while(current)
    {
        ++count;
        cout << current->name << ' ' << endl;
        current = current -> next;
    }
    return count;
}

//precondition: receives room name to delete from user
//postcondition: sends address of room to Room::remove_accessory
int List::remove_accessory(char *room_name, char *to_remove)
{
    if(!head) //empty list
        return 0;

    Room *finder = find_room(room_name);//find room of interest
    if(!finder)//if cannot find room
        return 0;
    finder->remove_accessory(to_remove);
}

//Precondition: User enters in char* of accessory
//they wish to remove
//Postcondition: Accessory is removed
int Room::remove_accessory(char *to_remove)
{
    if(!ahead)//no list
        return 0;
    //set pointers
    Access_node *current = ahead;
    Access_node *prev= ahead;
    Access_node *delPtr= NULL;
    //compare user entry to name of the accessory on first node
    //if one node list and name matches delete all info
    //set head to null, return true flag.
    while(current)
    {
        if(strcmp(to_remove,current->Accessory_info.access_name)==0)
        {
            if(current==ahead)
            {

                current = ahead->next;
                prev= ahead->next;
                delPtr= ahead;
                ahead = ahead->next;
            }
            else
            {
                prev->next = current->next;
                delPtr = current;
                current = current ->next;
            }
            delete delPtr;
            delPtr = NULL;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
} 
int List::remove_room(char *room_name)
{
    if(!head) //empty list
        return 0;
    Room * current = head;
    Room * prev = head;
    Room * delPtr = NULL;

    while(current)
    {
        if(strcmp(room_name,current->name)==0)
        {
            if(current==head)
            {

                current = head->next;
                prev= head->next;
                delPtr= head;
                head = head->next;
            }
            else
            {
                prev->next = current->next;
                delPtr = current;
                current = current ->next;
            }
            delete delPtr;
            delPtr = NULL;

        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

//postcondition:: deallocates dynamically allocated array
Room::~Room()
{
    Access_node *temp = NULL;
    if(name)
        delete [] name;
    while(ahead)
    {
        temp=ahead;
        ahead=ahead->next;
        delete temp;
    }
}

//postcondition:: deallocates dynamically allocated arrays
Access_node::~Access_node()
{
    if(Accessory_info.access_name)
        delete [] Accessory_info.access_name;
    if(Accessory_info.category)
        delete [] Accessory_info.category;
    if(Accessory_info.status)
        delete [] Accessory_info.status;
}

List::~List()
{
    Room *temp = NULL;
    while(head)
    {
        temp=head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}

