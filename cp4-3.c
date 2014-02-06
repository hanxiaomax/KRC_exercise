#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
int getop(char s[]);
void push(double);
double pop(void);
/*注意输入的时候，需要用空格作为间断*/
main()
{
	int type;
	double temp; /*储存弹出的临时数据*/
	char s[MAXOP];
	printf("----------RPN calculator----------\n");
	printf("*      use ctrl+z to exit        *\n");
	printf("*      use space to split        *\n");
	printf("----------------------------------\n");
	printf("please input:");
	
	while((type=getop(s))!=EOF)
	{
		switch (type)
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
			case '%':/*求模运算*/
				temp=pop();
				if(temp!=0.0)
					push(fmod(pop(),temp));
				else
					printf("error:zero divisor\n");
				break;
			case '\n':
				printf("result:\t%.8g\n",pop());
				break;
			default:
				printf("error:unknown command %s\n",s);
				break;
		}
	}
	return 0;
}



int sp=0;
double val[MAXVAL];
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
	int i=0,c;
	while((s[0]=c=getch())==' '||c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c)&&c!='.')
		return c;
	if(c=='-') /*如果该不是数字也不是小数点的字符，是-*/
		if(isdigit(c=getch())||c=='.')/*判断下一个字符，如果是数字或者小数点*/
			s[++i]=c;/*下一个字符是数，此处是一个负号*/
		else/*如果不是数，说明该-是一个减号*/
		{
			if(c!=EOF)
				ungetch(c);/*把预读的字符放到缓存buf中*/
			return '-';/*把减号返回*/
		}
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
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch error:BUF is full\n");
	else
		buf[bufp++]=c;
}
















