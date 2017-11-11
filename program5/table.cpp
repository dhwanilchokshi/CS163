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

//constructor sets table size and sets pointer to null
table::table(int size)
{
	list_size = size;
	adjacency_list = new vertex[list_size];
	
	for(int i = 0; i < list_size; i++)
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].places = NULL;
	}
}

//destructor deletes all data of table and sets table to NULL
table::~table()
{
	node *current = NULL;
	for(int i = 0; i < list_size; i++)
	{
			while(adjacency_list[i].head)
			{
				current = adjacency_list[i].head->next;
				delete adjacency_list[i].head;
				adjacency_list[i].head = current;
			}
			delete adjacency_list[i].places;
			adjacency_list[i].head = NULL;
			adjacency_list[i].places = NULL;
	}
	delete [] adjacency_list;
	adjacency_list = NULL;
			

}

//loops through the table and inserts vertex at first null index of table	
int table::insert_vertex(char to_do[], char f[], char s[], char t[])
{
	for(int i = 0; i < list_size; i++)
	{
		if(!adjacency_list[i].places)
		{
			adjacency_list[i].places = new trips;
			adjacency_list[i].places->create(to_do, f, s, t);
			return 1;
		}
	}
return 1;
}

//finds the index value of argument passed in by calling compare function		
int table::find(char *value)
{
	if(!value)
		return -1;
	for(int i = 0; i < list_size; i++)
	{
		if(adjacency_list[i].places)
		{
			if(adjacency_list[i].places->compare(value))
			{
				return i;
			}
		}
	}	
return -1;
}

//finds the two connection by finding their index values and attaches them together
//so they can be accessed 	
int table::insert_edge(char *current_vertex, char *to_attach)
{
	int connection1 = find(current_vertex);
	int connection2 = find(to_attach);

	if(connection1 == -1 && connection2 == -1)
		return 0;

	node *temp = new node;
	temp->adjacent = &adjacency_list[connection2];
	temp->next = adjacency_list[connection1].head;
	adjacency_list[connection1].head = temp;
	return 1;
}
		
//calls the recursive display function	
int table::display_all()
{
	if(!adjacency_list)
		return 0;

	else
		return display_all(adjacency_list->head);
}

//uses depth first recursion to loop through the vertexes and setting
//all vertex flags to false, then recursively goes through each node and
//display the info of the vertices if they are connected
int table::display_all(node *head)
{
	for(int i = 0; i < list_size; i++)
	{
		if(!adjacency_list[i].head)
		{
			set_flags();
			return 1;
		}		
		else if(adjacency_list[i].visit)
			return display_all(adjacency_list[i].head->next);
	
		else
		{
			adjacency_list[i].visit = true;
			adjacency_list[i].places->display_all();
		}
	}
return 1;
} 

//goes to each node of the vertex and sets flag to false
bool table::set_flags()
{
	node *current = NULL;
	for(int i = 0; i < list_size; i++)
	{
		current = adjacency_list[i].head;
		while(current)
		{
			if(current)
				current->adjacent->visit = false;
			current = current->next;
		}
	}
return true;
}
