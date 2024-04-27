
using namespace std;
# include "ClockFunctions.h" // Includes header file, where I put the functions.
#include <string>
#include <iomanip>
#include <iostream>

int main() {
	userInputClock(userHours12, userMinutes, userSeconds, amPm); // calls user input function for 12 hour clock
	user24HourClock(); // Calls format for 24 hour clock.
	twoDigitString(); // Calls the function to change int user inputs to string values.
	printClock(); // Calls function to output clock
	printMenu(); // Calls function to output menu
	menuOperate(); // Calls function for user interactions with menu.

}

