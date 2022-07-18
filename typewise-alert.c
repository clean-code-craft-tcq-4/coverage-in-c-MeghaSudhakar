#include "typewise-alert.h"
#include "How_to_alert.h"
#include "Check_and_Alert.h"
#include "Classify_Breach_Check.h"

#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}





