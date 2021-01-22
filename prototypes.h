/*

	Name: Tasviq Hossain | ICS4U1-02
	Dr. Noukhovitch
	Due: October 30, 2020
	C++ Midterm Project: Task Agenda/Calendar Program
				Purpose: Allows user to add, create, delete, and read a created task agenda
				Includes: Classes, Structures, Inheritance, Polymorphism, Pointers, Friends, Objects, Constructors/Destructors, Exceptions,
						  and concepts learned from the Nodes lab and the labs on strings.
						  
    This "prototypes.h" file includes: The prototypes of the classes and structures, and the functions associated with them

*/

#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

//C++ Libraries
#include<iostream> //This library allows input and output
#include <ctime> //This library allows access to the current date in the system
#include <string> //This library allows working with strings
using namespace std;

//Declaring Event class (Base class)
class Event; 
    //Contains constructor
    //Declaring functions used in class Event
    int getId();
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    void print();

//Declaring Task class (Derived class of Event)
class Task; 
    //Contains a constructor
    //Contains virtual polymorphic print function which is from the Event base class
    
//Declaring Appointment class (Derived class of Event)
class Appointment; 
    //Contains a constructor
    //Contains virtual polymorphic print function which is from the Event base class
     
//Declaring Agenda class
class Agenda; 
    //Contains constructor
    //Contains destructor
    //Declaring functions used in class Agenda
    Event *addEvent(int eventChoice,string name,int year,int month,int day,int hour);
    void addEventPrompts ();
    void listEvents();
    void filterEvents(int year,int month, int day);
    void filterPrompts ();
    void deleteEvent(int id);
    void deleteEventPrompts ();
    //Contains 3 friend classes: friend of Task, Appointment, and Event

//Declaring structure called UserInterface
struct UserInterface;
	//Declaring functions used in the UserInterface structure
    void optionsMenu ();
    void mainMenu ();
    void closingMenu ();
    int setOption ();
    int getOption ();

#endif // PROTOTYPES_H_INCLUDED
