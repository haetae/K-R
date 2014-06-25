#include <stdio.h>
#define END '!'

void expand (char s1[], char s2[]);

int main () {
	char s1[100], s2[100];
	char c;
	int i;
	i = 0;

	printf("Please input a string\n");
	while ((c = getchar()) != END && i < 100){
		s1[i] = c;
		i++;
	}
	s1[i] = '\0';

	printf("Expanding now...\n");
	expand(s1, s2);
	printf("New expanded string is: %s \n", s2);

	return 0;
}

void expand (char s1[], char s2[]){
	int i = 0;
	int j;
	char a, b, c;

	i = j; 

	while (s1[i] != '\0'){
		a = s1[i];
		b = s1[i + 1];
		c = s1[i + 2];

		if (a >= 'a' && c <= 'z' && a < c && b == '-'){
			s2[j] = s1[i];
			a++;
			j++;
			while (a < c){
				s2[j] = a;
				j++;
				a++;
			}
			i += 2;
			continue;
		}
		if (a >= 'A' && c <= 'Z' && a < c && b == '-'){
			s2[j] = s1[i];
			a++;
			j++;
			while (a < c){
				s2[j] = a;
				j++;
				a++;
			}
			i += 2;
			continue;
		}
		if (a >= '0' && c <= '9' && a < c && b == '-'){
			s2[j] = s1[i];
			a++;
			j++;
			while (a < c){
				s2[j] = a;
				j++;
				a++;
			}
			i += 2;
			continue;
		}

		s2[j] = s1[i];
		j++;
		i++;
	}

	s2[j] = '\0';
}