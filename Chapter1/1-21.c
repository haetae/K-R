#include <stdio.h>
#define	SPACE ' '
#define	TAB	'\t'
#define TABSTOP 8
#define END '!'

int main (){
	char t;
	int counter; // counts characters
	int spacecount; // counts spaces
	int i;
	int nt; // number of tabs
	int ns; // number of spaces

	counter = 0;
	spacecount = 0;
	while ((t = getchar()) != END){

		if (t == '\n'){
			counter = 0;
			spacecount = 0;
			printf("\n");
			
		}

		else if (t == SPACE){
			spacecount++;
			
		}

		else if (t != SPACE && (spacecount != 0 || spacecount != 1)){ // case for spacecount != 1 bc spacecounter will go up even if there is one space
			nt = (counter + spacecount) / TABSTOP;
			ns = (counter + spacecount) % TABSTOP;
			for (i=0; i < nt; i++){
				printf("\t");
			}
			for (i=0; i < ns; i++){
				printf(" ");
			}
			printf("%c",t);
			spacecount = 0;
			
		}

		else {
			printf("%c",t);
			counter++;
			spacecount = 0;
		}
		
	}

	

	return 0;
}