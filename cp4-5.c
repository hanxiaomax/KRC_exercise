#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define NAME 'n'
int getop(char s[]);
void push(double);
double pop(void);
void clear(void);
void mathfunc(char s[]);
/*注意输入的时候，需要用空格作为间断*/
main()
{
	int type;
	double temp,temp2; 
	char s[MAXOP];
	printf("\n----------RPN calculator-----------\n");
	printf("*      察看栈顶元素-?*\n");
	printf("*      复制栈顶元素-c(copy)         *\n");
	printf("*      清空栈中元素-e(erase)        *\n");
	printf("*      交换栈顶元素-s(swap)         *\n");
	printf("*      可用函数:sin,cos,exp,pow     *\n");
	printf("*      请用空格间隔输入             *\n");
	printf("-----------------------------------\n");
	printf("please input:");
	
	while((type=getop(s))!=EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case NAME:/*数学函数*/
				mathfunc(s);
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
			case '?':/*打印栈顶元素*/
				temp=pop();
				printf("top element :\t%.8g\n",temp);
				push(temp);
				break;
			case 'c':/*复制栈顶元素*/
				temp=pop();
				push(temp);
				push(temp);
				break;
			case 'e':/*清楚栈中元素*/
				clear();
				break;
			case 's':
				temp=pop();
				temp2=pop();
				push(temp);
				push(temp2);
				break;
			default:
				printf("error:unknown command %s\n",s);
				break;
		}
	}
	return 0;
}


/*栈操作*/
int sp=0;
double val[MAXVAL];
/*压栈*/
void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stack overflow,can not push %g\n",f);
}
/*弹栈*/
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
/*清空*/
void clear(void)
{
	sp=0;
}





int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i=0,c;
	while((s[0]=c=getch())==' '||c=='\t')
		;
	s[1]='\0';
	if(islower(c))
	{
		while(islower(s[++i]=c=getch()))
			;
		s[i]='\0';
		if(c!=EOF)
			ungetch(c);
		if(strlen(s)>1)
			return NAME; /*找到一个函数名*/
		else 
			return c; /*找到的是一个命令符*/
	}
	if(!isdigit(c)&&c!='.')
		return c;
	if(c=='-') 
		if(isdigit(c=getch())||c=='.')
			s[++i]=c;
		else
		{
			if(c!=EOF)
				ungetch(c);
			return '-';
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
#define BUFSIZE 100
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
/*查找支持的数学函数并运算，把运算结果压入栈中*/
void mathfunc(char s[])
{
	double temp;
	if(strcmp(s,"sin")==0)/*strcmp函数*/
		push(sin(pop()));
	else if(strcmp(s,"cos")==0)
		push(cos(pop()));
	else if(strcmp(s,"exp")==0)
		push(exp(pop()));
	else if(strcmp(s,"pow")==0)
	{
		temp=pop();
		push(pow(pop(),temp));
	}
	else
		printf("error: %s not supported\n",s);
}
	














