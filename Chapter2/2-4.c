#include <stdio.h> 
void squeeze(char s1[], char s2[]);

int main (){
	char c;
	char s1[100], s2[100];
	int i, j;
	printf("Please type in a string: \n");
	i=0;
	while ((c = getchar()) != '\n' && i < 100){
		s1[i] = c;
		i++;
	}
	s1[i] = '\0';

	j=0;
	printf("Please type in another string: \n");
	while ((c = getchar()) != '\n' && j < 100){
		s2[j] = c;
		j++;
	}
	s2[j] = '\0';

	printf("Thank you. Squeezing now.\n");
	squeeze(s1, s2);
	printf("%s \n", s1);

	return 0;
}

void squeeze (char s1[], char s2[]) {
	int i, j, k, l;

	for (i = 0; s2[i] != '\0'; i++){
		for (j = 0; s1[j] != '\0'; j++){
			if (s2[i] == s1[j]){
				for (k = j + 1; s1[k] != '\0'; k++){
					s1[k-1] = s1[k];
				}
				s1[k-1] = '\0';
				j--;
			}
		}
	}
}