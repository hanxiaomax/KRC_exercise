#include<stdio.h>
main()
{
	int c,lastc;
	lastc='a';
	while((c=getchar())!=EOF)
	{	
		if(c!=' ')
			putchar(c);
		if(c==' ')
			if(lastc!=' ')
				putchar(c);
		lastc=c;
	}
}
				
