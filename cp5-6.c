#include<stdio.h>
int Getline(char *s,int lim);
main()
{
	
}

int Getline(char *s,int lim)
{
	int c;
	char *t=s/*保存起始指针*/
	while(lim--&&(c=getchar())!=EOF&&c!='\n')
		*s++=c;
	if(c=='\n')
		*s++=c;
	*s='\0';
	return s-t;/*返回长度*/



}
