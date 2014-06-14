#include <stdio.h>

int tonumber (char s[]);
unsigned int rightrot (unsigned int x, unsigned int n);

int main () {
	char buffer[100];
	char c;
	int i;
	unsigned int number, index, result;
	i = 0;
	printf("Please enter a number\n");
	while ((c = getchar()) != '\n' && i < 100){
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	number = tonumber(buffer);

	i = 0;
	printf("Please enter the number of bits you would like to shift to the right: \n");
	while ((c = getchar()) != '\n' && i < 100){
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	index = tonumber(buffer);

	result = rightrot(number, index);
	printf("The result is %d\n", result);


	return 0;
}

int tonumber (char s[]) {
	int result;
	result = 0;

	for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++){
		result = (10 * result) + s[i] - '0';
	}

	return result;
}

unsigned int rightrot(unsigned int x, unsigned int n){
	return x >> n;
}