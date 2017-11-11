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

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

//size of all statically allocated arrays
const int SIZE = 500;

//manager class of the program
//has direct access to members which store game info and functions
//which are accessed by the BST class below
class games_manage
{
	public:
		games_manage();
		~games_manage();
		int display_range(char first, char last);	//display games in a range (character range)
		int display_all();				//display all games and info
		int check(char name[]);				//check if the name is a match
		int check2(char name[]);			//strcmp check to see if its greater than/equal to 0
		int count_top_rating();				//count games rated 5 stars
		int remove_a_game(char name[], char plat[]);	//remove game based on name and platform
		int remove_all_game();				//remove all games based on name
		//dynamically allocates and creates the arrays to store info in for private members
		int copy_create(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);
		//copies the data from inorder successor to root data when deleting	
		int copier(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);
	private:
		char *game_name;		
		char *description;
		char *type;
		char *platform;
		char *stars;
		char *recommendation;
};

//node contains an instance of the manager class
//and the left/right pointers for the tree
struct node
{
	games_manage games;	//instance of the game manager class object
	node *left;
	node *right;
};

//BST class stores the operations which will be used to manipulate 
//data that is stored in the manager class. Most function used are
//recursive, hence they are put into the private section. Most functions
//are similar to the managing class except the load function, and root node pointer.
class BST
{
	public:
		BST();
		~BST();
		int add_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);	
		int display_range(char first, char last);	
		int display_all();
		int count_top_rating();
		int retrieve(char name[]);
		int load_games();			
		int remove_a_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);	
		int remove_all_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);	
	private:		
		node *root;
		int add(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[], node *&root);
		int display_range(char first, char last, node *root);	
		int display_all(node *root);
		int count_top_rating(node *root, int &total);
		int remove_a_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[], node*&root);	
		int remove_all_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[], node *&root);
		int deallocate_all(node *&root);
		int retrieve(char name[], node *root);
};
