#include "Lotto.h"
#include <stdio.h>
#include <stdlib.h>

int ZiehungenEinlesen (char filename[], 
struct Ziehung z[], int * anz)
{
	FILE * fp;
	int i;
	int res;
	int tag;
	fp = fopen (filename, "r");
	if (fp == NULL)
	{	
		return 0;
	}

	*anz=0;
	while (!feof (fp))
	{
		res = fscanf (fp, "%d %d %d", &z[*anz].tag,
			&z[*anz].monat,
			&z[*anz].jahr);
		if (res > 0)
		{
			for (i=0; i< 6; i++)
			{
				fscanf (fp, "%d", &z[*anz].zahlen [i]);
			}
			fscanf (fp, "%d", &z[*anz].zz);
			(*anz)++;
		}

	}
	fclose (fp);
	return 1;
}


void Haufigkeit (struct Ziehung ziehungen[], int anz, int h[])
{
	int i,j;

	for (i=0; i<49; i++)
	{
		h[i] =0;
	}
	for (i=0; i<anz; i++)
	{
		for (j=0; j<6; j++)
		{
			h[ziehungen[i].zahlen [j]-1]++;
		}
	}
}


int Richtige (struct Ziehung z, int zahlen[6])
{
	int i,j;
	int richtige=0;
	
	for (i=0; i<6; i++)
	{
		for (j=0; j<6; j++)
		{
			if (z.zahlen [i] == zahlen[j])
				richtige++;
		}
	}
	return richtige;
}


void Ziehen (int zahlen[6])
{
	int i,j,found;

	for (i=0; i<6; i++)
	{
		do
		{
			zahlen [i] = rand() % 49 +1;
			found = 0;
			for (j=0; j<i; j++)
			{
				if (zahlen [i] == zahlen[j])
					found = 1;
			}
		} while (found);
	}

}

void LetztesVorkommen (struct Ziehung ziehungen[], int anz, 
					   int l[])
{
	int i,j;
	for (i=0; i<49; i++)
		l[i] = 0;
	for (i=0; i<anz; i++)
	{
		for (j=0; j<6; j++)
		{
			l[ziehungen[i].zahlen [j]-1] = i;
		}
	}
}