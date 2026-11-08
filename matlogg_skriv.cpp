#include <stdio.h>
#include "verktyg.h"

void skriv_matlogg(double *logg, int antal)
{
    if (antal == 0 || logg == NULL)
    {
        printf("Matloggen är tom.\n");
    }
    else
    {
        for (int i = 0; i < antal; i++)
        {
            printf("%lf\n", logg[i]);
        }
    }
}