/*
Dhwanil Chokshi
CS163
Program 3

	The purpose of this program was to create a hash table of games and their respective info.
	The hash table will consist of index which will be a bunch of node pointers to nodes. The nodes
	will carry information about the games. The game can be loaded from an external file, or the game
	can be added by the add function from the menu options. This program consist of chaining as a collision
	resolution technique and it will basically be a linear linked list of a linear linked list, so that the user
	can add recommendation for a certain game if they wish to.

*/
#include "cs163_header.h"



//table class constructor recieving table size so the table
//can be created
//sets all the node pointers to NULL
table::table(int size)
{

	table_size = size;
	hash_table = new node *[table_size];
	
	for(int i = 0; i < table_size; i++)
	{
		hash_table[i] = NULL;
	}

}


//destructor which deletes all the node pointers and nodes 
//and deletes the dynamically allocated table in the end
table::~table()
{

	for(int i = 0; i < table_size; i++)
	{
		node *head = hash_table[i];
		deallocate(head);
	}
	if(hash_table)
	{
		delete [] hash_table;
		hash_table = NULL;
	}

}

//recursive function checks to see if there are multiple nodes to an index, goes through and deleted them
void table::deallocate(node *&head)
{
	if(!head)
		return;
	
	deallocate(head->next);
	if(head)
	{
		delete head;
		head = NULL;
	}
}

//add game function which adds a new game to the hash table
//gets the index after passing the game to the hash function and then adding the game to the table
int table::add_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[])
{
	node *temp = NULL;
	int index = hash_function(name);

	if(index == -1)
		return 0;

	if(temp)
	{
		delete temp;
	}

	if(!hash_table[index])
	{
		temp = new node;
		temp->games.copy_create(name, disc, g_type, plat, rate, reco);
		temp->next = NULL;
		hash_table[index] = temp;
		return 1;
	}

	else
	{
		temp = new node;
		temp->games.copy_create(name, disc, g_type, plat, rate, reco);
		temp->next = hash_table[index];
		hash_table[index] = temp;
		return 1;
	}
return 1;
}

//display the game information about a particular platform
//by passing the name of the game and platform to checking function in manager game class
//which returns based on if there was a match or not
int table::display_platform(char plat[])
{
	if(!hash_table)
		return 0;

	for(int i = 0; i < table_size; i++)
	{
		if(hash_table[i])
		{
			node *current = hash_table[i];
			while(current)
			{
				if(current->games.check(plat))
				{
					current->games.display_platform();
				}
				current = current->next;
			}
		}
	}
return 1;
}

//displays all game infromation by going through each index and displaying the information about
//all games
int table::display_all()
{

	if(!hash_table)
		return 0;
	
	for(int i = 0; i < table_size; i++)
	{
		if(hash_table[i])
		{
			node *current = hash_table[i];
			while(current)
			{
				current->games.display_all_platform();
				current = current->next;
			}
		}
	}

return 1;
}	

//checks whether or not if a game exists in the table or not
int table::retrieve(char name[])
{
	if(!hash_table)
		return 0;

	int index = hash_function(name);

	if(index == -1)
		return 0;

	else
	{
		node *current = hash_table[index];
		while(current)
		{
			if(current->games.check2(name))
			{
				return 1;
			}
			current = current->next;
		}
	}
return 1;
}

//load games from the external file and put the information directly into the arrays
//then insert the games into the hash tables so all information can be displayed and retrieved
int table::load_games()
{
	char name[SIZE];
	char disc[SIZE];
	char g_type[SIZE];
	char plat[SIZE];
	char rate[SIZE];
	char reco[SIZE];

	ifstream file_in;
	
	file_in.open("CS163_games.txt", ios::in);

	if(!file_in)
		return 0;

	else
	{

		if(file_in)
		{
			while(file_in.get(name, SIZE, ':') && !file_in.eof())
			{
				file_in.ignore(100, ':');

				file_in.get(disc, SIZE, ':');
				file_in.ignore(100, ':');

				file_in.get(g_type, SIZE, ':');
				file_in.ignore(100, ':');
			
				file_in.get(plat, SIZE, ':');
				file_in.ignore(100, ':');

				file_in.get(rate, SIZE, ':');
				file_in.ignore(100, ':');

				file_in.get(reco, SIZE, '\n');
				file_in.ignore(100, '\n');
	
				add_game(name, disc, g_type, plat, rate, reco);	
			}
			file_in.close();
			return 1;
		}
	}
return 1;
}

//removes a certain game based on the name, gets the name and checks the hash function index
//if the index contains multiple nodes then check and delete the one which needs to be deleted
int table::remove_game(char name[])
{
	if(!hash_table)
		return 0;

	int index = hash_function(name);

	if(index == -1)
	{
		return 0;
	}

	node *current = hash_table[index];
	node *previous = NULL;

	while(current)
	{
		if(current->games.check2(name))
		{
			if (previous)
			{
				previous->next = current->next;
				delete current;
				current = NULL;
				return 1;
			}
			else
			{
				hash_table[index] = current->next;
				delete current;
				current = NULL;
				return 1;
			}
		}
		previous = current;
		current = current->next;
	}

return 1;
}

//add recommendation for a certain game of a certain platform
//checks the platform and game name, if there is a match at the index, then the add recommendation
//function of managing class is called which adds the recommendation to the game (linked list of linked list)
int table::add_rec(char name[], char new_rec[], char plat[])
{
	if(!hash_table)
		return 0;

	int index = hash_function(name);

	if(index == -1)
		return 0;

	node *current = hash_table[index];
	while(current)
	{
		if(current->games.check2(name))
		{
			if(current->games.check(plat))
			{
				current->games.add_recommendation(name, new_rec);
				return 1;
			}
		}
		current = current->next;
	}
return 1;
}	

//hash function which mods the sum of ASCII values by table size to give us an index where items will 
//be inputted
int table::hash_function(char name[])
{
	if(!name)
		return -1;

	int sum = 0;
	int len = strlen(name);
	for(int i = 0; i < len; i++)
	{
		sum = sum + name[i];
	}
	
	return sum % table_size;
}
