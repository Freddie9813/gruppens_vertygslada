#include <iostream>
#include "rorelsesensor_klass.h"

void MotionSensor::skrivUt() const {
    std::cout << "[" << hamtaTyp() << "] ";
    Sensor::skrivUt();
    std::cout << " Rorelse detekterad: "
              << (harRorelseDetekterats() ? "ja" : "nej") << "\n";
}