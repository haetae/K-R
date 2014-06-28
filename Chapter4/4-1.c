#include <stdio.h>
#define END '!'

int getLine (char s[], int lim);
int strindex (char s[], char t[]);// partly from K&R textbook

int main () {
	char buffer1[100], buffer2[100];
	int index;

	printf("Please enter a string: \n");
	getLine(buffer1, 100);

	printf("Please enter another string\n");
	getLine(buffer2, 100);

	printf("Thank you. Searching for the rightmost appearance of %s in %s now...\n",buffer2, buffer1 );

	index = strindex(buffer1, buffer2);
	printf("The rightmost appearance is at %d \n", index);

	return 0;
}

int getLine (char s[], int size) {
	char c;
	int i;
	for (i = 0; (c = getchar ()) != END && c != '\n' && i < size; i++){
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

int strindex (char s[], char t[]){
	int length, i, j, k;
	length = 0;
	while (s[length] != '\0'){
		length++;
	}

	for(i = length; i >= 0; i--){
		for(j = 0, k = i; t[j] != '\0' && s[k] == t[j]; j++, k++);
		if (t[j] == '\0'){
			return i;
		}
	}

	return -1;
}