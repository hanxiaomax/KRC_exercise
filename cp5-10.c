#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
int getop(char []);
void push(double);
double pop(void);
void ungets(char []);/*把一个字符串压回到缓冲区*/

int main(int argc,char *argv[])
{
	char s[MAXOP];
	double temp;
	while(--argc>0)
	{
		ungets(" ");/*把一个参数的结束标记压回缓冲区,注意虽然是空格符但要用字符串*/
		ungets(*++argv);/*把该参数压入缓冲区*/
		
		switch(getop(s))
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				temp=pop();
				push(pop()-temp);
				break;
			case '/':
				temp=pop();
				if(temp!=0.0)
					push(pop()/temp);
				else
					printf("error:zero divisor\n");
				break;
			default:
				printf("error:unknown command %s\n",s);
				argc=1;
				break;
		}
	}
	printf("\t%.8g\n",pop());
	return 0;
}


int sp=0;/*下一个空闲位置*/
double val[MAXVAL];/*push和pop函数公用的栈*/
void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stack overflow,can not push %g\n",f);
}

double pop(void)
{
	if(sp>0)
		return val[--sp];
	else
	{
		printf("stack empty\n");
		return 0.0;
	}

}


int getch(void);
void ungetch(int);


int getop(char s[])
{
	int i,c;
	while((s[0]=c=getch())==' '||c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c)&&c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	if(c=='.')
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}


char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
	return buf[--bufp];
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch error:BUF is full\n");
	else
		buf[bufp++]=c;
}

/*cp4-7*/
void ungets(char s[])
{
	int len;
	void ungetch(int c);
	len=strlen(s);
	while(len>0)
		ungetch(s[--len]);
}




