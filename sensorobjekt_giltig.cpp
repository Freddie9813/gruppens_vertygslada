#include "sensorobjekt_klass.h"

bool Sensor::arGiltig() const
{
    if(namn[0] != '\0' && antalMatningar >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}