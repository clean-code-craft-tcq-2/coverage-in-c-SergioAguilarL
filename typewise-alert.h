#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
    TOO_LOW,
    TOO_HIGH,
    NORMAL
  
} BreachType;

BreachType inferBreach(float value, float lowerLimit, float upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, float temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, float temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
