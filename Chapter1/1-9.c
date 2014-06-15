#include <stdio.h>
#define END '!'

 int main()
 {
	 char temp;
	 while ((temp = getchar()) != END){
	 	if (temp != ' '){
	 		putchar(temp);
	 		continue;
	 	}

	 	while ((temp = getchar()) == ' ');

	 	putchar(' ');
	 	putchar(temp);
	 	continue;
	 }

	return 0;
}