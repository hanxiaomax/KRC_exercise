#include<stdio.h>
#include<ctype.h>
#define MAX 100
double atof(char s[]);
main()
{
	char s[20];
	double f;
	printf("input:");
	gets(s);
	f=atof(s);
	printf("%f\n",f);
}
double atof(char s[])
{
	int i,sign;
	double val,power;
	int sign_power;
	int e;
	for(i=0;isspace(s[i]);i++)
		;
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
		i++;
	for(val=0.0;isdigit(s[i]);i++)/*进行到小数点的时候循环就跳出了*/
		val=10.0*val+(s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++)
	{
		val=10.0*val+(s[i]-'0');
		power*=10.0;/*与小数位数相同，123.12=12312/100 */
	}
	if(s[i]=='e'||s[i]=='E')
	{
		sign_power=(s[++i]=='-')?-1:1;/*指数的符号*/
		if(s[i]=='+'||s[i]=='-')/*跳过符号*/
			i++;
		for(e=0;isdigit(s[i]);i++)
			e=10*e+(s[i]-'0');
		if(sign_power==1)/*正指数*/
			while(e-- >0)
				power/=10;/*缩小power，次数与指数相同，若原来power=100，正指数3，则缩小power到0.1*/
		else
			while(e-- >0)/*负指数*/
				power*=10;/*扩大power*/

	}
	return sign*val/power;
}

/*
123.12e-6=123.12*10^-6=123.12/1000000

123.12=12312/100
123.12e-2=123.12/100=12312/10000
*/
/*sign_power=(s[i]=='-')?-1:1 如果写成sign_power=s[i],那么必须输入加号，此处则不需要*/








