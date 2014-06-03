#include <stdio.h>
int main (){
	float fahr, celcius;

	#define lower 0
	#define upper 100
	#define step 20

	celcius = lower;
	printf("%10s\t%10s\n", "Celcius", "Fahrenheit");
	while (celcius <= upper){
		fahr = ((celcius * 5) / 9) + 32;
		printf("%10.0f\t%10.2f\n", celcius, fahr);
		celcius = celcius + step;

	}

	return 0;
}
