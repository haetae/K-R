// Mostly taken from K&R textbook. Added a few lines to fulfill the task.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>  
#define END '!'
#define MAXOP 100  
#define MAXVAL 100 
#define BUFSIZE 100
#define NUMBER  '0'  
int getop(char []);
void push(double);
double pop(void);

int main(){
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != END) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;

		case '+':
			push(pop() + pop());
			break;

		case '*':
			push(pop() * pop());
			break;

		case '-':
			op2 = pop();
			push(pop() - op2);
			break;

		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;

		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)(pop()) % (int)(op2));
			else
				printf("error:remainder by zero is undefined\n");
			break;

		case '\n':
			printf("\t%.8g\n", pop());
			break;

		default:
			printf("error: unknown command %s\n", s);
			break; 
		}
	}
	return 0; 
}

int sp = 0;
double val[MAXVAL];  

void push(double f){
	if (sp < MAXVAL){
		val[sp++] = f;
	}
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if (sp > 0){
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);
int getop(char s[]){
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t'){
		;
	}

	s[1] = '\0';
	if (!isdigit(c) && c != '.'){
		return c;      /* not a number */
	}

	i = 0;
	if (isdigit(c)){    /* collect integer part */
		while (isdigit(s[++i] = c = getch())){
			;
		}
	}
	if (c == '.'){      /* collect fraction part */
		while (isdigit(s[++i] = c = getch())){
			;
		}
	}
	
	s[i] = '\0';
	if (c != END){
		ungetch(c);
	}

	return NUMBER;
}

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */
int getch(void){  /* get a (possibly pushed-back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}
   
void ungetch(int c){   /* push character back on input */
	if (bufp >= BUFSIZE){
		printf("ungetch: too many characters\n");
	}

	else buf[bufp++] = c;
}