#include "verktyg.h"

double berakna(double a, double b, char operatortecken)
{
switch (operatortecken)
{
    case '+':
    return a + b;

    case '-':
    return a - b;

    case '*':
    return a * b;

    case '/':
    if ( b != 0)
    {
        return a / b;
    }
    return 0;

    default:
    return 0;
}
}
void byt_plats(double *a, double *b)
{
double temp = *a;
*a = *b;
*b = temp;
}