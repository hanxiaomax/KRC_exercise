#include<stdio.h>
#define MAXLINE 50
void Strcat(char *s,char *t);
int main()
{
	char a[MAXLINE];
	char b[MAXLINE];
	printf("please input array a:\n");
	gets(a);
	printf("please input array b:\n");
	gets(b);
	Strcat(a,b);
	printf("%s\n",a);

}


void Strcat(char *s,char *t)
{
	while(*s++)/*执行while之后，不论真假，s总是+1*/
		;
	s--;/*所以在开始复制前，s要回退一位，否则t会复制在'\0'之后，无法打印*/
	while(*s++=*t++)
		;
}

/*
void Strcat(char *s,char *t)
{
	while(*s)     //如果没有到末尾'\0'
		s++;      //指针+1
	while(*s++=*t++)
		;
}

/*
