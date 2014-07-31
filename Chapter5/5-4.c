#include <stdio.h>

void getLine(char *s, int size);
int strend(char *s, char *t);
int strlen(char *s);

int main(){
	char line1[100], line2[100];
	int result;

	printf("Please enter a string:\n");
	getLine(line1, 100);

	printf("Please enter another string:\n");
	getLine(line2, 100);

	printf("Checking if %s is at the end of %s \n", line2, line1);
	result = strend(line1, line2);

	if (result == 0){
		printf("%s is not at the end of %s \n", line2, line1);
	}
	else printf("%s is at the end of %s \n", line2, line1);

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

int strend(char *s, char *t){
	int slen = strlen(s), tlen = strlen(t);

	if (slen <= tlen){
		return 0;
	}

	s += (slen - tlen);

	while(*s == *t){
		s++;
		t++;
		if (*t == '\0'){
			return 1;
		}
	}
	return 0;
}

int strlen(char *s){
	int length;
	for (length = 0; *s != '\0'; s++, length++);

	return length;
}