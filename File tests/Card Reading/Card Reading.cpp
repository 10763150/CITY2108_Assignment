#include <iostream>
#include <fstream> //For  file interactions
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	while (true) {
		string text2;
	}
	string text;
	string tempString1;
	string tempString2;
	string tempString3;
	int tempInt1;
	int tempInt2 = 0;
	int i1;

	Rerun:

	ifstream Data("../CardTest.txt"); //Reads from the file

	if (!Data.fail()) { //If the file is found

		if (Data.is_open()) { //If the file is open

			//HARD CODED CARD      A CLASS WILL PASS THIS DATA
			int Role = 4;
			int Id = 2;
			string userName = "Bob Bill";
			bool EnteringNewCard = false; //Id will be ignored. Role and username will be placed on the next new Id



			i1 = 0;
			while (getline(Data, text)) { //Read a line each cycle and saves it as a string to "text"
				i1 = i1 + 1; //Will count the number of lines for dynamic array size
			}

			Data.close(); //Closes the file


			int ArrayCardSize = i1;

			ifstream Data("../CardTest.txt"); //Reads from the file

			if (!Data.fail()) { //If the file is found

				string* arrayCard;  //Creates pointer to memeory for array
				arrayCard = new string[ArrayCardSize];  //Allocates space (DURING COMPILE/RUNTIME)

				i1 = 0; //Resets counter
				while (getline(Data, text)) { //Read a line each cycle and saves it as a string to "text"

					arrayCard[i1] = text; //Array stores each line of text file
					i1 = i1 + 1; //Will move array space along 1
				}


				for (int i = 1; i < ArrayCardSize; i++) { //Goes through old text file lines
					//Starts at 1 to avoid the headers

					tempString1 = ""; //Clears stored characters from last loop
					tempString2 = "";
					tempString3 = "";


					for (int j = 0; j < arrayCard[i].length(); j++) { //Goes through the old file line letter by letter. Gets old line Id and role

						//cout << ":" << arrayCard[i][j] << " j:" << j << endl;

						if (arrayCard[i][j] == ' ' && i != 0 && j != 0) { //If there is a space then the Id is fully read and stops the loop

							tempString2 = arrayCard[i][j + 1]; //The next character will then be the role number

							tempInt2 = stoi(tempString2);

							j = j + 3;

							for (int x = j; x < arrayCard[i].length(); x++) {

								tempString3 += string(1, arrayCard[i][x]); //Adds the read character to tempString3 to get the full name
							}
							break;
						}
						tempString1 += string(1, arrayCard[i][j]); //Adds the read character to tempString
					}

					tempInt1 = stoi(tempString1);

					cout << "Line Read: " << tempInt1 << " " << tempInt2 << " " << tempString3 << endl;

				}
				delete[] arrayCard; //Destroys array and all data in it
			}
		}
	}

	else {  //If the file to be read is not found
		cout << "File not found." << endl; //If the file connection is failed
		Data.close();
	}

}
