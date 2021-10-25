/* Example code - Simple Functions
 * Dona Hertel
 * 
 *  shows the use of functions. A menu
 * program for entering temperature
 * readings. The program can add,
 * delete and print stats on temperature
 * data.
 */
#include "main.h"  // for constants and 
                   // function prototypes
/* Purpose: Main function.  Has the menu 
 * loop that runs the program.
 * Parameters: none
 * Return:  int value
 */
int main()
{
    Reading list[CAPACITY];
	int count = 0;
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
			  case 1:   addTemp(list, count);
			                 break;
			  case 2:   printList(list, count);
			                 break;
			  case 3:   deleteTemp(list, count);
			                 break;
			  case 4:   printStats(list, count);
			                 break;
              case 5:   readInFile(list, count);
                             break;
              case 6:   writeOutFile(list, count);
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
	cout << "5 - quit program" << endl;
	
	return getChoice(1,7);
}

// Task functions

/* Purpose: Ask user for a temperature value. 
 *  Puts the value at the end of the array.
 * Parameters: the list of temps (array of ints)
 *                     and the count as reference
 * Return:  none
 */
void addTemp(Reading list[], int &count)
{
	int temp;
    char dt[MAX_CHAR];
	// this just adds to end of array
	// if you want to put the temps in
	// order, see array example: insert_delete.cpp
	// for how to do that.
	cout << "Enter temperature: ";
	temp = getInt();
	list[count].setTemp(temp);
    // get date time
    cout << "enter date and time: ";
    cin.getline(dt, MAX_CHAR);
    list[count].setDatetime(dt);

    cout << "enter humidity ratio (between 0 and 1): ";
    list[count].setHumidity(getFloat());

	count++;
}

/* Purpose: Prints the list of temperatures.
 * Parameters: the list of temps (array of ints)
 *                     and the count
 * Return:  none
 */
void printList(Reading list[], int count)
{
	if(count == 0)
	{
		cout << "=== The List is Empty ===" << endl;
		return;
	}
    
	cout << "=== List ===" << endl;
	for(int i=0; i < count; i++)
	{
		cout << "temp: " << list[i].getTemp() << endl;
        cout << "Date time: " << list[i].getDatetime() << endl;
        cout << "Humidity: " << list[i].getHumidity() << endl;
	}
    
	cout << "=========="<< endl << endl;
}

/* Purpose: Calculates and prints out 
 * statistics about the temperatures. Prints
 * out the maximum temp, the minimum temp
 * and the average temp.
 * Parameters: the list of temps (array of ints)
 *                     and the count
 * Return:  none
 */
void printStats(Reading list[], int count)
{
	if(count == 0)
	{
		cout << "=== No Data ===" << endl;
		return;
	}
	int max = list[0].getTemp();
	int min = list[0].getTemp();
	float sum = 0.0;
	
	for(int i=0; i < count; i++)
	{
        int temp = list[i].getTemp();
		if(temp > max)
		{
			max = temp;
		}
		if(temp < min)
		{
			min = temp;
		}
		sum += temp;
	}
	
	cout << "=== Statistics ===" << endl;
	cout << "Max: " << max << endl;
	cout << "Min:  " << min << endl;
	cout << "Average: " << sum/count << endl;
	    
}

/* Purpose: Ask user for a temperature value.
 * Then delete the first temperature that matches
 * from the list. If temperature is not found, prints
 * an error message.
 * Parameters: the list of temps (array of ints)
 *                     and the count as reference
 * Return:  none
 */
void deleteTemp(Reading list[], int &count)
{
	//NOTE: this only deletes the first
	// element of the temperature in the
	// list.  I'll leave it up to students to
	// figure out how to delete all elements
	// of the given temperature
	
	if(count == 0) // nothing to delete.
	{
		cout <<  "=== No Data ===" << endl;
		return;
	}
	int del = 0;
	printList(list, count);
	cout << "What temperature to delete? ";
	del = getInt();
	
	for(int i=0; i < count; i++)
	{
		if(list[i].getTemp() == del)
		{
			// move over to the left
              for(int j = i+1; j < count; j++)
              {
				  list[j-1] = list[j];
			  }
			  // decrement the count
			  count--;
			  return; 
		  }
	  }
	  cout << "Cannot find this temperature" << endl; 			
}

void readInFile(Reading list[], int& count)
{
  ifstream infile;
  char filename[MAX_CHAR];
  char dt[MAX_CHAR];
  int temp;
  float hum;

  cout << "Enter file name to read: ";
  cin.getline(filename, MAX_CHAR);

  infile.open(filename);
  
  if(!infile.is_open())
  {
      cout << "file can't be opened: " << filename << endl;
      return;         
  }
  
  while( infile.getline(dt, MAX_CHAR))
  {
       list[count].setDatetime(dt);
       infile >> temp; 
       list[count].setTemp(temp);
       infile >> hum;
       list[count].setHumidity(hum);
       infile.ignore(100,'\n');
       count++;
  }

  infile.close();
     
}

void writeOutFile(Reading list[], int count)
{
   ofstream outfile;
   char filename[MAX_CHAR];

   cout << "Enter name of file to write: ";
   cin.getline(filename, MAX_CHAR);

   outfile.open(filename);
   if(!outfile.is_open())
   {
       cout << "file can't be opened" << endl;
       return;
   }
   for(int i=0; i<count; i++)
   {
      outfile << list[i].getDatetime() << endl;
      outfile << list[i].getTemp() << endl;
      outfile << list[i].getHumidity() << endl;
   }

   outfile.close();
}
