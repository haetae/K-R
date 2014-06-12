#include <stdio.h>

int htoi (char s[]) {
	int result;
	result = 0;
	int digit;
	digit = 0;
	int i = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		i = 2;
	}

	for (; s[i] != '\0'; i++){
		if (s[i] >= 'A' && s[i] <= 'F' ){
			digit = s[i] - 'A' + 10;
		}
		else if (s[i] >= 'a' && s[i] <= 'f'){
			digit = s[i] - 'a' + 10;
		}
		else if (s[i] >= '0' && s[i] <= '9'){
			digit = s[i] - '0';
		}

		else {
			printf("Wrong digit %c \n",s[i]);
			printf("Chainging digit to 0\n");
			digit = 0;
		}
		result = 16 * result + digit;
	}
	return result;
}

int getLine (char s[], int lim) {
	char c;
	int i;
	for (i = 0; (c = getchar ()) != '\n' && i < lim; i++){
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

int main () {
	char line[1000];
	while ( getLine (line, 1000) > 0){
		int result = htoi (line);
		printf("%d\n", result);
	}
	
}