
#pragma once

const int MAX_CHAR = 200;
class Reading {
  public:

    Reading(); // default constructor
    Reading(int temp, char* dt, float h); // parameterized constructor
 
    ~Reading();

    // getters (assessors) - to get values of the private variables
    const char* getDatetime();
    int getTemp();
    float getHumidity();

    // setters (mutators) - to change values of the private variables
    void setDatetime(const char* dt);
    void setTemp(int i);
    void setHumidity(float h);
    
  private:
    int temp;
    char* datetime;
    float humidity; 
};


