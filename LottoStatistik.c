#include <stdio.h>
#include <stdlib.h>
#include "Lotto.h"


void main ()
{
	struct Ziehung z[6000];
	int anz;
	int h[49];
	int i;
	int zahlen [6];
	int richtige [7]={0};
	int Zuletzt[49];

	srand (time (NULL));

	if (ZiehungenEinlesen ("Lotto.txt", z, & anz))
	{

		Haufigkeit (z,  anz,  h);
		printf ("Anzahl Ziehungen: %d\n", anz);
		for (i=0; i<49; i++)
		{
			printf ("%3d %5d ", i+1, h[i]);
			if ((i+1) % 7 == 0)
				printf ("\n");
		}


		Ziehen (zahlen);
		for (i=0; i<7; i++)
			richtige [i] = 0;

		for (i=0; i<anz; i++)
		{
			richtige [Richtige (z[i], zahlen)]++;
		}

		printf ("\nAngekreuzte Zahlen:\n");
		for (i=0; i<6; i++)
			printf ("%d ",  zahlen[i]);
		printf ("\n");

		printf ("\nErgebnis:\n");
		for (i=0; i<7; i++)
			printf ("%d %d\n", i, richtige[i]);

   		LetztesVorkommen (z, anz, Zuletzt);
		for (i=0; i<49; i++)
		{
			printf ("%3d:%2d.%2d.%2d", i+1, z[Zuletzt[i]].tag,  z[Zuletzt[i]].monat,  z[Zuletzt[i]].jahr);
			if ((i+1) % 5 == 0)
				printf ("\n");
		}
	}
}