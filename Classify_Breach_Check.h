#include "typewise-alert.h"
#include <stdio.h>


BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
  switch(coolingType) 
  {
    case PASSIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 40;
      break;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}
