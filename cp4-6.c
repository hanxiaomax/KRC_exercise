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
 	double v; 
	char s[MAXOP];
	int i,var=0;
	double variable[26];/*26个字母，需要一个长为27的数组*/
	for(i=0;i<26;i++)
		variable[i]=0.0;/*初始化数组*/
	
	printf("\n----------RPN calculator-------------\n");
	printf("*      察看栈顶元素-?               *\n");
	printf("*      复制栈顶元素-c(copy)         *\n");
	printf("*      清空栈中元素-e(erase)        *\n");
	printf("*      交换栈顶元素-s(swap)         *\n");
	printf("*      可用函数:sin,cos,exp,pow     *\n");
	printf("*      请用空格间隔输入             *\n");
	printf("---------------------------------------\n");
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
				v=pop();/*最近打印的结果存在v中*/
				printf("result:\t%.8g\n",v);/*注意：此处是v，不是pop()，否则会弹出下一个值*/
				break;
			case '?':
				temp=pop();
				printf("top element :\t%.8g\n",temp);
				push(temp);
				break;
			case 'c':
				temp=pop();
				push(temp);
				push(temp);
				break;
			case 'e':
				clear();
				break;
			case 's':
				temp=pop();
				temp2=pop();
				push(temp);
				push(temp2);
				break;
			case '=':/*赋值操作*/
				pop();/*把varibale相应位置弹出*/
				if(var>='A'&&var<='Z')/*此时var是刚才的type（A）*/
					variable[var-'A']=pop();/*把压入的字母弹出赋值给数组对应位置*/
				else
					printf("error:no variable name\n");
				break;
			default:
				if(type>='A'||type<='Z')/*A-Z为数组变量的索引*/
					push(variable[type-'A']);/*把数组相应位置元素压入，第一次赋值的时候是0，但是=赋值进行后，就变成了 字母前面的数字，并在调用的时候，该数字被压入*/
				else if(type=='v')/*如果输入v，则把结果v压入栈中*/
					push(v);
				else
					printf("error:unknow command %s\n",s);
				break;
		}
		var=type;/*每次switch结束后，都把刚才的type赋值给var*/
	}
	return 0;
}
/*举例 3 A =-------------A 3 *   */

/*栈操作*/
int sp=0;
double val[MAXVAL];
/*压栈*/
void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stadck overflow,can not push %g\n",f);
}
/*弹栈*/
double pop(void)
{
	if(sp>0)
		return val[--sp];
	else
	{
		printf("stack empty\n");
		return 0.0;/*空栈也要返回一个0*/
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
	














