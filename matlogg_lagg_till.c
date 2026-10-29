#include <stdio.h>
#include <stdlib.h>

void lagg_till_matning(double **matlogg, int *antal)
{
    double nytt_varde;
    double *temp;

    printf("Ange matvarde: ");

    if (scanf("%lf", &nytt_varde) != 1) {
        printf("Felaktig inmatning.\n");
        return;
    }

    temp = realloc(*matlogg, (*antal + 1) * sizeof(double));

    if (temp == NULL) {
        printf("Minnesallokering misslyckades.\n");
        return;
    }

    *matlogg = temp;
    (*matlogg)[*antal] = nytt_varde;
    (*antal)++;
}