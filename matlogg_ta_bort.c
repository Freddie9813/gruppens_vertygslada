#include <stdio.h>
#include <stdlib.h>

double *ta_bort_senaste_matning(double *logg, int *antal)
{
    if (logg == NULL)
    {
        return logg;
    }

    else if (*antal == 1)
    {
        free(logg);
        *antal = 0;
        return NULL;
    }
    double *ny_logg = realloc(logg, (*antal - 1) * sizeof(double));

    if (ny_logg == NULL)
    {
        return logg;
    }
    
    *antal = *antal -1;
    return ny_logg;
}