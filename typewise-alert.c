#include "typewise-alert.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <stdio.h>

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

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
 // int result =0;
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget) 
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      REQUIRE(ControllerCount == 1);
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
  
 ControllerCount++;
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
  if(breachType == 'TOO_LOW' || breachType == 'TOO_HIGH' )
  {
    checkmail(breachType);
  }
  else
  {
    printf("Hi, the temperature is too NORMAL\n");
  }
  
}



