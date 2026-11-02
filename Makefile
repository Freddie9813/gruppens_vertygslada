CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17

KALLOR = main.c temperatur.c geometri.c multiplikation.c primtal.c \
	fizzbuzz.c kalkylator.c matlogg_lagg_till.c matlogg_ta_bort.c \
	matlogg_skriv.c matlogg_statistik.c matlogg_kopiera.c \
	matlogg_frigor.c sensor_lagg_till.c sensor_skriv.c \
	sensor_medelvarde.c sensor_hitta.c sensor_spara.c sensor_lasa.c

OBJEKT = $(KALLOR:.c=.o)

verktygslada: $(OBJEKT)
	$(CC) $(CFLAGS) $(OBJEKT) -o verktygslada

%.o: %.c verktyg.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJEKT) verktygslada verktygslada.exe
