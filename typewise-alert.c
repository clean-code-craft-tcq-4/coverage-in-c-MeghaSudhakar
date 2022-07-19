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
 
  limit_struct_buffer limit_array[3];
 
  limit_array[0].lowerLimit = 0;
  limit_array[0].upperLimit = 35;
  
  limit_array[1].lowerLimit = 0;
  limit_array[1].upperLimit = 45;
  
  limit_array[2].lowerLimit = 0;
  limit_array[2].upperLimit = 40;
  
  return inferBreach(temperatureInC, limit_array[coolingType].lowerLimit, limit_array[coolingType].upperLimit);
  
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{

  int result =0;
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
    result = sendToEmail(breachType);
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

int sendToEmail(BreachType breachType) 
{
  const char* buffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  printf("%s", buffer[breachType]);  
  
  if(breachType > 4)
  return 0;
}



