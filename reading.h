
#pragma once

const int MAX_CHAR = 200;
class Reading {
  public:
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
    char datetime[MAX_CHAR];
    float humidity; 
};


