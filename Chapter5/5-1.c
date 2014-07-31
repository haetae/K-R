#include <ctype.h>
#include <stdio.h>

#define END '!'
#define BUFSIZE 10

int getch(void);
void ungetch(int);
int getint(int *pn);

int main () {
    int n;
    printf("Please enter a number: \n");
    getint(&n);

    printf("The number is %d\n", n);
    return 0;
}


int getint(int *pn){
    int c, sign, ifsign;

    ifsign = 0;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != END && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        ifsign = 1;
        c = getch();
    }

    if (!isdigit(c) && (ifsign == 1)){
        ungetch(c);
        if (sign == -1){
            ungetch('-');
        }
        else ungetch('+');
    
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    
    if (c != END)
        ungetch(c);
    return c; 
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