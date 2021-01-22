/*

	Name: Tasviq Hossain | ICS4U1-02
	Dr. Noukhovitch
	Due: October 30, 2020
	C++ Midterm Project: Task Agenda/Calendar Program
				Purpose: Allows user to add, create, delete, and read a created task agenda
				Includes: Classes, Structures, Inheritance, Polymorphism, Pointers, Friends, Objects, Constructors/Destructors, Exceptions,
						  and concepts learned from the Nodes lab and the labs on strings.

    This "main.cpp" file includes: The main function which controls the user inputs for the main menu, exceptions, and the
                                   execution of corresponding functions using the objects of classes from the header file "clsses.h"
*/

#include "prototypes.h" //Includes the "prototypes.h" header file which contains the class and function prototypes
#include "classes.h" //Includes the "classes.h" header file which contains the contents of the classes and functions

//Main function
int main()
{
	//Declaring objects
	UserInterface interface; //Declares interface object of struct UserInterface
	Agenda agenda; //Object agenda of class Agenda

	interface.mainMenu(); //Invoking mainMenu function from class userInterface to display Main Menu and options

	bool eventAdded = false; //Boolean variable used to ensure that user does not choose delete event (option 4) before adding any event.
	bool running = true; //Loop control variable for while loop called running set as true
	while (running) //While loop that runs until running is set to false
	{
		try //Try and catch block, throws exception when user enters invalid option (out of range)
		{
			interface.setOption(); //Invoking the setOption() to have the user input the option
			
			//The follow if and else if statements check which option the user chooses and executes corresponding functions
			if (interface.getOption() == '1') //The condition is if the getOption() (based on user input in setOption function) returns 1
			{
				cout << "-------------   Option 1: Add Event to Agenda   -------------" << endl;
				eventAdded = true; //Event added set as true, now user can delete if desired
				agenda.addEventPrompts(); //Invoking addEventPrompts function from class Agenda if option 1
			} //End of if statement for choice 1
			
			else if (interface.getOption() == '2') //If user chooses option 2
			{
				cout << "-------------   Option 2: List the Events in Agenda    -------------" << endl;
				agenda.listEvents(); //Invoking listEvents function from class Agenda if option 2
				cout << endl;
			} //End of else if for choice 2 
			
			else if (interface.getOption() == '3') //If user chooses option 3
			{
				cout << "-------------   Option 3: Check Event from Specific Date   -------------" << endl;
				agenda.filterPrompts(); //Invoking filterEvents function from class Agenda if option 3
				cout << endl;
			} //End of else if for choice 3
			
			else if (interface.getOption() == '4') //If user chooses option 4
			{
				if (!eventAdded) //If the user chose to delete event (option 4) without any events being added already
					throw string("There are no events to delete as the agenda is currently empty. Add an event first.\n");
				else //Else: user can delete if an event has already been added
				{
					cout << "-------------   Option 4: Delete an Event from Agenda    -------------" << endl;
					agenda.deleteEventPrompts(); //Invoking deleteEvent function from class Agenda if option 4
					cout << endl;
				} //End of else statement
			} //End of else if for choice 4
			
			else if (interface.getOption() == '5') //If user chooses option 5
			{
					interface.closingMenu(); //Invoking closingMenu function from class userInterface if option 6
					running = false; //Set running as false to terminate the loop when user exits via option 6
			} //End of else if for choice 5
			
			else //If user entered an invalid choice for the option, throw exception
					throw string("Invalid input. Enter a valid option between 1-6."); //Throwing exception

		} catch (string error) { //Catch block that displays the error messege of invalid input
			cout << error;
		} //End of try and catch block

		if (interface.getOption() != '5') //If user does not want to exit
			interface.optionsMenu(); 	//Display the options

	} //End of while loop

	return 0;
}
