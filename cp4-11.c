#include<stdio.h>
#include<ctype.h>
#define NUMBER '0'
int getch(void);
int getop(char s[])
{
	int i=0,c;
	static int lastc=0;/*静态内部变量，只能在函数中使用但一直存在。*/
	if(lastc==0)
		c=getchar();
	else
	{
		c=lastc;
		lastc=0;
	}
	while((s[0]=c)==' '||c=='\t')/*先检查完当前的c，才读入*/
		c=getch();
	s[1]='\0';
	if(islower(c))
	{
		while(islower(s[++i]=c=getch()))
			;
		s[i]='\0';
		if(c!=EOF)
			lastc=c;/*替代ungetcch*/
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
				lastc=c;/*替代ungetcch*/
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
		lastc=c;/*替代ungetcch*/
	return NUMBER;
}
