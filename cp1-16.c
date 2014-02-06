/*#include<stdio.h>
#define MAXLINE 1000
int Getline(char line[],int maxline);//stdio.h中包含了getline，这里应该有所区别
void copy(char to[],char from[]);
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0;
	while((len=Getline(line,MAXLINE))>0)
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
	if(max>0)
		printf("%s",longest);
		return 0;
}
int Getline(char s[],int lim)
{
	int c,i;
	for (i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)
		s[i]=c;
	if (c=='\n')
	{
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}
void copy(char to[],char from[])
{
	int i=0;
	while((to[i]=from[i])!='\0')
		++i;
}

*/

#include<stdio.h>
#define MAXLINE 1000
int Getline(char line[],int maxline);
void copy(char to[],char from[]);
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0;
	while((len=Getline(line,MAXLINE))>0)
	{
		printf("%d,%s",len,line);//打印每行的长度和该行
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
	}
	if(max>0)
		printf("%s",longest);
		return 0;
}
int Getline(char s[],int lim)
{
	int c,i;
	for (i=0;(c=getchar())!=EOF&&c!='\n';i++)
		if (i<lim-2)
		{	
			s[j]=c;
			++j;
		}				
	if (c=='\n')
	{
		s[j]=c;
		++i;
		++j;
		
	}
	s[j]='\0';
	return i;
}
void copy(char to[],char from[])
{
	int i=0;
	while((to[i]=from[i])!='\0')
		++i;
}
















