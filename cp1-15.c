#include<stdio.h>
float Temtrans(float f);         //函数声明
main()
{	
	float f;                     //变量f需要定义
	int max=300,min=0,step=20;	
	while(f<=max)
	{	
		printf("%3.1f\t%3.1f\n",f,Temtrans(f));//Temtrans(f)调用后返回一个值
		f=f+step;
	}
}
float Temtrans(float f)         //函数定义，此时已经定义了f
{	
	return (5.0/9.0)*(f-32.0); //直接返回值，可以免去变量c
}

/*
float Temtrans(float f)
{	
	int c;
	c=(5.0/9.0)*(f-32.0);
	return c;
}
*/
