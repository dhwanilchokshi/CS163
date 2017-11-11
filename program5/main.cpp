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

int main()
{
	table Table;
	trips location;
	char to_do[SIZE];
	char first[SIZE];
	char second[SIZE];
	char third[SIZE];
	char repeat;
	char response2;
	int count = 0;

	//do while loop takes in task from user with steps needed to complete task
	do
	{
		cout << "Please enter the task you want to do: ";
		cin.get(to_do, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter your primary step: ";
		cin.get(first, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter your secondary step: ";
		cin.get(second, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter the third step: ";
		cin.get(third, SIZE, '\n');
		cin.ignore(100, '\n');
		count++;	
		if(!Table.insert_vertex(to_do, first, second, third))
			cerr << "Cant add anymore!" << endl;

		else
			cout << "Your task has been added!" << endl;

		cout << "Do you want to add another task (Y/y for yes, any other key for no): ";
		cin >> repeat;
		cin.ignore(); 

	}while(repeat == 'y' || repeat == 'Y');	

	//second do while loop asks for vertices to connect if there are more than two task entered by user
	do
	{
		char connected[SIZE];
		if(count >= 2)
		{
			cout << "Enter the two goals that are connected!" << endl;
			cout << "Please enter the first task: ";
			cin.get(to_do, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "Please enter the second task: ";	
			cin.get(connected, SIZE, '\n');
			cin.ignore(100, '\n');
		
			Table.insert_edge(to_do, connected);
			Table.insert_edge(connected, to_do);

			cout << "Again? (Y/y - yes, another key for no): ";
			cin >> response2;
			cin.ignore();
		}
		else
		{
			cout << "Need more than one task to connect!" << endl;
		}

	}while(response2 == 'y' || response2 == 'Y');

	//display the connecting vertices	
	cout << "\nThese are the connected contents so far: " << endl;
	Table.display_all();

return 0;
}
