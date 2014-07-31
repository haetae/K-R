#include <stdio.h>

void getLine(char *s, int size);
void strcat(char *s, char *t);

int main(){
	char line1[100], line2[100];
	printf("Enter a string.\n");
	getLine(line1, 100);

	printf("Enter another string.\n");
	getLine(line2, 100);

	strcat(line1, line2);
	printf("First string with second string is %s \n", line1);

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


void strcat(char *s, char *t){
    while (*s != '\0')
        s++;
    while ((*(s++) = *(t++)) != '\0'); 
}
