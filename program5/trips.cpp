/*
Dhwanil Chokshi
CS163
Program 5 - Graphs
	
	The purpose of this program was to use the graph data structure to create a simple
	planner type application which the user can use with the primary steps to achieve their
	specific goals. The vertices can be connected if you connect multiple goals together.
	Therefore the end of the program displays the connected goals.
*/

#include "graphs.h" 

//constructor sets all pointer data members to null
trips::trips() 
{ 
	thing_to_do = NULL; 
	primary_task = NULL; 
	secondary_task = NULL; 
	third_task = NULL;
} 

//destructor deallocates all dynamic memory used
trips::~trips()
{
	if(thing_to_do)
	{
		delete [] thing_to_do;
		thing_to_do = NULL;
	}
	
	if(primary_task)
	{
		delete [] primary_task;
		primary_task = NULL;
	}
	
	if(secondary_task)
	{
		delete [] secondary_task;
		secondary_task = NULL;
	}

	if(third_task)
	{
		delete [] third_task;
		third_task = NULL;
	}
}

//creates dynamic arrays and string copies from arguement to private members
int trips::create(char to_do[], char f[], char s[], char t[])
{
	if(thing_to_do)
	{
		delete [] thing_to_do;
		thing_to_do = NULL;
	}

	if(primary_task)
	{
		delete [] primary_task;
		primary_task = NULL;
	}
		
	if(secondary_task)
	{
		delete [] secondary_task;
		secondary_task = NULL;
	}
		
	if(third_task)
	{
		delete [] third_task;
		third_task = NULL;
	}

	thing_to_do = new char[strlen(to_do) + 1];
	strcpy(thing_to_do, to_do);
		
	primary_task = new char[strlen(f) + 1];
	strcpy(primary_task, f);

	secondary_task = new char[strlen(s) + 1];
	strcpy(secondary_task, s);

	third_task = new char[strlen(t) + 1];
	strcpy(third_task, t);
	return 1;
}

//string compare the value passed in to the task in private section
//of managing class
int trips::compare(char value[])
{
	if(!value)
		return 0;

	if(strcmp(value, thing_to_do) == 0)
		return 1;

	else
		return 0; 
}

//display all the data from private members
int trips::display_all()
{
	if(thing_to_do)
		cout << "\nTask: " << thing_to_do << endl;
	if(primary_task)
		cout << "First step: " << primary_task << endl;
	if(secondary_task)
		cout << "Second step: " << secondary_task << endl;
	if(third_task)
		cout << "Third step: " << third_task << endl;
return 1;
}
