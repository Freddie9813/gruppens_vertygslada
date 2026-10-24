#include "verktyg.h"

double celsius_till_fahrenheit(double celsius)
{
    return celsius * 9 / 5 + 32;
}

void konvertera_serie(double *matningar, int antal)
{
    for (int i = 0; i < antal; i++)
    {
        matningar[i] = celsius_till_fahrenheit(matningar[i]);
    }
}
