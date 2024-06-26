#include <assert.h>
#include <iostream>
using namespace std;


bool checkInRange(float value, float min, float max, const char* message) {
  if (value < min || value > max) {
    cout << message << endl;
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

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
