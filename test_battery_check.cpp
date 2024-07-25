#include "battery_check.h"
#include <cassert>
#include <iostream>
 
void testBatteryCheck() {
  // Test in English
  currentLanguage = ENGLISH;
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
 
  // Test in German
  currentLanguage = GERMAN;
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  cout << "All tests passed!" << endl;
}
 
int main() {
  testBatteryCheck();
  return 0;
}
