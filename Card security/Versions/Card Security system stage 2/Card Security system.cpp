#include <iostream>
#include <string>
#include <Windows.h>  //For colours
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //For colours



class Room {   //Creates the class for rooms
    int type=0;  //Creates variables
    bool emerState=false;
    int id=0;
    char building='z';
    int name=0;
    int floor=0;
    
    public:
        
        Room() {};  //Default blank constructor initialises the array variables
        
        Room(int Id, bool EmerState, int Type, char Building, int Floor, int Name) {  //Constructor takes variables passed to it upon their creation
            type = Type;
            emerState = EmerState;
            id = Id;
            building = Building;
            name = Name;
            floor = Floor;
        }

        void swipeRoom() {}
        void updateRoomType(int RoomType) { type = RoomType; }
        void updateRoomState(bool RoomState) { emerState = RoomState; }
        int viewRoomType() { return type; }
        bool viewRoomState() { return emerState; }
        int viewRoomId() { return id; }
        char viewRoomBuilding () { return building; }
        int viewRoomFloor() { return floor; }
        int viewRoomName() { return name; }

        ~Room() {     //Destructor
           //cout << "Destroyed \n";
        }

};




bool InputValidation(int InputValidationMode, string InputValidationData, int InputValidationIntMin, int InputValidationIntMax) {
    int InputValidationInt;

    if (InputValidationMode == 1) { //User input check for int values

        for (size_t i = 0; i < InputValidationData.length(); i++) {   //Checking input is a number before convert to int to avoid error

            if (isdigit(InputValidationData[i])) { //If checked character is a number
            }
            else {                //If checked character is not a number
                return false;   //False is returned and function is broken, avoiding the convertion later and subsequent crashes
            }
        }


        InputValidationInt = stoi(InputValidationData);  //Converting string to int

        if (InputValidationIntMax >= InputValidationInt && InputValidationInt >= InputValidationIntMin) {   //Checks within acceptable range
            return true;
        }
        else {
            return false;
        }
    }

    return false; //Failsafe will return false to ensure a response
}



int main()
{
   
    //0)Unassigned  1)Lecture hall  2)Teaching room  3)Staff room  4)Secure room

    int roomCount = 32; //For For loops to go through all rooms and not beyond to a non-existant array space

    Room rooms[32] = {  //Creating an array of the rooms, allocating the data to an array number, allowing searching

        //int Id, bool EmerState, int Type, char Building, int floor, int Name
        Room( 0, false, 0, 'A', 1, 1),     //Creation of hard coded room objects
        Room( 1, false, 0, 'A', 1, 2),
        Room( 2, false, 0, 'A', 1, 3),
        Room( 3, false, 0, 'A', 1, 4),
        Room( 4, false, 1, 'A', 1, 5),
        Room( 5, false, 1, 'A', 1, 6),
        Room( 6, false, 1, 'A', 1, 7),
        Room( 7, false, 1, 'A', 1, 8),
        Room( 8, false, 2, 'A', 1, 9),
        Room( 9, false, 2, 'A', 1, 10),
        Room(10, false, 2, 'A', 1, 11),
        Room(11, false, 2, 'A', 1, 12),
        Room(12, false, 3, 'A', 1, 13),

        Room(13, false, 3, 'A', 2, 1),
        Room(14, true, 3, 'A', 2, 2),
        Room(15, false, 3, 'A', 2, 3),
        Room(16, false, 4, 'A', 2, 4),
        Room(17, false, 4, 'A', 2, 5),
        Room(18, false, 4, 'A', 2, 6),
        Room(19, false, 4, 'A', 2, 7),


        Room(20, false, 0, 'B', 1, 1),
        Room(21, false, 0, 'B', 1, 2),
        Room(22, false, 1, 'B', 1, 3),
        Room(23, false, 1, 'B', 1, 4),

        Room(24, false, 1, 'B', 2, 1),
        Room(25, false, 2, 'B', 2, 2),
        Room(26, false, 2, 'B', 2, 3),

        Room(27, false, 3, 'B', 3, 1),
        Room(28, false, 3, 'B', 3, 2),
        Room(29, false, 4, 'B', 3, 3),
        Room(30, false, 4, 'B', 3, 4),
        Room(31, false, 4, 'B', 3, 5),
    };
    
    SetConsoleTextAttribute(hConsole, 15); // Resets console colour

    char building = 'z';   //For floor viewing
    bool state = false;  //Default false
    int floor = 0;
    int tempInt = 0; //To assign singular numbers to for printing


    cout << "1)  View daily log" << endl;
    cout << "2)  View rooms and their states" << endl;
    cout << "3)  Simulate card swipe attempt" << endl;
    cout << "4)  View list of people with active cards" << endl;
    cout << "5)  Change room/building's state" << endl;
    cout << "6)  Add, Update, or Remove rooms" << endl;
    cout << "7)  Add or Remove a card user" << endl;
    cout << "8)  Update a card user's information" << endl;

    MenuRetry:    //To allow retrying entering a value
    cout << "\nEnter a number for the option you wish to choose: ";
    
    string UserInputString;  //For use as user's input
    int UserInputInt;     //For use in switch case

    cin >> UserInputString;  //Gets user input

    if (InputValidation(1,UserInputString,1,8) == false) {  //Passes data to input validation function
        cout << "\nInvalid input, re-enter a Number\n\n";
        goto MenuRetry;    //Sends the code back to allow another entry attempt
    }

    else {
        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
    }




    switch (UserInputInt) {    //Will send the user to the appropriate place with appropriate code based on their menu choice
        





        case 1: {
            cout << "1" << endl;
            break;
        }






        case 2: {   //View room and their states
            cout << "2" << endl;

            cout << "\n\nRoom type key: \n\n"; //COLOUR THIS KEY
            SetConsoleTextAttribute(hConsole, 111);
            cout << "Lecture hall" << endl;
            SetConsoleTextAttribute(hConsole, 47);
            cout << "Teaching room" << endl;
            SetConsoleTextAttribute(hConsole, 63);
            cout << "Staff room" << endl;
            SetConsoleTextAttribute(hConsole, 143);
            cout << "Secure room" << endl;
            SetConsoleTextAttribute(hConsole, 15); //Resets colour

            for (int i = 0; i < roomCount; i++) {   //Goes through all rooms

                if (rooms[i].viewRoomBuilding() != building) { //If the building changes in this cycle then a new set of headers are made
                    building = rooms[i].viewRoomBuilding();  //Gets the letter of the building

                    for (int j = 0; j < roomCount; j++) {   //Goes through all rooms in the same building
                        
                        if (rooms[j].viewRoomState() == true && rooms[j].viewRoomBuilding() == building) {   //Checks the floors in the same building for any emergency states
                            
                            for (int i = 0; i < roomCount; i++) {   //Goes through all rooms again
                                
                                if (rooms[i].viewRoomBuilding() == building) { //Sets all rooms within the building to emergency state
                                    rooms[i].updateRoomState(true);
                                }     
                            }
                            state = true;  //For printing the building state
                        }
                    }
                    
                    cout << "\n\n\nBuilding: " << building << endl;   //Output's the headers for the rooms
                    cout << "State: ";

                    if (state == true && rooms[i].viewRoomBuilding() == building) {  //Depending on the state value depends on the output text
                        cout << "Emergency\n\n" << endl;
                    }

                    else {
                        cout << "Normal\n\n";
                    }

                    state = false;  //Resets it after printed inpreperation for the next building. Rooms states would already have been changed earlier if one was emergency

                    floor = rooms[i].viewRoomFloor(); //Floor is the first number of the room

                    cout << "Floor: " << floor << "\n";
                    
                }



                if (rooms[i].viewRoomFloor() != floor) {  //Incase of the first number changing, the floor change will be showed accordingly
                    cout << "\n\nFloor: " << rooms[i].viewRoomFloor() << "\n";
                }

                floor = rooms[i].viewRoomFloor();  //Allows the code above to check if the room floor has changed next cycle

                switch (rooms[i].viewRoomType()) {  //Will colour the rooms depending on their role
                    case 1:
                        SetConsoleTextAttribute(hConsole, 111); //Lecture hall
                        break;
                    case 2:
                        SetConsoleTextAttribute(hConsole, 47); //Teaching room
                        break;
                    case 3:
                        SetConsoleTextAttribute(hConsole, 63); //Staff room
                        break;
                    case 4:
                        SetConsoleTextAttribute(hConsole, 143); //Secure room
                        break;
                    default:
                        SetConsoleTextAttribute(hConsole, 15); //Resets colour
                }

                cout << rooms[i].viewRoomFloor();  //Outputs the room name in the appropriate colour after adding a 0 if its a single digit
                
                if ((rooms[i].viewRoomName() - 10) < 0) { cout << "0" << rooms[i].viewRoomName(); }
                else { cout << rooms[i].viewRoomName(); }


                SetConsoleTextAttribute(hConsole, 15); //Resets colour

                if (rooms[i].viewRoomState() == true) {   //If the building is in emergency then red coloured spaces are output here
                    SetConsoleTextAttribute(hConsole, 207);
                }

                cout << "  ";

                SetConsoleTextAttribute(hConsole, 15); // Removes colour

                if (rooms[i].viewRoomName() % 10 == 0 && rooms[i].viewRoomName() != 0) {  //To get rows of ten, this will drop the line down every 10 rooms by checking the second and last digit
                    cout << "\n\n";
                }

            }

            SetConsoleTextAttribute(hConsole, 15); // Removes colour. Failsafe

            building = 'x';  //Resets building variable to invalid value as its lowercase. This allows the code above to be re-run multiple times

            cout << "\n\n\n\n";

            break;
        }






        case 3: {
            cout << "3" << endl;
            break;
        }
        case 4: {
            cout << "4" << endl;
            break;
        }
        case 5: {
            cout << "5" << endl;
            break;
        }
        case 6: {
            cout << "6" << endl;
            break;
        }
        case 7: {
            cout << "7" << endl;
            break;
        }
        case 8: {
            cout << "8" << endl;
            break;
        }
    }

}


