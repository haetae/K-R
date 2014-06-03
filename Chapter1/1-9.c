#include <stdio.h>
#define EOF '!'

 int main()
 {
	 char temp;
	 while ((temp = getchar()) != EOF){
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