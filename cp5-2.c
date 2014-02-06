#include<stdio.h>
#include<ctype.h>
#define SIZE 10

main()
{
	int getfloat(float *);
	float array[SIZE]={0.0};
	int i;
	for(i=0;i<SIZE&&getfloat(&array[i])!=EOF;i++)
		;
	for(i=0;i<SIZE;i++)
		printf("%f\n",array[i]);

}

int getch(void);
void ungetch(int c);

int getfloat(float *pn)/*返回的仍然是int，*pn才是浮点*/
{	
	int c,sign;
	float pow=1;/*float*/
	while(isspace(c=getch()))
		;
	if(!isdigit(c)&&c!=EOF&&c!='-'&&c!='+'&&c!='.')
	{
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='-'||c=='+')
		c=getch();
	for(*pn=0;isdigit(c);c=getch())/*收集整数部分*/
		*pn=(*pn)*10.0+(c-'0');
	if(c=='.')
	{
		c=getch();/*此处需要先读一个，才能有下面的isdigit*/
		for(pow=1;isdigit(c);c=getch())
		{
			*pn=(*pn)*10+(c-'0');
			pow*=10;
		}
	}
	*pn= sign* *pn/pow;/*通过*pn修改，而不是return*/
	if(c!=EOF)
		ungetch(c);
	return c;

}
#define BUFSIZE 10
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("error:buf is full\n");
	else
		buf[bufp++]=c;
}

/*
if(c=='.')
	c=getch();
for(pow=1;isdigit(c);c=getch()) 
{
			*pn=(*pn)*10+(c-'0');
			pow*=10;
}

*/
/*这样写也是可以的，因为上面的for遇到不是数字跳出，判断该字符是不是.，如果不是，那么不会再getch，下面的for语句isdigit(c)，仍然不会执行。，此时会把该符号压回buf区并返回*/









