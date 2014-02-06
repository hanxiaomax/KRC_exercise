#include<stdio.h>
#define BUFSIZE 100
int buf[BUFSIZE];/*char型变int型*/
int bufp=0;


int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch error:BUF is full\n");
	else
		buf[bufp++]=c;
}


