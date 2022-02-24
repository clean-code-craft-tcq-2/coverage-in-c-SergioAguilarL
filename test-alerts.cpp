#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"


/*TC1 inferBreach  */
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12.0, 20.0, 30.0) == TOO_LOW);
  REQUIRE(inferBreach(35.0, 20.0, 30.0) == TOO_HIGH);
  REQUIRE(inferBreach(25.0, 20.0, 30.0) == NORMAL);
}

/*TC2 classifyTemperatureBreach */
TEST_CASE("classification of temperature breach") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,20.0)== NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,20.0)== NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,20.0)== NORMAL);
}

/*TC3 checkAndAlert*/
TEST_CASE("checking alert to den to controller")
{
    BatteryCharacter test_batteryChar;

    test_batteryChar.coolingType =HI_ACTIVE_COOLING;
    checkAndAlert(TO_CONTROLLER,test_batteryChar,50.0);
}

/*TC4 checkAndAlert*/
TEST_CASE("checking alert to den to EMAIL")
{
    BatteryCharacter test_batteryChar;

    test_batteryChar.coolingType =HI_ACTIVE_COOLING;
    checkAndAlert(TO_EMAIL,test_batteryChar,50.0);
}