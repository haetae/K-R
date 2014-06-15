#include <stdio.h>
#define END '!'
int main () {
	char c;
	char line[1000];
	int index;
	int start;
	start = 0;
	index = 0;

	for (int i = 0; i < 1000 && (c=getchar()) != END ; i++){
	    line[index] = c;
	    index++;
	}
	line[index] = '\0';

	for (int i = 0; i < index; i++){
		if (line[i] == '\n'){
			for (int j = i-1; j >= start; j--){
				printf("%c",line[j]);
			}
			start = i+1;
			printf("\n");
		}
	}
	return 0;
}