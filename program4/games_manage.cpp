/*
Dhwanil Chokshi
CS 163
Program 4 - BST

		The purpose of this program was to keep it the same as the hash table program but to implement it
		with binary search trees. With comparison to the last program, some of the functions have changed
		according to new requirements but the overarching concept is still the same. You can add a game,
		load games from file, delete a game based on name and platform, delete all instances of a game based
		on name, count the number of games rated 5 stars, retrieve games existence, display all games in
		alphabetical order, and display games in ranged character value of user choice. 


		NOTE: The games which you insert manually have their first letter only capitalized according to the 
	              requirements set by the instructor. Therefore, when you remove a game based on name, or look
		      for a game, make sure to make only the first letter lowercase since the code makes it uppercase
	 	      when taken in.
*/
#include "cs163_header.h"

//class constructor intitializing all data members to NULL
games_manage::games_manage()
{
	game_name = NULL;
	description = NULL;
	type = NULL;
	platform = NULL;
	stars = NULL;
	recommendation = NULL;
}

//delete all dynamically allocated arrays so we dont
//have a memory leak in the program
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
}

//uses string compares to see if the game passed in by user
//is greater than the root game, to determine in which subtree
//the game will be stored/
int games_manage::check(char name[])
{
	if(strcmp(name, game_name) >= 0)
		return 1;

	else
		return 0;

}

//checks to see if the name passed in by user matched
//the root game which will be searched for recursively
int games_manage::check2(char name[])
{
	if(strcmp(name, game_name) == 0)
		return 1;
	
	else
		return 0;

}

//displays all the data from the private members
int games_manage::display_all()
{
	cout << "\nName: " << game_name << endl;
	cout << "Description: " << description << endl;
	cout << "Type: " << type << endl;
	cout << "Platform: " << platform << endl;
	cout << "Rating: " << stars << endl;
	cout << "Recommendation/Comments: " << recommendation << endl;
	return 1;
}

//string compares the first and last character of range passed in
//to see which to display based on the specified range
int games_manage::display_range(char first, char last)
{

	if(game_name[0] >= first && game_name[0] <= last)
		return 1;
	
	else
		return 0;
}

//string compares the value of root node to "5", if it matches
//then return one indicating the node had a full 5 rating
int games_manage::count_top_rating()
{
	if(strcmp(stars, "5") == 0)
		return 1;
	
	else 
		return 0;
}

//string compares the game name and platform, if they match then return 1
//indicating that the node has data which will need to be deleted
int games_manage::remove_a_game(char name[], char plat[])
{
	if(strcmp(name, game_name) == 0 && strcmp(plat, platform) == 0)
		return 1;
	else
		return 0;

}

//used when we find the inorder successor to copy the data, from current to root
//in order to successfully delete the node after
int games_manage::copier(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[])
{
	strcpy(name, game_name);
	strcpy(disc, description);
	strcpy(g_type, type);
	strcpy(plat, platform);
	strcpy(rate, stars);
	strcpy(reco, recommendation);
	return 1;
}

//dynamically creates the array for private members which will be 
//string copied into it
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
