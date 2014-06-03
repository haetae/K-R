#include <stdio.h>
#define	SPACE ' '
#define	TAB	'\t'
#define EOF '!'

int main (){
	char t;
	int counter;
	int i;
	int nt;

	counter = 0;
	while ((t = getchar()) != EOF){
		if (t == '\n'){
			counter = 0;
			printf("\n");
		}

		else if (t == TAB){
			i = counter/4;
			nt = ( 4 * (i + 1) ) + 1;
			int a;
			a = 0;
			while (a < (nt - counter)){
				printf("%c",SPACE);
				a++;
			}
		}
		else {
			printf("%c",t);
			counter++;
		}
		
	}

	

	return 0;
}