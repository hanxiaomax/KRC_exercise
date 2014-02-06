#include<stdio.h>
#include<string.h>
#define MAX 20
unsigned setbit(unsigned x,int p,int n,unsigned y);
int bi_input(char bi[]);
void to2(int a,char s[]);
main()
{	
	char s[MAX];   /*储存x的二进制码*/
	char c[MAX];   /*储存y的二进制码*/
	char d[MAX];   /*储存setbit结果的二进制码*/
	int x,y;       /*x是待转换的二进制数，y是用来操作的二进制数*/
	int p,n;       /*p，n是两个参数*/	
	printf("input x:");
	scanf("%s",s);
	x=bi_input(s);/*调用bi_input函数，把输入的字符串变为二进制数*/
	
	printf("input y:");
	scanf("%s",c);
	y=bi_input(c);

	printf("input is %d(%s)\n",x,s);/*展示输入情况，包括输入二进制数和它对应的整型数*/
	printf("input is %d(%s)\n",y,c);

	printf("p=? n=?\n");
	scanf("%d %d",&p,&n);

	printf("The result is %d\n",setbit(x,p,n,y));/*对输入的数据，根据参数，待用setbit函数进行操作*/

	printf("result in binumber:");
	to2(setbit(x,p,n,y),d); /*把setbit得到的整型结果，转换成二进制并按字符串打印出来*/
	
}


/*setbit函数：将x中从第p位开始的n个位，设置为y中最右边n位，其余位置不变*/
unsigned setbit(unsigned x,int p,int n,unsigned y)
{
	return x&~(~(~0<<n)<<(p+1-n))|(y&~(~0<<n))<<(p+1-n);
}
/*bi_input函数：用数组的方式，输入一个二进制数*/
int bi_input(char s[])
{
	
	int i,n=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='0'||s[i]=='1')/*注意这里要加引号，因为是字符型*/
		{	
			n<<=1;/*不是<<+1*，把n左移1位，并赋值给n*/	
			n+=s[i]-'0';/*让n得到输入的真实值（和上面语句顺序不能变）*/	
		}
		else
		{	
			printf("error.");
			return -1;
		}
	}
	return n;/*返回的是一个二进制数，但并不能直接打印成二进制，只能打印成%d*/
}


/*to2函数：整型a转换成二进制，储存在s[]中，并作为字符串打印*/
void to2(int a,char s[])
{
	int shang,yu;
    int i=0;
	shang=a;
	while(shang!=0)
	{
	    yu=shang%2;
	    s[i]=yu+'0';/*注意这里的'0'，数字和字符之间永远隔着一个0，如果没有，打印的会是空白*/
	    shang=shang/2;
	    i++;
	}
	s[i]='\0';
    for(i=(strlen(s)-1);i>=0;i--)
        printf("%c",s[i]);
    printf("\n");

}




/*
输入1001
n=0
0000
n<<=1  左移1位并赋值给n
0000
n+=s[0]-'0'=1 此时n=0+1=1
0001
n<<=1  左移1位并赋值给n(0010)
0010
n+=s[1]-'0'=0 此时n=0010+0=0010
n<<=1  左移1位并赋值给n(0100)
0100
n+=s[2]-'0'=0 此时n=0100+0=0100
n<<=1  左移1位并赋值给n(1000)
1000
n+=s[3]-'0'=1 此时n=1000+0001=1001------得到该二进制的值
*/


/*linux下没有itoa这个函数（可以转换成二进制），用sprintf代替,但是sprintf并不能转换成二进制*/

/*p=2 n=2.且假定最右边一位是第0位
x
1100
y
1101
--------把10，设成01---->1010
p=3 n=1
1111
0010
------------------>0111
*/






