#include "program1.h"
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

int main()
{
	assistance help;
	int menu_choice;
	char repeat_menu;
	char name_class[MAX];
	char description[MAX];
	char hours[MAX];
	int rating;
	char location[MAX];
	char on_weekends[MAX];



	do
	{
		cout << "1 -- ADD A SUBJECT" << endl;
		cout << "2 -- DISPLAY ALL" << endl;
		cout << "3 -- DISPLAY TOP RATED (RATING: 8, 9, 10)" << endl;
		cout << "4 -- REMOVE ASSISTANCE (RATING: 3 or lower)" << endl;
		cout << "5 -- EDIT RATING FOR A SUBJECT" << endl;
		cout << "6 -- DISPLAY ALL SUBJECTS" << endl;
		cout << "7 -- ADD A NEW WAY TO GET ASSISTANCE FOR A SUBJECT" << endl;

		cout << "CHOICE: ";
		cin >> menu_choice;
		cin.ignore();

		if(menu_choice == 1)
		{  

			cout << "SUBJECT: ";
			cin.get(name_class, MAX, '\n');
			cin.ignore(100, '\n');
	
			cout << "DESCRIPTION OF ASSISTANCE: ";
			cin.get(description, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "HOURS OF AVAILABILITY: ";
			cin.get(hours, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "RATING OF ASSISTANCE: ";
			cin >> rating;
			cin.ignore(100, '\n');

			cout << "LOCATION: ";
			cin.get(location, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "IS THERE ASSISTANCE ON WEEKENDS? (YES/NO): ";
			cin.get(on_weekends, MAX, '\n');
			cin.ignore(100, '\n');

			help.add_subject(name_class, description, hours, rating, location, on_weekends);
		}
		
		else if(menu_choice == 2)
		{
			if(help.display());
			
			else
				cout << "SORRY YOU HAVENT ENTERED ANYTHING!" << endl;
		}

		else if(menu_choice == 3)
		{
			if(help.display_top());
	
			else
				cout << "SORRY THERE ARE NO RATINGS OF 8, 9, 10 OR YOU HAVENT ENTERED ANYTHING!" << endl;
		}

		else if(menu_choice == 4)
		{
			if(help.remove_3(name_class, description, hours, rating, location, on_weekends));

			else
				cout << "SORRY THERE ARE NO RATINGS OF 3 AND LOWER OR YOU HAVENT ENTERED ANYTHING!" << endl;
		}

		else if(menu_choice == 5)
		{
			char subject_name[MAX];
			int new_rating;
	
			cout << "FOR WHAT SUBJECT WOULD YOU LIKE TO CHANGE THE RATING: ";
			cin.get(subject_name, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "WHATS THE NEW RATING: ";
			cin >> new_rating;
			cin.ignore();

			if(help.edit_rating(subject_name, new_rating));

			else
				cout << "THE RATING COULD NOT BE EDITED" << endl; 
		}

		else if(menu_choice == 6)
		{
			if(help.display_subjects());

			else
				cout << "SORRY WE COULDNT DISPLAY ALL SUBJECTS!" << endl;
		}

		else if(menu_choice == 7)
		{

			cout << "WHAT IS THE SUBJECT YOU WANT TO ADD HELP FOR: ";
			cin.get(name_class, MAX, '\n');
			cin.ignore(100, '\n');
	
			cout << "DESCRIPTION OF ASSISTANCE: ";
			cin.get(description, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "HOURS OF AVAILABILITY: ";
			cin.get(hours, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "RATING OF ASSISTANCE: ";
			cin >> rating;
			cin.ignore(100, '\n');

			cout << "LOCATION: ";
			cin.get(location, MAX, '\n');
			cin.ignore(100, '\n');

			cout << "IS THERE ASSISTANCE ON WEEKENDS? (YES/NO): ";
			cin.get(on_weekends, MAX, '\n');
			cin.ignore(100, '\n');

			if(help.add_new_help(name_class, description, hours, rating, location, on_weekends));

			else
				cout << "ASSISTANCE COULD NOT BE ADDED!" << endl;	
		}
		cout << "\nCHOOSE FROM THE MENU AGAIN? (Y/y FOR YES, ANY OTHER KEY FOR NO): ";
		cin >> repeat_menu;
		cin.ignore();
	
	}while(repeat_menu == 'y' || repeat_menu == 'Y');


return 0;
}
