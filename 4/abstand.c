/*
abstand.c - Entwerfen Sie eine Datenstruktur, 
die die Koordinaten eines Punktes in der Ebene speichern kann. 
Schreiben Sie ein Programm, das die Koordinaten zweiter Punkte 
einliest und deren Abstand berechnet.
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
	point_t pt1, pt2;

	printf("Punkt 1 in Form x y: ");
	scanf("%d %d", &pt1.x, &pt1.y);

	printf("Punkt 2 in Form x.y: ");
	scanf("%d %d", &pt2.x, &pt2.y);

	printf("Abstand: %f\n", abstand(pt1, pt2));


	return 0;
}