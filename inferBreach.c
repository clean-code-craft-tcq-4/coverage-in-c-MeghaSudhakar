#include "typewise-alert.h"
#include <stdio.h>
#include <string.h>
#include "inferBreach.h"

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

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
 
  limit_struct_buffer limit_array[3] = {{0,35}, {0,45}, {0,40}};
  
  return inferBreach(temperatureInC, limit_array[coolingType].lowerLimit, limit_array[coolingType].upperLimit);
  
}
