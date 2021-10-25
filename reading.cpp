
#include <cstring>
#include "reading.h"

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


 
