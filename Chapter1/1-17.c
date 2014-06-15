#include <stdio.h>
#define MAXLINE 1000
#define END '!'
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int main() {
	int len;
	int max;
	max = 0;
	char line[MAXLINE];
	char longest[MAXLINE]; 

	while ((len = getLine(line, MAXLINE)) > 0){
		if (len > 80) {
			copy(longest, line);
			printf("%s\n", longest);
		}
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

void copy(char to[], char from[]){
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}