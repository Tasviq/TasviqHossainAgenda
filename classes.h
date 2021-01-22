/*

	Name: Tasviq Hossain | ICS4U1-02
	Dr. Noukhovitch
	Due: October 30, 2020
	C++ Midterm Project: Task Agenda/Calendar Program
				Purpose: Allows user to add, create, delete, and read a created task agenda
				Includes: Classes, Structures, Inheritance, Polymorphism, Pointers, Friends, Objects, Constructors/Destructors, Exceptions,
						  and concepts learned from the Nodes lab and the labs on strings.
						  
    This "classes.h" file includes: The contents and implementations of classes and functions. This file is also a header file
    								rather than a ".cpp" file so that "main.cpp" is the only ".cpp" file to organize the program functionality.
    								Also, classes have been redeclared to make the interpretation and reading of code clearer and simpler

*/

#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "prototypes.h" //Includes the "prototype.h" header file which has the prototypes

int numEvents = 1; //Initializing the numEvents to 1, used as the ID for a task/appointment



//Class named Event that contains a constructor, member "getter" functions, private variables, and a virtual function with polymorphism ------------------------------------
class Event //This is the base class, it will be inherited by the derived classes
{
	private:
		//Declaring private int variables
		int year;
		int month;
		int day;
		int hour;
		int id;

	public:
		Event *next; //Pointer to object of class Event
		Event(int y,int m,int d,int h) //Constructor of class Event
		{
			//Assigning the private variables with the values passed in by the constructor parameters
			year = y;
			month = m;
			day = d;
			hour = h;
			id = numEvents; //Set id as the numEvents (numEvents keeps track of number of events)
			numEvents++; //Increment the numEvents by 1 each time a new event is added
		} //End of Event constructor

		int getId() //Getter function that returns the private variable id
		{
			return id;
		} //End of getId() function

		int getYear() //Getter function that returns the private variable year
		{
			return year;
		} //End of getYear() function

		int getMonth() //Getter function that returns the private variable month
		{
			return month;
		} //End of getMonth() function

		int getDay() //Getter function that returns the private variable day
		{
			return day;
		} //End of getDay() function

		int getHour() //Getter function that returns the private variable hour
		{
			return hour;
		} //End of getHour() function

		//Using polymorphism
		virtual void print() {}; //Declaring polymorphic function using virtual keyword, print() used in the other classes
		
}; //End of base class Event



//Derived Class named Task that contains inheritance, private variable, constructor, and a print function -------------------------------------------
class Task : public Event //Using Inheritence; inheriting from base class Event
{
	private:
		string taskname;

	public:
		Task(string t,int y,int m,int d,int h): Event(y,m,d,h) //Constructor of class Task that has a member constructor of the Event class
		{
			taskname = t; //Assigning the private variable taskname to t which is passed in by the constructor parameter
		} //End of Task constructor

		void print() //Print function that displays the task with all the information (name, date, time)
		{
			cout << "Task #" << getId() << " at " << getDay() << "/" << getMonth() << "/" << getYear() << ", at " << getHour() << ":00:";
			cout << " - " << taskname << endl; //Display task with aligned formatting
		} //End of print() function
		
}; //End of subclass Task



//Derived Class named Appointment that inherits from base class Event; contains private variable, constructor, and print function ---------------------
class Appointment : public Event //Using inheritance
{
	private:
		string aptName;

	public:
		Appointment(string n,int y,int m,int d,int h) : Event(y,m,d,h) //Contains members of the Event constructor
		{
			aptName = n;
		} //End of Appointment constructor

		void print() //Print function that displays the appointment with all the information (name, date, time)
		{
			cout << "Appointment #" << getId() << " on " << getDay() << "/" << getMonth() << "/" << getYear() << ", at " << getHour()  << ":00:";
			cout << " - " << aptName << endl; //Display task with aligned formatting
		} //End of print() function
		
}; //End of subclass Appointment



//Class named Agenda that contains private object pointer, constructors, and member functions ---------------------------------------------------------
class Agenda
{
	private:
		Event *head; //Private pointer to object head of class Event, called head
		Event *temp; //Private "temporary" pointer object of class Event
		Event *original; //Private pointer that stores the original/main data

	public:
		Agenda() //Constructor for class Agenda that initializes a variable
		{
			head = NULL; //Initializing the head to NULL (no value to start with)
		}

		~Agenda() //Destructor for class Agenda that deletes the pointers of objects
		{
			//Deleting the pointers that were assigned to "new ...." 
			delete head;
			delete temp;
			delete original;
		}

		//From class Event, a pointer to the addEvent function is made
		Event *addEvent(int eventChoice,string name,int year,int month,int day,int hour)
		{
			//**This function uses the concepts learned from the nodes lab

			Event *temp; //Temporary pointer object of class Event
			if(eventChoice == 0) //If user chose to make a task
			{
				temp = new Task(name,year,month,day,hour); //Assigning temp to a new task with passed in parameters
			} //End of If statement
			else if(eventChoice == 1) //If user chose to make an appointment
			{
				temp = new Appointment(name,year,month,day,hour); //Assigning temp to a new Appointment with passed in parameters
			} //End of Else if

			temp -> next = NULL; //Assign NULL to be the value next to temp, this makes temp the last spot

			if(head == NULL) //If the head is NULL, in the first iteration, head must be NULL as it is intialized in the constructor
			{
				head = temp; //Assign the temp to head
				return temp; //Return the temp
			} //End of If statement

			Event *original = head; //Another pointer to object of class Event initialized as the value of head

			while (original->next != NULL) //While loop that runs until there is a NULL next to the original (until the last spot)
				original = original->next; //Set original to the next spot

			original->next = temp; //Assign temp to be the value next to original
			return temp; //Return temp

		} //End of *addEvent function


		void addEventPrompts () //Function that displays prompts and gets the information for the variables from user
		{
			int userEventChoice, userYear, userMonth, userDay, userHour, option; //Declaring the int variables
			string errorMsg = " Ensure that the year is from 2020-2050, month in range 1-12, day in 1-31, and hour from 1-23."; //Storing a string in variable to avoid redundant code
			string getInfoMsg = "Enter year, month, day, and hour seperated by spaces (Ex: 2020 11 11 12): "; //Storing a string in variable to avoid redundant code

			try //Try and catch block; throws 2 exceptions: 1 exception thrown if user enters invalid input for task/appointment and another when year, month, day are invalid
			{
				cout << "Would you like to add a task or an appointment?\nEnter 0 for task, 1 for appointment: ";
				int userEventChoice;
				cin >> userEventChoice;

				if (userEventChoice == 0) //If statement: if the user chooses 0, the task commands execute
				{
					cout << "Enter task: ";
					string task;
					cin.ignore(); //Gets rid of the whitespace left by cin >> eventChoice
					getline (cin, task); //Stores the user input to task
					cout << getInfoMsg;
					cin >> userYear >> userMonth >> userDay >> userHour;

					//If statement to validate the user inputs of year, month, day, hour
					if ( userYear >= 2020 && userYear <= 2050 && userMonth >= 1 && userMonth <= 12 && userDay >= 1 && userDay <= 31 && userHour >= 0 && userHour <= 23)
					{
						addEvent (userEventChoice, task, userYear, userMonth, userDay, userHour);
						cout << "\nEvent added." << endl;
					} //End of if statement for validation

					else //If the user inputs are invalid, throw exception
						throw errorMsg;
				} //End of if statement for choice 0

				else if (userEventChoice == 1) // Else If: if user chooses 1, the appointment commands execute
				{
					cout << "Appointment name: ";
					string appointment;
					cin.ignore(); //Gets rid of the whitespace left by cin >> eventChoice
					getline (cin, appointment);
					cout << getInfoMsg;
					cin >> userYear >> userMonth >> userDay >> userHour;

					//If statement to validate the user input of year, month, day, year
					if ( userYear >= 2020 && userYear <= 2050 && userMonth >= 1 && userMonth <= 12 && userDay >= 1 && userDay <= 31 && userHour >= 0 && userHour <= 23)
					{
						addEvent (userEventChoice, appointment, userYear, userMonth, userDay, userHour);
						cout << "\nEvent added." << endl;
					} //End of if statement for validation

					else //If the user inputs are invalid, throw exception
						throw errorMsg;
				} //End of else if statement for choice 1

				else //If invalid input for choice (not 0 or 1), then throw unique exception
					throw string(" Please enter 0 (to add a task) or 1 (to add an appointment).");

			} catch (string exception) //Catch block which displays error messege accordingly
			{ cout << "\nInvalid Input." << exception << endl; } //End of try and catch block

		} //End of addEventPrompts() function


		void listEvents() //Function that lists the events if the events are stored, otherwise an exception is thrown
		{
			try //Try block
			{
				if(head == NULL) //If the head (the first spot) is empty/NULL
				{
					throw 0; //Exception thrown because it means list is empty
				} //End of if statement

				Event *temp = head; //Pointer to object of class Event assigned to head (if head is not NULL)

				while(temp != NULL) //While loop that runs until temp is NULL (until last spot with event data)
				{
					temp -> print(); //Using the pointer to object temp of class Event, the print function is invoked each time
					temp = temp -> next; //Assign the temp to the next spot
				} //End of while loop

			} catch(...) //Catch block
			{ cout << "There are currently no events. List is empty." << endl; } //End of try and catch block
		} //End of listEvents() function


		void filterEvents(int year,int month, int day) //Function that takes the inputted year, month, day and checks for events on that date
		{
			try //Try block
			{
				bool eventFound = false; //Boolean variable eventFound initialized to false, used to track if event is found
				Event *temp = head; //Pointer to object temp of class Event intialized as the head value
				while (temp!=NULL) //While that runs through the sequence of events
				{
					if(temp->getYear() == year && temp->getMonth() == month && temp-> getDay() == day) //If statement that checks if the year and month matches
					{
						temp -> print(); //If the year and month matches, the event in that location is printed
						eventFound = true; //Change eventFound to true once the event is found
					} //End of if statement
					temp=temp->next; //Proceed the temp to the next spot
				} //End of while loop

				if(!eventFound) //If statement that checks if the selected event was found
					throw 0; //Throw exception if the event was not found

			} catch(...) //Catch block with error messege
			{ cout << "No events have been scheduled on this date. ";} //End of try and catch block
		} //End of filterEvents function


		void filterPrompts () //Function that prints prompt, gets information, and invokes filterEvents function with the info
		{
			int filterYear, filterMonth, filterDay;
			cout << "What is the date of the tasks you want to see?\nEnter the year: ";
			cin >> filterYear;
			cout << "Enter the month: ";
			cin >> filterMonth;
			cout << "Enter the day: ";
			cin >> filterDay;
			cout << "\nThese are the events on " <<  filterDay << "/" << filterMonth << "/" << filterYear << ":" << endl << endl;
			filterEvents (filterYear, filterMonth, filterDay); //Invoking the filterEvents with the inputted variables as parameters
		} //End of filterPrompts() function


		void deleteEvent(int id) //Function that deletes the event based on ID number
		{
			try //Try block for exceptions
			{
				Event *original = head; //Pointer to object original of class Event assigned to the head value
				Event *temp = NULL; //Pointer to object temp of class Event assigned to NULL
				string errorMsg = "Event not found\n"; //Error messege for the exception

				if(head->getId() == id)  //If statement that checks if getId in head holds the same value as id
				{
					head = original->next; //Assign the subsequent spot to the head
					delete original; //Delete the original object pointer
					cout << "Deleted event with ID " << id << endl;
					return; //End the function execution
				} //End of if statement
				else
					throw errorMsg;

				while(original->getId() !=id) //While loop that runs when the getId (in the original pointer object) does not return the same id
				{
					temp = original; //Assign the original pointer object to the temp pointer object
					original = original->next; //Proceed original to the next spot
					if(original == NULL) //If statement when original holds NULL value
					{
						throw errorMsg;
						break; //Terminate the while loop if original holds NULL
					}
				} //End of while loop

				if (original != NULL) //If statement if original is not NULL
				{
					temp->next = original->next; //Assign the spot next to temp to the spot next to original
					delete original; //Delete the pointer object original
					cout << "Deleted";
					return; //End the function execution
				} //End of if statement

			} catch(string c) //Catch block
			{
				cout<<c; //Display error message
				return; //Terminate the function execution
			} //End of try and catch block
		} //End of deleteEvent function

		void deleteEventPrompts () //Function that prints prompt, gets information, and invokes deleteEvent function with the info
		{
			cout << "Which event would you like to delete?\nEnter the ID of the event: ";
			int id;
			cin >> id;
			deleteEvent (id); //Invoking function deleteEvent with the id as parameter
		} //End of deleteEventPrompts() function

		//Using friend classes so that this class Agenda can use the private variables of the classes Task, Appointment, and Event
		friend class Task;
		friend class Appointment;
		friend class Event;

}; //End of class Agenda



//------------------------------------------------ Using structures ---------------------------------------------------------------------------------
//Struct named UserInterface that contains member functions that display main menu and options 
struct UserInterface
{
	public:
		char option; //Option variable that stores the user's option choice from menu as char to prevent errors like user entering char in an int variable

		void optionsMenu () //Function that displays the options menu
		{
			cout << "\n__________________________________________________________" << endl;
			cout << "    ___________________________________" << endl;
			cout << "   |           Options Menu            |" << endl;
			cout << "   | 1. Add Event to Agenda            |" << endl;
			cout << "   | 2. List the Events in Agenda      |" << endl;
			cout << "   | 3. Check Event from Specific Date |" << endl;
			cout << "   | 4. Delete an Event from Agenda    |" << endl;
			cout << "   | 5. Exit the program               |" << endl;
			cout << "   |___________________________________|" << endl;
			cout << "\nSelect an option: ";
		} //End of optionsMenu() function

		int setOption () //Setter function that takes the user input of option
		{
                cin >> option; //Store user input in the option variable
                cout << endl;
		} //End of setOption() function

		char getOption () //Getter function that returns the option of user
		{
			return option;
		} //End of getOption() function
		
		void mainMenu () //Function that displays the main menu, title and time/date
		{
			cout << "----------------------------------------------------------" << endl;
			cout << "**********  WELCOME TO THE TASK AGENDA PROGRAM  **********" << endl;
			cout << "****************     By Tasviq Hossain     ***************" << endl << endl;

			//Getting and displaying current date and time from system by using the <ctime> file
			time_t now = time(0); // Current date/time based on current system
   			char* date = ctime(&now); // Convert now to string form
   			cout << "Today's date is: " << date << endl; //Displaying current date and time

   			optionsMenu(); //Display the options menu by invoking the optionsMenu() function
		} //End of mainMenu() function

		void closingMenu () //Function that displays the closing Menu
		{
			cout << "\n--------------   Thanks for using the Task Agenda Program by Tasviq Hossain!   ----------------" << endl;
			cout << "Name: Tasviq Hossain | Dr. Noukhovitch | C++ Midterm Project | ICS4U1-02 | October 30th, 2020 | " << endl;
		} //End of closingMenu() function

}; //End of class UserInterface


#endif // CLASSES_H_INCLUDED
