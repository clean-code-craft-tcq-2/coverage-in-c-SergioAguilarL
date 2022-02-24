#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(float value, float lowerLimit, float upperLimit) {

  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
CoolingType coolingType, float temperatureInC) {
    float coolingTypeUpperlimit [3] = {35.0,45.0,40.0};
    float lowerLimit = 0.0;
    float upperLimit = coolingTypeUpperlimit[coolingType];
    return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, float temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {

    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {

  const char* recepient = "a.b@c.com";
  const char* temperatueStatus[] = {"low", "high"};
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too");
    printf("%s",temperatueStatus[breachType]);

}
