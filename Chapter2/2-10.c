#include <stdio.h>

void lower (char s[]);

int main (){
	char s[100];
	char c;
	int i;
	printf("Please enter a string\n");
	i = 0;
	while ((c = getchar()) != '\n'&& i < 100){
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	printf("Shifting everything to lower case: \n");
	lower(s);
	printf("%s\n", s);
	return 0;
}

void lower (char s[]){
	for (int i = 0; s[i] != '\0'; i++){
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] + ('a' - 'A')) : s[i]; 
	} 
}