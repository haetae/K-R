// Mostly taken from K&R textbook. Added a few lines to fulfill the task.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h>

#define END '!'
#define MAXOP 100  
#define MAXVAL 100 
#define BUFSIZE 1

enum command{
    NUMBER, PLUS, MIN, MOD, MUL, DIV, SIN, COS, TAN, EXP, POW, PRINT,
    DUP, SWAP, CLEAR, NEWLINE, MENU, NOTFOUND, ENDNUM, PUTVAR, GETVAR};

enum command getop(char []);
void push(double);
double pop(void);
void print (); //prints stack without popping
void duplicate (); // duplicates last element in stack
void swap (); // swaps the last two elements in stack
void clear (); // clears stack;
void putlast();
void printmenu ();
double peek ();

int sp = 0; 
double val[MAXVAL];
double var[26];  

int main(){
    int i, j;

    for (i = 0; i < 26; i++){
        var[i] = 0;
    }

    printmenu();

    enum command type;
    double op2, index;
    char s[MAXOP];
    while ((type = getop(s)) != ENDNUM) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case PLUS:
            if (sp > 1){
                push(pop() + pop());
            }

            else printf("Cannot add. Not enough elemnts in stack ;n; \n");

            break;

        case MUL:
            if (sp > 1){
                push(pop() * pop());
            }

            else printf("Cannot multiply. Not enough elements in stack ;n; \n");
            break;

        case MIN:
            if (sp > 1){
                op2 = pop();
                push(pop() - op2);
            }

            else printf("Cannot subtract. Not enough elements in stack ;n; \n");
            break;

        case DIV:
            if (sp > 1){
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else printf("error: zero divisor ;n;\n");
            }

            else printf("Cannot divide. Not enough elements in stack ;n; \n");
            break;

        case MOD:
            if (sp > 1){
                op2 = pop();
                if (op2 != 0.0)
                    push((int)(pop()) % (int)(op2));
                else printf("error:remainder by zero is undefined ;n;\n");
            }

            else printf("Cannot get remainder. Not enough elements in stack ;n;\n");
            break;

        case PRINT:
            print();
            break;

        case DUP:    
            duplicate();
            break;

        case SWAP:
            swap();
            break;

        case CLEAR:
            printf("clearing stack \n");
            clear();
            break;

        case SIN:
            push(sin(pop()));
            break;

        case COS:
            push(cos(pop()));
            break;

        case TAN:
            push(tan(pop()));
            break;

        case EXP:
            push(exp(pop()));
            break;

        case POW:
            op2 = pop();
            push(pow(op2, pop()));
            break;

        case NEWLINE:
            putlast();
            break;

        case MENU:
            printmenu();
            break;

        case PUTVAR:
            op2 = pop();
            var[s[4]-'a'] = op2;
            printf("setting the variable %c to value %f \n", (s[4]), op2);
            push(op2);
            break;

        case GETVAR:
            push(var[s[0]-'a']);
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
    printf("\t 'print' to print all values in stack \n");
    printf("\t 'dup' to duplicate the last element in stack \n");
    printf("\t 'swap' to swap the last two elements in stack \n");
    printf("\t 'clear' to clear stack \n");
    printf("\t + to add the last two elements \n");
    printf("\t * to multiply the last two elements \n");
    printf("\t - to subtract the last two elements \n");
    printf("\t / to divide the last two elements \n");
    printf("\t %% to get the remainder of the last two elements \n");
    printf("\t 'menu' to print this menu again \n");
    printf("\t %c to quit \n", END);
    printf("\nThis calculator supports sin, cos, tan, exp and pow functions\n");
    printf("You can store values in variables by typing 'put-' followed by the character of the variables (from 'a' to 'z')\n");
    printf("The most recently cacluated value will be put into variable 'a'\n");
    printf("All variables are initialized to zero.\n");
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

double peek (){
    if (sp > 0){
       return val[sp];
    }

    else{
        printf("error: stack empty ;n; \n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);
void ungets(char []);

void getword (char s[]){
    char c;
    int i = 0;
    while ((c = getch()) == ' ' || c == '\t');

    if (c == '\n') {
        s[0] = '\n';
        s[1] = '\0';
        return;
    }

    while ((c != ' ') && (c != '\t') && (c != '\n')){
        s[i] = c;
        i++;

        c = getch();
    }

    if (c == '\n') {
        ungetch(c);
    }

    s[i] = '\0';
}


enum command getop(char s[]){

    getword(s);

    if (isdigit(s[0]) || s[0] == '.') {
        return NUMBER;
    }

    if (s[0] =='p' && s[1] == 'u' && s[2] == 't' && s[3] == '-'){
        if (s[4] >= 'a' && s[4] <= 'z'){
            return PUTVAR;
        }
    }

    if (s[0] >= 'a' && s[0] <='z' && s[1] =='\0'){
        return GETVAR;
    } 

    if (s[0] == '+')
        return PLUS;
    
    else if (s[0] == '-')
        return MIN;
    
    else if (s[0] == '*')
        return MUL;
    
    else if (s[0] == '/' || s[0] == '\\')
        return DIV;

    else if ((strcmp(s, "sin") == 0) || (strcmp(s, "Sin")) == 0)
        return SIN;

    else if ((strcmp(s, "cos") == 0) || (strcmp(s, "Cos")) == 0)
        return COS;

    else if ((strcmp(s, "tan") == 0) || (strcmp(s, "Tan")) == 0)
        return TAN;

    else if (strcmp(s, "exp") == 0)
        return EXP;

    else if(strcmp(s, "pow") == 0)
        return POW;

    else if (strcmp(s, "print") == 0)
        return PRINT;

    else if (strcmp(s, "dup") == 0)
        return DUP;

    else if (strcmp(s, "swap") == 0)
        return SWAP;

    else if (strcmp(s, "clear") == 0)
        return CLEAR;

    else if (s[0] == '\n')
        return NEWLINE;

    else if (strcmp(s, "menu") == 0)
        return MENU;

    else if (s[0] == END)
        return ENDNUM;

    else return NOTFOUND;
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

void ungets(char s[]){
    int i;

    for (i = 0; s[i] != '\0'; i++){
        buff[bufp++] = s[i];
    }
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

void putlast (){
    if (sp > 0) {
        double last = pop();
        printf("last element is %f, setting variable a to this element\n", last);
        var[0] = last;
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
