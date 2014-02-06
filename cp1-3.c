#include<stdio.h>
main()
{	
	float c,f;
	int max=300,min=0,step=20;
	printf("华氏温度-摄氏温度转换表\n");
	f=min;
	while(f<max)
	{
		c=(5.0/9.0)*(f-32);  //如果写成5/9会truncate为0，则c全为0
		printf("%3.1f\t%3.1f\n",f,c);//3.1f表示输出3位，小数点后1位的浮点数
		f=f+step;
	}
}
