#include <stdio.h>
void getLine (char s[], int size);
int tonumber (char s[]);
void tostring (int number, char[]);

int main(){
	int i;
	char buffer[100];
	printf("Please enter an integer\n");
	getLine(buffer, 100);
	i = tonumber (buffer);

	buffer[0] = '\0';
	tostring(i, buffer);

	printf("The number is %s \n", buffer);

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

void tostring (int number, char s[]){
	int i;
	char x = s[0];

	if (number > 0){
		for (i = 0; s[i] != '\0'; i++){
			char temp = s[i];
			s[i] = x;
			x = temp;
		}

		s[i] = x;
		s[i + 1] = '\0';
		s[0] = (number % 10) + '0'; //shited everything in array by 1
		number = number / 10;

		return tostring(number, s);
	}

	else return;
	
}