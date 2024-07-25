#include "battery_check.h"
#include <iostream>

using namespace std;

Language currentLanguage = ENGLISH;

const ParameterRange temperatureRange = {0, 45, LOW_BREACH, HIGH_BREACH};
const ParameterRange socRange = {20, 80, LOW_BREACH, HIGH_BREACH};
const ParameterRange chargeRateRange = {0, 0.8, NORMAL, HIGH_BREACH};

const char* getErrorMessage(BreachType breachType) {
  static map<BreachType, map<Language, string>> errorMessages = {
    {LOW_BREACH, {
      {ENGLISH, "Value is below the minimum limit!"},
      {GERMAN, "Wert liegt unter dem Mindestwert!"}
    }},
    {HIGH_BREACH, {
      {ENGLISH, "Value is above the maximum limit!"},
      {GERMAN, "Wert liegt über dem Höchstwert!"}
    }},
    {LOW_WARNING, {
      {ENGLISH, "Value is approaching the minimum limit!"},
      {GERMAN, "Wert nähert sich dem Mindestwert!"}
    }},
    {HIGH_WARNING, {
      {ENGLISH, "Value is approaching the maximum limit!"},
      {GERMAN, "Wert nähert sich dem Höchstwert!"}
    }},
    {NORMAL, {
      {ENGLISH, "Value is within the normal range."},
      {GERMAN, "Wert liegt im normalen Bereich."}
    }}
  };
  return errorMessages[breachType][currentLanguage].c_str();
}
BreachType classifyRangeBreach(float value, const ParameterRange& range) {
  if (value < range.min) {
    return range.lowBreach;
  }
  if (value > range.max) {
    return range.highBreach;
  }
  
  // Define warning thresholds
  const float warningThreshold = 5.0;

  // Check for warnings
  if (value < range.min + warningThreshold) {
    return LOW_WARNING;
  }
  if (value > range.max - warningThreshold) {
    return HIGH_WARNING;
  }
  
  return NORMAL;
}

void printBreachMessage(BreachType breachType) {
  if (breachType != NORMAL) {
    cout << getErrorMessage(breachType) << endl;
  }
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  BreachType temperatureBreach = classifyRangeBreach(temperature, temperatureRange);
  BreachType socBreach = classifyRangeBreach(soc, socRange);
  BreachType chargeRateBreach = classifyRangeBreach(chargeRate, chargeRateRange);

  printBreachMessage(temperatureBreach);
  printBreachMessage(socBreach);
  printBreachMessage(chargeRateBreach);

  return temperatureBreach == NORMAL && socBreach == NORMAL && chargeRateBreach == NORMAL;
}
