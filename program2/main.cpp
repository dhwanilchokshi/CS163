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

int main()
{

	stack Stack;
	queue Queue;
	trip_stop journey;
	char response;
	char response2;
	char stop[MAX];
	char location[MAX];
	char lodging[MAX];
	char miles[MAX];
	char rate[MAX];
	char gas[MAX];
	int stop_num = 1;

	cout << "\t\t\t\t --WELCOME TO TRIP PLANNING PROGRAM-- \t\t\t\t" << endl;
	do	
	{
		cout << "\nPlease enter your next stop: ";
		cin.get(stop, MAX, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter the location (city and state): ";
		cin.get(location, MAX, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter the lodging info (name, address, price): ";
		cin.get(lodging, MAX, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter the miles to travel from previous stop: ";
		cin.get(miles, MAX, '\n');
		cin.ignore(100, '\n');
	

		if(!Queue.enqueue(stop, location, lodging, miles))		//add the stops to circ list
			cerr << "Could not add the requested stop!" << endl;
		
		cout << "\nThis is what you have in your trip plan: ";
		
		if(!Queue.display())		//display the information contained in the stacks
			cerr << "No stops to  display!" << endl;
	
		cout << "\nDo you want to enter another stop for trip planning? (Y/y for yes, any other key for no): ";
		cin >> response;
		cin.ignore();

	}while(response == 'Y' || response == 'y');	

	do
	{
		cout << "You have reached stop #" << stop_num <<  endl;
		
		cout << "Please rate how the lodge was: ";
		cin.get(rate, MAX, '\n');
		cin.ignore(100, '\n');

		cout << "What was the amount spent on gas: ";
		cin.get(gas, MAX, '\n');
		cin.ignore(100, '\n');	

		stop_num++;
		if(!Queue.dequeue(stop, location, lodging, miles, Stack, rate, gas))		//dequeue the info and push onto stack
			cerr << "There are no stops!" << endl;

		if(!Stack.display())							//display the info stored in stack)
			cerr << "No stops to display!" << endl;
	
		if(!Stack.pop())
			cerr << "Nothing to remove!" << endl;
	
		cout << "\nDo you want to move to your next stop? (Y/y for yes, any other key for no): ";
		cin >> response2;
		cin.ignore();
	
		if(!Queue.peek())				//if there is nothing left in queue, then let user know and return
		{
			cerr << "\nNo more stops!" << endl;
			cout << "Thanks for using the program!" << endl;
			return 0;
		}

	}while(response2 == 'y' || response2 == 'Y');




return 0;
}
