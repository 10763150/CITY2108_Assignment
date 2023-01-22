#include <iostream>
#include <fstream> //For  file interactions
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
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


				ofstream Data("../CardTest.txt"); //Makes a blank file inplace of the last one

				for (int i = 0; i < ArrayCardSize; i++) { //Goes through old text file lines


					tempString1 = ""; //Clears stored characters from last loop
					tempString2 = "";
					tempString3 = "";


					for (int j = 0; j < arrayCard[i].length(); j++) { //Goes through the old file line letter by letter. Gets old line Id and role

						//cout << ":" << arrayCard[i][j] << " j:" << j << endl;

						if (arrayCard[i][j] == ' ' && i != 0 && j != 0) { //If there is a space then the Id is fully read and stops the loop

							tempString2 = arrayCard[i][j+1]; //The next character will then be the role number

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
					//cout << "Id: " << Id << endl;
					//cout << "tI: " << tempInt1 << endl << endl;

					if (i != 0 && Id == tempInt1 && EnteringNewCard == false && tempInt2 != 0) { //If the Id matches an existing value then the new 
						//line is printed in place of the old file one. Also a role of 0 cannot be changed as its deactivated

						Data << tempInt1 << " " << Role << " " << userName << endl; //Saves user entered card in file
						cout << "Card updated: " << tempInt1 << " " << Role << " " << userName << endl;
						goto Skip; //Avoids printing the line that was replaced
					}

					else if (tempInt2 == 0 && i != 0 && tempInt1 == Id && EnteringNewCard == false) { //If the role is 0 and not the first line and was chosen
						cout << "Card Id is deactivated and cant be changed" << endl;
					}

					else if (EnteringNewCard == true) {

						if (i == ArrayCardSize-1 || ArrayCardSize == 1) { //Will only print the new card line at the bottom of the file
							tempInt1 = tempInt1 + 1;
							Data << arrayCard[i] << endl; //Print old file line in the file
							Data << tempInt1 << " " << Role << " " << userName << endl; //Saves user entered card in file
							cout << "New Card printed: " << tempInt1 << " " << Role << " " << userName << endl;
							goto Skip; //Avoids printing the line that was replaced
						}
					}	

					Data << arrayCard[i] << endl; //Print old file line in the file
					Skip:;
					tempInt1 = tempInt1 + 1; //Will increment from the previous Id
				}
				delete[] arrayCard; //Destroys array and all data in it
			}
		}
	}

	else {  //Creates the file
		Data.close();
		ofstream Data("../CardTest.txt"); //Makes the file

		Data << "0 Id Role Name" << endl; //Puts in header and gives a number for card Id's to use to continue from

		cout << "File not found. New file created" << endl; //If the file connection is failed

		Data.close();
		goto Rerun;   //Once this is printed the rest of the code wont run until it is saved, so by closing and reopening it will work
	}

	Data.close(); //Closes the file


}
