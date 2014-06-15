#include <stdio.h>
#define END '!'

int main () {
	char c;
	char b;
	char line[1000];
	int index;
	index = 0;

	for (int i = 0; i < 1000 && (c=getchar()) != END ; i++){
		if ((b == ' ' || b == '\n') && (c == ' ' || c == '\n')){
			continue;
		}
	    line[index] = c;
	    b = c;
	    index++;
	}
	line[index] = '\0';

	printf("%s\n",line);

	return 0;
}







