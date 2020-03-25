#include "project1_class.h"

int main(int argc, char **argv)
{
	List myList;
    Accessories myAccessories;

   //create accessories object, load data 
	char  room[100];
    char accessory[100];
    int user_input = 0;//input for menu options
    char name[50];//input for removebyName function   
    myAccessories.access_name = new char[100];
    myAccessories.category= new char[100];
    myAccessories.status= new char[100];
    do  
    {   
        myList.menu(user_input);//execute menu
        switch(user_input)
        {   
            case 1:myList.clear();
                   {
	                    cout << "Enter a room name." << endl;
                        cin.get(room, 100, '\n');
                        cin.ignore(100, '\n');
                        myList.add_room(room);
                        
                   }
            break;
            case 2: myList.clear();//clear screen 
                   {
	                    cout << "Enter a room name to remove." << endl;
                        cin.get(room, 100, '\n');
                        cin.ignore(100, '\n');
                        myList.remove_room(room);
                        
                   }
                    
            break;
            case 3: myList.clear();//clear screen 
                   {
                        cout << "Enter room name to add to." << endl;
                        cin.get(room, 100, '\n');
                        cin.ignore(100, '\n');
                        cout << "Enter accessory name: " << endl;
                        cin.get(myAccessories.access_name, 100, '\n');
                        cin.ignore(100,'\n');
                        cout << "Enter accessory category: " << endl;
                        cin.get(myAccessories.category, 100, '\n');
                        cin.ignore(100, '\n');
                        cout <<"Enter status of accessory: " << endl;
                        cin.get(myAccessories.status, 100, '\n');
                        cin.ignore(100, '\n');
                        myList.add_accessory(room,myAccessories);
                   }
                        
            break;
            case 4: myList.clear();//clear screen
                
                    cout << "Enter room that accessory is in: " << endl;
                    cin.get(room, 100, '\n');
                    cin.ignore(100, '\n');
                    cout << "Enter accessory you wish to remove: " << endl;
                    cin.get(accessory, 100, '\n');
                    cin.ignore(100, '\n');
                    myList.remove_accessory(room,accessory);
                    

            break;
            case 5:myList.clear();//clear screen
                   myList.display_all_accessories();
            break;
            case 6:myList.clear();//clear screen
                   myList.display_all_rooms();
            break;
            case 7:myList.clear();//clear screen
               
                   cout << "Enter room to display accessories: " << endl;
                   cin.get(room, 100, '\n');
                   cin.ignore(100, '\n');
                   myList.display_accessories(room);
                   
            break;

            case 8:myList.clear();//clear screen
                    delete [] myAccessories.access_name; 
                    delete [] myAccessories.category; 
                    delete [] myAccessories.status; 
                   return 0;//exit
            default:
                     break;
        }   
    }while(user_input <= 7 && user_input >= 1); 
    return 0;
}
