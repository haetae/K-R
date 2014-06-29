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
void print (); //prints stack without popping
void duplicate (); // duplicates last element in stack
void swap (); // swaps the last two elements in stack
void clear (); // clears stack;
void printlast ();
void printmenu ();

int sp = 0; 
double val[MAXVAL];  

int main(){

    printmenu();

    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != END) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            if (sp > 1){
                push(pop() + pop());
            }

            else printf("Cannot add. Not enough elemnts in stack ;n; \n");

            break;

        case '*':
            if (sp > 1){
                push(pop() * pop());
            }

            else printf("Cannot multiply. Not enough elements in stack ;n; \n");
            break;

        case '-':
            if (sp > 1){
                op2 = pop();
                push(pop() - op2);
            }

            else printf("Cannot subtract. Not enough elements in stack ;n; \n");
            break;

        case '/':
            if (sp > 1){
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else printf("error: zero divisor ;n;\n");
            }

            else printf("Cannot divide. Not enough elements in stack ;n; \n");
            break;

        case '%':
            if (sp > 1){
                op2 = pop();
                if (op2 != 0.0)
                    push((int)(pop()) % (int)(op2));
                else printf("error:remainder by zero is undefined ;n;\n");
            }

            else printf("Cannot get remainder. Not enough elements in stack ;n;\n");
            break;

        case 'p':
            print();
            break;

        case 'd':    
            duplicate();
            break;

        case 's':
            swap();
            break;

        case 'c':
            printf("clearing stack \n");
            clear();
            break;

        case '\n':
            printlast();
            break;

        case 'm':
            printmenu();
            break;

        default:
            printf("error: unknown command ;n; %s\n", s);
            break; 
        }
    }
    return 0; 
}

void printmenu () {
    printf("Type in: \n");
    printf("\t p to print all values in stack \n");
    printf("\t d to duplicate the last element in stack \n");
    printf("\t s to swap the last two elements in stack \n");
    printf("\t c to clear stack \n");
    printf("\t + to add the last two elements \n");
    printf("\t * to multiply the last two elements \n");
    printf("\t - to subtract the last two elements \n");
    printf("\t / to divide the last two elements \n");
    printf("\t %% to get the remainder of the last two elements \n");
    printf("\t m to print this menu again \n");
    printf("\t %c to quit \n", END);
}

void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
    }
    else printf("error: stack full, can't push ;n; %g\n", f);
}

double pop(void){
    if (sp > 0){
        return val[--sp];
    }
    else {
        printf("error: stack empty ;n; \n");
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
        return c;
    }

    i = 0;
    if (isdigit(c)){
        while (isdigit(s[++i] = c = getch())){
            ;
        }
    }
    if (c == '.'){
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

char buf[BUFSIZE];
int bufp = 0;
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
   
void ungetch(int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }

    else buf[bufp++] = c;
}

void print (){
    int i;
    if (sp > 0){
        printf("Printing all the values of stack \n");
        for (i = 0; i < sp; i++){
            printf("%f\n", val[i]);
        } 
    }

    else printf("Stack is empty ;n; \n");
}

void printlast (){
    if (sp > 0) {
        double last = pop();
        printf("last element is %f\n", last);
        push(last);
    }
}


void duplicate (){
    if (sp > 0 && sp < MAXVAL - 2){
        printf("duplicating the last element of stack \n");
        double last = pop();
        push(last);
        push(last);
    }

    else printf("Cannot duplicate. Empty stack ;n; \n");
}


void swap (){
    if (sp > 1){
        printf("swapping the last two elements in the stack \n");
        double last1, last2;

        last1 = pop();
        last2 = pop();

        push(last1);
        push(last2);
    }

    else printf("Cannot swap. Not enough elements in stack ;n;\n");
} 

void clear (){
    while (sp > 0){
        pop();
    }
}