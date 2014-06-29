#include <stdio.h>
#include <ctype.h>

int getLine (char s[], int size);
double atof (char s[]);

int main () {
	double n;
	char buffer[100];
	printf("Please enter a number: \n");
	getLine (buffer, 100);
	n = atof(buffer);

	printf("The number is %f\n", atof(buffer));
	return 0;
}

int getLine (char s[], int size) {
	char c;
	int i;
	for (i = 0; (c = getchar ()) != '\n' && i < size; i++){
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

double atof (char s[]){
	int i, sign, esign, enumber;
	double result;
	esign = 1;
	enumber = 0;
	sign = 1;
	result = 0;
	i = 0;

	if (s[i] == '-'){
		sign = -1;
		i++;
	}
	for (; s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'); i++){
		result = result * 10 + (s[i] - '0');
	}

	if (s[i] == '.'){
		i++;

		double j = 0.1;
		for (; s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'); i++, j/= 10){
			result = result + ((s[i] - '0') * j);
		}
	}

	if (s[i] == 'e' || s[i] == 'E'){
		i++;

		if (s[i] == '-'){
			esign = -1;
			i++;
		}

		for (; s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'); i++){
			enumber = enumber * 10 + (s[i] - '0');
		}

		if (esign == 1){
			for (int j = 0; j < enumber; j++){
				result *= 10;
			}
		}

		if (esign == -1){
			for (int j = 0; j < enumber; j++){
				result *= 0.1;
			}
		}
	}

	return result * sign;
}