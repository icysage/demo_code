
#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

List::List()
{
   head = NULL;
   tail = NULL;
}

void List::addToList(Reading* data)
{
   // create a node and set data field
   Node* newNode = new Node;
   newNode->data = data;
   newNode->next = NULL;

/*   // backwards
   // insert in front
   newNode->next = head;
   head = newNode; 
*/

/*   // forwards
   // insert in back
   
   if(!head) // list is empty
   {
       head = tail = newNode;
   }
   else // list is not empty
   {
       tail->next = newNode;
       tail = newNode;
   }
*/

   // insert in ordered.

   // list is empty
   if(!head) // head == NULL
   {
        head = newNode;
        return;
   } 
   // new node's temp
   int temp = data->getTemp();

   // insert at the beginning
   if(temp < head->data->getTemp())
   {
       // insert in front
       newNode->next = head;
       head = newNode;
       return;
   }

   // inserting in the middle/end

   Node* current = head;
   Node* prev = NULL;

  //  prev -> current
  //  prev -> newNode -> current

   while(current)
   {
      if(current->data->getTemp() > temp)
      {
         break;
      }
      prev = current;
      current = current->next;
   }
   newNode->next = current;
   prev->next = newNode;

}

List::~List()
{
    while(head) // head != NULL
    {
       Node* temp = head;
       head = head->next; 
       delete temp->data;
       delete temp;
    }

}


/* Purpose: Ask user for int type value. Checks for valid int before returning
 * the value.
 * Parameters: none
 * Return:  Valid int value
 */
int List::getInt()
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
float List::getFloat()
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
 


/* Purpose: Ask user for a temperature value. 
 *  Puts the value at the end of the array.
 * Parameters: the list of temps (array of ints)
 *                     and the count as reference
 * Return:  none
 */
void List::addTemp()
{
	int temp;
    char dt[MAX_CHAR];
    float hum;
	// this just adds to end of array
	// if you want to put the temps in
	// order, see array example: insert_delete.cpp
	// for how to do that.
	cout << "Enter temperature: ";
	temp = getInt();

    // get date time
    cout << "enter date and time: ";
    cin.getline(dt, MAX_CHAR);

    cout << "enter humidity ratio (between 0 and 1): ";
    hum = getFloat();

    //create memory for new object and pass in values
    // via the parameterized constructor
    Reading* data = new Reading(temp,dt,hum);
    addToList(data);
    
}

/* Purpose: Prints the list of temperatures.
 * Parameters: the list of temps (array of ints)
 *                     and the count
 * Return:  none
 */
void List::printList()
{
	if(!head) // head is NULL
	{
		cout << "=== The List is Empty ===" << endl;
		return;
	}
    
	cout << "=== List ===" << endl;
    Node* current = head;

	while(current) // current != NULL
	{
		cout << "temp: " << current->data->getTemp() << endl;
        cout << "Date time: " << current->data->getDatetime() << endl;
        cout << "Humidity: " << current->data->getHumidity() << endl;
        current = current->next;
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
void List::printStats()
{
	if(!head) // head is NULL
	{
		cout << "=== No Data ===" << endl;
		return;
	}
	int max = head->data->getTemp();
	int min = head->data->getTemp();
	float sum = 0.0;
	int count = 0;
	for(Node* current=head; current; current = current->next)
	{
        int temp = current->data->getTemp();
		if(temp > max)
		{
			max = temp;
		}
		if(temp < min)
		{
			min = temp;
		}
		sum += temp;
        count++;
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
void List::deleteTemp()
{
	//NOTE: this only deletes the first
	// element of the temperature in the
	// list.  I'll leave it up to students to
	// figure out how to delete all elements
	// of the given temperature
	
	if(!head) // head is NULL
	{
		cout <<  "=== No Data ===" << endl;
		return;
	}

	int del = 0;
	printList();
	cout << "What temperature to delete? ";
	del = getInt();
	
    // delete the first node. 
    if(del == head->data->getTemp())
    {
        Node* temp = head->next; // second node
        delete head->data;
        delete head;
        head = temp; // second becomes the first node
        return;
    }
 
    // delete in the middle (or at the end)
    Node* current = head->next;
    Node* prev = head;

	while(current) // current is not NULL
	{
		if(current->data->getTemp() == del)
		{
			// tie around the node
            // prev/next -> current/next 
             prev->next = current->next;
             delete current->data;
             delete current;
			 //return; // for one temp
             current = prev;  //for more than one temp 
		}
        prev = current;
        current = current->next;
	}
	cout << "Cannot find this temperature" << endl;
	
}

void List::readInFile()
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
       infile >> temp; 
       infile >> hum;
       infile.ignore(100,'\n');
       
       Reading* data = new Reading(temp, dt, hum);

       addToList(data);   
  }

  infile.close();
     
}

void List::writeOutFile()
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
   Node* current = head;
   while(current)
   {
      outfile << current->data->getDatetime() << endl;
      outfile << current->data->getTemp() << endl;
      outfile << current->data->getHumidity() << endl;
      current = current->next;
   }

   outfile.close();
}
