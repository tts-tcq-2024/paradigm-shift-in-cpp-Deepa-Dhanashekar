#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H
 
#include <map>
#include <string>
 
enum Language { ENGLISH, GERMAN };
 
extern Language currentLanguage;
 
const char* getErrorMessage(const char* errorKey);
bool checkInRange(float value, float min, float max, const char* errorKey);
bool batteryIsOk(float temperature, float soc, float chargeRate);
 
#endif // BATTERY_CHECK_H
