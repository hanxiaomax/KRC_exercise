#include<stdio.h>
#include<string.h>
void Reverse(char s[]);
main()
{}
void Reverse(char s[])
{
	void Reverser(char s[],int i,int len);
	Reverser(s,0,strlen(s))
}

void Reverser(char s[],int i,int len)
{
	int c,j;
	j=len-(i+1);
	if(i<j)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		Reverser(s,++i,len);
	}
}
