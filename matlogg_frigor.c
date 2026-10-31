#include <stdlib.h>
#include "verktyg.h"

void frigor_matlogg(double *logg)
{
    if (logg != NULL)
    {
        free(logg);
    }
}