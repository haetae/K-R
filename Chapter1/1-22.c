//Exercise 1-22.
//Write a program to ``fold'' long input lines into two or more shorter lines after
//the last non-blank character that occurs before the n-th column of input. Make sure
//your program does something intelligent with very long lines, and if there are no
//blanks or tabs before the specified column.


#include <stdio.h>
#define	SPACE ' '
#define COLLENGTH 50 //length of column is 50 characters
//#define EOF '!'

int main () {
	char c;
	int counter;
	counter = 0;
	int wordlen; // counts the length of a word
	wordlen = 0;
	int i;
	char word[100];

	while ( (c = getchar()) != '!'){

		if (c == '\n'){
			word[wordlen] = '\0';
			if (counter < COLLENGTH){
				printf("%s\n", word);
				counter = 0;
			}

			if (counter > COLLENGTH){
				printf("\n%s ", word);
				counter = wordlen + 1;
			}
			wordlen = 0;
		}

		if (c == SPACE){
			word[wordlen] = '\0';
			if (counter < COLLENGTH){
				printf("%s ", word);
				wordlen = 0;
				counter++;
			}
			else if (counter > COLLENGTH){
				printf("\n%s ", word);
				wordlen = 0;
				counter = 0;
			}
		}

		else if (c != SPACE && c != '\n'){
			word[wordlen] = c;
			wordlen++;
			counter++;
		}
	}

	if ( wordlen > 0){
		word[wordlen] = '\0';
		printf("%s!\n", word);
	}

	return 0;
}
