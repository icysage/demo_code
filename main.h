/* Example code - Simple Functions
 * Dona Hertel
 * 
 *  This is a general header file for
 *  things that are needed through out
 * the code. Not a requirement but
 * nice to have.
 */

// this is needed in all header files
// to prevent the header from being
// included more than once.

#pragma once

// either put standard libraries in
// the header file in the cpp file
#include <iostream>
#include <fstream>
using namespace std;

#include "reading.h"

//put constants here
// you can optionally
// put constants in 
// a header/cpp file if
// that constant is not being
// used outside of that file
const int CAPACITY = 100;

// put function prototypes here
// this allows functions to be
// defined anywhere in the main.cpp
// file. 

void deleteList(Reading* list[], int count);
int getChoice(int lo, int hi);
int getInt();
float getFloat();
int chooseFromMenu();
// one way to pass in an array of pointers:
void addTemp(Reading* list[], int &count);
// another way
void printList(Reading** list, int count);
void printStats(Reading* list[], int count);
void deleteTemp(Reading* list[], int &count);
void readInFile(Reading* list[], int &count);
void writeOutFile(Reading* list[], int count);
 
