#include<stdio.h>
main()
{	
	int n=0,t=0,w=0;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			++n;
		else if(c=='\t')
			++t;
		else if(c==' ')
			++w;
	}
	printf("there are %d lines.\n",n);
	printf("there are %d tabs.\n",t);
	printf("there are %d whitespace.\n",w);
}
