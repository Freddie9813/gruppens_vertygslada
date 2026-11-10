#include <stdio.h>
#include <stdlib.h>
#include "verktyg.h"

void berakna_loggstatistik(double *logg, int antal, double *min_ut, double *max_ut, double *medel_ut)
{
    if(antal == 0)
    {
        *min_ut = 0;
        *max_ut = 0;
        *medel_ut = 0;

        return;
    }

    *min_ut = logg[0];
    *max_ut = logg[0];

    double summa = logg[0];

    for (int i = 1; i < antal; i++)
    {
        if(logg[i] < *min_ut)
        {
            *min_ut = logg[i];
        }

        if(logg[i] > *max_ut)
        {
            *max_ut = logg[i];
        }

        summa += logg[i];
    }

    *medel_ut = summa / antal;
}