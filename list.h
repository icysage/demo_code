/*  list.cpp - Dona Hertel
    manages array of Reading objects
*/
#pragma once

#include "reading.h"

const int CAP = 100;

class List {
   public:
       List();

       // tasks 
       void addTemp();
       void printList();
       void printStats();
       void deleteTemp();
       void readInFile();
       void writeOutFile();
 

   private:
      Reading list[CAP];
      int count;

      // utilities
      int getInt();
      float getFloat();

}; 
