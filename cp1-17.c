#include<stdio.h>
#define MAXLINE 1000
int Getline(char line[],int maxline);
main()
{
	int len;
	char line[MAXLINE];
	while((len=Getline(line,MAXLINE))>0)//如果直接是>80，则当长度不足80的字符输入后，程序就会结束
	{
		if(len>8)					//将判断放在循环能进行。
			printf("%s",line);		//将字符数组完全打印出来
	}
}

int Getline(char s[],int lim)
{
	int c,i;  //c用来都取输入字符，i用来计数
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)//i<lim-1是要给结束符留一个位置
		s[i]=c;
	if(c=='\n')
	{
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}

