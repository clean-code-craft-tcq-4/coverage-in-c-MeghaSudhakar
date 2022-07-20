#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(100, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("classifyTemperatureBreach") 
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 36) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 25) == NORMAL);
  
}

TEST_CASE("checkmail") 
{
  REQUIRE(checkmail(NORMAL) == NORMAL);
  REQUIRE(checkmail(TOO_LOW) == NORMAL);
  REQUIRE(checkmail(TOO_HIGH) == NORMAL);
  REQUIRE(checkmail(UNDEFINED_BREACHTYPE) == TOO_LOW);
}

TEST_CASE("sendToEmail") 
{
  REQUIRE(sendToEmail(NORMAL) == NORMAL);
  REQUIRE(sendToEmail(TOO_LOW) == NORMAL);
  REQUIRE(sendToEmail(TOO_HIGH) == NORMAL);
  REQUIRE(sendToEmail(UNDEFINED_BREACHTYPE) == 1);
}

TEST_CASE("sendToController") 
{
  REQUIRE(sendToController(NORMAL) == NORMAL);
  REQUIRE(sendToController(TOO_LOW) == NORMAL);
  REQUIRE(sendToController(TOO_HIGH) == NORMAL);
  REQUIRE(sendToController(UNDEFINED_BREACHTYPE) == 1);
}

TEST_CASE("func") 
{
  REQUIRE(func(TO_CONTROLLER,NORMAL) == NORMAL);
  REQUIRE(func(TO_EMAIL,NORMAL) == NORMAL); 
  REQUIRE(func(UNDEFINED_TARGET,NORMAL) == 1); 
}

TEST_CASE("checkAndAlert one") 
{
  BatteryCharacter SAMPLE;
  SAMPLE.coolingType = PASSIVE_COOLING;
    
  REQUIRE(checkAndAlert(TO_CONTROLLER,SAMPLE,45) == NORMAL);
 // REQUIRE(func(TO_EMAIL,NORMAL) == NORMAL);  
}

TEST_CASE("checkAndAlert two") 
{
  BatteryCharacter SAMPLE;
  SAMPLE.coolingType = HI_ACTIVE_COOLING;
    
  REQUIRE(checkAndAlert(TO_CONTROLLER,SAMPLE,45) == NORMAL);
//  REQUIRE(func(TO_EMAIL,NORMAL) == NORMAL);  
}

TEST_CASE("checkAndAlert three") 
{
  BatteryCharacter SAMPLE;
  SAMPLE.coolingType = MED_ACTIVE_COOLING;
    
  REQUIRE(checkAndAlert(TO_CONTROLLER,SAMPLE,45) == NORMAL);
 // REQUIRE(func(TO_EMAIL,NORMAL) == NORMAL);  
}

TEST_CASE("checkAndAlert four") 
{
  BatteryCharacter SAMPLE;
  SAMPLE.coolingType = UNDEFINED_COOLINGTYPE;
    
  REQUIRE(checkAndAlert(UNDEFINED_TARGET,SAMPLE,45) == NORMAL);
 // REQUIRE(func(UNDEFINED_TARGET,NORMAL) == 1);  
}
