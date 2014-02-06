#include<stdio.h>
main()
{	
	float c,f;
	int max=300,min=0,step=20;
	f=max;
	while(f>min)
	{	
		f=f-step;
		c=(5.0/9.0)*(f-32);
		printf("%3.1f\t%3.1f\n",f,c);
		
	}
}
