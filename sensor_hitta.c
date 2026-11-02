#include "verktyg.h"
#include <string.h>

int hitta_sensor(Sensormatning *reg, int antal, const char *namn)
{
    for (int i = 0; i < antal; i++)
    {
        if (strcmp(reg[i].namn, namn) == 0)
        {
            return i;
        }
    }
    return -1; // ger tillbaka -1 om sensorn inte finns
}