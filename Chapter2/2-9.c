#include <stdio.h>
void getLine (char s[], int size);
int tonumber (char s[]);
int bitcount (int x);

int main (){
	int x, result;
	char buffer[100];
	
	printf("Please input a number \n");
	getLine(buffer, 100);
	x = tonumber(buffer);

	printf("Counting number of bits set to one in %d ... \n", x);

	result = bitcount(x);
	printf("There are %d bits set to one in %d \n", result, x);

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

int bitcount (int x) {
	int count;
	count = 0;

	while (x != 0){
		x &= (x-1);
		count++;
	}

	return count;
}