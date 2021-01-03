// Programm zur Berechnung der Zeitkonstante tau und der 3-dB-Grenzfrequenz fg aus der Anstiegszeit tr (en. rise time)
// Autor: Fabian Prestros
// Datum: 03.01.2021
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double einlesen(char koef[2])
{
	int chk = 0;
	double zahl = 0;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%s = ", koef);
		chk = scanf_s("%lf", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

int main()
{
	double tr = 0;
	double tau = 0;
	double fg = 0;

	printf("Bitte geben Sie die Anstiegszeit tr in Sekunden als Gleitkommazahl in Exponentialschreibweise ein!\n");
	tr = einlesen("tr");

	tau = tr / log(9);
	fg = 1 / (2 * PI * tau);

	printf("tau =  %e s\n", tau);
	printf("fg =  %e Hz\n", fg);
}