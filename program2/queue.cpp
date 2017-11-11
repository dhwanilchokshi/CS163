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

queue::queue()
{
	rear = NULL;
}

//destructor used as wrapper to call recursive function
//to delete and deallocate infomation in all nodes
queue::~queue()
{
	anode *temp = rear;
	if(rear)
	{
		rear = rear->next;
		temp->next = NULL;
		queue_deallocate(rear);
	}
}

//recursive deallocation function to delete the nodes 
//and set them to NULL
int queue::queue_deallocate(anode *&rear)
{
	if(!rear)
	{
		return 0;
	}

	queue_deallocate(rear->next);
	delete rear;
	rear = NULL;

return 1;
}

//enqueue function will get information from user about their trip stops
//and pass the information to manager class for creation/copying
//it will check special cases to add in the circular list respectively
int queue::enqueue(char pla[], char loc[], char lod[], char mil[])
{
	anode *temp = NULL;
	if(!rear)
	{
		temp = new anode;
		temp->trips.copy(pla, loc, lod, mil);
		rear = temp;
		rear->next = rear;
		return 1;
	}

	else
	{
		anode *holder = rear->next;
		anode *last_one = rear;
		temp = new anode;
		temp->trips.copy(pla, loc, lod, mil);
		last_one->next = temp;
		rear = temp;
		rear->next = holder;
		return 1;
	}
return 0;
}

//queue copy function called when information is dequeued so it can copy all
//info into arrays and push it into the stack
int queue::copy(char pla[], char loc[], char lod[], char mil[], stack &Stack, char rating[], char gas_spent[])
{

	anode *first = rear->next;
	first->trips.stack_copy(pla, loc, lod, mil, rating, gas_spent);
	Stack.push(pla, loc, lod, mil, rating, gas_spent);

return 1;
}

//dequeue function removes the data item at rear->next according to FIFO rule
//which all queues follow. 
//this function will also call the copy function to copy information into arrays
//to be pushed into stack later on
int queue::dequeue(char stop[], char location[], char lodge[], char miles[], stack &Stack, char rating[], char gas_spent[])
{
	anode *temp = NULL;

	if(!rear)
	{
		return 0;
	}

	if(rear->next == rear)
	{
		if(copy(stop, location, lodge, miles, Stack, rating, gas_spent));
		delete rear;
		rear = NULL;
		return 1;
	}

	else
	{
		if(copy(stop, location, lodge, miles, Stack, rating, gas_spent));
		temp = rear->next->next;
		delete rear->next;
		rear->next = temp;
		return 1;
	}	
}

//peek function checks if the circular lists consists of something
//or if its totally empty
int queue::peek()
{
	if(!rear)
		return 0;

return 1;
}

//queue display function traverses the circular list, displaying information
//contained in the list
int queue::display()
{
	anode *temp = rear->next;
	anode *holder = rear;
	if(!rear)
		return 0;
	
	if(rear)
	{	
		while(temp != holder)
		{
			temp->trips.display();
			temp = temp->next;
		}
		rear->trips.display();
		return 1;
	}
return 1;
}
