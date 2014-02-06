#include<stdio.h>
#include<string.h>
#define MAX 20
int strrindex(char s[],char t[]);
int strrindex_adv(char s[],char t[]);
main()
{
	char s[MAX],t[MAX];
	int pos=0;
	printf("input for s[MAX]\n");
	gets(s);
	printf("input for t[MAX]\n");
	gets(t);
	pos=strrindex(s,t);
	printf("the rightmost index is:%d\n",pos);
}

int strrindex(char s[],char t[])
{
	int i,j,k;
	int pos=-1;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0'&&t[k]==s[j];j++,k++)
			;
		if(k>0&&t[k]=='\0')
			pos=i;
	}
	return pos;
}

int strrindex_adv(char s[],char t[])
{
	int i,j,k;
	for(i=strlen(s)-strlen(t);i>=0;i--)
	{
		for(j=i,k=0;t[k]!=0&&t[k]==s[j];k++,j++)
			;
		if(k>0&&t[k]=='\0')
			return i;
	}

}
/*
abcdefg len:7
cd      len:2
i=7-2=5,从f开始。因为f前面不可能有cd
*/
