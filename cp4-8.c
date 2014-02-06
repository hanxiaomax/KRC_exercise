#include<stdio.h>
char buf=0;

int getch(void)
{
	int c;
	if(buf!=0)/*如果buf中有字符*/
		c=buf;/*把buf赋值给c*/
	else/*如果buf=0*/
		c=getchar();/*从键盘读一个字符给c*/
	buf=0;/*无论如何都去，buf都需要归零*/
	return c;/*返回字符*/
}

void ungetch(int c)
{
	if(buf!=0)/*如果buf中有字符*/
		printf("ungetch error:too many characters\n");/*已满*/
	else
		buf=c;/*如果buf中没字符，把c赋值给buf*/
}
