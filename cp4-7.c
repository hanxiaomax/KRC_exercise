#include<stdio.h>
#include<string.h>
void ungets(char s[])
{
	int len;
	void ungetch(int c);
	len=strlen(s);
	while(len>0)
		ungetch(s[--len]);
}


