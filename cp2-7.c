#include<stdio.h>
#include<string.h>
#define MAX 20
unsigned invert(unsigned x,int p,int n);
int bi_input(char s[]);
void to2(int n,char s[]);
main()
{
	int n,p;
	int x;
	char c[MAX];/*储存x二进制码*/
	char s[MAX];/*储存to2结果*/
	char d[MAX];
	unsigned result;
	printf("input x: ");
	scanf("%s",c);
	x=bi_input(c);
	//printf("input is %d (%s)\n",x,c);
	printf("input p: ");
	scanf("%d",&p);
	printf("input n: ");
	scanf("%d",&n);
	printf("invert result is :");
	to2(invert(x,p,n),s);
	
}

unsigned invert(unsigned x,int p,int n)
{	
	return x^(~(~0<<n)<<(p+1-n));
}

int bi_input(char s[])
{
	int i,n=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='1'||s[i]=='0')
		{	
			n<<=1;
			n+=s[i]-'0';
		}
		else
			return -1;
	}
	return n;
}
void to2(int a,char s[])
{
	int yu,shang;
	int i=0;
	shang=a;
	while(shang!=0)
	{
		yu=shang%2;
		s[i]=yu+'0';
		shang/=2;
		i++;
	}
	s[i]='\0';
	for(i=strlen(s);i>=0;i--)
		printf("%c",s[i]);
	printf("\n");

}





/*p=2 n=2
x 
1010--------------1100

*/




