/*
++----------------------------------------------------------------------------------------------++
|Dhwanil Chokshi										 |							
|Program 1											 |
|CS163 -- Karla Fant 										 |
|												 |
|	The purpose of this program was to implement a data structure (Linear Linked List)	 |
|	into an ADT. In this program, I have a created a tutor service for newcomers to 	 |
|	the university. This service implements the data structure in such a way, that it	 |
|	can be manipulated in multiple forms to fit the needs of the user. The user can add	 |
|	a subject with its assistance method, the user can display the subjects and their 	 |
|	respective assistance method, the user can display only top rated assistance method,	 |
|	user can remove the assistance method with ratings of 3 or lower, user can edit a	 |
|	rating of a particular subject, and they can add a new way of assistance to a subject	 |
|	of their choice.									 |
++----------------------------------------------------------------------------------------------++	
*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 500;	//max size for temporary arrays created

//structure for assistance node
//consists of different facts about particular assistance method
struct method	
{
	char *description;
	char *hours;
	int rating;
	char *location;
	char *on_weekends;
	method *next;
	method();	//constructor for initialization
};

//class which consists of functions that manipulate the information
//in method structure
//functions called by the second class below for data manipulation/display
class n_method
{
	public:
		n_method();
		~n_method();
		int add(char sub[], char disc[], char hours[], int &rating, char loc[], char weekends[]);
		int display();
		int display_top(char *subj);
		int remove_three();
		int edit(int &new_rating);
		int new_help(char disc[], char hours[], int &rate, char loc[], char weekends[]);	
	private:
		method *head;	
		method *tail;
};

//node structure to hold the subject, first class (so it can be accesed by second class)
//and pointer to next node
struct node
{
	char *subject;
	node *next;
	n_method data;
	node();		//constructor for initializing subject
};

//main class which will use its functions to get user input from client
//and functions which call other class function to manipulate info
//this class also consists of a recursive function in private section
class assistance
{
	public:
		assistance();
		~assistance();
		int add_subject(char sub[], char disc[], char hours[], int &rating, char loc[], char weekends[]);
		int display();
		int display_top(); //rating of 8,9,10
		int remove_3(char sub[], char disc[], char hours[], int &rate, char loc[], char weekends[]); //rating of 3 or lower
		int edit_rating(char subj[], int &new_rate);
		int add_new_help(char sub[], char disc[], char hours[], int &rate, char loc[], char weekends[]);
		int display_subjects();
	private: 
		node *head;
		node *tail;
		int display(node *head);

};
