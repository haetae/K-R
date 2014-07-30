int getint(int *pn){
    int c, sign, ifsign;

    ifsign = 0;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
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

    for (*pn = 0; isdigit(c), c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);
    return c; 
}