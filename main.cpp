#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "verktyg.h"
#include "sensorobjekt_klass.h"

static void skriv_meny(void)

{
    printf("\n=== Gruppens verktygslada ===\n");
    printf("1. Temperaturkonvertering (Celsius -> Fahrenheit)\n");
    printf("2. Rektangelns area\n");
    printf("3. Multiplikationstabell\n");
    printf("4. Kontrollera om ett tal ar ett primtal\n");
    printf("5. FizzBuzz for ett intervall\n");
    printf("6. Enkel rakning (+, -, *, /)\n");
    printf("7. Konvertera flera temperaturer (Celsius -> Fahrenheit)\n");
    printf("8. Storst rektangel i en lista\n");
    printf("9. Flera multiplikationstabeller\n");
    printf("10. Rakna primtal i en lista\n");
    printf("11. FizzBuzz-sammanfattning\n");
    printf("12. Byt plats pa tva tal\n");
    printf("13. Lagg till en matning i matloggen\n");
    printf("14. Ta bort senaste matningen\n");
    printf("15. Skriv ut matloggen\n");
    printf("16. Statistik for matloggen (min/max/medel)\n");
    printf("17. Kopiera matloggen\n");
    printf("18. Frigor matloggen\n");
    printf("19. Lagg till en sensormatning\n");
    printf("20. Skriv ut sensorregistret\n");
    printf("21. Medelvarde for sensorregistret\n");
    printf("22. Hitta en sensor via namn\n");
    printf("23. Spara sensorregistret till fil\n");
    printf("24. Las in sensorregistret fran fil\n");
    printf("25. Visa alla sensorer (sensorobjekt)\n");
    printf("26. Uppdatera en sensors varde\n");
    printf("27. Nollstall en sensors matningsrakning\n");
    printf("28. Kontrollera om en sensor ar inom en grans\n");
    printf("29. Byt namn pa en sensor\n");
    printf("30. Jamfor tva sensorer\n");
    printf("31. Hamta information om en sensor (gatters)\n");
    printf("32. Satt antal matningar direkt (testar validering)\n");
    printf("33. Kontrollera om en sensor ar giltig\n");
    printf("0. Avsluta\n");
    printf("Val: ");
}

int main(void)
{
    int val;
    double *matlogg = NULL;
    int matlogg_antal = 0;
    Sensormatning *sensorregister = NULL;
    int sensorregister_antal = 0;

    Sensor sensorer[3] = {
        Sensor("Temp-ute", 18.5),
        Sensor("Temp-inne", 21.0),
        Sensor("Luftfuktighet", 45.0)};

    std::cout << std::fixed << std::setprecision(2);
    setvbuf(stdout, NULL, _IONBF, 0);

    do
    {
        skriv_meny();
        std::cin >> val;

        switch (val)
        {
        case 1:
        {
            double celsius;
            std::cout << "Ange temperatur i Celsius: ";
            std::cin >> celsius;
            std::cout << celsius << " C = "
                      << celsius_till_fahrenheit(celsius) << " F\n";
            break;
        }
        case 2:
        {
            double bredd, hojd;
            std::cout << "Ange bredd och hojd: ";
            std::cin >> bredd >> hojd;
            std::cout << "Arean ar " << rektangelarea(bredd, hojd) << "\n";
            break;
        }
        case 3:
        {
            int tal;
            std::cout << "Ange ett tal: ";
            std::cin >> tal;
            skriv_multiplikationstabell(tal);
            break;
        }
        case 4:
        {
            int tal;
            std::cout << "Ange ett heltal: ";
            std::cin >> tal;
            if (ar_primtal(tal))
            {
                std::cout << tal << " ar ett primtal.\n";
            }
            else
            {
                std::cout << tal << " ar inte ett primtal.\n";
            }
            break;
        }
        case 5:
        {
            int fran, till;
            std::cout << "Ange start och slut (t.ex. 1 20): ";
            std::cin >> fran >> till;
            skriv_fizzbuzz(fran, till);
            break;
        }
        case 6:
        {
            double a, b;
            char operatortecken;

            std::cout << "Ange uttryck, t.ex. \"4 + 2\": ";
            std::cin >> a >> operatortecken >> b;

            std::cout << "Resultat: " << berakna(a, b, operatortecken) << "\n";

            break;
        }
        case 7:
        {
            double matningar[20];
            int antal;
            std::cout << "Hur manga matningar vill du mata in (max 20)? ";
            std::cin >> antal;
            for (int i = 0; i < antal; i++)
            {
                std::cout << "Matning " << (i + 1) << " (Celsius): ";
                std::cin >> matningar[i];
            }

            konvertera_serie(matningar, antal);

            std::cout << "I Fahrenheit: ";
            for (int i = 0; i < antal; i++)
            {
                std::cout << matningar[i] << " ";
            }
            std::cout << "\n";
            break;
        }
        case 8:
        {
            double bredder[20], hojder[20];
            int antal;
            double storsta_area;
            int index;

            std::cout << "Hur manga rektanglar vill du jamfora (max 20)? ";
            std::cin >> antal;
            for (int i = 0; i < antal; i++)
            {
                std::cout << "Rektangel " << (i + 1) << ", bredd och hojd ";
                std::cin >> bredder[i] >> hojder[i];
            }

            storst_rektangel(bredder, hojder, antal, storsta_area, index);

            std::cout << "Storst area ar " << storsta_area
                      << ",rektangel nummer " << (index + 1) << "\n";
            break;
        }
        case 9:
        {
            int tal[20];
            int antal;
            std::cout << "Hur manga tabeller vill du skriva ut (max antal 20)? ";
            std::cin >> antal;
            for (int i = 0; i < antal; i++)
            {
                std::cout << "Tal " << (i + 1) << ": ";
                std::cin >> tal[i];
            }
            skriv_flera_tabeller(tal, antal);
            break;
        }
        case 10:
        {
            int tal[20];
            int antal;
            std::cout << "Hur manga tal vill du kontrollera (max antal 20)? ";
            std::cin >> antal;
            for (int i = 0; i < antal; i++)
            {
                std::cout << "tal " << (i + 1) << ": ";
                std::cin >> tal[i];
            }
            std::cout << "Antal primtal: "
                      << raknar_primtal_i_array(tal, antal) << "\n";
            break;
        }
        case 11:
        {
            int fran, till;
            char sammanfattning[100];

            std::cout << "Ange start och slut (t.ex. 1 20): ";
            std::cin >> fran >> till;

            fizzbuzz_sammanfattning(fran, till, sammanfattning);
            std::cout << sammanfattning << "\n";
            break;
        }
        case 12:
        {
            double a, b;
            std::cout << "Ange tva tal, t.ex. \"3 7\": ";
            std::cin >> a >> b;

            std::cout << "Fore: a = " << a << ", b = " << b << "\n";

            byt_plats(a, b);

            std::cout << "Efter: a = " << a << ", b = " << b << "\n";
            break;
        }
        case 13:
        {
            double varde;
            printf("Ange matvarde att lagga till: ");
            std::cin >> varde;
            matlogg = lagg_till_matning(matlogg, &matlogg_antal, varde);
            printf("Matloggen innehaller nu %d matning(ar).\n", matlogg_antal);
            break;
        }
        case 14:
        {
            matlogg = ta_bort_senaste_matning(matlogg, &matlogg_antal);
            printf("Matloggen innehaller nu %d matning(ar).\n", matlogg_antal);
            break;
        }

        case 15:
            skriv_matlogg(matlogg, matlogg_antal);
            break;

        case 16: // menyvalet skriver bara ut minst värde och det är även fel värde-
        {
            double min, max, medel;
            berakna_loggstatistik(matlogg, matlogg_antal, &min, &max, &medel);
            printf("Min: %.2f, Max: %.2f, Medel: %.2f\n", min, max, medel);
            break;
        }

        case 17:
        {
            int kopia_antal = matlogg_antal;
            double *kopia = kopiera_matlogg(matlogg, matlogg_antal);
            printf("Kopierade %d matning(ar) till en ny logg:\n", kopia_antal);
            skriv_matlogg(kopia, kopia_antal);
            frigor_matlogg(kopia);
            printf("(Kopian ar nu frigjord igen, den var bara for testet.)\n");
            break;
        }
        case 18:
            frigor_matlogg(matlogg);
            matlogg = NULL;
            matlogg_antal = 0;
            printf("Matloggen ar frigjord.\n");
            break;
        case 19:
        {
            char namn[50];
            double varde;
            printf("Namn pa sensorn (utan mellanslag): ");
            std::cin >> std::setw(50) >> namn;
            printf("Matvarde: ");
            std::cin >> varde;
            sensorregister = lagg_till_sensormatning(sensorregister,
                                                     &sensorregister_antal,
                                                     namn, varde);
            printf("Sensorregistret innehaller nu %d post(er).\n",
                   sensorregister_antal);
            break;
        }
        case 20:
        {
            skriv_sensorregister(sensorregister, sensorregister_antal);
            break;
        }
        case 21:
        {
            printf("Medelvarde: %.2f\n",
                   medelvarde_sensorregister(sensorregister, sensorregister_antal));
            break;
        }
        case 22:
        {
            char namn[50];

            printf("Vilket namn vill du soka efter? ");
            std::cin >> std::setw(50) >> namn;

            int index = hitta_sensor(sensorregister, sensorregister_antal, namn);

            if (index == -1)
            {
                printf("Hittade ingen sensor med namnet \"%s\".\n", namn);
            }
            else
            {
                printf("Hittade \"%s\" på plats %d, varde %.2f\n",
                       namn, index, sensorregister[index].varde);
            }

            break;
        }

        case 23:
        {
            char filnamn[100];
            printf("Filnamn att spara till: ");
            std::cin >> std::setw(100) >> filnamn;
            spara_sensorregister(filnamn, sensorregister, sensorregister_antal);
            printf("Sensorregistret sparat till %s.\n", filnamn);
            break;
        }

        case 24:
        {
            char filnamn[100];
            printf("Filnamn att lasa fran: ");
            std::cin >> std::setw(100) >> filnamn;
            free(sensorregister);
            sensorregister = lasa_sensorregister(filnamn, &sensorregister_antal);
            printf("laste in %d post(er) fran %s.\n", sensorregister_antal, filnamn);
            break;
        }

        case 25:
            for (int i = 0; i < 3; i++)
            {
                std::cout << i << ": ";
                sensorer[i].skrivUt();
            }
            break;
        case 26:
        {
            int index;
            double nyttVarde;
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            std::cout << "Nytt varde: ";
            std::cin >> nyttVarde;
            sensorer[index].uppdateraVarde(nyttVarde);
            sensorer[index].skrivUt();
            break;
        }
        case 27:
        {
            int index;
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            sensorer[index].nollstallRakning();
            sensorer[index].skrivUt();
            break;
        }

        case 28:
        {
            int index;
            double min, max;
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            std::cout << "Undre och ovre grans: ";
            std::cin >> min >> max;
            if (sensorer[index].arInomGrans(min, max))
            {
                std::cout << "Ja, senaste vardet ligger inom gransen.\n";
            }
            else
            {
                std::cout << "Nej, senaste vardet ligger utanfor gransen.\n";
            }
            break;
        }

        case 29:
        {
            int index;
            char nyttNamn[50];
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            std::cout << "Nytt namn (utan mellanslag): ";
            std::cin >> std::setw(50) >> nyttNamn;
            if (sensorer[index].bytNamn(nyttNamn))
            {
                sensorer[index].skrivUt();
            }
            else
            {
                std::cout << "Ogiltigt namn -- namnet fick inte bytas.\n";
            }
            break;
        }

        case 30:
        {
            int index1, index2;

            std::cout << "Jamfor sensor (0-2) och sensor (0-2): ";
            std::cin >> index1 >> index2;

            if (sensorer[index1].harHogreVarde(sensorer[index2]))
            {
                std::cout << "Sensor " << index1
                          << " har ett hogre varde an sensor "
                          << index2 << ".\n";
            }
            else
            {
                std::cout << "Sensor " << index1
                          << " har inte ett hogre varde an sensor "
                          << index2 << ".\n";
            }
            break;
        }

        case 31:
        {
            int index;
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            std::cout << "Namn: " << sensorer[index].hamtaNamn() << "\n";
            std::cout << "Senaste varde: " << sensor[index].hamtaSenasteVarde() << "\n";
            std::cout << "Antal matningar: " << sensor[index].hamtaAntalMatningar() << "\n";
            break;
        }

        case 32:
        {
            int index, nyttAntal;
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            std::cout << "Nytt antal matningar: ";
            std::cin >> nyttAntal;
            if (sensorer[index].sattAntalMatningar(nyttAntal))
            {
                std::cout << "Antal matningar uppdaterat.\n";
            }
            else
            {
                std::cout << "Ogiltigt antal -- ett negativt antal accepteras inte.\n";
            }
            sensorer[index].skrivUt();
            break;
        }

        case 33:
        {
            int index;
            std::cout << "Vilken sensor (0-2)? ";
            std::cin >> index;
            if (sensorer[index].arGiltig())
            {
                std::cout << "Sensorn ar giltig.\n";
            }
            else
            {
                std::cout << "Sensorn ar INTE giltig.\n";
            }
            break;
        }
        case 0:
            if (matlogg != NULL)
            {
                frigor_matlogg(matlogg);
                matlogg = NULL;
                matlogg_antal = 0;
            }
            free(sensorregister);
            sensorregister = NULL;
            sensorregister_antal = 0;
            printf("Avslutar.\n");
            break;
        default:
            printf("Ogiltigt val, forsok igen.\n");
        }
    } while (val != 0);

    return 0;
}