#include <stdio.h>

void getLine (char s[], int size);
int tonumber (char s[]);
int invert (int x, int p, int n);

int main () {
	char buffer[100];
	int x, n, p;
	int result;

	printf("Please input a number.\n");
	getLine(buffer, 100);
	x = tonumber(buffer);

	printf("Please enter the number of bits you would like to invert. \n");
	getLine(buffer, 100);
	p = tonumber(buffer);

	printf("Please enter the number of the position where you would like to start inverting. \n");
	getLine(buffer, 100);
	n = tonumber(buffer);

	printf("Inverting %d bits starting from position %d on number %d ...\n", n, p, x);
	result = invert (x, n, p);

	printf("Inverted number is %d \n", result);

	return 0;
}

void getLine (char s[], int size){
	int i;
	char c;
	for (i = 0; (c = getchar()) != '\n' && i < size; i++){
		s[i] = c;
	}
	s[i] = '\0';
}

int tonumber(char s[]){
	int result;
	result = 0;

	for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++){
		result = (10 * result) + s[i] - '0';
	}

	return result;
}

int invert (int x, int p, int n) {
	int bit;

	for (int i = p; i < p + n; i++){
		bit = (x >> i) % 2;

		if (bit == 1){
			x = x & ~ (1 << i);
		}

		else {
			x = x | (1 << i);
		}

	}

	return x;
}