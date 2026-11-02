#ifndef VERKTYG_H
#define VERKTYG_H

typedef struct
{
    char namn[50];
    double varde;
} Sensormatning;
double celsius_till_fahrenheit(double celsius);
double rektangelarea(double bredd, double hojd);
void skriv_multiplikationstabell(int tal);
int ar_primtal(int tal);
void skriv_fizzbuzz(int fran, int till);
double berakna(double a, double b, char operatortecken);
void byt_plats(double *a, double *b);
void skriv_flera_tabeller(int tal[], int antal);
int raknar_primtal_i_array(int tal[], int antal);
void konvertera_serie(double *matningar, int antal);
void berakna_loggstatistik(double *logg, int antal, double *min_ut, double *max_ut, double *medel_ut);

void storst_rektangel(double bredder[], double hojder[], int antal,
                      double *storsta_area_ut, int *index_ut);

void fizzbuzz_sammanfattning(int fran, int till, char *sammanfattning);
double *ta_bort_senaste_matning(double *logg, int *antal);
double *lagg_till_matning(double *logg, int *antal, double varde);
void skriv_matlogg(double *logg, int antal);
double *kopiera_matlogg(double *logg, int antal);
void frigor_matlogg(double *logg);
Sensormatning *lagg_till_sensormatning(Sensormatning *reg, int *antal,
                                       const char *namn, double varde);
void skriv_sensorregister(Sensormatning *reg, int antal);
double medelvarde_sensorregister(Sensormatning *reg, int antal);
int hitta_sensor(Sensormatning *reg, int antal, const char *namn);
void spara_sensorregister(const char *filnamn, Sensormatning *reg, int antal);
Sensormatning *lasa_sensorregister(const char *filnamn, int *antal_ut);
#endif