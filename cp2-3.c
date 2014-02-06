#include<stdio.h>
#define MAX 20
#define YES 1
#define NO 0
int htoi(char s[]);
main()
{
	char s[MAX];
	scanf("%s",s);
	printf("the number is %d\n",htoi(s));
}


int htoi(char s[])
{
	int hexdigit;/*十六进制位数*/
	int i;
    int inhex;/*判断循环是否进行*/
	int n;/*返回的整形值*/
	
	i=0;
	if(s[i]=='0')/*用来跳过可选的前缀*/
	{
		++i;
		if(s[i]=='x'||s[i]=='X')
			++i;
	}
	
	n=0;
	inhex=YES;/*默认是十六进制*/
	while(inhex==YES)
	{
		if(s[i]>='0'&&s[i]<='9')/*如果字符在0-9之间*/
			hexdigit=s[i]-'0';/*得到真实的值*/
		else if(s[i]>='a'&&s[i]<='f')/*如果字符在a-f之间*/
			hexdigit=s[i]-'a'+10;/*得到具体的值并+10，得到十进制数*/
		else if(s[i]>='A'&&s[i]<='Z')/*如果字符在A-F之间*/
			hexdigit=s[i]-'A'+10;/*得到具体的值并+10，得到十进制数*/
		else/*如果字符不在上述范围，说明不是十六进制数*/
			inhex=NO;/*inhex置NO，循环中断*/

		/*上述if结构已经结束*/

		if(inhex==YES)/*如果是十六进制数*/
			n=16*n+hexdigit;/*计算对应的十进制整型数的值*/
		i++;

			/*if是在循环当中，每产生一个hexdigit都要计算相应的n，并且把之前的n进一个位，即乘以16*/
	}
	return n;/*返回该值*/
}
















