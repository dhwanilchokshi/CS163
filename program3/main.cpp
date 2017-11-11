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



int main()
{
	table Games;		//table class object
	
	char game[SIZE];
	char description[SIZE];
	char game_type[SIZE];
	char platform[SIZE];
	char stars[SIZE];
	char rec[SIZE];	
	char response, menu_choice;
 	
	cout << "\n\t\t\tWelcome to the Game Database Program!\t\t\t" << endl;
	
	do
	{
		cout << "1 -- Insert a new game" << endl;
		cout << "2 -- Load games from an external file" << endl;
		cout << "3 -- Remove a game based on a name" << endl;
		cout << "4 -- Add recommendations for a game" << endl;
		//go into table class recommendation function
		//get the index value of where the game is for new rec to be added
		//call managing class recommendation function with that index found
		//create a new node for the new recommendation
		cout << "5 -- Retrieve information about a game" << endl;
		cout << "6 -- Display games for a particular platforms" << endl;
		cout << "7 -- Display games for all the platforms" << endl;
		cout << "Menu Choice: ";
		cin >> menu_choice;
		cin.ignore();
		if(menu_choice == '1')
		{
			cout << "Name of the game: ";
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');
	
			game[0] = toupper(game[0]);
		
			cout << "Description of the game: ";
			cin.get(description, SIZE, '\n');
			cin.ignore(100, '\n');
	
			cout << "Type of game: ";
			cin.get(game_type, SIZE, '\n');
			cin.ignore(100, '\n');
		
			cout << "Platform for the game: ";
			cin.get(platform, SIZE, '\n');
			cin.ignore(100, '\n');
		
			cout << "Rating of the game (0 - not good | 5 - really good): ";
			cin.get(stars, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "Recommendations/Comments: ";
			cin.get(rec, SIZE, '\n');
			cin.ignore(100, '\n');	
		
			if(!Games.add_game(game, description, game_type, platform, stars, rec))
				cerr << "Game could not be added!" << endl;
	
			else
				cout << "Game has been added!" << endl;
		}

		else if(menu_choice == '2')
		{
			if(!Games.load_games())
				cerr << "Sorry couldnt load the games!" << endl;
			else
				cout << "The games have been loaded!" << endl;
		}

		else if(menu_choice == '3')
		{
			cout << "What game would you like to remove: ";
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');	

			game[0] = toupper(game[0]);
	
			if(!Games.remove_game(game))
				cerr << "Game could not be removed!" << endl;

			else
				cout << "Game has been removed!" << endl;
		}

		else if(menu_choice == '4')
		{

			char recom[SIZE];
			cout << "What is the game for which you would like to add recommendation: ";
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');

			game[0] = toupper(game[0]);	

			cout << "What is the new recommendation/comments for the game: ";
			cin.get(recom, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "For which platform would you like to add this new recommendation: ";
			cin.get(platform, SIZE, '\n');
			cin.ignore(100, '\n');

			if(!Games.add_rec(game, recom, platform))
				cerr << "Recommendation/comment could not be added!" << endl;
	
			else
				cout << "Recommendation/comment has been added!" << endl;
		}

		else if(menu_choice == '5')
		{
			cout << "What game would you like to retrieve: ";
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');
		
			game[0] = toupper(game[0]);
		
			if(!Games.retrieve(game))
				cerr << "Game you searched for doesnt exist!" << endl;

			else
				cout << "Game you searched for exist and has been found!" << endl;
		}

		else if(menu_choice == '6')
		{
			cout << "For which platform would you like to display: ";
			cin.get(platform, SIZE, '\n');
			cin.ignore(100, '\n');
	
			if(!Games.display_platform(platform))
				cerr << "Inputted platform doesnt exist for display!" << endl;
		}

		else if(menu_choice == '7')
		{
			Games.display_all();
		}
	
	 	cout << "Would you like to pick from the menu? (Y/y -- yes, any other key for no): ";
		cin >> response;
		cin.ignore();

	}while(response == 'Y' || response == 'y');



return 0;
}
