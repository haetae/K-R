#include <stdio.h>

void getLine (char s[], int size);
int tonumber (char s[]);
int setbits (int x, int p, int n, int y);
unsigned int rightrot (unsigned int x, unsigned int n);

int main () {
	char buffer[100];
	char c;
	unsigned int x, n, result;

	printf("Please enter a number\n");
	getLine(buffer, 100);
	x = tonumber(buffer);

	printf("Please enter the number of bits you would like to shift to the right: \n");
	getLine(buffer, 100);
	n = tonumber(buffer);

	result = rightrot(x, n);
	printf("The result is %d\n", result);

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

int setbits (int x, int p, int n, int y){
	int i;
	int bit;
	for (i = 0; i < n; i++){
		bit = (y >> i) % 2;

		if (bit == 1){
			x = x | (1 << (p + i));
		}

		else{
			x = x & ~ (1 << (p + i));
		} 
	}

	return x;
}

unsigned int rightrot(unsigned int x, unsigned int n){
	int result, temp;
	n = n % 32;

	temp = x >> n;
	result = setbits(temp, 32 - n, n, x);

	return result;
}