#include <stdio.h>

void getstring (char s[], int size);
int any (char s1[], char s2[]);

int main () {
	char c, d;
	char s1[100], s2[100];
	int size, result;
	size = 100;
	printf("Please type in a string: \n");
	getstring (s1, size);

	printf("Please type in another string: \n");
	getstring (s2, size);

	printf("First location of a character in the second string on the first string is : \n");
	result = any(s1, s2);
	printf("%d\n", result);

	return 0;
}

void getstring (char s[], int size){
	int i;
	char c;
	i = 0;
	while ((c = getchar()) != '\n' && i < size){
		s[i] = c;
		i++;
	}
	s[i] = '\0';

}

int any(char s1[], char s2[]){
	int counter;
	int i, j;
	for (i = 0; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0'; j++){
			if (s1[i] == s2[j]){
				return i;
			}
		}
	}	

	return -1;
}

