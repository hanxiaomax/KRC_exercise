/*itoa函数不能处理最大的负数，因为此时不能使用n=-n*/
#include<stdio.h>
#include<math.h>
void itoa(int n,char s[]);
main()
{
	int n;
	char a[20];
	printf("input: ");
	scanf("%d",&n);
	itoa(n,a);
	printf("%d\n");
}
void itoa(int n,char s[])
{
	void Reverse(char s[]);/*只在该函数中使用，则在该函数中声明*/
	int i,sign;
	i=0;
	sign=n;
	do
	s[i++]=abs(n%10)+'0';
	while((n/10)!=0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0'
	Reverse(s);
}

void Reverse(char s[])
{
	int i,j;
	int temp;
	i=j=0;
	while(s[i]!='\0')
		i++;
	--i;
	if(s[i]='\n')
		i--;
	while(j<i)
	{
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		i--;
		j++;
	}
}







