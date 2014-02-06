#include<stdio.h>
#include<string.h>
#define MAX 100
unsigned rightrot(unsigned x,int n);
int bi_input(char s[]);
void to2(int a,char s[]);
main()
{


}
unsigned rightrot(unsigned x,int n)
{
	int wordlength();/*计算运行程序的计算机所用的字长*/
	int rbit;
	while(n-->0)
	{
		rbit=(x&1)<<(wordlength()-1);
		x>>=1;
		x=x|rbit;

	}
	return x;
	
}
int wordlength()
{
	int i;
	unsigned v=(unsigned)~0;/*对0取反并类型转换，赋值给v，不一定是0000（四位）*/
	for(i=1;(v>>=1)>0;i++)/*i从1开始，如果把v（1）右移1位后，v仍然大于0，则i+1*/
			;
	return i;/*返回i的值就是长度*/
}
int bi_input(char s[])
{
	int i,n=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='1'||s[i]=='0')
		{
			n<<=1;
			n=s[i]-'0';
		}
		else 
			return n;
	}
	return -1;
}

void to2(int a,char s[])
{
	int yu,shang;
	int i;
	shang=a;
	while(shang!=0)
	{
		yu=shang%2;
		s[i]=yu;
		shang/=2;
		i++;
	}
	s[i]='\0';
	for(i=strlen(s);i>=0;i++)
		printf("%c",s[i]);
	printf("\n");
}



/*1001--1100--0110--0011--1001*/
/*

1001&1-----1001&0001=0001
0001<<wordlength()-1=1000   左移

rbit=1000
x>>=1                       右移1位并赋值
1001-----------0100
0100|rbit--------0100|1000=1100  完成一次循环


*/


/*假设是4位
1111>>0111>>0011>>0001>0000(==0循环结束)
进行了3次循环，但是，输出结果要是4，所以i从1开始
*/





