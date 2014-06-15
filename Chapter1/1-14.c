#include <stdio.h>
#define in 1
#define out 0
#define END '!'
int main (){
	int number[50];
	char a;
	int counter;
	int state;
	state = out;
	counter = 0;

	for (int k = 0; k < 50; k++){
		number[k] = 0;
	}

	while ((a = getchar()) != END){
		if (state == in){
			if (a == ' ' || a == '\n' || a == '\t'){
				state = out;
				number[counter]++;
				counter = 0;
			}
			else counter++;
		}
		if (state == out){
			if (a != ' ' && a != '\n' && a != '\t'){
				state = in;
				counter++;
			}
		}
	}

	int i = 0;
	while (i < 50){
		if (number[i] == 0){
			i++;
			continue;
		}
		printf("%d\t|",i);
		int j = 0;
		while(j < number[i]){
			printf("-");
			j++;
		}
		i++;
		putchar(10);
	}
	

	return 0;
}