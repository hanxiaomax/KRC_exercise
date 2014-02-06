#include<stdio.h>
#include<math.h>
void itoa(int n,char s[],int b);
main()
{
	int n,b;
	char s[20];
	printf("please input number:");
	scanf("%d",&n);
	printf("please input width: ");
	scanf("%d",&b);
	printf(".........................\n");
	itoa(n,s,b);
	printf("the result is: %s\n",s);
}
void itoa(int n,char s[],int b)
{
	void Reverse(char s[]);
	int i,sign;
	sign=n;
	i=0;
	do
	{
		s[i++]=abs(n%10)+'0';
	}
	while((n/=10)!=0);
	if(sign<0)
		s[i++]='-';
	while(i<b)
		s[i++]=' ';
	s[i]='\0';
	Reverse(s);
}
void Reverse(char s[])
{
	int i,j;
	char temp;
	i=j=0;
	while(s[i]!='\0')
		i++;
	--i;
	if(s[i]=='\n')/*之前总是会吞掉最后一个字符，转换后第一个字符丢失，是因为把==写成了=*/
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
