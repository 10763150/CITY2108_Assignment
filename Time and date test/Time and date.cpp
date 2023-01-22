#pragma warning(disable : 4996) //Disables a warning that prevents it running as its "unsafe"
#include <iostream> //For cout commands
#include <ctime> //For getting the time in many seconds from 1970 January 1st
#include <windows.h> //For the sleep function

using namespace std;

int main()
{
    //STOLE AND ADAPTED FROM https://www.softwaretestinghelp.com/date-and-time-in-cpp/

    while (true) {  //Just makes this run over and over

        time_t ttime = time(0);                 //Gets the time from the system clock
        tm* local_time = localtime(&ttime);     //



        int years = 1900 + local_time->tm_year; //Assigns the appropriate data to the variable
        int months = 1 + local_time->tm_mon;
        int days = local_time->tm_mday;

        cout << years << "/";  //Prints the year and then adds a slash on the end
        cout << months << "/";
        cout << days << endl << endl; //2 endl to drop the next line down twice



        int hours = local_time->tm_hour;   //Assigns the appropriate data to the variable
        int minutes = local_time->tm_min;
        int seconds = local_time->tm_sec;

        cout << hours << ":";  //Prints the hours and then adds a colon after
        cout << minutes << ":";
        cout << seconds << endl;


        Sleep(100); //Will add a 100ms delay here

        printf("\33[2K\033[A\33[2K\033[A\33[2K\033[A");  //Clears the line and moves the cursor up to clear that line (\33[2K\033[A)
                                                         //Does it 3 times to clear the console before printing the data again

    }


    return 0;
}