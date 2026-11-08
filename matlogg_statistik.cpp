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

    for(int i = 0; i < antal; i++)
    {
        if(logg[i] < logg[i + 1])
        {
            *min_ut = logg[i];
        }
    }
}