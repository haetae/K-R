#include <stdio.h>
#define MAXLINE 1000 
#define END '!'
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int main() {
	int len;
	int max;
	int index;
	index = 0;
	max = 0;
	char line[MAXLINE];
	char longest[MAXLINE]; 

	while ((len = getLine(line, MAXLINE)) > 0){
		index ++;
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0){ 
		printf("The longest line is line %d with length %d \n", index, max);
		printf("The line is %s", longest);
	}
	return 0; 
}

int getLine(char s[],int lim) {
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!= END && c!='\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i; 
	}
	s[i] = '\0';
	return i; 
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}