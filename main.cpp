#include "battery_check.h"
#include <cassert>

int main() {
  currentLanguage = ENGLISH;
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  
  currentLanguage = GERMAN;
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);

  return 0;
}
