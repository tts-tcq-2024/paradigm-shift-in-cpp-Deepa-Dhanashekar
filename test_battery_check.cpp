#include "battery_check.h"
#include <cassert>
#include <iostream>

void testBatteryParameterRanges() {
  // Normal cases
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(0, 20, 0.0) == true);
  assert(batteryIsOk(45, 80, 0.8) == true);

  // Breach cases
  assert(batteryIsOk(-1, 70, 0.7) == false); // Temperature below min
  assert(batteryIsOk(25, 19, 0.7) == false); // SOC below min
  assert(batteryIsOk(25, 70, 0.9) == false); // Charge rate above max
  assert(batteryIsOk(50, 85, 0) == false); // Temperature and SOC above max

  // Warning cases
  assert(batteryIsOk(2, 70, 0.7) == true); // Temperature near min
  assert(batteryIsOk(25, 21, 0.7) == true); // SOC near min
  assert(batteryIsOk(25, 70, 0.78) == true); // Charge rate near max
  assert(batteryIsOk(44, 79, 0.7) == true); // Temperature and SOC near max
}

void testBatteryCheck() {
  // Test in English
  currentLanguage = ENGLISH;
  testBatteryParameterRanges();

  // Test in German
  currentLanguage = GERMAN;
  testBatteryParameterRanges();
}

int main() {
  testBattCheck();
  return 0;
}
