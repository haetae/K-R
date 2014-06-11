#include <stdio.h>
#include <limits.h>
#include <float.h>

int main () {
	int imax, imin;
	unsigned int uimax, uimin;
	char cmax, cmin;
	unsigned char ucmax, ucmin;
	short smax, smin;
	unsigned short usmax, usmin;
	long lmax, lmin;
	unsigned long ulmax, ulmin;
	

	imax = uimax = cmax = ucmax = smax = usmax = lmax = ulmax = 1;
	imin = cmin = smin = lmin = -1;

	while (imax * 2 > imax){
		imax = imax * 2;
	}
	printf("Maximum integer is %d\n", imax );

	while (imin * 2 < imin){
		imin = imin * 2;
	}
	printf("Minimum integer is %d\n", imin );

	while (uimax * 2 > uimax){
		uimax = uimax * 2;
	}
	printf("Maximum unsigned integer is %u\n", uimax );
	printf("Minimum unsigned integer is 0\n");

	char tempc;
	tempc = cmax;
	while (tempc >= cmax){
		cmax = tempc;
		tempc = tempc *2;
	}
	printf("Maximum character is %d\n", cmax);

	while (cmin * 2 < cmin){
		cmin = cmin * 2;
	}
	printf("Minimum character is %d\n", cmin);
	
	unsigned char tempuc;
	tempuc = ucmax;
	while (tempuc >= ucmax){
		ucmax = tempuc;
		tempuc = tempuc * 2;
	}
	printf("Maximum unsigned character is %u\n", ucmax);
	printf("Minimum unsigned character is 0\n");

	short temps;
	temps = smax;
	while (temps >= smax){
		smax = temps;
		temps = temps *2;
	}
	printf("Maximum short is %d\n", smax);

	while (smin * 2 < smin){
		smin = smin * 2;
	}
	printf("Minimum short is %d\n", smin);
	
	unsigned short tempus;
	tempus = usmax;
	while (tempus >= usmax){
		usmax = tempus;
		tempus = tempus * 2;
	}
	printf("Maximum unsigned short is %u\n", usmax);
	printf("Minimum unsigned short is 0\n");

	long templ;
	templ = lmax;
	while (templ >= lmax){
		lmax = templ;
		templ = templ *2;
	}
	printf("Maximum long is %ld\n", lmax);

	while (lmin * 2 < lmin){
		lmin = lmin * 2;
	}
	printf("Minimum long is %ld\n", lmin);
	
	unsigned long tempul;
	tempul = ulmax;
	while (tempul >= ulmax){
		ulmax = tempul;
		tempul = tempul * 2;
	}
	printf("Maximum unsigned long is %lu\n", ulmax);
	printf("Minimum unsigned long is 0\n");

	return 0;
}
