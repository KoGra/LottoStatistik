struct Ziehung
{
	int tag;
	int monat;
	int jahr;
	int zahlen[6];
	int zz;
};

int ZiehungenEinlesen (char filename[], 
struct Ziehung ziehungen[], int * anz);

void Haufigkeit (struct Ziehung ziehungen[], int anz, int h[]);

int Richtige (struct Ziehung z, int zahlen[6]);

void Ziehen (int zahlen[6]);

void LetztesVorkommen (struct Ziehung ziehungen[], 
					   int anz, int l[]);