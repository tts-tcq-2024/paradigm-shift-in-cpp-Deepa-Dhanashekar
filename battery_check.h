#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include <map>
#include <string>

enum Language { ENGLISH, GERMAN };

extern Language currentLanguage;

enum BreachType {
  NORMAL,
  LOW_BREACH,
  HIGH_BREACH,
  LOW_WARNING,
  HIGH_WARNING
};

struct ParameterRange {
  float min;
  float max;
  BreachType lowBreach;
  BreachType highBreach;
};

extern const ParameterRange temperatureRange;
extern const ParameterRange socRange;
extern const ParameterRange chargeRateRange;

const char* getErrorMessage(BreachType breachType);
BreachType classifyRangeBreach(float value, const ParameterRange& range);
bool batteryIsOk(float temperature, float soc, float chargeRate);
void printBreachMessage(BreachType breachType);

#endif // BATTERY_CHECK_H
