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
}

TEST_CASE("sendToEmail") 
{
  REQUIRE(sendToEmail(NORMAL) == NORMAL);
  REQUIRE(sendToEmail(TOO_LOW) == NORMAL);
  REQUIRE(sendToEmail(TOO_HIGH) == NORMAL);
}

TEST_CASE("sendToController") 
{
  REQUIRE(sendToController(NORMAL) == NORMAL);
  REQUIRE(sendToController(TOO_LOW) == NORMAL);
  REQUIRE(sendToController(TOO_HIGH) == NORMAL);
}

/*TEST_CASE("checkAndAlert") 
{
  REQUIRE(checkAndAlert(TO_CONTROLLER,0,25) == NORMAL);
}*/
