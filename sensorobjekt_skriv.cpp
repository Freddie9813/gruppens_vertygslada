#include <iostream>
#include "sensorobjekt_klass.h"

void Sensor::skrivUt() const
{
    std::cout << namn << ": " << senasteVarde
              << " (" << antalMatningar << " matning(ar) totalt)\n";
}