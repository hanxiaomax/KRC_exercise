#include<stdio.h>
#include<string.h>
void itob(int n,char s[],int b);
main()
{
	int n,b;
	char s[100];
	printf("please input number:");
	scanf("%d",&n);
	printf("please input basis: ");
	scanf("%d",&b);
	printf(".........................\n");
	itob(n,s,b);
	printf("the result is : %s\n",s);
	
}

void itob(int n,char s[],int b)
{
	void Reverse(char s[]);
	int yu;
	int i=0;
	int sign;
	if((sign=n)<0)
		n=-n;
	do
	{
		yu=n%b;
		s[i++]=(yu<=9)? yu+'0':yu+'a'-10;
	}
	while((n/=b)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	Reverse(s);
	/*
	for(i=strlen(s);i>=0;i--)
		printf("%c",s[i]);
	printf("\n");
	*/
	/*可以用该三行代码，代替Reverse函数和输出，但是需要string.h支持*/
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


/*转换部分可以按前面的to2函数来写，但是本题这种写法更简练*/



