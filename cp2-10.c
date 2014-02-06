#include<stdio.h>
char lower(char c);
main()
{
	int c;
	while((c=getchar())!='\n')
	printf("%c\n",lower(c));
}

char lower(char c)
{
	
	return (c>='A'&&c<='Z')?c+('a'-'A'):c;
	
}
