#include <iostream>
#include <fstream> //For  file interactions
#include <string>
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //For colours

using namespace std;

int main()
{
	string text;
	string tempString = "";
	string Name;
	char BuildingLog;
	char Building = 'z';
	char Floor;
	bool State;
	

	int tempInt = 0;
	int i = 0;



	ifstream Data("../RoomTest.txt"); //Reads from the file

	if (!Data.fail()) { //If the file connection is not failed

		if (Data.is_open()) { //If the file is open
			
			while (!Data.eof()) { //While not at the end of the file:
	
				i = 0;
				while (getline(Data, text)) { //Read a line each cycle and saves it as a string to "text"
					i = i + 1; //Will count the number of lines for dynamic array size
				}

				Data.close(); //Closes the file


				int ArraySize = i;
				int tempInt2 = 0;

				ifstream Data("../RoomTest.txt"); //Reads from the file

				if (!Data.fail()) { //If the file is found

					string* Array;  //Creates pointer to memeory for array
					Array = new string[ArraySize];  //Allocates array space (DURING COMPILE/RUNTIME)

					i = 0; //Resets counter
					while (getline(Data, text)) { //Read a line each cycle and saves it as a string to "text"

						Array[i] = text; //Array stores each line of text file
						i = i + 1; //Will move array space along 1
					}


					for (int i = 0; i < ArraySize; i++) { //Will go through each line of the file

						tempString = ""; //Clears value

						if (Array[i] == "-------" || Array[i] == "xxxxxxx" || Array[i] == "id Type EmState") { //Skips any divides or headers
							goto Skip;
						}

						if (isupper(Array[i][0])) {  //Stores the first building thats being read
							BuildingLog = Array[i][0];
						}

						if (Array[i][2] != ':') { //Checks a floor is being read

							/*
							string Name;
							char Building;
							char Floor;
							bool State;
							*/

							Building = BuildingLog;
							Floor = Array[i][0];
							if (Array[i][6] == '0') { State = 0; }
							else { State = 1; }

							//Getting numbers for Name.  No letters or symbols make it here
							tempString += string(1, Array[i][1]);
							tempString += string(1, Array[i][2]);

							Name = tempString;

							cout << BuildingLog << Floor << Name << " " << State << endl;

							//PASS DATA TO A CLASS CONSTRUCTOR
						}



						//cout << Array[i] << endl;

						Skip:; //Bypasses rest of file reading code
					}








					delete[] Array; //Destroys array and all data in it
				}
			}
		}
	}

	else {
		cout << "File error" << endl; //If the file connection is failed
	}


	End:;
	Data.close(); //Closes the file
}