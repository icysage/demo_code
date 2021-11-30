/*  list.cpp - Dona Hertel
    manages array of Reading objects
*/
#pragma once

#include "reading.h"

const int CAP = 100;


class List {
   public:
       List();
       ~List();

       // tasks 
       void addTemp();
       void printList();
       void printStats();
       void deleteTemp();
       void readInFile();
       void writeOutFile();
 

   private:
      //Reading list[CAP];
      //int count;
      struct Node {
         Reading* data;
         Node* next;
      };
      Node* head;
      Node* tail; // for forwards insert ONLY

      // utilities
      void addToList(Reading* data);
      int getInt();
      float getFloat();

}; 
