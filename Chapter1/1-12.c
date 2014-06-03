#include <stdio.h>
#define IN 1
#define OUT 0
#define EOF '!'

int main (){
	int c, state;
	state = 0;

	while ((c = getchar ()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			putchar('\n');

		}
		else if (state == OUT) {
			state = IN;
		}

		if (state == IN) putchar(c);
		
	}

	return 0;
}