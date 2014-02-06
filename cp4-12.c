#include<stdio.h>
#define MAXLINE 100

void itoa(int n,char s[]);
main()
{
	int n;
	char s[MAXLINE];
	printf("input n:\n");
	scanf("%d",&n);
	itoa(n,s);
	printf("%s\n",s);

}

void itoa(int n,char s[])
{
	static int i;
	if(n/10)
		itoa(n/10,s);
	else{
		i=0;
		if(n<0)
			s[i++]='-';
	}
	s[i++]=abs(n)%10+'0';
	s[i]='\0';
}
