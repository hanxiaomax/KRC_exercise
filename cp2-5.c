#include<stdio.h>
#define MAX 20
int any(char s1[],char s2[]);
main()
{
	char a[MAX],b[MAX];
	scanf("%s %s",a,b);
	printf("the position is %d",any(a,b));
}

int any(char s1[],char s2[])
{
	int i,j;
	for(i=0;s1[i]!='\0';i++)
		for(j=0;s2[j]!=0;j++)
		{
			if(s1[i]==s2[j])
				return i;  /*应该返回的是i，而不是j*/
			else
				return -1;
		}

}
