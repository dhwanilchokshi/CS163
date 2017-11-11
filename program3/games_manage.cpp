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

//anode constructor which sets the value of new recommendation pointer to NULL
anode::anode()
{
	new_rec = NULL;
}

//games manage destructor which sets all the data pointers to NULL
games_manage::games_manage()
{
	head = NULL;
	tail = NULL;
	game_name = NULL;
	description = NULL;
	type = NULL;
	platform = NULL;
	stars = NULL;
	recommendation = NULL;
}

//destructor for managing class which deletes and sets NULL all the data in the class
//furthermore it calls a deallocating recursive function which deletes all extra recommendations
//added to the nodes of the hash table
games_manage::~games_manage()
{

	if(game_name)
	{
		delete [] game_name;
		game_name = NULL;
	}
	
	if(description)
	{
		delete [] description;
		description = NULL;
	}
	
	if(type)
	{
		delete [] type;
		type = NULL;
	}

	if(platform)
	{
		delete [] platform;
		platform = NULL;
	}

	if(stars)
	{
		delete [] stars;
		stars = NULL;
	}
	
	if(recommendation)
	{
		delete [] recommendation;
		recommendation = NULL;
	}
	if(head)
	{
		deallocate_all(head);	//recursive function to delete all extra recommendation
		
		tail = NULL;
	}
}

//recursive function which goes through and deletes all extra added recommendation
//nodes for the game
void games_manage::deallocate_all(anode *&head)
{
	if(!head)
		return;

	deallocate_all(head->next);
	if(head->new_rec)
	{
		delete [] head->new_rec;
		head->new_rec = NULL;
	}
	if(head)
	{
		delete head;
		head = NULL;
	}
}
		
//display platform function which only displays all information for a game
int games_manage::display_platform()
{
		cout << "\nName: " << game_name << endl;	
		cout << "Description: " << description << endl;
		cout << "Type of game: " << type << endl;
		cout << "Platform: " << platform << endl;
		cout << "Rating: " << stars << endl;	
		cout << "Recommendations/Comments: " << recommendation << endl;
		return 1;
}

//function which string compares the platforms to check if the data passed in matches
//the private data platform
int games_manage::check(char plat[])
{
	if(strcmp(plat, platform) == 0)
		return 1;
	else
		return 0;
}

//function which string compares the name of the game to check if the data passed
//in matches the private data name of game
int games_manage::check2(char name[])
{
	if(strcmp(name, game_name) == 0)
		return 1;
	else
		return 0;
}

//dislays information about the game
//traverses through the second linear linked list to check if there are extra
//recommendations for a given game
int games_manage::display_all_platform()
{
		cout << "\nName: " << game_name << endl;
		cout << "Description: " << description << endl;
		cout << "Type of game: " << type << endl;
		cout << "Platform: " << platform << endl;
		cout << "Rating: " << stars << endl;
		cout << "Recommendations/Comments: " << recommendation << endl;
		if(head)
		{
			anode *current = head;
			while(current)
			{
				cout << "Other added recommendations/comments: " << current->new_rec << endl;
				current = current->next;
			}
		}
return 1;
}

//creates the dynamically allocated array and string copies the data into it
//deletes the data before if it exists
int games_manage::copy_create(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[])
{
	if(game_name)
	{
		delete [] game_name;
	}

	if(description)
	{
		delete [] description;
	}

	if(type)
	{
		delete [] type;
	}

	if(platform)
	{
		delete [] platform;
	}
	
	if(stars)
	{
		delete [] stars;
	}
	
	if(recommendation)
	{
		delete [] recommendation;
	}

	game_name = new char[strlen(name) + 1];
	strcpy(game_name, name);

	description = new char[strlen(disc) + 1];
	strcpy(description, disc);

	type = new char[strlen(g_type) + 1];
	strcpy(type, g_type);

	platform = new char[strlen(plat) + 1];
	strcpy(platform, plat);

	stars = new char[strlen(rate) + 1];
	strcpy(stars, rate);

	recommendation = new char[strlen(reco) + 1];
	strcpy(recommendation, reco);
	return 1;
}

//a node function which creates and copies the new added recommendation to the new recommendation
//pointer in the node
int anode::create(char new_reco[])
{
	if(new_rec)
	{
		delete [] new_rec;
	}

	new_rec = new char[strlen(new_reco) + 1];
	strcpy(new_rec, new_reco);
	return 1;
}

//adds a new recommendation with a head and tail pointer so it can simply append
//to the list when a new recommendation needs to be added to make the program more efficient
int games_manage::add_recommendation(char name[], char new_rec[])
{
	if(!head)
	{
		head = new anode;
		head->create(new_rec);
		head->next = NULL;
		tail = head;
		return 1;
	}
	
	else
	{
		anode *temp = new anode;
		temp->create(new_rec);
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
		return 1;
	}	
return 1;	
}

