#include "classes.h"

/*
Dhwanil Chokshi 
CS 163
Program 2

	The main purpose of this program was to use the stack data structure with linear linked list of arrays
	and to use the queue data structure with circular linked list. Mixing these data structures enabled us 
	to create an efficient application which helps the user plan their trip. First the user will plan their
	stops for the trip, which will be enqueued into the circular list. After the user is done planning, they
	will reach their destination, and the information will be dequeued and pushed into stack. This will help
	the user know when they have reached their destination. As they pop the stack, they will eventually be
	able to go back to their starting location.		

*/

trip_stop::trip_stop()
{
	next_stop = NULL;
	location_stop = NULL;
	reserved_lodging = NULL;
	miles_from_previous = NULL;
	lodge_rating = NULL;
	gas_amount = NULL;

}

trip_stop::~trip_stop()
{
	if(next_stop)
	{
		delete [] next_stop;
		next_stop = NULL;
	}
	
	if(location_stop)
	{
		delete [] location_stop;
		location_stop = NULL;
	}

	if(reserved_lodging)
	{
		delete [] reserved_lodging;
		reserved_lodging = NULL;
	}

	if(miles_from_previous)
	{
		delete [] miles_from_previous;
		miles_from_previous = NULL;
	}
	
	if(lodge_rating)
	{
		delete [] lodge_rating;
		lodge_rating = NULL;
	}
		
	if(gas_amount)
	{
		delete [] gas_amount;
		gas_amount = NULL;
	}
}

//copy and create the information passed in by queue when enqueueing
//only contains information that will be used in queues	
int trip_stop::copy(char pla[], char loc[], char lod[], char mil[])
{
	if(next_stop != NULL)
		delete [] next_stop;


	if(location_stop)
		delete [] location_stop;

	if(reserved_lodging)
		delete [] reserved_lodging;

	if(miles_from_previous)
		delete [] miles_from_previous;

	next_stop = new char[strlen(pla) + 1];
	strcpy(next_stop, pla);
	
	location_stop = new char[strlen(loc) + 1];
	strcpy(location_stop, loc);
	
	reserved_lodging = new char[strlen(lod) + 1];
	strcpy(reserved_lodging, lod);

	miles_from_previous = new char[strlen(mil) + 1];
	strcpy(miles_from_previous, mil);
	return 1;

}

//copy and create information passed in when info is pushed on stack
//contains all info needed for stack
int trip_stop::copy2(char pla[], char loc[], char lod[], char mil[], char rating[], char gas_spent[])
{
	if(next_stop)
		delete [] next_stop;

	if(location_stop)
		delete [] location_stop;

	if(reserved_lodging)
		delete [] reserved_lodging;

	if(miles_from_previous)
		delete [] miles_from_previous;

	if(lodge_rating)
		delete [] lodge_rating;

	if(gas_amount)
		delete [] gas_amount;

	next_stop = new char[strlen(pla) + 1];
	strcpy(next_stop, pla);
	
	location_stop = new char[strlen(loc) + 1];
	strcpy(location_stop, loc);
	
	reserved_lodging = new char[strlen(lod) + 1];
	strcpy(reserved_lodging, lod);

	miles_from_previous = new char[strlen(mil) + 1];
	strcpy(miles_from_previous, mil);

	lodge_rating = new char[strlen(rating) + 1];
	strcpy(lodge_rating, rating);

	gas_amount = new char[strlen(gas_spent) + 1];
	strcpy(gas_amount, gas_spent);
	return 1;

}	

//displays the information in queue about the trip plans of the user
int trip_stop::display()
{
	cout << "\nStop: " << next_stop << endl;
	cout << "Location of stop: " << location_stop << endl;
	cout << "Lodging info: " << reserved_lodging << endl;
	cout <<	"Miles from previous stop: " << miles_from_previous << endl;
	return 1;
}

//displays the information in the stack when the user reached a certain spot
int trip_stop::display2()
{
	cout << "\nStop: " << next_stop << endl;
	cout << "Location of stop: " << location_stop << endl;
	cout << "Lodging info: " << reserved_lodging << endl;
	cout <<	"Miles from previous stop: " << miles_from_previous << endl;
	if(lodge_rating)
		cout << "Rate of the lodging: " << lodge_rating << endl;
	if(gas_amount)
		cout << "Gas spent on this part of trip: " << gas_amount << endl;
	return 1;
}

//function to copy over information into stack (before dequeueing) so we can 
//immediately push the information
int trip_stop::stack_copy(char place[], char loca[], char lodge[], char miles[], char rating[], char gas_spent[])
{
	strcpy(place, next_stop);
	strcpy(loca, location_stop);
	strcpy(lodge, reserved_lodging);
	strcpy(miles, miles_from_previous);  	
	return 1;	
}
