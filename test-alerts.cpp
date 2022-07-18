#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "Check_and_Alert.h"
#include "Classify_Breach_Check.h"
#include "How_to_alert.h"

TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 35) == TOO_HIGH);
}
