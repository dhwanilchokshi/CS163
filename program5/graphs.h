/*
Dhwanil Chokshi
CS163
Program 5 - Graphs
	
	The purpose of this program was to use the graph data structure to create a simple
	planner type application which the user can use with the primary steps to achieve their
	specific goals. The vertices can be connected if you connect multiple goals together.
	Therefore the end of the program displays the connected goals.
*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 500;

//trip class which is used to name your trip or the task that you are going
//to do or achieve
class trips
{
	public:
		trips();	//class constructor allocating adjacency list
		~trips();	//destructor deallocating all memory of list vertex and nodes
		int create(char to_do[], char f[], char s[], char t[]);	//create and copy all data into private members	
		int compare(char value[]);	//string compare the data value with task to achieve
		int display_all();	//display all contents of list
	private:
		char *thing_to_do;
		char *primary_task;
		char *secondary_task;
		char *third_task;
};

//vertex contains pointer to managing class
//contains node pointer to head and visit flag so we dont visit vertex more than once
struct vertex
{
	trips *places;
	struct node *head;
	bool visit;
};

//node contains pointer to vertex struct
//next pointer to next vertex
struct node
{
	vertex *adjacent;
	node *next;
};

//class used in main to insert edge, insert vertex, and display all tasks with steps
class table
{
	public:
		table(int size = 7);	//constructor sets ajcacency list size
		~table();	//deallocates all memory
		int insert_vertex(char to_do[], char f[], char s[], char t[]);	//insert vertex information
		int find(char *value);		//find the index of value passed in
		int insert_edge(char *current_vertex, char *to_attach);	//insert edge to connect vertices 
		int display_all();		//display all connecting vertices using recursion
		bool set_flags();	//function which visits all vertexes and sets flag to true or false
	private:
		vertex *adjacency_list;		//pointer to vertex
		int list_size;		//size of table
		int display_all(node *head);	//recursive function to display all vertices depth first
};
