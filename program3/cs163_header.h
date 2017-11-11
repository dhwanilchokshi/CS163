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


#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

const int SIZE = 500;

//This node contains information about adding a new recommendation
//It will be a seperate linear linked list from the original node of hash tables
struct anode
{
	anode();
	char *new_rec;
	anode *next;
	int create(char new_reco[]);	//add rec function, create and add the passed in new rec to the pointer
};

//this is the manager game class which contains all the info
//an instance of this class is created in the node below
//it contains all functions which will operate on the data collection
class games_manage
{
	public:
		games_manage();
		~games_manage();
		int display_platform();		//display all game information for certain platforms
		int check(char plat[]);		//checks platform with one passed in to see if theres a match
		int check2(char name[]);	//checks game name with one passed in to see if theres a match
		int display_all_platform();	//display all game information for all platforms
		int remove(char name[]);	//remove a game based on the name of the game
		int copy_create(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);	//copy and create the dynamic arrays
		int add_recommendation(char name[], char new_rec[]);	//add recommendations based on game name
	private:
		anode *head;			//head pointer to the anode, which contains new rec
		anode *tail;			//tail pointer to the anode, so we can append on added recommendations
		char *game_name;		
		char *description;
		char *type;
		char *platform;
		char *stars;
		char *recommendation;
		void deallocate_all(anode *&head);	//recursive function which deallocated all memory of added recommendations
};

//node which consist of an instance of the manager class so it 
//can be accessed by the table class
struct node
{
	games_manage games;	//instance of the game manager class object
	node *next;
};

//table class is the main class which contains a double pointer to the hash table
//so we can create an array of node pointers to create buckets in case of collisions
class table
{
	public:
		table(int size = 101);
		~table();
		int add_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[]);	//insert game and info into table	
		int display_platform(char plat[]);	//display based on platform
		int display_all();			//display all
		int retrieve(char name[]);		//retrieve a game
		int load_games();			//load games from file into table
		int remove_game(char name[]);		//remove a game based on name
		int add_rec(char name[], char new_rec[], char plat[]);	//add a recommendation for game
	private:		
		node ** hash_table;		//double pointer to hash_table so we can create a dynamic table of node pointers
		int table_size;			//size of the table, created in constructor
		int hash_function(char name[]);		//hash function to give us an index
		void deallocate(node *&head);		//deletes all nodes if multiple nodes to an index	
};
