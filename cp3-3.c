#include<stdio.h>
#define MAX 100
void expand(char s1[],char s2[]);
void my_expand(char s1[],char s2[]);
main()
{
	char a[MAX],b[MAX];
	char c[MAX],d[MAX];
	//printf("please input:\n");
	//gets(a);
	//expand(a,b);
	//printf("expanded resulted    %s\n",b);
	gets(c);
	my_expand(c,d);
	printf("my_expanded resulted %s\n",d);
	
}

void expand(char s1[],char s2[])
{
	char c;
	int i,j;
	i=j=0;
	while((c=s1[i++])!='\0')/*先读入一个字符（a）*/
		if(s1[i]=='-'&&s1[++i]>=c)/*对下一个字符和下下个字符判断，如果下一个字符是-，再下一个字符大于当前字符（a-g）*/
		{
			/*i++;*//*再到下一个字符,如果上面是s1[i+1]的话，i并没有被改变，所以此处要+1*/
			while(c<s1[i])/*对速记符号扩展,s1[i]现在是结束的一个字符*/
				s2[j++]=c++;/*拷贝字符*/
		}
		else/*不符合a-g这种模式*/
			s2[j++]=c;/*原样拷贝*/
	
	s2[j]='\0';
}


void my_expand(char s1[],char s2[])
{
	int i=0;
	int j=0;
	char c;
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]=='-'&&(s1[i-1]<s1[i+1]))/*如果读取到一个-,比较该符号前面一个字符和后面一个字符的大小*/
		{
			c=s1[i];
			while(c<s1[i+1])/*扩展字符*/
				s2[j++]=++c;
		}
		else
			s2[j++]=s1[i];/*原样拷贝*/
	}
	
	s2[j]='\0';

}

/*a-f*/







