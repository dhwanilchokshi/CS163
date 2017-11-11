//stack class functions 
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

stack::stack()
{
	head = NULL;
	top_index = 0;
}


//stack constructor used to call another recursive
//function which will deallocate and delete memory used
//for stack
stack::~stack()
{
	stack_deallocate(head);
}

int stack::stack_deallocate(node *&head)
{
	if(!head)
	{
		return 0;
	}

	if(!head->next)
	{
		delete [] head->trip;
		delete head;
		head = NULL;
		return 1;
	}
	
	stack_deallocate(head->next);	
	delete [] head->trip;	
	delete head;
	head = NULL;


	return 1;
}
//pushes the information onto the stack, once the information is dequeued,
//all info is copied into arrays, and pushed into this stack so we know
//which stop the user will reach first
int stack::push(char stop[], char loca[], char lodg[], char mile[], char rating[], char gas_spent[])
{
	node *temp = NULL;
	if(!head)
	{
		temp = new node;
		temp->trip = new trip_stop[A_SIZE];
		temp->trip[top_index].copy2(stop, loca, lodg, mile, rating, gas_spent);
		temp->next = NULL;
		head = temp;
		++top_index;
		return 1;
	}

	if(top_index == 5)
	{
		top_index = 0;
		temp = new node;
		temp->trip = new trip_stop[A_SIZE];
		temp->trip[top_index].copy2(stop, loca, lodg, mile, rating, gas_spent);
		temp->next = head;
		head = temp;
		++top_index;
		return 1;
	}

	head->trip[top_index].copy2(stop, loca, lodg, mile, rating, gas_spent);
	++top_index;
	return 1;
		
}

//stack pop function, decrements the index, once the index
//reaches zero, then it deletes the head node
int stack::pop()
{
	if(!head)
		return 0;

	if(top_index == 0)
	{
		node *temp = head->next;
		delete head;
		head = temp;
	}
	--top_index;
return 1;
}

//peek function for stack, used to check if the stack
//contains any information
int stack::peek()
{
	if(!head)
		return 0;

return 1;
}

//stack display function used to traverse the linked list of arrays
//and display the information
int stack::display()
{
	if(top_index == 0)
		return 0;


	head->trip[top_index-1].display2();
return 1;
}
