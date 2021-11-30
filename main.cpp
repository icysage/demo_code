/* Example code - Simple Functions
 * Dona Hertel
 * 
 *  shows the use of functions. A menu
 * program for entering temperature
 * readings. The program can add,
 * delete and print stats on temperature
 * data.
 */

// THIS HAS CHANGED
#include "main.h"  // for constants and 
                   // function prototypes
#include "list.h"

/* Purpose: Main function.  Has the menu 
 * loop that runs the program.
 * Parameters: none
 * Return:  int value
 */
int main()
{
    List list;
	bool cont = true;
	int choice = -1;
	
	// while loop
    // you can also check for 
    // choice not equal to the 'quit'
    // choice.
	while(cont)
	{
          
	      choice = chooseFromMenu();
	      
	      switch (choice)
	      {
			  case 1:   list.addTemp();
			                 break;
			  case 2:   list.printList();
			                 break;
			  case 3:   list.deleteTemp();
			                 break;
			  case 4:   list.printStats();
			                 break;
              case 5:   list.readInFile();
                             break;
              case 6:   list.writeOutFile();
                             break;
			  case 7:   cont = false;
			                 break;
			  default:  cout << "Wrong choice!" << endl;
		  }
    }
   
    
    return 0;
}



/* Purpose: Ask user for int type value. Checks for valid int before returning
 * the value.
 * Parameters: none
 * Return:  Valid int value
 */
int getInt()
{
     int num;
     cin >> num;
     while(cin.fail())  // clear the fail flag
     {
         cin.clear();
         // clear out the entire buffer
         cin.ignore(200,'\n');
         // have user re-enter the number
         cout << "Not an integer. Please enter an integer. \n";
         cin >> num;
     }
    // useful for when using getline or get functions
    // in the rest of the code. strips out the newline
    // that is left behind
     cin.ignore(200,'\n');
     return num;
}

// Utility functions

/* Purpose: Ask user for float type value. Checks for valid float before returning
 * the value.
 * Parameters: none
 * Return:  Valid float value
 */
float getFloat()
{
    float num;
    cin >> num;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Not a number. Please enter a number. \n";
        cin >> num;
    }
    cin.ignore(200,'\n'); 
    return num;
}
 
/* Purpose: Ask user for a choice from the menu.
 * Makes sure choice is between a low and high 
 *  number. 
 * Parameters: the low and high number.
 * Return:  Valid choice
 */
int getChoice(int low, int high)
{
    int choice = -1;
    cout << "Enter choice: ";
    choice = getInt();
    while(choice < low || choice > high)
    {
        cout << "choice needs to be between ";
        cout << low << " and " << high << endl;
        choice = getInt();
    }
    return choice;

}
/* Purpose:  Prints the menu and asks for
 * a choice
 * Parameters: none
 * Return:  Valid choice
 */
int chooseFromMenu()
{
	cout << "*** MENU ***" << endl;
	cout << "1 - add temp to list" << endl;
	cout << "2 - print list" << endl;
	cout << "3 - delete temp from list" << endl;
	cout << "4 - print statistics" << endl;
    cout << "5 - read in from a file" << endl;
    cout << "6 - write out to a file" << endl;
	cout << "7 - quit program" << endl;
	
	return getChoice(1,7);
}



