#include <stdio.h>
#define END '!'

void escape (char s[], char t[]);

int main () {
	char s[100], t[100];
	char c;
	int i;
	i = 0;

	printf("Please input a string\n");

	while ((c = getchar()) != END && i < 100){
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	printf("Escaping now ...\n");
	escape (s, t);
	printf("New escaped string is %s\n", t);

	return 0;
}

void escape (char s[], char t[]){
	int i, j;
	char c;
	i = 0;
	j = i;
	while (s[i] != '\0'){
		switch (s[i]){
			case '\n': 
				t[j] = '\\';
				t[j+1] = 'n';
				j += 2;
				i++;
				break;

			case '\t':
				t[j] = '\\';
				t[j+1] = 't';
				j+= 2;
				i++;
				break;

			default: t[j] = s[i];
				j++;
				i++;
				break;
		}
		
	}
}
