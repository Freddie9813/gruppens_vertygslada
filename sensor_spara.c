#include "verktyg.h"
#include <stdio.h>

void spara_sensorregister(const char *filnamn, Sensormatning *reg, int antal)
{
    FILE *fil = fopen(filnamn, "w");
    if (fil == NULL)
    {
        printf("Kunde inte öppna filen %s för skrivning.\n", filnamn);
        return;
    }

    for (int i = 0; i < antal; i++)
    {
        fprintf(fil, "%s %.2lf\n", reg[i].namn, reg[i].varde);
    }
    fclose(fil);
}