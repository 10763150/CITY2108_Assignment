#include <iostream>
#include <fstream> //For  file interactions
#include <string>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //For colours

using namespace std;

int main()
{
	string text;
	string tempString;
	string tempString2;
	bool tempBool = false;
	bool tempBool2 = false;
	bool tempBool3 = false;
	int i = 0;
	int tempInt;
	int tempInt2;
	int tempInt3;



	char BuildingLog = 'z'; //Stores what last building was sent to the file

	Rerun:

	ifstream Data("../../RoomTest.txt"); //Reads from the file

	if (!Data.fail()) { //If the file is found

		if (Data.is_open()) { //If the file is open

			//HARD CODED ROOM
			char Building = 'A';  //A CLASS WILL PASS THIS DATA
			char Floor = '4';     //DIRECTARY IS 2 LEVELS HIGHER NOW
			string Name = "16";
			char Role = '2';



			i = 0;
			while (getline(Data, text)) { //Read a line each cycle and saves it as a string to "text"
				i = i + 1; //Will count the number of lines for dynamic array size
			}

			Data.close(); //Closes the file


			int ArraySize = i;
			int tempInt2 = 0;

			ifstream Data("../../RoomTest.txt"); //Reads from the file

			if (!Data.fail()) { //If the file is found

				string* arrayRoom;  //Creates pointer to memeory for array
				arrayRoom = new string[ArraySize];  //Allocates space (DURING COMPILE/RUNTIME)

				i = 0; //Resets counter
				while (getline(Data, text)) { //Read a line each cycle and saves it as a string to "text"

					arrayRoom[i] = text; //Array stores each line of text file
					i = i + 1; //Will move array space along 1

				}


				for (int i = 0; i < ArraySize; i++) { //Goes through old text file lines

					if (isupper(arrayRoom[i][0])) {  //Stores the first building thats being read
						BuildingLog = arrayRoom[i][0];
					}

					if ((BuildingLog == Building) && (arrayRoom[i][0] == Floor) && (arrayRoom[i][1] == Name[0]) && (arrayRoom[i][2] == Name[1]) && (arrayRoom[i][4] == Role)) {
						cout << "Room already exists" << endl;     //Will check for the room Id already existing with the same role
						delete[] arrayRoom; //Destroys array and all data in it
						goto End;
					}

				}


				ofstream Data("../../RoomTest.txt"); //Makes a blank file inplace of the last one

				for (int i = 0; i < ArraySize; i++) { //Goes through old text file lines

					tempString = ""; //Clears stored characters
					tempString2 = "";

					if (arrayRoom[0] == "xxxxxxx") { //Checks for an empty document and places headers in
						Data << Building << " :Building" << endl;
						Data << "0 :State" << endl;
						Data << "id Type EmState" << endl;
						tempBool2 = true;

						Data << arrayRoom[ArraySize - 1]; //Will output the bottom x line
						Data.close();
						goto Rerun;   //Once this is printed the rest of the code wont run until it is saved, so by closing and reopening it will work
					}

					if (arrayRoom[i] == "xxxxxxx" && BuildingLog != Building && tempBool2 == false && i == ArraySize - 1) {
						Data << "xxxxxxx" << endl;						//Checks if a new building should be made and is at the bottom of the
						Data << Building << " :Building" << endl;		//list, via seeing a seperator and the building of the room being
						Data << "0 :State" << endl;						//placed is different than last building read
						Data << "id Type EmState" << endl;
						tempBool2 = true;

						Data << arrayRoom[ArraySize - 1]; //Will output the bottom x line
						Data.close();
						goto Rerun;   //Once this is printed the rest of the code wont run until it is saved, so by closing and reopening it will work
					}

					if ((BuildingLog == Building) && (arrayRoom[i][0] == Floor) && (((arrayRoom[i][1] == Name[0]) && (arrayRoom[i][2] == Name[1])) || (arrayRoom[i][1] == '0') && (arrayRoom[i][2] == Name[0]))) {
						//If the room in the old file is the same as the user entered one, dont print old file, only user entered one
						cout << "here20\n";
						if (Role == '0') {
							cout << "here16\n";
							cout << arrayRoom[i + 1] << " " << arrayRoom[i - 1] << endl;

							if ((arrayRoom[i+1] == "-------" && arrayRoom[i - 1] == "-------") || (arrayRoom[i+1] == "-------" && arrayRoom[i+2] == "xxxxxxx") ) {
								//Prevents 2 floor dividers being left when the only room in a floor is removed. Or when last floor in bottom of file is removed
								cout << "here18" << endl;
								i = i + 1;
								
							}
							goto Skip2;
						}
						cout << "here17\n";
						tempInt2 = stoi(Name); //Saves the number of the Room the user entered
						if (tempInt2 < 10) { Data << Floor << "0" << Name << " " << Role << " 0" << endl; } // If name is a single digit then a 0 is added infront of it
						else { Data << Floor << Name << " " << Role << " 0" << endl; }
						tempBool = true;
						cout << "Room role updated: " << Floor << tempString2 << "  " << arrayRoom[i][4] << "-->" << Role << endl;
						goto Skip2; //Prevents the room being given the option to be printed again below
					}

					if (tempBool == false) { //As only 1 room is added at a time this will skip rest of code and go right to print rest of old file
						cout << "here1 i:" << i << " Line:  " << arrayRoom[i] << "\n";

						if (arrayRoom[i][2] == ':' && arrayRoom[i][3] == 'B') { //Gets the building letter whenever ":B" is found
							BuildingLog = arrayRoom[i][0];
						}

						//cout << "Building: " << Building << "  BuildingLog: " << BuildingLog << endl;

						if (Building != BuildingLog) { //If the building of the user input room is different that the building last scanned from the file, print the next line
							cout << "here1.2 " << endl;
							goto Skip;
						}

						if (i > 0) { //Prevents the code below checking for array space -1

							cout << "here1.3" << endl;

							if ((arrayRoom[i - 1][1] == 'd') && (i == ArraySize - 1)) { //Checks if its the very first and only room in a building
								cout << "here1.5\n";
								goto printRoom;
							}

							cout << "here1.6\n";

							if (arrayRoom[i][0] == Floor || arrayRoom[i - 1][0] == Floor || ((arrayRoom[i - 1][1] == 'd') && (arrayRoom[i] == "xxxxxxx")) || arrayRoom[i - 1] == "-------") {
								//Checks the floor on the file line above is the same. Or it is the first room under a header
								cout << "here2\n";

								if (arrayRoom[i][0] == Floor || arrayRoom[i] == "xxxxxxx") {
									//Checks if the floor to be printed on this line is the same or are x's

									cout << "here3\n";

									//Get old file room number as int for ordering
									tempString += string(1, arrayRoom[i][1]);
									tempString += string(1, arrayRoom[i][2]);

									//Gets the old file line before for ordering
									if (i + 1 != ArraySize) { //if it is not the last line (to avoid getting char's of nonexistant lines)
										cout << "here3.1\n";
										tempString2 += string(1, arrayRoom[i - 1][1]);
										tempString2 += string(1, arrayRoom[i - 1][2]);
									}

									if (arrayRoom[i] != "xxxxxxx") { //Prevent comparason and just prints the new line is x's are reached
										cout << "here3.2\n";

										tempInt = stoi(tempString); //Saves the number of the Room to be printed
										tempInt2 = stoi(Name); //Saves the number of the Room the user entered

										if (isdigit(tempString2[0]) && isdigit(tempString2[1])) { //Checks that stoi wont crash the code by being passed a non number

											tempInt3 = stoi(tempString2); //Saves the number of the Line above (if no letters)
											cout << "here3.3" << endl;

											//Now that tempInt3 is a number:
											if ((tempInt2 < tempInt) && (tempInt2 > tempInt3)) {
												//If the room the user adds is SMALLER than the room to be printed,
												//and the room the user adds is BIGGER than the number before it: Print it
												cout << "here4\n";

												goto printRoom;
											}
											else { //If the floor wont fit in order here, then the next line is printed and next cycle begins
												cout << "here4.2\n";
												if (Role != '0') {
													cout << "here4.3\n";
													goto Skip;
												}

											}

										}
										else if (arrayRoom[i - 1][1] == 'd' || arrayRoom[i - 1] == "-------") { //Checks if the line above is the headers/floor divider and so wont use the line above
											cout << "here3.4 " << tempInt2 << " <= " << tempInt << endl;
											if ((tempInt2 <= tempInt)) { //Will compare if the room the user input is smaller than the one to be printed is
												cout << "here3.5\n";    //or the same room in which is will replace to update the role
												goto printRoom;
											}
											else {
												cout << "here3.6\n";
												goto Skip;
											}
										}

										if (tempInt < tempInt2) { //Will compare to only the line to be printed as there is no
											cout << "here3.7\n";  //line above to give tempInt3 a value. This is only reached
											goto printRoom;       //if the goto's above are not triggered by tempInt3
										}
										else { //Makes the next cycle run
											cout << "here3.8\n";
											if (Role != '0') {
												cout << "here3.9\n";
												goto Skip;
											}
										}



									}

									else { //If the line is x's then the room is just printed
										cout << "here4.5\n";
										goto printRoom;
									}



								}

								if (arrayRoom[i - 1][1] == 'd' && arrayRoom[i][0] != 1) { //If its the first floor in the building, print
									cout << "here5\n";                            //Also checks that theres atleast 1 floor
									goto printRoom;
								}

								if (arrayRoom[i] == "-------" && arrayRoom[i - 1][0] == Floor) { //Checks that the floor above is the same, and a floor divider is to be printed
									cout << "here5.1\n";
									tempString += string(1, arrayRoom[i - 1][1]);
									tempString += string(1, arrayRoom[i - 1][2]);

									if (isdigit(tempString[0]) && isdigit(tempString[0])) { //Avoids passing a non number to Stoi
										cout << "here5.2\n";
										tempInt = stoi(tempString); //Saves the number of the Room to be printed
										tempInt2 = stoi(Name); //Saves the number of the Room the user entered

										if (tempInt < tempInt2) { //Will compare if the user entered room belongs under the room above
											cout << "here5.3\n";
											goto printRoom;
										}
										else { //Makes the next cycle run
											cout << "here5.4\n";
											goto Skip;
										}
									}
								}



								cout << "here6\n";
							}

							else if (isdigit(arrayRoom[i - 1][0]) && isdigit(arrayRoom[i - 1][2]) && arrayRoom[i - 1][0] != Floor && arrayRoom[i] == "-------" && Building == BuildingLog) {
								//If the floor above is different, and not a letter or colon, and the line to be printed is a floor divider
								//then floor above and below will be checked so the floor is printed in the right order
								cout << "here7\n";
								cout << arrayRoom[i - 1][0] << "<" << arrayRoom[i + 1][0] << " " << arrayRoom[i + 1][0] << ">" << Floor << endl;
								if ((arrayRoom[i - 1][0] < arrayRoom[i + 1][0]) && (arrayRoom[i + 1][0] > Floor)) { //Checks if the floor above is smaller and floor below is larger
									cout << "here8\n";
									Data << "-------" << endl;
									goto printRoom;
								}
							}

							else if (arrayRoom[i - 1] == "id Type EmState" && isdigit(arrayRoom[i][0])) {
								//If the floor to be printed is different, and the floor above it is the header,
								//then the user enterd floor is printed above with a divider below itself
								if ((arrayRoom[i][0] > Floor)) { //Checks if the user entered floor is smaller than the one to be printed
									cout << "here8.5\n"; //Prints the room and then the divider. Cant use printRoom as the divider wouldn't be placed

									tempInt2 = stoi(Name); //Saves the number of the Room the user entered
									if (tempInt2 < 10) { Data << Floor << "0" << Name << " " << Role << " 0" << endl; } // If name is a single digit then a 0 is added infront of it
									else { Data << Floor << Name << " " << Role << " 0" << endl; }

									tempBool = true;
									cout << "Room printed: " << Floor << " " << Name << "  " << Role << endl;

									Data << "-------" << endl;
								}
							}

							else if (isdigit(arrayRoom[i - 1][0]) && isdigit(arrayRoom[i - 1][2]) && arrayRoom[i - 1][0] != Floor && arrayRoom[i] == "xxxxxxx" && Building == BuildingLog) {
								cout << "here9\n";
								//If the floor above is different, and not a letter or colon, and the line to be printed is the 
								//end of the building, and its in the same building as the last one checked, Then make a new floor
								Data << "-------" << endl;
								goto printRoom;
							}

							if (Name.length() == 1) {  //If name is a single digit number, then it is saved as a string with 0 infront of it
								tempString = "0";
								tempString2 = tempString + Name;
							}
							else {
								tempString2 = Name;
							}

							if (1 == 2 || ((Role == '0') && (/*tempString[1] == arrayRoom[i][2]*/arrayRoom[i][2] != ':'))) { //Stores print code here and only accessable if goto is used (This is like a locally placed function)
								tempBool = true;               //Also checks that State doesnt get in
								printRoom:
								cout << "here10\n";
								//cout << BuildingLog << ":" << Building << " & " << arrayRoom[i][0] << ":" << Floor << " & (" << arrayRoom[i][1] << ":" << Name[0] << " & " << arrayRoom[i][2] << ":" << Name[1] << ") or (" << arrayRoom[i][1] << ":" << "0" << " & " << arrayRoom[i][0] << ":" << Name[0] << ")" << endl;



								if (((BuildingLog == Building) && (arrayRoom[i][0] == Floor)) && (arrayRoom[i][1] == tempString2[0] && arrayRoom[i][2] == tempString2[1])) {
									//Checks if the new room is the same as the old. If so then the old one isnt printed but the new one is
									//Unless if the role is 0
									cout << "here11\n";
									if (Role == '0') {
										cout << "here12\n";
										goto Skip2;
									}
									cout << "here13\n";
									tempInt2 = stoi(Name); //Saves the number of the Room the user entered
									if (tempInt2 < 10) { Data << Floor << "0" << Name << " " << Role << " 0" << endl; } // If name is a single digit then a 0 is added infront of it
									else { Data << Floor << Name << " " << Role << " 0" << endl; }
									tempBool = true;
									cout << "Room role updated: " << Floor << tempString2 << "  " << arrayRoom[i][4] << "-->" << Role << endl;
									goto Skip2; //Prevents the room being given the option to be printed again below
								}

								else { //The the room is new to the file, this prints it
									//Unless if the role is 0
									cout << "here14\n";
									if (Role == '0') {
										cout << "here15\n";
										goto Skip;
									}


									tempInt2 = stoi(Name); //Saves the number of the Room the user entered
									if (tempInt2 < 10) { Data << Floor << "0" << Name << " " << Role << " 0" << endl; } // If name is a single digit then a 0 is added infront of it
									else { Data << Floor << Name << " " << Role << " 0" << endl; }

									tempBool = true;
									cout << "Room printed: " << Floor << tempString2 << "  " << Role << endl;

								}

							}

						}
					}

				Skip:
					if ((BuildingLog == Building) && (arrayRoom[i][0] == Floor) && (arrayRoom[i][1] == Name[0]) && (arrayRoom[i][2] == Name[1])) {
						//Checks if the new room is the same as the old. If so then the old one isnt printed but the new one is
						cout << "Room role updated: " << Floor << " " << Name << "  " << arrayRoom[i][4] << "-->" << Role << endl;
						tempBool = true;
					}

					//If type is 0 in an old file line, then to delete the room it wont be saved
					else if (arrayRoom[i][4] != '0') {

						if (arrayRoom[i] == "-------" && arrayRoom[i-1] == "-------") {
							//Prevents 2 floor dividers being left when the only room in a floor is removed
							cout << "here19" << endl;
							goto Skip2;
						}

						Data << arrayRoom[i] << endl; //Prints what was copied in the last file
						cout << "Printed: " << arrayRoom[i] << endl << endl;
					}
				Skip2:;
				}






				tempBool = false;
				BuildingLog = 'z';
				delete[] arrayRoom; //Destroys array and all data in it
			}
		}
	}

	else {  //Creates the file

		ofstream Data("../../RoomTest.txt"); //Makes the file

		Data << "xxxxxxx";
		//Data << "\n101 0 0" << endl;  This is for debug
		//Data << "102 1 0" << endl;  A new file should contain the top part to avoid
		//Data << "103 2 0" << endl;  reading a blank line in a blank file and crashing


		cout << "File not found. New file created" << endl; //If the file connection is failed

		Data.close();
		goto Rerun;   //Once this is printed the rest of the code wont run until it is saved, so by closing and reopening it will work
	}

	End:
	Data.close(); //Closes the file



}