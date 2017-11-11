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


method::method()
{
	description = NULL;
	hours = NULL;
	rating = 0;
	location = NULL;
	on_weekends = NULL;
}

n_method::n_method()
{
	head = NULL;
	tail = NULL;
}

n_method::~n_method()
{
	method *temp = NULL;

	while(head)
	{
		if(head->description)
		{
			delete [] head->description;
			head->description = NULL;
		}
		if(head->hours)
		{
			delete [] head->hours;
			head->hours = NULL;
		}
		if(head->location)
		{
			delete [] head->location;
			head->location = NULL;
		}
		if(head->on_weekends)
		{
			delete [] head->on_weekends;
			head->on_weekends = NULL;
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
this function adds the assistance node to the subject list. if head is not present,
it will add a head node, but if head is present, it will append the tail node each
time
*/
int n_method::add(char sub[], char disc[], char hours[], int &rating, char loc[], char weekends[])
{
	if(!head)
	{
		head = new method;

		head->description = new char[strlen(disc) + 1];
		strcpy(head->description, disc);
	
		head->hours = new char[strlen(hours) + 1];
		strcpy(head->hours, hours);

		head->rating = rating;

		head->location = new char[strlen(loc) + 1];
		strcpy(head->location, loc);

		head->on_weekends = new char[strlen(weekends) + 1];
		strcpy(head->on_weekends, weekends);
		
		head->next = NULL;
		tail = head;
		return 1;
	}
	else
	{
		tail->next = new method;
		tail = tail->next;

		tail->description = new char[strlen(disc) + 1];
		strcpy(tail->description, disc);
	
		tail->hours = new char[strlen(hours) + 1];
		strcpy(tail->hours, hours);

		tail->rating = rating;

		tail->location = new char[strlen(loc) + 1];
		strcpy(tail->location, loc);

		tail->on_weekends = new char[strlen(weekends) + 1];
		strcpy(tail->on_weekends, weekends);
		
		tail->next = NULL;
		return 1;
	}

	
return 0;
}

/*
this function traverses the assistance nodes to display the details about each
assistance method
*/
int n_method::display()
{
	method *current = head;

	if(head)
	{
		while(current)
		{
			
			cout <<  "DESCRIPTION: " << current->description
			<< "\nHOURS:  " << current->hours
			<< "\nRATING: " << current->rating
			<< "\nLOCATION: " << current->location
			<< "\nOFFERED ON WEEKENDS: " << current->on_weekends << endl;
			current = current->next;
		}
	return 1;
	}

return 0;
}

/*
this function traverses the assistance nodes, checks if rating is above than 8,
if it is, then display the info in the node, else dont display the info
*/	
int n_method::display_top(char *subj)
{
	method *current = head;
	int success = 0;

	if(head)
	{
		while(current)
		{
			if(current->rating >= 8)
			{
				cout << "\nSUBJECT: " << subj << endl;
				cout << "DESCRIPTION: " << current->description << endl;
				cout << "HOURS: " << current->hours << endl;
				cout << "RATING: " << current->rating << endl;
				cout << "LOCATION: " << current->location << endl;
				cout << "OFFERED ON WEEKENDS: " << current->on_weekends << endl;
				success = 1;
			}
			current = current->next;
		}
	}

return success;
}

/*
check special cases in removal of node, if only one node, remove the node if rating <= 3,
else traverse the nodes and remove nodes with rating of 3 or lower
*/
int n_method::remove_three()
{
//	method *current = head;
//	method *previous = NULL;
	int success = 0;

	if(!head) 
	{ 
		return 0; 
	}
/*	
	if(!head->next)
	{
		if(head->rating <= 3)
		{
			delete head;
			head = NULL;
		}
		success = 1;
	}
*/
	if(head->rating <= 3)
	{
		delete head;
		head = head->next;
		remove_three();
	}

	method *current = head;
	method *previous = NULL;
	
	while(current)
	{
		if(!current->next && current->rating <= 3)
		{
			delete current;
			current = NULL;
			return 1;
		}
			
		if(current->rating <= 3)
		{
			previous->next = current->next;
			delete current;
			current = previous;	
		}
		previous = current;	
		current = current->next;
	}
			
return 1;		
}

/*
assign the new rating to the old rating
*/
int n_method::edit(int &new_rating)
{
	method *current = head;
	
	if(new_rating > 0)
	{
		current->rating = new_rating;
		return 1;
	}

return 0;
}

/*
check the head case, in case nothing is in the list. If node is present
in the list, then append the tail pointer
*/
int n_method::new_help(char disc[], char hours[], int &rate, char loc[], char weekends[])
{
	if(!head)
	{
		head = new method;

		head->description = new char[strlen(disc) + 1];
		strcpy(head->description, disc);
	
		head->hours = new char[strlen(hours) + 1];
		strcpy(head->hours, hours);

		head->rating = rate;

		head->location = new char[strlen(loc) + 1];
		strcpy(head->location, loc);

		head->on_weekends = new char[strlen(weekends) + 1];
		strcpy(head->on_weekends, weekends);
		
		head->next = NULL;
		tail = head;
		return 1;
	}
	else if(!strcmp(head->description, disc) == 0)
	{
		tail->next = new method;
		tail = tail->next;

		tail->description = new char[strlen(disc) + 1];
		strcpy(tail->description, disc);

		tail->hours = new char[strlen(hours) + 1];
		strcpy(tail->hours, hours);

		tail->rating = rate;

		tail->location = new char[strlen(loc) + 1];
		strcpy(tail->location, loc);

		tail->on_weekends = new char[strlen(weekends) + 1];
		strcpy(tail->on_weekends, weekends);

		tail->next = NULL;
		return 1;
	}
return 0;
}

