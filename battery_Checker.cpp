#include "battery_check.h"
#include <iostream>
 
using namespace std;
 
Language currentLanguage = ENGLISH;
 
const char* getErrorMessage(const char* errorKey) {
  static map<string, map<Language, string>> errorMessages = {
    {"Temperature out of range!", {
      {ENGLISH, "Temperature out of range!"},
      {GERMAN, "Temperatur außerhalb des zulässigen Bereichs!"}
    }},
    {"State of Charge out of range!", {
      {ENGLISH, "State of Charge out of range!"},
      {GERMAN, "Ladezustand außerhalb des zulässigen Bereichs!"}
    }},
    {"Charge Rate out of range!", {
      {ENGLISH, "Charge Rate out of range!"},
      {GERMAN, "Laderate außerhalb des zulässigen Bereichs!"}
    }}
  };
  return errorMessages[errorKey][currentLanguage].c_str();
}
 
bool checkInRange(float value, float min, float max, const char* errorKey) {
  if (value < min || value > max) { 
    cout << getErrorMessage(errorKey); // Print error message based on current language
    return false;
  }
  return true;
}
 
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool temperatureIsOk = checkInRange(temperature, 0, 45, "Temperature out of range!");
  bool socIsOk = checkInRange(soc, 20, 80, "State of Charge out of range!");
  bool chargeRateIsOk = checkInRange(chargeRate, 0, 0.8, "Charge Rate out of range!");
  return temperatureIsOk && socIsOk && chargeRateIsOk; 
}
