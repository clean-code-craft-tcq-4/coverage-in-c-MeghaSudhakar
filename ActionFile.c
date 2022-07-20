#include "ActionFile.h"
#include "typewise-alert.h"
#include <stdio.h>
#include <string.h>

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* breachbuffer[3] = {"Hi the temperature is NORMAL\n", "Hi the temperature is TOO_LOW\n", "Hi the temperature is TOO_HIGH\n"}; 
  printf("%s", breachbuffer[breachType]);  
  
}
