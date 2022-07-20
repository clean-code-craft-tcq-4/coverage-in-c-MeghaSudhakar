#include "typewise-alert.h"
#include <stdio.h>
#include <string.h>
#include "inferBreach.h"
#include "def.h"

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

void checkmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  
  printf("To: %s\n", recepient);
  
  const char* breachbuffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  
  printf("%s", breachbuffer[breachType]); 
  
}


void sendToEmail(BreachType breachType) 
{
  const char* buffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  printf("%s", buffer[breachType]);  
  
}


void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

