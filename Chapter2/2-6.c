#include <stdio.h>

void getLine (char s[], int size);
int tonumber (char s[]);
int setbits (int x, int p, int n, int y);

int main (){
	int x, p, n, y;
	char buffer[100];
	int i, result;
	
	printf("Please input a number \n");
	getLine(buffer, 100);
	x = tonumber(buffer);

	printf("Please input another nunber \n");
	getLine(buffer, 100);
	y = tonumber(buffer);

	printf("Please enter the position where you want the bits to be set \n");
	getLine(buffer, 100);
	p = tonumber(buffer);

	printf("Please enter the number of bits you want to set \n");
	getLine(buffer, 100);
	n = tonumber(buffer);

	printf("Thank you. Setting bits now ...\n");

	result = setbits(x, p, n, y);
	printf("New number with set bits is %d.\n", result);


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