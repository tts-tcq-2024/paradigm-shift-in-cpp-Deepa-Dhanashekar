#include "battery_check.h"
#include <cassert>
 
void testBatteryCheck() {
  // Test in English
  assert(batteryIsOk(15, 50, 0.4) == true); //Normal
  assert(batteryIsOk(10, 30, 0.3) == true); //Normal
  assert(batteryIsOk(-5, 70, 0.7) == false); // Temperature far below min
  assert(batteryIsOk(25, 15, 0.7) == false); // SOC far below min
  assert(batteryIsOk(25, 70, 1.0) == false); // Charge rate far above max
  assert(batteryIsOk(50, 90, 1.0) == false); // Temperature, SOC, and Charge rate above max

}
 
int main() {
  testBatteryCheck();
  return 0;
}
