#include "typewise-alert.h"
#include <stdio.h>
#include <string.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  if(value <= lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value >= upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}
