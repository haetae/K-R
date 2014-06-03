#include <stdio.h>

float tofah (float cel){
	float fah;
	fah = ((cel * 5)/9) + 32;
	cel = 20;
	return fah;
}

float tocel (float fah){
	float cel;
	cel = (((fah - 32) * 5)/9);
	fah = 20;

	return cel;
}

int main (){
	int i;
	i = 10;

 	printf("%d Celcius = %.3f Fahrenheit \n", 10, tofah(i));
 	printf("%d Fahrenheit = %.3f Celcius \n", 10, tocel(10));

	return 0;
}




