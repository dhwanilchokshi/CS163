#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*
Dhwanil Chokshi 
CS 163
Program 2

	The main purpose of this program was to use the stack data structure with linear linked list of arrays
	and to use the queue data structure with circular linked list. Mixing these data structures enabled us 
	to create an efficient application which helps the user plan their trip. First the user will plan their
	stops for the trip, which will be enqueued into the circular list. After the user is done planning, they
	will reach their destination, and the information will be dequeued and pushed into stack. This will help
	the user know when they have reached their destination. As they pop the stack, they will eventually be
	able to go back to their starting location.		

*/

const int MAX = 500;
const int A_SIZE = 5;

//manager class which consists of copy and display functions called by
//stack and queue class to display and copy information passed in
class trip_stop
{
	public:
		trip_stop();
		~trip_stop();
		int copy(char pla[], char loc[], char lod[], char mil[]);
		int copy2(char pla[], char loc[], char lod[], char mil[], char rating[], char gas_spent[]);
		int display();
		int display2();
		int stack_copy(char place[], char loca[], char lodge[], char miles[], char rating[], char gas_spent[]);
	private:
		char *next_stop;
		char *location_stop;
		char *reserved_lodging;
		char *miles_from_previous;
		char *lodge_rating;
		char *gas_amount;
};

//node to be used with linear linked list of arrays
//which will be used with the stack structure
struct node
{
	trip_stop *trip;
	node *next;
};

//node to be used with circular list
//which will be used with queue structure
struct anode
{
	trip_stop trips;
	anode *next;
};

//core stack class, responsible for recieving info and passing it to
//manager class for creation and copying
//furthermore, this class has stack operations on data structure
class stack
{
	public:
		stack();
		~stack();
		int push(char stop[], char loca[], char lodg[], char mile[], char rating[], char gas_spent[]);
		int pop();
		int peek();
		int display();
	private:
		node *head;
		int top_index;
		int stack_deallocate(node *&head);
};

//core queue class responsible for getting information and passing it to 
//manager class for creation and copying
//this structure will perform queue operations on circular list
class queue
{
	public:
		queue();
		~queue();	
		int enqueue(char pla[], char loc[], char lod[], char mil[]);
		int dequeue(char stop[], char location[], char lodge[], char miles[], stack &Stack, char rating[], char gas_spent[]);
		int copy(char pla[], char loc[], char lod[], char mil[], stack &Stack, char rating[], char gas_spent[]);
		int peek();
		int display();
	private:
		anode *rear;
		int queue_deallocate(anode *&rear);
};



