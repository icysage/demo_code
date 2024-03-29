
#include <cstring>
#include "reading.h"

const char notset[] = "<NOT SET>";


Reading::Reading()
{
   temp = 0;
   // make empty C string
   int size = strlen(notset) + 1;
   datetime = new char[size];
   strcpy(datetime, notset);
   humidity = 0.0;
}

Reading::Reading(int t, char* dt, float h)
{
    temp = t;
    int size = strlen(dt)+1;
    datetime = new char[size];
    strcpy(datetime, dt);
    humidity = h;
}

Reading::Reading(Reading &cpy)
{
   this->temp = cpy.temp;
   int size = strlen(cpy.datetime) + 1;
   this->datetime = new char[size];
   strcpy(this->datetime, cpy.datetime);
   this->humidity = cpy.humidity;
}

Reading & Reading::operator=(Reading &cpy)
{
   if(this != &cpy)
   {
      this->temp = cpy.temp;
      delete this->datetime;
      int size = strlen(cpy.datetime) + 1;
      this->datetime = new char[size];
      strcpy(this->datetime, cpy.datetime);
      this->humidity = cpy.humidity;
   }
   return *this;
}

Reading::~Reading()
{
   delete datetime;
}

const char* Reading::getDatetime()
{
   return datetime;
}

int Reading::getTemp()
{
   return temp;
}

float Reading::getHumidity()
{
  return humidity;
}

void Reading::setDatetime(const char* dt)
{
   delete datetime;
   int size = strlen(dt)+1;
   datetime = new char[size];
   strcpy(datetime, dt);
}

void Reading::setTemp(int t)
{
   temp = t;
}

void Reading::setHumidity(float h)
{
   humidity = h;
}


 
