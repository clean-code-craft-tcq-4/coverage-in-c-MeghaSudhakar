#pragma once

typedef struct 
  {
    int lowerLimit;
    int upperLimit;
  } limit_struct_buffer;

typedef enum 
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  UNDEFINED_COOLINGTYPE
} CoolingType;

typedef enum 
{
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  UNDEFINED_BREACHTYPE
} BreachType;


typedef enum 
{
  TO_CONTROLLER,
  TO_EMAIL,
  UNDEFINED_TARGET
} AlertTarget;

typedef struct 
{
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
int checkmail(BreachType breachType);
int sendToController(BreachType breachType);
int sendToEmail(BreachType breachType);
int func(AlertTarget alertTarget, BreachType breachType);
