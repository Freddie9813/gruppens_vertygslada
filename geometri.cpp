#include "verktyg.h"

double rektangelarea(double bredd, double hojd)
{
    return bredd * hojd;
}

void storst_rektangel(double bredder[], double hojder[], int antal, double *storsta_area_ut, int *index_ut)
{
    double storsta_area = bredder[0] * hojder[0];
    int storsta_index = 0;

    for (int i = 1; i < antal; i++)
    {
        double area = bredder[i] * hojder[i];

        if (area > storsta_area)
        {
            storsta_area = area;
            storsta_index = i; 
        }
    }
    *storsta_area_ut = storsta_area; 
    *index_ut = storsta_index;
}