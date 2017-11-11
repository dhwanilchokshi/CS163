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

//BST constructor only has private data root, which is initialized to NULL
BST::BST()
{
	root = NULL;

}

//destructor calls another recursive function which deletes
//all root data and sets it to NULL
BST::~BST()
{
	deallocate_all(root);
	if(root)
	{
		root = NULL;
	}
}

//recursive function which goes left and right and deletes all the nodes
//on its way back, also setting data to NULL.
int BST::deallocate_all(node *&root)
{
	if(!root)
		return 0;	

	deallocate_all(root->left);
	deallocate_all(root->right);
	if(!root->left && !root->right)
	{
		delete root;
		root = NULL;
	}
return 1;
}

//calls a recursive function which adds the game
int BST::add_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[])
{
	if(!name)
		return 0;

	return add(name, disc, g_type, plat, rate, reco, root);
}

//recursive function which checks the cases and adds the games respectively.
//the data which is same as root is stored to right subtree
int BST::add(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[], node *&root)
{
	if(!root)
	{
		root = new node;
		root->games.copy_create(name, disc, g_type, plat, rate, reco);
		root->left = root->right = NULL;
		return 1;
	}

	else if(!root->games.check(name))
	{
		return add(name, disc, g_type, plat, rate, reco, root->left);
	}

	else
	{
		return add(name, disc, g_type, plat, rate, reco, root->right);
	}

}

//calls the recursive display
int BST::display_all()
{
	if(!root)
		return 0;

	return display_all(root);
}

//recursive display which displays alphabetically by the inorder method
//by calling the managing class display to display the private members
int BST::display_all(node *root)
{
	if(!root)
		return 1;

	display_all(root->left);
	root->games.display_all();
	display_all(root->right);
return 1;
}

//calls the recursive function which will display the range
int BST::display_range(char first, char last)
{
	if(!root)
		return 0;

	return display_range(first, last, root);

}

//recursive function which will display the character range in which
//the user wants to view the data. The first and last letter is passed
//in to a function of managing class, which string compares and displays
//only the data with the given range
int BST::display_range(char first, char last, node *root)
{
	if(!root)
		return 1;

	display_range(first, last, root->left);
	if(root->games.display_range(first, last))
	{
		root->games.display_all();
	}
	display_range(first, last, root->right);
return 1;
}

//calls recursive function which displays total
//amount of nodes with rating of 5
int BST::count_top_rating()
{
	if(!root)
		return 0;

	int total = 0;
	return count_top_rating(root, total);
}

//recursive function which traverses left and right
//calling the manager class function to check if the 
//rating of the node is 5, if it is then increment total
int BST::count_top_rating(node *root, int &total)
{
	if(!root)
		return total;

	if(root->games.count_top_rating())
		total++;

	count_top_rating(root->left, total);
	count_top_rating(root->right, total);
return total;
}

//calls recursive function which removes a game based on name and platform
int BST::remove_a_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[])
{
	if(!root)
		return 0;

	return remove_a_game(name, disc, g_type, plat, rate, reco, root);
}

//recursive function, which checks to see if the platform and name matches the 
//game which is to be removed. If yes, then is checks all the cases for deletion,
//copying the data of inorder successor into the root's data, then deleting the node
int BST::remove_a_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[], node *&root)
{
	if(!root)
		return 0;

	if(root->games.remove_a_game(name, plat))
	{
		if(!root->left && !root->right)
		{
			delete root;
			root = NULL;
			return 1;
		}

		else if(!root->left)
		{
			node *temp = root;
			root = root->right;
			delete temp;
			return 1;
		}

		else if(!root->right)
		{
			node *temp = root;
			root = root->left;
			delete temp;
			return 1;
		}

		else
		{
			node *current = root->right;
			if(!current->left)
			{
				current->games.copier(name, disc, g_type, plat, rate, reco);
				root->games.copy_create(name, disc, g_type, plat, rate, reco);
				if(current->right)
				{
					root->right = current->right;
					delete current;
					return 1;
				}
			}
			else
			{
				while(current->left)
				{
					current = current->left;
				}
				current->games.copier(name, disc, g_type, plat, rate, reco);
				root->games.copy_create(name, disc, g_type, plat, rate, reco);
				delete current;
				return 1;
			}
		}
	}

//calls the recursive function on right and left based on which is going to be used
//to efficiently only travel down certain path for greater efficiency
	if(!root->games.check(name))
		return remove_a_game(name, disc, g_type, plat, rate, reco, root->left);	
	else
		return remove_a_game(name, disc, g_type, plat, rate, reco, root->right);
		
}

//calls the recursive function which deletes all game instances based on name
//by calling the retrieve function to check if the game will exist or not
int BST::remove_all_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[])
{
	if(!root)
		return 0;
	

	if(retrieve(name))
	{
		remove_all_game(name, disc, g_type, plat, rate, reco, root);
		return 1;
	}
	
return 0;	
}

//recursive function deleting all games instances based on the name of the game.
//Checks all the cases for deletion, then calls the recursive function again so we are
//not stopping once a match has been found. This way we can delete all instances of the game
int BST::remove_all_game(char name[], char disc[], char g_type[], char plat[], char rate[], char reco[], node *&root)
{
	if(!root)
		return 0;

	remove_all_game(name, disc, g_type, plat, rate, reco, root->left);
	remove_all_game(name, disc, g_type, plat, rate, reco, root->right);
	
	if(root->games.check2(name))
	{
		
		if(!root->left && !root->right)
		{
			delete root;
			root = NULL;
			return 1;
		}
		else if(!root->left)
		{
			node *temp = root;
			root = root->right;
			delete temp;
			return remove_all_game(name, disc, g_type, plat, rate, reco, root);
		}
		else if(!root->right)
		{
			node *temp = root;
			root = root->left;
			delete temp;
			return remove_all_game(name, disc, g_type, plat, rate, reco, root);
		}
		else
		{
			node *current = root->right;
			if(!current->left)
			{
				current->games.copier(name, disc, g_type, plat, rate, reco);
				root->games.copy_create(name, disc, g_type, plat, rate, reco);
				
				return remove_all_game(name, disc, g_type, plat, rate, reco, root->right);
			}
			else
			{
				while(current->left)
				{
					current = current->left;
				}
				current->games.copier(name, disc, g_type, plat, rate, reco);
				root->games.copy_create(name, disc, g_type, plat, rate, reco);
			        
				return remove_all_game(name, disc, g_type, plat, rate, reco, root->right);
			}
		}
	}
return 1;	
}

//calls the recusive function which checks if the game name
//passed in matches.
int BST::retrieve(char name[])
{
	if(!root)
		return 0;

	return retrieve(name, root);
}

//recursive function traversing both the subtrees and returning success
//if a match is found
int BST::retrieve(char name[], node *root)
{
	if(!root)
		return 0;

	if(root->games.check2(name))
		return 1;

	if(!root->games.check(name))	
		return retrieve(name, root->left);
	else
		return retrieve(name, root->right);
}

//function which loads the game from the external file in which
//they are stored. Then proceeds to add the game to the tree so
//we can conduct our operations on it.
int BST::load_games()
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

