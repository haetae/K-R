#include <stdio.h>
void reverse (char s[]);
void reverseindex (char s[], int f, int l);
void getLine (char s[], int size);


int main () {
	int i;
	char buffer[100];
	printf("Please enter a string\n");
	getLine(buffer, 100);

	printf("Reversing now...\n");
	reverse(buffer);

	printf("Reversed string is %s \n", buffer);

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

void reverse (char s[]){
	int f, l;
	f = 0;

	for (l = 0; s[l] != '\0'; l++);
	l--;

	return reverseindex(s, f, l);
}

void reverseindex(char s[], int f, int l){
	char temp;

	if ((l - f) <= 0)
		return;

	else{
		temp = s[f];
		s[f] = s[l];
		s[l] = temp;

		return reverseindex(s, f+1, l-1);
	}
}