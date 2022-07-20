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

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
 
  limit_struct_buffer limit_array[3] = {{0,35}, {0,45}, {0,40}};
  
  return inferBreach(temperatureInC, limit_array[coolingType].lowerLimit, limit_array[coolingType].upperLimit);
  
}

int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
  int result=0;
   
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  result = func(alertTarget, breachType);
  
  if(!result)
  return result;
  else
    return 1;
}
  
int func(AlertTarget alertTarget, BreachType breachType)
{
  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      {
      sendToController(breachType);
        return 0;
      break;
      }
    case TO_EMAIL:
      {
      sendToEmail(breachType);
        return 0;
      break;
      }
        default:
        return 1;      
  } 
}

int checkmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  
  printf("To: %s\n", recepient);
  
  const char* breachbuffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  
  printf("%s", breachbuffer[breachType]); 
  
  if(breachType == 3)
    return 1;
  else
    return 0;
}


int sendToEmail(BreachType breachType) 
{
  const char* buffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  printf("%s", buffer[breachType]);  
  
  if(breachType <0 || breachType >3)
    return 1;
  else
    return 0;
  
}


int sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  
  if(breachType <0 || breachType >3)
    return 1;
  else
    return 0;
}

