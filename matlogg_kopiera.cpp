#include <stdlib.h>
#include "verktyg.h"

double *kopiera_matlogg(double *logg, int antal)
{
    if (antal <= 0 || logg == NULL)
    {
        return NULL;
    }

    double *kopia = malloc(antal * sizeof(double));
    if (kopia == NULL)
    {
        return NULL; // detta är om allokering misslyckas !
    }

    for (int i = 0; i < antal; i++)
    {
        kopia[i] = logg[i];
    }

    return kopia;
}