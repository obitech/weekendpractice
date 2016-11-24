/*
punkte.c - Schreiben Sie ein Programm, das die Koordinaten von 10 Punkten in der Ebe- ne(siehe Aufgabe 6.1) einliest und in einem Feld speichert Anschließend sollen die Punkte bestimmt werden, die dem Ursprung am nächsten liegen bzw. am weitesten entfernt liegen (wenn dabei mehrere Punkte gleich weit entfernt sind, soll einer davon angegeben werden).
*/

#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} point_t;

double abstand(point_t p1, point_t p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {	
	int i;
	float max_ab, min_ab;
	point_t ebene[5];
	point_t nullp = {0, 0};
	point_t max_p, min_p;

	// Punkte einlesen
	for (i = 0; i < 3; i++) {
		printf("P%d: ", (i + 1));
		scanf("%d %d", &ebene[i].x, &ebene[i].y);
	}

	// Punkte ausgeben
	for (i = 0; i < 3; i++) {
		printf("P%d = %d.%d\n", (i + 1), ebene[i].x, ebene[i].y);
	}	

	// Max & min Abstände gleich dem des ersten Punktes setzen
	max_ab = abstand(nullp, ebene[0]);
	min_ab = abstand(nullp, ebene[0]);

	// Punkt mit größten und kleinsten Abstand = erster Punkt in Ebene
	min_p = ebene[0];
	max_p = ebene[0];

	// Vergleiche Abstände mit Nullpunkte
	for(i = 0; i < 3; i++) {
		if (abstand(nullp, ebene[i]) >= max_ab) {			
			max_ab = abstand(nullp, ebene[i]);			
			max_p = ebene[i];
			imax = i + 1;			
		}

		else if (abstand(nullp, ebene[i]) <= min_ab) {			
			min_ab = abstand(nullp, ebene[i]);
			min_p = ebene[i];
			imin = i + 1;			
		}
	}

	printf("P (%d.%d) hat den größten Abstand mit %f\n", max_p.x, max_p.y, max_ab);
	printf("P (%d.%d) hat den kleinsten Abstand mit %f\n", min_p.x, min_p.y, min_ab);

	return 0;
}