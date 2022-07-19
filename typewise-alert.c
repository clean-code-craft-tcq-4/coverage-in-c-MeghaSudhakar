#include "typewise-alert.h"


#include <stdio.h>
struct
  {
    LowerLimit;
    UpperLimit;
  } limit;
int ControllerCount =0;

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
 // int lowerLimit = 0;
 // int upperLimit = 0;
  
  
  
  limit coolinglimit[3] = {{0,35}, {0,45}, {0,40}};
  
  
  
  
  return inferBreach(temperatureInC, coolinglimit[coolingType].LowerLimit, coolinglimit[coolingType].UpperLimit);
  
  /*switch(coolingType) 
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
  }*/
 // return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
 // int result =0;
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      {
      sendToController(breachType);
     // REQUIRE(ControllerCount == 1);
      break;
      }
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}


void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  
 //ControllerCount++;
}



void checkmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  switch(breachType) 
  {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    
  }
}

void sendToEmail(BreachType breachType) 
{
  
  const char* buffer[3] = {"Hi, the temperature is NORMAL\n", "Hi, the temperature is TOO_LOW\n", "Hi, the temperature is TOO_HIGH\n"};
  
  printf (" %s", buffer[breachType]);
  
 /* if(breachType == 'TOO_LOW' || breachType == 'TOO_HIGH' )
  {
    checkmail(breachType);
  }
  else
  {
    printf("Hi, the temperature is NORMAL\n");
  }*/
  
}



