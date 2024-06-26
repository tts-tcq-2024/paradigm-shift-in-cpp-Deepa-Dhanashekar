#include <assert.h>
#include <iostream>
using namespace std;

// A pure function which checks if input is out of range and prints error message
bool checkInRange(float value, float min, float max, const char* error) {
  if (value < min || value > max) { 
    cout << error ;//print error message
    return false;
  }
  return true;
}

//conditional statements are removed and replaced by a functional call to a pure function to reduce CCN and to follow paradigm
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
