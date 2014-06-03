#include <stdio.h>
#define EOF '!'

 int main()
 {
	 int nl;
	 int nt;
	 int ns;
	 char temp;
	 nl = 0;
	 nt = 0;
	 ns = 0;
	 while ((temp = getchar()) != EOF){
	 	if (temp == '\n')
	 		++nl;
	 	if (temp == '\t')
	 		++nt;
	 	if (temp == ' ')
	 		++ns;
	 }
	 printf("Number of lines: %d\t Number of tabs: %d\t Number of spaces: %d\n", nl, nt, ns);

	

	return 0;
}