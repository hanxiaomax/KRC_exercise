#include<stdio.h>
main()
{
	float c,f;
	int max=100,min=-100,step=20;
	printf("摄氏温度-华氏温度转换表\n");
	c=min;
	while(c<max)
	{
		f=c*(9.0/5.0)+32;
		c=c+step;
		printf("%3.1f\t%3.1f\n",c,f);//对齐方式？默认右对齐，-3.1f左对齐
	}
}
