#include <stdio.h>
int main (){
	float fahr, celcius;

	#define lower 0
	#define upper 300
	#define step 20

	printf("%10s\t%10s\n", "Fahrenheit", "Celcius");
	for (fahr = upper; fahr >= lower; fahr -= step){
		celcius = 5 * (fahr - 32) / 9;
		printf("%10.0f\t%10.2f\n", fahr, celcius);
	}

	return 0;
}
