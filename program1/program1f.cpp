#include "program1.h"

/*
++----------------------------------------------------------------------------------------------++
|Dhwanil Chokshi										 |							
|Program 1											 |
|CS163 -- Karla Fant 										 |
|												 |
|	The purpose of this program was to implement a data structure (Linear Linked List)	 |
|	into an ADT. In this program, I have a created a tutor service for newcomers to 	 |
|	the university. This service implements the data structure in such a way, that it	 |
|	can be manipulated in multiple forms to fit the needs of the user. The user can add	 |
|	a subject with its assistance method, the user can display the subjects and their 	 |
|	respective assistance method, the user can display only top rated assistance method,	 |
|	user can remove the assistance method with ratings of 3 or lower, user can edit a	 |
|	rating of a particular subject, and they can add a new way of assistance to a subject	 |
|	of their choice.									 |
++----------------------------------------------------------------------------------------------++	
*/

/*
node constructor to set the subject and next pointer to null,
since we cannot use class constructor to set subject to null
*/
node::node()
{
	subject = NULL;
	next = NULL;
}	

/*
class constructor to set pointer variables to null,
these pointers will hold the list together
*/
assistance::assistance()
{
	head = NULL;
	tail = NULL;
}

/*
destructore using temp to connect to head->next, while head it deleted
using traversal
*/
assistance::~assistance()
{
	node *temp = NULL;

	while(head)
	{
		if(head->subject)
		{
			delete [] head->subject;
			head->subject = NULL;
		}
		temp = head->next;
		delete head;
		head = temp;
	}
	if(head)
	{
		delete head;
		head = NULL;
	}
		tail = NULL;
}

/*
adds a subject to the list, if head is not present, it adds a head node. After first
item is added, the tail pointer is used to append the linear linked list. We call the functions
in our first class to add the data taken from client about assistance in the seperate list.
*/
int assistance::add_subject(char sub[], char disc[], char hours[], int &rating, char loc[], char weekends[])
{
	
	if(!head)
	{
		head = new node;
		head->subject = new char[strlen(sub) + 1];
		strcpy(head->subject, sub);

		head->data.add(sub, disc, hours, rating, loc, weekends);		
		head->next = NULL;
		tail = head;
		return 1;
	}	
	else
	{
		tail->next = new node;
		tail = tail->next;
		tail->subject = new char[strlen(sub) + 1];
		strcpy(tail->subject, sub);

		tail->data.add(sub, disc, hours, rating, loc, weekends);
		tail->next = NULL;
		return 1;
	}

return 0;			
}

/*
wrapper function, used to call the recursive function. checks the if not head
case, so if nothing is present, we have nothing to display.
*/
int assistance::display()
{
	if(!head)
		return 0;
	
	else
	{
		display(head);
		return 1;
	}
}

/*
recursive function to display the list with its subject, and then a call
to fist class function to display assistance method.
*/
int assistance::display(node *head)
{	
	int success = 0;
	
	if(!head)
		return success;

	cout << "\nSUBJECT: " << head->subject << endl;
	if(head->data.display())
		success = 1;

	display(head->next);

return success;
}

/*
display top rated assistance method (rating of 8, 9, 10).
passing in current->subject to first class function so it displays
subject only if only rating is 8, 9, 10
*/ 
int assistance::display_top()
{
	node *current = head;
	int success = 0;

	if(head)
	{
		while(current)
		{
			if(current->data.display_top(current->subject))
				success = 1;
			current = current->next;
		}
	}

return success;
}

/*
calls the remove function of first class to remove the node if rating
is 3 or lower, if rating is three or lower, call the function in the first class 
which will remove the data of the nodes which consists of assistance. It will
not remove the subject node, incase user wants to add to subject later on.
*/
int assistance::remove_3(char sub[], char disc[], char hours[], int &rate, char loc[], char weekends[])
{
	node *current = head;	
	int success = 0;
	if(head)
	{	
		while(current)
		{
			if(current->data.remove_three() && rate > 3)
			{
				add_new_help(sub, disc, hours, rate, loc, weekends);
			}
			current = current->next;
		}
		success = 1;
	}

return success;
}

/*
take the new rating from client user and passes it to the first class
function which changes the rating of the first assistance node
*/
int assistance::edit_rating(char subj[], int &new_rate)
{
	node *current = head;
	int success = 0;	

	if(head)
	{
		while(current)
		{
			if(strcmp(current->subject, subj) == 0)
			{
				if(current->data.edit(new_rate))
					success = 1;
			}
			current = current->next;
		}
	}

return success;
}

/*
this function takes from the user the suject to which they want to add a new assistance
method, it then string compares the nodes until the subejct match is found, it then calls 
the first class function which adds the new assistance node to the subject 
*/
int assistance::add_new_help(char sub[], char disc[], char hours[], int &rate, char loc[], char weekends[])
{
	node *current = head;
	int success = 0;

	if(head)
	{
		while(current)
		{
			if(strcmp(current->subject, sub) == 0)
			{
				if(current->data.new_help(disc, hours, rate, loc, weekends))
				return 1;
			}
			current = current->next;
		}
	}

return success;
}

/*
this function traverses the subject list and display each subject
*/
int assistance::display_subjects()
{
	node *current = head;
	int success = 0;
	
	if(head)
	{
		while(current)
		{
			cout << "SUBJECT: " << current->subject << " ";
			current = current->next;
		}
		success = 1;
	}
return success;
}
