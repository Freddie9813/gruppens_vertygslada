#include "sensorobjekt_klass.h"

bool Sensor::harHogreVarde(const Sensor &annan) const
{
    if(senasteVarde > annan.senasteVarde)
    {
        return true;
    }
    else
    {
        return false;
    }
}