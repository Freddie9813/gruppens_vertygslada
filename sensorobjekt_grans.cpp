#include "sensorobjekt_klass.h"

bool Sensor::arInomGrans(double min, double max) const
{
    if(senasteVarde < min || senasteVarde > max)
    {
        return false;
    }
    else
    {
        return true;
    }
}