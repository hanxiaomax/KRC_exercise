#include<stdio.h>
#define MAX 20
void squeeze(char s[],char t[]);
main()
{
	char s[MAX];
	char t[MAX];
	scanf("%s %s",s,t);
	squeeze(s,t);
	printf("%s\n",s);
}
/*abcdef bc =adef*/
void squeeze(char s[],char t[])
{
	int i,j,k;
	for(i=k=0;s[i]!='\0';i++)/*循环一直进行到s字符串的末尾*/
	{	
		for(j=0;t[j]!='\0'&&t[j]!=s[i];j++)/*对每个s中的字符，要和t中的元素对比，即对t循环比对直到结尾，如果【相同】，则循环结束*/
			;
		
		/*循环结束说明找到一个相同的字符或者没找到（此时t[j]=='\0'）*/
		if(t[j]=='\0')/*如果没找到相同的（此时t[j]=='\0'）也就是这里为真。说明该字符要保留*/	
			s[k++]=s[i];/*把当前的值复制到s中，然后下标+1，这里s[k++]=s[i]等价于s[k]=s[i],k++，而且只有复制后才k++，否则k是不变化的*/
	}
	s[k]='\0';
}






