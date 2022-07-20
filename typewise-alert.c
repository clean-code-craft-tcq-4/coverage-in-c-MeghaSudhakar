

#include "typewise-alert.h"
#include <stdio.h>
#include <string.h>
#include "inferBreach.h"

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
 
  limit_struct_buffer limit_array[3] = {{0,35}, {0,45}, {0,40}};
  
  return inferBreach(temperatureInC, limit_array[coolingType].lowerLimit, limit_array[coolingType].upperLimit);
  
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{


  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      {
      sendToController(breachType);
      break;
      }
    case TO_EMAIL:
      {
      sendToEmail(breachType);
      break;
      }
  }
}


void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}



void checkmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  
  printf("To: %s\n", recepient);
  
  const char* buffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  
  printf("%s", buffer[breachType]); 
  
}

void sendToEmail(BreachType breachType) 
{
  const char* buffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  printf("%s", buffer[breachType]);  
  
}


