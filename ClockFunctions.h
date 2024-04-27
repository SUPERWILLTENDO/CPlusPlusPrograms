using namespace std;
#include <string>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>

// String values and char are used for formating clock output.
string hours12;
string hours24;
string minutes;
string seconds;
string amPm;
char colon = ':';

// Int values used for updating time values to add hours, seconds, minutes to clock, and for user menu choice.
int userHours12; 
int userHours24;
int userMinutes;
int userSeconds;
int menuChoice;

// userInputClock function takes initial user input for hours, minutes, seconds.
void userInputClock(int, int, int, string) {
	cout << "Please enter Hour: ";
	cin >> userHours12; // Takes user input for hour

	// While loop verifies user input on hours. 
	while (userHours12 < 1 or userHours12 > 12) {
		cout << "Please enter Hour value between 1 - 12: ";
		cin >> userHours12;
	}
	cout << "Please enter Minutes: ";
	cin >> userMinutes; // Takes user input for minutes.

	// Verifies user input on minutes.
	while (userMinutes < 0 or userMinutes > 59) {
		cout << "Please enter Minutes value between 1 - 12: ";
		cin >> userMinutes;
	}
	cout << "Please enter Seconds: ";
	cin >> userSeconds; // Takes user input on seconds.

	// Verifies user input on seconds.
	while (userSeconds < 0 or userSeconds > 59) {
		cout << "Please enter Seconds value between 1 - 12: ";
		cin >> userSeconds;
	}
	cout << "Please enter AM or PM: ";
	cin >> amPm; // Takes user input on AM or PM.

	// Verifies user input on AM or PM.
	while (amPm != "AM" && amPm != "PM") {
		cout << "Please enter AM or PM: ";
		cin >> amPm;
	}
}

void user24HourClock() {

	if (userHours12 > 0 && userHours12 < 12 && amPm == "PM") {
		userHours24 = userHours12 + 12; // Takes 12 hour clock variable and adds 12.
	}
	if (userHours12 > 0 && userHours12 < 12 && amPm == "AM") {
		userHours24 = userHours12; // If time is before noon, 24 hours is same as 12 hour value.
	}
	if (userHours12 == 12 && amPm == "PM") {
		userHours24 = userHours12; // Sets value to be same as noon, important for later loop functionality. 
	}
}

void twoDigitString() { // Converts user inputs as integers to string values. Adds '0' infront of values less than 9.

	// I converted the integer inputs for hours and changed them to strings. 
	hours12 = to_string(userHours12);
	minutes = to_string(userMinutes);
	seconds = to_string(userSeconds);
	hours24 = to_string(userHours24);

	// If loops check for values less than 9 for 12 hour format, 24 hour format, minutes and seconds. 
	if (userHours12 < 10) {
		hours12.insert(0, 1, '0');
	}
	if (userHours24 < 10) {
		hours24.insert(0, 1, '0');
	}
	if (userMinutes < 10) {
		minutes.insert(0, 1, '0');
	}
	if (userSeconds < 10) {
		seconds.insert(0, 1, '0');
	}
}

// Print clock function outputs the 12 hour and 24 hour clock.
void printClock() {

	// I formated the strings that I made with the function two digit string for ease of use.
	string formatHours12 = (hours12 + colon + minutes + colon + seconds + amPm);
	string formatHours24 = (hours24 + colon + minutes + colon + seconds + amPm);

	cout << "\n";
	cout << "**************************" << "	" << "*************************\n";
	cout << "*     12-Hour Clock      *" << "	" << "*    24-Hour Clock      *\n";
	cout << "*      " << formatHours12 << "        *";
	cout << "      *      " << formatHours24 << "       * \n";
	cout << "**************************" << "	" << "*************************\n";

}

//Print menu function displays menu for user to interact with clock program.
void printMenu() {

	cout << "\n";
	cout << "                " << "************************** \n";
	cout << "                " << "* 1 - Add One Hour       * \n";
	cout << "                " << "* 2 - Add One Minute     * \n";
	cout << "                " << "* 3 - Add One Second     * \n";
	cout << "                " << "* 4 - Exit Program       * \n";
	cout << "                " << "************************** \n";
}

// The function menu operate allows the user to interact with the clock program.
void menuOperate() {

	cout << "Please enter menu choice: ";
	cin >> menuChoice;

	// This while loop checks for valid user input, allows for multple tries until correct. 
	while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4) {
		cout << "Please enter a valid input between 1 - 4. \n";
		cout << "Please enter menu choice: \n";
		cin >> menuChoice;
	}

	// This while loop is for user input 1 or add one hour. 
	while (menuChoice == 1) {
		userHours12++; // Increases userHours12 values.
		userHours24++; // Increases userHours24 values.

		if (userHours12 == 13) { // If statement sets time for 12 hour format to equal 1 at 12 pm and 12 am.
			userHours12 = 1;
		}
		if (userHours24 == 24) { // if statement sets time for 24 hour format at 12 am to equal 0.
			userHours24 = 0;
		}

		if (userHours12 == 12 && userHours24 == 12 && amPm == "AM") { // Sets parameters for noon to change amPm string. 
			amPm = "PM";
		}
		if (userHours12 == 12 && userHours24 == 0 && amPm == "PM") {
			amPm = "AM"; // Sets parameters for midnight or 12 am, where the 24 hour clock will be 0, changes amPm string.
		}

		user24HourClock(); // Calls function to format 24 hour clock again.
		twoDigitString(); // Calls function to update to new integer values for hours, and format them to a string.
		printClock(); // Calls function to output clock again with updated values.

		printMenu(); // Calls the menu again.
		menuOperate(); // Allows for user to interact with clock again.
		break;
	}

	// While loop for user to add a minute to the clock.
	while (menuChoice == 2) {
		userMinutes++; // Adds a minute to the clock. 

		// If user minutes reaches 60 minutes, adds an hour to each clock, resets minutes to 0.
		if (userMinutes == 60) {
			userMinutes = 0;
			userHours12++;
			userHours24++;
		}

		if (userHours12 == 13) {
			userHours12 = 1; // Accounts for AM and PM for 12 hour format
		}
		if (userHours24 == 24) {
			userHours24 = 0; // Accounts for AM and PM for 24 hour format. 
		}

		if (userHours12 == 12 && userHours24 == 12 && userMinutes == 0 && amPm == "AM") {
			amPm = "PM"; // Accounts for PM switch due to adding minutes.
		}
		if (userHours12 == 12 && userHours24 == 0 && userMinutes == 0 && amPm == "PM") {
			amPm = "AM"; // Accounts for AM switch due to adding minutes.
		}

		// I called the functions again for updated values, and continuted user interaction with clock.
		user24HourClock();
		twoDigitString();
		printClock();
		printMenu();
		menuOperate();
		break;
	}

	// While loop for adding seconds to the clock if user enters 3.
	while (menuChoice == 3) {
		userSeconds++;
		if (userSeconds == 60) {
			userSeconds = 0;// Resets seconds to 0 if 60 seconds is reached.
			userMinutes++; // Adds a minute if 60 seconds is reached.
		}

		// I called the functions once more for updated values, and continued user interaction with clock.
		user24HourClock();
		twoDigitString();
		printClock();
		printMenu();
		menuOperate();
		break;
	}

	// If statement for exiting program.
	if (menuChoice == 4) {
		system("cls"); // Clears console of previous outputs. Used for printing only 1 thank you message.
		cout << " \nThank you for using the Chada Clock program!\n"; // Prints thank you message c:
	}
}
