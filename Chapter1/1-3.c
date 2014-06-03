#include <stdio.h>
int main (){
	float fahr, celcius;

	#define lower 0
	#define upper 100
	#define step 20

	fahr = lower;
	printf("%10s\t%10s\n", "Fahrenheit", "Celcius");
	while (fahr <= upper){
		celcius = 5 * (fahr - 32) / 9;
		printf("%10.0f\t%10.2f\n", fahr, celcius);
		fahr = fahr + step;

	}

	return 0;
}
