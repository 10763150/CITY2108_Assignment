#include <iostream>
#include <string>
#include <Windows.h>  //For colours
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //For colours



class Room {   //Creates the class for rooms
    char type='0';  //Creates variables
    bool emerState=false;
    int id=0;
    char building='z';
    int name=0;
    int floor=0;
    
    public:
        
        Room() {};  //Default blank constructor initialises the array variables
        
        Room(int Id, bool EmerState, char Type, char Building, int Floor, int Name) {  //Constructor takes variables passed to it upon their creation
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
        char viewRoomType() { return type; }
        bool viewRoomState() { return emerState; }
        int viewRoomId() { return id; }
        char viewRoomBuilding () { return building; }
        int viewRoomFloor() { return floor; }
        int viewRoomName() { return name; }

        ~Room() {     //Destructor
           //cout << "Destroyed Room\n";
        }

};




class Card {   //Creates the class for card
    int id = 0;  //Creates variables
    int role = 1;
    string userName = "Default Name";

public:

    Card() {};  //Default blank constructor initialises the array variables

    Card(int Id, int Role, string UserName) {  //Constructor takes variables passed to it upon their creation
        id = Id;
        role = Role;
        userName = UserName;
    }

    void logCard() {}
    void updateCardRole(int CardRole) { role = CardRole; }
    void updateCardUserName(string CardUserName) { userName = CardUserName; }
    int viewCardId() { return id; }
    int viewCardRole() { return role; }
    string viewCardUserName() { return userName; }

    ~Card() {     //Destructor
       //cout << "Destroyed Card\n";
    }

};




bool InputValidation(int InputValidationMode, string InputValidationData, int InputValidationIntMin, int InputValidationIntMax) {
    int InputValidationInt;

    if (InputValidationMode == 1) { //User input check for int values

        for (size_t i = 0; i < InputValidationData.length(); i++) {   //Checking input all characters are a number before converting to int to avoid error

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




    if (InputValidationMode == 2) { //User input check for a single letter

        if (InputValidationData.length() == 1 && isalpha(InputValidationData[0])) {   //If theres 1 character and its a letter it returns true
            return true; 
        }
        else {
            return false; //Will return false if the 2 statements are not true
        }

        
    }




    if (InputValidationMode == 3) {  //User input check for room name format
        //Need to check for 4 characters. 1st is a letter, next 3 are numbers
        
        if (InputValidationData.length() == 4 && isalpha(InputValidationData[0]) && isdigit(InputValidationData[1]) && isdigit(InputValidationData[2]) && isdigit(InputValidationData[3])) {
            return true;
        }
        else {
            return false;
        }
    
    }




    if (InputValidationMode == 4) {  //User input check for only letters and 1 space
    //Need to check for 4 characters. 1st is a letter, next 3 are numbers

        bool oneSpaceCheck = false;

        for (size_t j = 0; j < InputValidationData.length(); j++) { //Checks all characters input (for just spaces)

            if (isspace(InputValidationData[j]) && oneSpaceCheck == true) { //Checks for more than 1 space
                return false;
            }

            if (isspace(InputValidationData[j]) && oneSpaceCheck == false) { //Checks only for a first space
                oneSpaceCheck = true;
            }

            if (j + 1 == InputValidationData.length() && oneSpaceCheck == false) { //Checks for no spaces
                return false;
            }

        }

        for (size_t i = 0; i < InputValidationData.length(); i++) { //Checks all characters input (for just letters)

            if (isalpha(InputValidationData[i])) { //Checks for letters
            }

            else if (!isspace(InputValidationData[i])) { //Ignores spaces, only checking for non letters
                return false;
            }

        }

        return true;

    }


    return false; //Failsafe will return false to ensure a response
}



int main()
{
   
    //Room types:
    //0)To be removed  1)Unassigned  2)Lecture hall  3)Teaching room  4)Staff room  5)Secure room

    int roomCount = 34; //For For loops to go through all rooms and not beyond to a non-existant array space

    Room rooms[34] = {  //Creating an array of the rooms, allocating the data to an array number, allowing searching
        
        //Creation of hard coded room objects
        //int Id, bool EmerState, int Type, char Building, int floor, int Name 
        
        Room( 0, false, '0', 'A', 1, 1), //Building A
        Room( 1, false, '1', 'A', 1, 2), //Floor 1
        Room( 2, false, '1', 'A', 1, 3),
        Room( 3, false, '1', 'A', 1, 4),
        Room( 4, false, '2', 'A', 1, 5),
        Room( 5, false, '2', 'A', 1, 6),
        Room( 6, false, '2', 'A', 1, 7),
        Room( 7, false, '2', 'A', 1, 8),
        Room( 8, false, '3', 'A', 1, 9),
        Room( 9, false, '3', 'A', 1, 10),
        Room(10, false, '3', 'A', 1, 11),
        Room(11, false, '3', 'A', 1, 12),
        Room(12, false, '4', 'A', 1, 13),

        Room(13, false, '4', 'A', 2, 1), //Floor 2
        Room(14, false, '4', 'A', 2, 2),
        Room(15, false, '4', 'A', 2, 3),
        Room(16, false, '5', 'A', 2, 4),
        Room(17, false, '5', 'A', 2, 5),
        Room(18, false, '5', 'A', 2, 6),
        Room(19, false, '5', 'A', 2, 7),


        Room(20, false, '1', 'B', 1, 1), //Building B
        Room(21, false, '1', 'B', 1, 2), //Floor 1
        Room(22, false, '2', 'B', 1, 3),
        Room(23, false, '2', 'B', 1, 4),

        Room(24, false, '2', 'B', 2, 1),
        Room(25, false, '3', 'B', 2, 2), //Floor 2
        Room(26, false, '3', 'B', 2, 3),

        Room(27, false, '4', 'B', 3, 1),
        Room(28, false, '4', 'B', 3, 2), //Floor 3
        Room(29, false, '5', 'B', 3, 3),
        Room(30, false, '5', 'B', 3, 4),
        Room(31, false, '5', 'B', 3, 5),
    };
    


    //Roles:
    //0)Deactivated  1)Unassigned  2)Staff member  3)Student  4)Visitor/Guest  5)Contract  cleaner  6)Manager  7)Security  8)Emergency responder 
    //Unassigned cards cannot be used to avoid an Id being reused and activating a new and old card

    int cardCount = 10; //For For loops to go through all cards and not beyond to a non-existant array space

    Card cards[10] = {  //Creating an array of the cards, allocating the data to an array number, allowing searching
        
        //Creation of hard coded room objects
        //int Id, int Role, string UserName
       
        Card(1, 0, "Jerry Banks"),
        Card(2, 1, "Bob Foreks"),
        Card(3, 2, "Smith Guy"),
        Card(4, 3, "Garith Hobbs"),
        Card(5, 4, "Robert Harth"),
        Card(6, 5, "Harry Lloyds"),
        Card(7, 6, "Kyle Swift"),
        Card(8, 7, "Jack Thompson"),

    };




    SetConsoleTextAttribute(hConsole, 15); // Resets console colour

    char building = 'z';   //For floor viewing
    bool state = false;  //Default false
    int floor = 0;

    int tempInt = 0; //Temporary values to be used as required when    eg to assign singular numbers to for printing
    int tempInt2 = 0;
    string tempString = "";
    char tempChar = 'x';
    char tempChar2 = 'x';
    bool tempBool = false;

    ProgramRedo:  //To allow the easy retart of the code without placing it all in a loop

    cout << "\n\n1)  View daily log" << endl;
    cout << "2)  View rooms and their states" << endl;
    cout << "3)  Simulate card swipe attempt" << endl;
    cout << "4)  View list of people with active cards" << endl;
    cout << "5)  Change building's state" << endl;
    cout << "6)  Add, Update, or Remove rooms" << endl;
    cout << "7)  Add or Remove a card user" << endl;
    cout << "8)  Update a card user's information" << endl;

    MenuRetry:    //To allow retrying entering a value
    cout << "\nEnter a number for the option you wish to choose: ";
    
    string UserInputString;  //For use as user's input
    int UserInputInt;     
    char UserInputChar;

    cin >> UserInputString;  //Gets user input
    
    if (InputValidation(1,UserInputString,1,8) == false) {  //Passes data to input validation function
        cout << "\nInvalid input, re-enter a Number\n\n";
        goto MenuRetry;    //Sends the code back to allow another entry attempt
    }

    else {
        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
    }




    switch (UserInputInt) {    //Will send the user to the appropriate place with appropriate code based on their menu choice
        





        case 1: {  //View daily log
            cout << "1" << endl;
            break;
        }






        case 2: {   //View room and their states
            cout << "2" << endl;

            cout << "\n\nRoom type key: ";
            cout << "\n\nUnassigned";
            SetConsoleTextAttribute(hConsole, 111);
            cout << "\nLecture hall";
            SetConsoleTextAttribute(hConsole, 47);
            cout << "\nTeaching room";
            SetConsoleTextAttribute(hConsole, 63);
            cout << "\nStaff room";
            SetConsoleTextAttribute(hConsole, 143);
            cout << "\nSecure room";
            SetConsoleTextAttribute(hConsole, 15); //Resets colour
            cout << "\n";

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
                    case '1':
                        SetConsoleTextAttribute(hConsole, 15); //Unassigned
                        break;
                    case '2':
                        SetConsoleTextAttribute(hConsole, 111); //Lecture hall
                        break;
                    case '3':
                        SetConsoleTextAttribute(hConsole, 47); //Teaching room
                        break;
                    case '4':
                        SetConsoleTextAttribute(hConsole, 63); //Staff room
                        break;
                    case '5':
                        SetConsoleTextAttribute(hConsole, 143); //Secure room
                        break;
                    default:
                        SetConsoleTextAttribute(hConsole, 15); //Resets colour
                }

                if (rooms[i].viewRoomType() != '0') {  //Checks the room isnt to be deleted

                    cout << rooms[i].viewRoomFloor();  //Outputs the room name in the appropriate colour after adding a 0 if its a single digit
                    
                    if ((rooms[i].viewRoomName() - 10) < 0) { cout << "0" << rooms[i].viewRoomName(); } //Outputs single digit rooms with a 0 infront for formatting
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



            }

            SetConsoleTextAttribute(hConsole, 15); // Removes colour. Failsafe

            building = 'x';  //Resets building variable to invalid value as its lowercase. This allows the code above to be re-run multiple times

            cout << "\n\n\n\n";

            break;
        }






        case 3: { //Simulate card swipe attempt
            
            //Based on building state, room type, user role, and time

            int Time = 0;
            int TimeHours = 0;
            int TimeMinutes = 0;

            MenuRetryCase3_1:

            cout << "\nWhich room do you want to access? Format- building letter, floor, then room number (adding a 0 infront if it's a single digit)" << endl;
            cout << "(eg A203 is building A, floor 2, room 3) : ";

            cin >> UserInputString;  //Gets user input

            if (InputValidation(3, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                cout << "\nInvalid input, re-enter a room name\n\n";
                goto MenuRetryCase3_1;    //Sends the code back to allow another entry attempt
            }

            tempString = "";  //Clears it before use again

            //Gets just the room number, removing the building and floor digits
            for (int i = 0; i < UserInputString.length(); i++) {  //Checks length of input

                if (isdigit(UserInputString[i])) {  //Checks what isnt a letter

                    if ((UserInputString[2] == '0' && i == 2) || i == 1) {  //Checks the 3rd digit for a 0, signifying a 1 digit room. But wont error on a room thats a multiple of ten. Also removes floor number.
                    }  //If this runs it prevents the else statement from running

                    else {   //Wont run for 1 cycle if there is a 1 digit input to avoid passing 03 instead of 3
                        tempString += string(1, UserInputString[i]); //Adds all non letters to a string
                    }
                }
            }

            UserInputInt = stoi(tempString); //Changes the room number to int to allow comparson to room data

            tempChar = toupper(UserInputString[0]); //Capitalises the building letter

            tempString = UserInputString[1];  //Middle statement of If statement needs to be compared to an int value
            tempInt = stoi(tempString);

            //char Building, int floor, int Name
            for (int i = 0; i < roomCount; i++) { //Goes through all rooms

                //Checks all 3 data entered match
                if ((rooms[i].viewRoomBuilding() == tempChar) && (rooms[i].viewRoomFloor() == tempInt) && (rooms[i].viewRoomName() == UserInputInt)) {

                    if (rooms[i].viewRoomType() == '0') { //Checks if the room is to be deleted
                        cout << "\nRoom is flagged for deletion\n\n";
                        goto MenuRetryCase3_1;    //Sends the code back to allow another entry attempt
                    }

                    tempChar = rooms[i].viewRoomBuilding();  //Saving details for determining entry later
                    tempChar2 = rooms[i].viewRoomType();


                    MenuRetryCase3_2:    //To allow retrying entering a value

                    cout << "\n\n1)  (Do not use)" << endl;
                    cout << "2)  Staff member" << endl;
                    cout << "3)  Student" << endl;
                    cout << "4)  Visitor/Guest" << endl;
                    cout << "5)  Contract cleaner" << endl;
                    cout << "6)  Manager" << endl;
                    cout << "7)  Security" << endl;
                    cout << "8)  Emergency responder" << endl;

                    MenuRetryCase3_3:    //To allow retrying entering a value
                    cout << "\nEnter a number for the role you wish to use: ";


                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 2, 8) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase3_3;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
                    }

                    tempInt = UserInputInt;




                    MenuRetryCase3_4:    //To allow retrying entering a value
                    cout << "\nEnter the hour your entry is (0-23): ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 0, 23) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a value\n\n";
                        goto MenuRetryCase3_4;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        TimeHours = stoi(UserInputString); //Converts the string user input to int
                    }



                    MenuRetryCase3_5:    //To allow retrying entering a value
                    cout << "\nEnter the minute your entry is (0-59): ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 0, 59) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a value\n\n";
                        goto MenuRetryCase3_5;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        TimeMinutes = stoi(UserInputString); //Converts the string user input to int
                    }



                    goto MenuRetryCase3_6;

                }

            }

            cout << "This room does not exist\n\n";
            goto MenuRetryCase3_1;  //Will send the code back up to the user can retry


            MenuRetryCase3_6:  //When all details are successfully entered: 

            Time = (TimeHours * 60) + TimeMinutes;


            cout << "1)  Normal state" << endl;
            cout << "2)  Emergency state" << endl;

            MenuRetryCase3_7:    //To allow retrying entering a value
            cout << "\nEnter a number for the option you wish to choose: ";


            cin >> UserInputString;  //Gets user input

            if (InputValidation(1, UserInputString, 1, 2) == false) {  //Passes data to input validation function
                cout << "\nInvalid input, re-enter a Number\n\n";
                goto MenuRetryCase3_7;    //Sends the code back to allow another entry attempt
            }

            else {
                UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
            }


            tempBool = UserInputInt-1; //As bool is 1 or 0 and input is 1 or 2




            //Building state = tempBool
            //Building = tempChar
            //Room type = tempInt2
            //User role = tempInt
            //Time = TimeHours & TimeMinutes

            //Room types:
            //0)To be removed  1)Unassigned  2)Lecture hall  3)Teaching room  4)Staff room  5)Secure room
            
            //Card Roles:
            //0)Deactivated  1)Unassigned  2)Staff member  3)Student  4)Visitor/Guest  5)Contract  cleaner  6)Manager  7)Security  8)Emergency responder 
 
            //    Lecture hall         Staff member           5:30     to     24:00          Normal state                                                   
            if ((tempChar2 == '2') && ( ((tempInt == 2) && ((Time >= 330) && (Time < 1440)) && (tempBool == 0))
                                  /*      Student             8:30     to     22:00          Normal state  */
                                  || ((tempInt == 3) && ((Time >= 510) && (Time < 1320)) && (tempBool == 0))
                                  /*   Visitor/Guest          8:30     to     22:00         Normal state  */
                                  || ((tempInt == 4) && ((Time >= 510) && (Time < 1320)) && (tempBool == 0)) 
                                  /*  Contract cleaner        5:30      to     10:30      or      17:30      to     22:30          Normal state  */
                                  || ((tempInt == 5) && (((Time >= 330) && (Time < 630)) || ((Time >= 1050) && (Time < 1350))) && (tempBool == 0)) 
                                  /*  Manager   anytime   Normal state  */
                                  || ((tempInt == 6) && (tempBool == 0)) 
                                  /*  Security anytime any state  */
                                  ||  (tempInt == 7)         
                                  /*Emergency responder anytime  Emergency state*/
                                  || ((tempInt == 8)    &&    (tempBool == 1)))
                                    ) {
                
                cout << "\nAccess Granted\n";
            }


            //       Teaching room         Staff member           5:30     to     24:00          Normal state                                                   
            else if ((tempChar2 == '3') && (((tempInt == 2) && ((Time >= 330) && (Time < 1440)) && (tempBool == 0))
                                      /*      Student             8:30     to     22:00          Normal state  */
                                      || ((tempInt == 3) && ((Time >= 510) && (Time < 1320)) && (tempBool == 0))
                                      /*   Visitor/Guest    Never accessable  */

                                      /*  Contract cleaner        5:30      to     10:30      or      17:30      to     22:30          Normal state  */
                                      || ((tempInt == 5) && (((Time >= 330) && (Time < 630)) || ((Time >= 1050) && (Time < 1350))) && (tempBool == 0))
                                      /*  Manager   anytime   Normal state  */
                                      || ((tempInt == 6) && (tempBool == 0))
                                      /*  Security anytime any state  */
                                      ||  (tempInt == 7)
                                      /*Emergency responder anytime  Emergency state*/
                                      || ((tempInt == 8) && (tempBool == 1)))
                                        ) {
                    
                     cout << "\nAccess Granted\n";
                 }


            //         Staff room         Staff member           5:30     to     24:00          Normal state                                                   
            else if ((tempChar2 == '4') && (((tempInt == 2) && ((Time >= 330) && (Time < 1440)) && (tempBool == 0))
                                      /*      Student      Never accessable */

                                      /*   Visitor/Guest   Never accessable*/

                                      /*  Contract cleaner        5:30      to     10:30      or      17:30      to     22:30          Normal state  */
                                      || ((tempInt == 5) && (((Time >= 330) && (Time < 630)) || ((Time >= 1050) && (Time < 1350))) && (tempBool == 0))
                                      /*  Manager   anytime   Normal state  */
                                      || ((tempInt == 6) && (tempBool == 0))
                                      /*  Security anytime any state  */
                                      ||  (tempInt == 7)
                                      /*Emergency responder anytime  Emergency state*/
                                      || ((tempInt == 8) && (tempBool == 1)))
                                        ) {
                 
                     cout << "\nAccess Granted\n";
                 }


            //        Secure room         Staff member           5:30     to     24:00          Normal state                                                   
            else if ((tempChar2 == '5') && (((tempInt == 2) && ((Time >= 330) && (Time < 1440)) && (tempBool == 0))
                                      /*      Student        Never accessable */

                                      /*   Visitor/Guest     Never accessable */

                                      /*  Contract cleaner   Never accessable */

                                      /*  Manager   anytime   Normal state  */
                                      || ((tempInt == 6) && (tempBool == 0))
                                      /*  Security anytime any state  */
                                      || (tempInt == 7)
                                      /*Emergency responder anytime  Emergency state*/
                                      || ((tempInt == 8) && (tempBool == 1)))
                                        ) {
            
                    cout << "\nAccess Granted\n";
                 }

            else {  //If no statements are true then entry is refused
                cout << "\nAccess Denied\n" << endl;
            }



            break;
        }






        case 4: {  //View list of people with active cards
            cout << "4" << endl;
            break;
        }






        case 5: {  //Change a building's state

            cout << "Which building do you want to change the state of?: ";

            MenuRetryCase5_1:

            cin >> UserInputString;

            if (InputValidation(2, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                cout << "\nInvalid input, re-enter a singular letter\n\n";
                goto MenuRetryCase5_1;    //Sends the code back to allow another entry attempt
            }

            UserInputChar = toupper(UserInputString[0]);  //Saves the string as a char and capitalises it

            for (int i = 0; i < roomCount; i++) {   //Checks all room's letters to ensure the building exists
                
                if (rooms[i].viewRoomBuilding() == UserInputChar) { //If one room has the same building letter as the user inputs, then the code continues
                    goto MenuRetryCase5_2;
                }  
            }

            cout << "\nBuilding does not exist\nRe-enter a letter\n\n\n\n"; 
            goto MenuRetryCase5_1;

            MenuRetryCase5_2:

            for (int i = 0; i < roomCount; i++) {   //Goes through all rooms
                //cout << rooms[i].viewRoomBuilding() << endl;
                if (rooms[i].viewRoomBuilding() == UserInputChar) {  //Checks rooms in the selected building

                    if (rooms[i].viewRoomState() == true) { rooms[i].updateRoomState(false); }  //The state will be flipped
                    else { rooms[i].updateRoomState(true); }

                }
            }
            cout << "\n\n";   //Spaces out the menu
            break;
        }






        case 6: {   //Add, Update, or Remove rooms

            cout << "1)  Add a room" << endl;
            cout << "2)  Remove a room" << endl;
            cout << "3)  Update a room's type" << endl;

            MenuRetryCase6_1:    //To allow retrying entering a value
            cout << "\nEnter a number for the option you wish to choose: ";


            cin >> UserInputString;  //Gets user input

            if (InputValidation(1, UserInputString, 1, 3) == false) {  //Passes data to input validation function
                cout << "\nInvalid input, re-enter a Number\n\n";
                goto MenuRetryCase6_1;    //Sends the code back to allow another entry attempt
            }

            else {
                UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
            }


            switch (UserInputInt) {    //Will send the user to the appropriate place with appropriate code based on their menu choice



                case 1: { //Add a room
                    MenuRetryCase6_1_1:

                    cout << "Enter room details: Format- building letter, floor, then room number (adding a 0 infront if it's a single digit)" << endl;
                    cout << "(eg A203 is building A, floor 2, room 3) : ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(3, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a room name\n\n";
                        goto MenuRetryCase6_1_1;    //Sends the code back to allow another entry attempt
                    }

                    tempString = "";  //Clears it before use again

                    //Gets just the room number, removing the building and floor digits
                    for (int i = 0; i < UserInputString.length(); i++) {  //Checks length of input

                        if (isdigit(UserInputString[i])) {  //Checks what isnt a letter

                            if ((UserInputString[2] == '0' && i == 2) || i == 1) {  //Checks the 3rd digit for a 0, signifying a 1 digit room. But wont error on a room thats a multiple of ten. Also removes floor number.
                            }  //If this runs it prevents the else statement from running

                            else {   //Wont run for 1 cycle if there is a 1 digit input to avoid passing 03 instead of 3
                                tempString += string(1, UserInputString[i]); //Adds all non letters to a string
                            }
                        }
                    }

                    UserInputInt = stoi(tempString); //Changes the room number to int to allow comparson to room data

                    tempChar = toupper(UserInputString[0]); //Capitalises the building letter

                    tempString = UserInputString[1];  //Middle statement of If statement needs to be compared to an int value
                    tempInt = stoi(tempString);


                    //char Building, int floor, int Name
                    for (int i = 0; i < roomCount; i++) { //Goes through all rooms

                        //Checks all 3 data entered dont match to an existing room
                        if ((rooms[i].viewRoomBuilding() == tempChar) && (rooms[i].viewRoomFloor() == tempInt) && (rooms[i].viewRoomName() == UserInputInt)) {

                            cout << "\nRoom already exists\n\n";
                            goto MenuRetryCase6_1_1;    //Sends the code back to allow another entry attempt

                        }

                    }

                    tempChar2 = '0'; //Needed to store the type before room creation

                    cout << "\nWhat type do you want the room to be?\n";

                    cout << "\n\nRoom type key: \n\n";
                    cout << "1) Unassigned" << endl;
                    cout << "2) Lecture hall" << endl;
                    cout << "3) Teaching room" << endl;
                    cout << "4) Staff room" << endl;
                    cout << "5) Secure room" << endl;

                    MenuRetryCase6_1_2:    //To allow retrying entering a value
                    cout << "\nEnter a number for the option you wish to choose: ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 1, 5) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase6_1_2;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        tempChar2 = UserInputString[0]; //Converts the string user input to int for the switch case
                    }



                    for (int i = 0; i < roomCount; i++) { //Goes through all rooms

                        if (rooms[i].viewRoomId() != (rooms[i+1].viewRoomId()-1)) {  //Checks the next array space is clear

                            i++; //Moves i to the clear array space

                            //int Id, bool EmerState, char Type, char Building, int floor, int Name
                            rooms[i] = Room(i, false, tempChar2, tempChar, tempInt, UserInputInt); //Creates the room in the new array space

                            break; //Ensures only 1 room is written
                        }

                    }




                    break;
                }

                      

                case 2: { //Remove a room

                    MenuRetryCase6_2_1:

                    cout << "Which room? Format- building letter, floor, then room number (adding a 0 infront if it's a single digit)" << endl;
                    cout << "(eg A203 is building A, floor 2, room 3) : ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(3, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a room name\n\n";
                        goto MenuRetryCase6_2_1;    //Sends the code back to allow another entry attempt
                    }

                    tempString = "";  //Clears it before use again

                    //Gets just the room number, removing the building and floor digits
                    for (int i = 0; i < UserInputString.length(); i++) {  //Checks length of input

                        if (isdigit(UserInputString[i])) {  //Checks what isnt a letter

                            if ((UserInputString[2] == '0' && i == 2) || i == 1) {  //Checks the 3rd digit for a 0, signifying a 1 digit room. But wont error on a room thats a multiple of ten. Also removes floor number.
                            }  //If this runs it prevents the else statement from running

                            else {   //Wont run for 1 cycle if there is a 1 digit input to avoid passing 03 instead of 3
                                tempString += string(1, UserInputString[i]); //Adds all non letters to a string
                            }
                        }
                    }

                    UserInputInt = stoi(tempString); //Changes the room number to int to allow comparson to room data

                    tempChar = toupper(UserInputString[0]); //Capitalises the building letter

                    tempString = UserInputString[1];  //Middle statement of If statement needs to be compared to an int value
                    tempInt = stoi(tempString);

                    //char Building, int floor, int Name
                    for (int i = 0; i < roomCount; i++) { //Goes through all rooms
                        
                        //Checks all 3 data entered match
                        if ((rooms[i].viewRoomBuilding() == tempChar) && (rooms[i].viewRoomFloor() == tempInt) && (rooms[i].viewRoomName() == UserInputInt)) {
                            rooms[i].updateRoomType('0');
                            goto MenuRetryCase6_2_2;
                        }
                    }

                    cout << "This room does not exist\n\n";
                    goto MenuRetryCase6_2_1;  //Will send the code back up to the user can retry

                    MenuRetryCase6_2_2:
                    break;
                }



                case 3: { //Update a room's type
                    
                    MenuRetryCase6_3_1:

                    cout << "Which room? Format- building letter, floor, then room number (adding a 0 infront if it's a single digit)" << endl;
                    cout << "(eg A203 is building A, floor 2, room 3) : ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(3, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a room name\n\n";
                        goto MenuRetryCase6_3_1;    //Sends the code back to allow another entry attempt
                    }

                    tempString = "";  //Clears it before use again

                    //Gets just the room number, removing the building and floor digits
                    for (int i = 0; i < UserInputString.length(); i++) {  //Checks length of input

                        if (isdigit(UserInputString[i])) {  //Checks what isnt a letter

                            if ((UserInputString[2] == '0' && i == 2) || i == 1) {  //Checks the 3rd digit for a 0, signifying a 1 digit room. But wont error on a room thats a multiple of ten. Also removes floor number.
                            }  //If this runs it prevents the else statement from running

                            else {   //Wont run for 1 cycle if there is a 1 digit input to avoid passing 03 instead of 3
                                tempString += string(1, UserInputString[i]); //Adds all non letters to a string
                            }
                        }
                    }

                    UserInputInt = stoi(tempString); //Changes the room number to int to allow comparson to room data

                    tempChar = toupper(UserInputString[0]); //Capitalises the building letter

                    tempString = UserInputString[1];  //Middle statement of If statement needs to be compared to an int value
                    tempInt = stoi(tempString); 

                    //char Building, int floor, int Name
                    for (int i = 0; i < roomCount; i++) { //Goes through all rooms

                        //cout << "DEBUG  Looking_for:Recieved   " << tempChar << ":" << rooms[i].viewRoomBuilding() << "   " << tempInt << ":" << rooms[i].viewRoomFloor() << "   " << UserInputInt << ":" << rooms[i].viewRoomName() << "\n";

                        //Checks all 3 data entered match
                        if ((rooms[i].viewRoomBuilding() == tempChar) && (rooms[i].viewRoomFloor() == tempInt) && (rooms[i].viewRoomName() == UserInputInt)) {
                            
                            if (rooms[i].viewRoomType() == '0') { //Checks if the room is to be deleted
                                cout << "\nRoom is flagged for deletion\n\n";
                                goto MenuRetryCase6_3_1;    //Sends the code back to allow another entry attempt
                            }

                            cout << "\nWhat type do you want to change the room to?\n";

                            cout << "\n\nRoom type key: \n\n";
                            cout << "1) Unassigned" << endl;
                            cout << "2) Lecture hall" << endl;
                            cout << "3) Teaching room" << endl;
                            cout << "4) Staff room" << endl;
                            cout << "5) Secure room" << endl;

                            MenuRetryCase6_3_2:    //To allow retrying entering a value
                            cout << "\nEnter a number for the option you wish to choose: ";

                            cin >> UserInputString;  //Gets user input

                            if (InputValidation(1, UserInputString, 1, 5) == false) {  //Passes data to input validation function
                                cout << "\nInvalid input, re-enter a Number\n\n";
                                goto MenuRetryCase6_3_2;    //Sends the code back to allow another entry attempt
                            }

                            else {
                                UserInputChar = UserInputString[0]; //Converts the string user input to int for the switch case
                            }

                            rooms[i].updateRoomType(UserInputChar); //Updates the room info and jumps past the failure statement
                            goto MenuRetryCase6_3_3;

                        }

                    }

                    cout << "This room does not exist\n\n";
                    goto MenuRetryCase6_3_1;  //Will send the code back up to the user can retry

                    MenuRetryCase6_3_3:
                    break;
                }


 
            }



            break;
        }






        case 7: {  //Add or remove a card user
            
            cout << "1)  Remove a card user" << endl;
            cout << "2)  Add a card user" << endl;

            MenuRetryCase7_1:    //To allow retrying entering a value
            cout << "\nEnter a number for the option you wish to choose: ";


            cin >> UserInputString;  //Gets user input

            if (InputValidation(1, UserInputString, 1, 2) == false) {  //Passes data to input validation function
                cout << "\nInvalid input, re-enter a Number\n\n";
                goto MenuRetryCase7_1;    //Sends the code back to allow another entry attempt
            }

            else {
                UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
            }


            switch (UserInputInt) {    //Will send the user to the appropriate place with appropriate code based on their menu choice

                case 1: { //Remove a card user

                    MenuRetryCase7_1_1:    //To allow retrying entering a value

                    cout << "\nEnter the card Id you want to remove: ";

                    MenuRetryCase7_1_2:
                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 0, 99999) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase7_1_1;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
                    }

                    for (int i = 0; i < cardCount; i++) { //Goes through all cards

                        if (cards[i].viewCardId() == UserInputInt && cards[i].viewCardRole() != 0) { //Checks that card id exists and isn't unassigned (so the Id cant be reused)
                            goto MenuRetryCase7_1_3;
                        }

                    }

                    cout << "\nCard Id is not active, re-enter an id\n\nEnter the card Id you want to change the username of: ";
                    goto MenuRetryCase7_1_2;

                    MenuRetryCase7_1_3:

                    cards[UserInputInt-1].updateCardRole(0); //Sets the role to 0, deactivating the card. 
                           //Not deleted to avoid a new card with the same Id as an old one being made. 
                           //This allows the old card to be used again which is a security threat, so the old ID will be kept


                    break;
                }



                case 2: { //Add a card user



                    cout << "\n\n1)  Unassigned" << endl;
                    cout << "2)  Staff member" << endl;
                    cout << "3)  Student" << endl;
                    cout << "4)  Visitor/Guest" << endl;
                    cout << "5)  Contract cleaner" << endl;
                    cout << "6)  Manager" << endl;
                    cout << "7)  Security" << endl;
                    cout << "8)  Emergency responder" << endl;

                    MenuRetryCase7_2_1:    //To allow retrying entering a value
                    cout << "\nEnter the number for the role to be stored: ";

                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 1, 8) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase7_2_1;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
                    }

                    tempInt = UserInputInt; //Saves selected Id as UserInputInt is reused




                    cin.ignore(); //Required to set up data for getline

                    MenuRetryCase7_2_2:    //To allow retrying entering a value
                    cout << "\n(In the format of- forname surname)\nEnter the username to be saved to the card: ";

                    getline(cin, UserInputString);  //Gets user input and keeps the space

                    if (InputValidation(4, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a name\n\n";
                        goto MenuRetryCase7_2_2;    //Sends the code back to allow another entry attempt
                    }


                    //To capitalise the name correctly. All becomes lower case, first letter is capitalised, then the first letter after the space

                    for (int i = 0; i < UserInputString.length(); i++) { //Goes through length of string

                        UserInputString[i] = tolower(UserInputString[i]); //Gets letter to lowercase

                        if (i == 0) { //First letter becomes uppercase
                            UserInputString[i] = toupper(UserInputString[i]);
                        }

                        if (tempBool == true) { //If previous cycle was a space then this letter is capitalised
                            UserInputString[i] = toupper(UserInputString[i]);
                            tempBool = false;
                        }

                        if (isspace(UserInputString[i])) { //The next letter after a space is capitalised
                            tempBool = true;
                        }

                    }

                    tempBool = false;
                    tempString = UserInputString;



                    for (int i = 0; i < cardCount; i++) { //Goes through all cards

                        //cout << "i:" << i << " " << "Id:" << cards[i].viewCardId() << endl;
                        if (cards[i].viewCardId() != (i+1)) {  //Checks the array space is clear

                            cards[i] = Card((i + 1), tempInt, tempString); //Writes data to object
                            break; //Ensures only 1 is written
                        }
                        
                    }


                    break;
                }





            }


            break;
        }






        case 8: {  //Update a car user's information
            
            cout << "1)  Update a card user's name" << endl;
            cout << "2)  Update a card user's role" << endl;

            MenuRetryCase8_1:    //To allow retrying entering a value
            cout << "\nEnter a number for the option you wish to choose: ";


            cin >> UserInputString;  //Gets user input

            if (InputValidation(1, UserInputString, 1, 2) == false) {  //Passes data to input validation function
                cout << "\nInvalid input, re-enter a Number\n\n";
                goto MenuRetryCase8_1;    //Sends the code back to allow another entry attempt
            }

            else {
                UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
            }


            switch (UserInputInt) {    //Will send the user to the appropriate place with appropriate code based on their menu choice

                case 1: { //Update a card user's name
                    
                    MenuRetryCase8_1_1:    //To allow retrying entering a value

                    cout << "\nEnter the card Id you want to change the username of: ";

                    MenuRetryCase8_1_2:
                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 0, 99999) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase8_1_1;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
                    }

                    for (int i = 0; i < cardCount; i++) { //Goes through all cards

                        if (cards[i].viewCardId() == UserInputInt && cards[i].viewCardRole() != 0) { //Checks that card id exists and isn't unassigned (so the Id cant be reused)
                            goto MenuRetryCase8_1_3;
                        }

                    }

                    cout << "\nCard Id is not active, re-enter an id\n\nEnter the card Id you want to change the username of: ";
                    goto MenuRetryCase8_1_2;

                    MenuRetryCase8_1_3:

                    cin.ignore(); //Required to set up data for getline

                    MenuRetryCase8_1_4:    //To allow retrying entering a value
                    cout << "\n(In the format of- forname surname)\nEnter the username to be saved to the card: ";

                    getline(cin,UserInputString);  //Gets user input and keeps the space
                    
                    if (InputValidation(4, UserInputString, 0, 0) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a name\n\n";
                        goto MenuRetryCase8_1_4;    //Sends the code back to allow another entry attempt
                    }


                    //To capitalise the name correctly. All becomes lower case, first letter is capitalised, then the first letter after the space
       
                    for (int i = 0; i < UserInputString.length(); i++) { //Goes through length of string

                        UserInputString[i] = tolower(UserInputString[i]); //Gets letter to lowercase

                        if (i == 0) { //First letter becomes uppercase
                            UserInputString[i] = toupper(UserInputString[i]);
                        }

                        if (tempBool == true) { //If previous cycle was a space then this letter is capitalised
                            UserInputString[i] = toupper(UserInputString[i]);
                            tempBool = false;
                        }

                        if (isspace(UserInputString[i])) { //The next letter after a space is capitalised
                            tempBool = true;
                        }

                    }

                    tempBool = false;


                    for (int i = 0; i < cardCount; i++) { //Goes through all cards

                        if (cards[i].viewCardId() == UserInputInt) {  //On the selected card the info is updated
                            cards[i].updateCardUserName(UserInputString);
                        }

                    }



                    break;
                }



                case 2: { //Update card user's role

                    MenuRetryCase8_2_1:    //To allow retrying entering a value

                    cout << "\nEnter the card Id you want to change the role of: ";

                    MenuRetryCase8_2_2:
                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 0, 99999) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase8_2_1;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
                    }

                    for (int i = 0; i < cardCount; i++) { //Goes through all cards

                        if (cards[i].viewCardId() == UserInputInt && cards[i].viewCardRole() != 0) { //Checks that card id exists and isn't unassigned (so the Id cant be reused)
                            goto MenuRetryCase8_2_3;
                        }

                    }

                    cout << "\nCard Id is not active, re-enter an id\n\n";
                    goto MenuRetryCase8_2_2;

                    MenuRetryCase8_2_3:




                    tempInt = UserInputInt; //Saves selected Id as UserInputInt is reused

                    cout << "\n\n1)  Unassigned" << endl;
                    cout << "2)  Staff member" << endl;
                    cout << "3)  Student" << endl;
                    cout << "4)  Visitor/Guest" << endl;
                    cout << "5)  Contract cleaner" << endl;
                    cout << "6)  Manager" << endl;
                    cout << "7)  Security" << endl;
                    cout << "8)  Emergency responder" << endl;
                    
                    MenuRetryCase8_2_4:    //To allow retrying entering a value
                    cout << "\nEnter a number for the option you wish to choose: ";


                    cin >> UserInputString;  //Gets user input

                    if (InputValidation(1, UserInputString, 1, 8) == false) {  //Passes data to input validation function
                        cout << "\nInvalid input, re-enter a Number\n\n";
                        goto MenuRetryCase8_2_4;    //Sends the code back to allow another entry attempt
                    }

                    else {
                        UserInputInt = stoi(UserInputString); //Converts the string user input to int for the switch case
                    }


                    for (int i = 0; i < cardCount; i++) { //Goes through all cards

                        if (cards[i].viewCardId() == tempInt) {  //On the selected card the info is updated
                            cards[i].updateCardRole(UserInputInt);
                        }

                    }


                    break;
                }





            }



            break;
            
        }


 

        default: {  //Should never run
            cout << "Menu Defaulted" << endl;
        }

    }

    /*
    //To see the new card info   Debug
    cout << "\nDEBUG\n";
    for (int i = 0; i < cardCount; i++) {
        cout << cards[i].viewCardId() << " " << cards[i].viewCardRole() << " " << cards[i].viewCardUserName() << endl;
    }
    */

    goto ProgramRedo;   //Will replay the code

}


