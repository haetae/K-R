#include <ctype.h>
#include <stdio.h>

#define END '!'
#define BUFSIZE 10

int getch(void);
void ungetch(int);
int getfloat(double *pn);

int main () {
    double n;
    printf("Please enter a number: \n");
    getfloat(&n);

    printf("The number is %f\n", n);
    return 0;
}

int getfloat(double *pn){
    int c, sign, ifsign, ifdeci, decipower;

    ifsign = ifdeci = 0;
    decipower = 1;

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

    for (*pn = 0; isdigit(c) || (c == '.'); c = getch()){
        if (c == '.'){
            ifdeci = 1;
            continue;
        }

        if (ifdeci == 0) {
            *pn = 10 * (*pn) + (c - '0');
        }

        if (ifdeci == 1){
            double temp = (c - '0');
            decipower *= 10;
            temp /= decipower;
            *pn += temp;
        }
    }
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