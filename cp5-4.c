#include<stdio.h>
#define MAXLINE 20 
int strend(char *s,char *t);
main()
{
	char a[MAXLINE],b[MAXLINE];
	printf("a:\n");
	gets(a);
	printf("b:\n");
	gets(b);
	printf("is b in the end of a?\n");
	if(strend_my(a,b)==1)
		printf("yes!\n");
	else
		printf("no!\n");
	
	printf("%d\n",strend_my(a,b));
}


int strend(char *s,char *t)
{
	char *bs=s;
	char *bt=t;
	while(*s)
		s++;
	while(*t)
		t++;
	while(*s==*t)
	{
		s--;
		t--;
		if(t==bt||s==bs)/*任意字符串回到起始处*/
			break;
	}
	if(*s==*t&&t==bt&&*s!='\0')/*上面的while对于最后一个字符，只移动，没比较，所以这里要先*s==*t*/
		return 1;
	else
		return 0;
}

/*为了能够反向比较，需要记住起始处的指针*/




int strend_my(char *s,char *t)
{
	char *bs=s;
	char *bt=t;
	while(*s)
		s++;
	while(*t)
		t++;
	while(*s==*t)
	{
		s--;
		t--;
		if(t==bt||s==bs)/*任意字符串回到起始处*/
			break;
	}
	if(t==bt&&*s!='\0')
		return 1;
	else
		return 0;
}

