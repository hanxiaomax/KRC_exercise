#include<stdio.h>
#define MAXLINE 1000
int Getline(char line[],int maxline);
int Remove(char s[]); //remove是一个函数，移除并储存移除后的结果
main()
{	
	int  i;
	char line[MAXLINE];
	while(Getline(line,MAXLINE)>0)	
	{
		if(Remove(line)>0)
			printf("%s",line);
	}
}
int Getline(char s[],int lim)
{
	int i;
	char c;
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)//c!='\n'不能省，会导致无输出
		s[i]=c;
	if(c=='\n')
	{	
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}
int Remove(char s[])
{
	int i=0; //赋初值
	while(s[i]!='\n')//如果s[i]不是换行符
		i++;		//继续向后寻找，直到找到换行符
	--i;			//找到换行符之后，向前一个
	while(i>=0&&(s[i]==' '||s[i]=='\t'))//从换行符前一个字符，向前寻找，如果是空格且没到头
		--i;//继续向前，直到找到第一个不是换行符的字符
	if(i>=0)//如果此时仍旧没到头
	{
		++i;//向后一个元素
		s[i]='\n';//赋值为换行符
		++i;//向后一个元素
		s[i]='\0';//添加结束符
	}
	return i;//返回新的长度
}







