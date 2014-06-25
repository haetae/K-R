#include <stdio.h>
#include <string.h>

int getLine (char s[], int size);
int tonumber(char s[]);
void itob (int n, char s[], int b);

int main () {
	int n, b;
	char buffer[100];
	printf("Please enter a number: \n");
	getLine (buffer, 100);
	n = tonumber(buffer);

	printf("Please enter a base number: \n");
	getLine (buffer, 100);
	b = tonumber(buffer);

	itob(n, buffer, b);

	printf("Number %d changed to the base %d is %s \n", n, b, buffer);

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


int tonumber(char s[]){
	int result;
	result = 0;

	for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++){
		result = (10 * result) + s[i] - '0';
	}

	return result;
}

char digtochar (int n);
void reverse (char s[]); //copied from K&R textbook

void itob (int n, char s[], int b){
	int i;
	int digit;

	for (i = 0; n > 0; i++){
		digit = n % b;
		n /= b;
		s[i] = digtochar(digit);
	}

	s[i] = '\0';
	reverse(s);
}

char digtochar (int n){
	if (n > 9){
		return n - 10 + 'A';
	}

	return n + '0';
}

void reverse (char s[]){
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i <j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}