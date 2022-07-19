#include "typewise-alert.h"


#include <stdio.h>
#include <string.h>

typedef struct 
  {
    int lowerLimit;
    int upperLimit;
  } stat;



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
 
   stat array[3];
 
  array[0].lowerLimit = 0;
 array[0].upperLimit = 35;
  
  array[1].lowerLimit = 0;
 array[1].upperLimit = 45;
  
  array[2].lowerLimit = 0;
 array[2].upperLimit = 40;
  
  return inferBreach(temperatureInC, array[coolingType].lowerLimit, array[coolingType].upperLimit);
//  return inferBreach(10, 0, 20);

}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
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



