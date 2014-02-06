#include<stdio.h>
int bitcount(unsigned x);
int bi_input(char s[]);
main()
{
	char a[20];
	int num=0;
	printf("please input the number:");
	scanf("%s",a);
	num=bitcount(bi_input(a));
	printf("the number of 1 is: %d\n",num);
}


int bitcount(unsigned x)
{
	int b=0;/*如果不赋初值，则计算结果不正确*/
	while(x!=0)
	{
		x&=(x-1);
		b++;
	}
	return b;
}

int bi_input(char s[])
{
	int n,i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='0'||s[i]=='1')
		{
			n<<=1;
			n+=s[i]-'0';
		}
		else
			return -1;
	}
	return n;
}
