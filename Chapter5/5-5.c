#include <stdio.h>
strncpy, strncat, and strncmp

void getLine(char *s, int size);
void strncat(char *s, char *t, int n);
void strncpy(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

int main(){
	char line1[100], line2[100];
	printf("Enter a string.\n");
	getLine(line1, 100);

	printf("Enter another string.\n");
	getLine(line2, 100);

	if (strncmp(s, t, 100) == 0){
		printf("The two strings are not equal.\n");
	}

	else printf("The two strings are equal.\n");

	strncpy(s, t, 10);

	printf("first 10 letters cop");

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

void strncat(char *s, char *t, int n){
    while (*s != '\0')
        s++;

    int i = 0;
    while (i++ < n){
    	*(s++) = *(t++);
    }
    *s = '\0';
}

void strncpy(char *s, char *t, int n){
	int i = 0;

	while (*t != '\0' && i++ < n){
		*(s++) = *(t++);
	}

	while (i++ < n){
		*(s++) = '\0';
	}
}

int strncmp(char *s, char *t, int n){
	int i = 0;

	while (*s != '\0' && (i++) < n){
		if (*(s++) != *(t++)){
			if (*s > *t){
				return 1;
			}

			else return -1;
		}
	}

	return 0;
}