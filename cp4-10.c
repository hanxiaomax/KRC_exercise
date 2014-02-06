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
main()
{
	int type;
	double temp,temp2;
 	double v; 
	char s[MAXOP];
	int i,var=0;
	double variable[26];
	for(i=0;i<26;i++)
		variable[i]=0.0;
	
	printf("\n----------RPN calculator-------------\n");
	printf("*      察看栈顶元素-?               *\n");
	printf("*      复制栈顶元素-c(copy)         *\n");
	printf("*      清空栈中元素-e(erase)        *\n");
	printf("*      交换栈顶元素-s(swap)         *\n");
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
				v=pop();
				printf("result:\t%.8g\n",v);
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
			case '=':
				pop();
				if(var>='A'&&var<='Z')
					variable[var-'A']=pop();
				else
					printf("error:no variable name\n");
				break;
			default:
				if(type>='A'||type<='Z')
					push(variable[type-'A']);
				else if(type=='v')
					push(v);
				else
					printf("error:unknow command %s\n",s);
				break;
		}
		var=type;
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


#define MAXLINE 100
int Getline(char s[],int lim);

li=0;/*外部变量，由不同的调用共同维护*/
char line[MAXLINE];/*外部变量，由不同的调用共同维护*/

int getop(char s[])
{
	int i=0,c;
	if(line[li]=='\0')/*如果line[]尚未读入或到达末尾）*/
		if(Getline(line,MAXLINE)==0)/*调用Getline读入一行，判断长度*/
			return EOF;
		else/*已经读入了。读入的行长度不为0*/
			li=0;/*索引归零*/

	while((s[0]=c=line[li++])==' '||c=='\t')
		;
	s[1]='\0';
	
	if(!isdigit(c)&&c!='.')
		return c;
	if(isdigit(c))
		while(isdigit(s[++i]=c=line[li++]))
			;
	if(c=='.')
		while(isdigit(s[++i]=c=line[li++]))
			;
	s[i]='\0';
	li--;/*相当于压回，此处是把已经加1的li回退*/
	return NUMBER;
}
int Getline(char s[],int lim)
{
	int i=0;
	int c;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')	
		s[i++]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;

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
	














