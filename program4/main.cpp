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



int main()
{
	//instance of BST 
	BST Games;

	//static arrays allocated for input from user	
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
		cout << "4 -- Remove all games of a certain name" << endl;
		cout << "5 -- Count of games with a rating of 5" << endl;
		cout << "6 -- Retrieve information about a game" << endl;
		cout << "7 -- Display all games" << endl;
		cout << "8 -- Display games in a range" << endl;
		cout << "Menu Choice: ";
		cin >> menu_choice;
		cin.ignore();

		//insert a game of choice
		//first letter of name capitalized
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

		//load games from external files
		else if(menu_choice == '2')
		{
			if(!Games.load_games())
				cerr << "Sorry the games could not be loaded!" << endl;
			else
				cout << "The games have been loaded from the file!" << endl;
		}

		//remove a game based on name and platform
		//first letter of game name capitalized when taken from user
		else if(menu_choice == '3')
		{
			cout << "What is the name of the game you want to remove: ";		
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "What is the platform of the game to be removed: ";
			cin.get(platform, SIZE, '\n');
			cin.ignore(100, '\n');

			game[0] = toupper(game[0]);

			if(!Games.remove_a_game(game, description, game_type, platform, stars, rec))
				cerr << "The game could not be removed!(remember not to capitalize the first letter of game)" << endl;

			else
				cout << "The game has been removed!" << endl;
		}

		//remove all instances of the game by the name
		//first letter of game capitalized
		else if(menu_choice == '4')
		{
			cout << "What is the name of the game for which you want to remove all instances: ";
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');
	
			game[0] = toupper(game[0]);
	
			if(!Games.remove_all_game(game, description, game_type, platform, stars, rec))
				cerr << "The game instances could not be removed!(remember not to capitalize the first letter of game)" << endl;
		
			else
				cout << "The games instances have been removed!" << endl;
		}
	
		//counts the amount of games which have rating of full 5
		else if(menu_choice == '5')
		{
			cout << "There are " << Games.count_top_rating() << " games which are rated a full 5 stars!" << endl;
		}

		//retrieves the game, if it exists in the tree
		//first letter of game capitalized
		else if(menu_choice == '6')
		{
			cout << "What game are you trying to retrieve: ";
			cin.get(game, SIZE, '\n');
			cin.ignore(100, '\n');

			game[0] = toupper(game[0]);

			if(!Games.retrieve(game))
				cerr << "Game could not be found!" << endl;
			else
				cout << "Game exists and has been found!" << endl;
		}

		//display all the games in the tree in alphabetical order
		else if(menu_choice == '7')
		{
			if(!Games.display_all())
				cerr << "No games to display!" << endl;
		}
		
		//display games within certain range provided by user
		//capitalized starting parameter and ending parameter
		else if(menu_choice == '8')
		{
			char first;
			char last;

			cout << "Starting first letter of character range: ";
			cin >> first;
			cin.ignore();

			first = toupper(first);
			
			cout << "Ending letter of the character range: ";
			cin >> last;
			cin.ignore();

			last = toupper(last);

			if(!Games.display_range(first, last))
				cerr << "Games couldnt be displayed in given range!" << endl;

		}
	
	 	cout << "Would you like to pick from the menu? (Y/y -- yes, any other key for no): ";
		cin >> response;
		cin.ignore();

	}while(response == 'Y' || response == 'y');



return 0;
}
