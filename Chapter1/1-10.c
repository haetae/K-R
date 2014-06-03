#include <stdio.h>
#define EOF '!'

 int main()
 {
	 char temp;
	 while ((temp = getchar()) != EOF){
	 	if (temp != '\t' && temp != '\b' && temp != '\\'){
	 		putchar(temp);
	 		continue;
	 	}

	 	if (temp  == '\t'){
		 	putchar('\\');
		 	putchar('t');
		 	continue;
	 	}

	 	if (temp == '\b'){
	 		putchar('\\');
	 		putchar('b');
	 		continue;
	 	}


	 	if (temp == '\\'){
		 	putchar('\\');
		 	continue;	
	 	}
	 	


	 }

	return 0;
}