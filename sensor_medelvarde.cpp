#include "verktyg.h"

double medelvarde_sensorregister(Sensormatning *reg, int antal)
{
    double summa = 0.0;

    if (antal == 0)
    {
        return 0;
    }
    
    for(int i = 0; i < antal; i++)
    {
        summa += reg[i].varde;
    }
    return summa /antal;
}