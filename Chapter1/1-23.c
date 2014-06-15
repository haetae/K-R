#include <stdio.h>
#define true 1
#define false 0
#define END '!'

int main () {
	char c,b;
	int incomment, instring;
	incomment = instring = false;
	b = getchar();
	while ((c = getchar()) != END ){
		if (incomment == true){
			if (b == '*' && c == '/'){
				incomment = false;
				b = getchar();

			}
			else b = c;
			continue;
		}

		if (b == '/' && c == '*' && instring == false){
			incomment = true;
			b = getchar();
			continue;
		}

		if (b == '"'){
			if (instring == false){
				instring = true;
			}
			else if (instring == true){
				instring = false;
			}
		}

		printf("%c", b);
		b = c;
	}
	return 0;
}