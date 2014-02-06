#include<stdio.h>
#define LIMIT 1000
main()
{
	int a;
	int i=0;
	int j;
	char m[LIMIT];
	char s[LIMIT];
	scanf("%s",s);
	while(s[i]!='\0')    
		i++;
	--i;
	if(s[i]=='\n')
		--i;
	a=i;
	for(j=0;j<=a;j++,i--)          
	{	
		m[j]=s[i];
	}
	j++;
	m[j]='\n';
	j++;
	m[j]='\0';
	printf("%s\n",m);
}

