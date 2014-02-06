#include<stdio.h>
char daytable[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};/*第一列0，使月份和序数对应*/
int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *monthp,int *dayp);

main()
{
	int n;
	int year,month,day;
	int day_num;
	printf("-------------------------------\n");
	printf("*       1.日期转换天数        *\n");
	printf("*       2.天数转换日期        *\n");
	printf("-------------------------------\n");
	printf("请选择功能\n\n");
	scanf("%d",&n);
	switch (n)
	{
		case 1:
			printf("请输入日期（用空格隔开）\n");
			scanf("%d %d %d",&year,&month,&day);
			day_num=day_of_year(year,month,day);
			while(!day_num)/*不要加！，因为非零都是真，即-1也是真,所以不能用-1作为返回值*/
			{
				printf("输入错误:日期超出范围！\n");
				printf("-------------------------------\n");
				printf("请重新输入\n");
				printf("请输入日期（用空格隔开）\n");
				scanf("%d %d %d",&year,&month,&day);
				day_num=day_of_year(year,month,day);
			}
			printf("该天是该年的第%d天\n",day_num);
			break;
		case 2:
			printf("想要知道某年第几天的日期（空格隔开）？\n");
			scanf("%d %d",&year,&day_num);
			month_day(year,day_num,&month,&day);
			while(!month&&!day)
			{
				printf("输入错误:年数小于0或天数太多！\n");
				printf("-------------------------------\n");
				printf("请重新输入\n");
				printf("想要知道某年第几天的日期（空格隔开）？\n");
				scanf("%d %d",&year,&day_num);
				month_day(year,day_num,&month,&day);
			}
			printf("该天日期是：%d 月 %d 日\n",month,day);
			break;
	}
	
}

int day_of_year(int year,int month,int day)
{
	int i,leap;
	
	if(year<1)
		return 0;
	else
		leap=(year%4==0&&year%4!=100||year%400==0);
	if(month<1||month>12)
		return 0;
	if(day<1||day>daytable[leap][month])
		return 0;
	for(i=1;i<month;i++)
		day+=daytable[leap][i];
	return day;
}
void month_day(int year,int yearday,int *monthp,int *dayp)
{
	int i,leap;
	if(year<1)
	{
		*monthp=0;
		*dayp=0;
		//printf("年份必须大于0\n");
		return ;/*void型，不能返回-1*/
	}
	else
		leap=(year%4==0&&year%4!=100||year%400==0);	
	
	for(i=1;i<=12&&yearday>daytable[leap][i];i++)
		yearday-=daytable[leap][i];
	if(i>12||yearday>daytable[leap][12])/*循环结束后，i=13或yearday大于12月份天数*/
	{
		*monthp=0;
		*dayp=0;
		//printf("天数溢出\n");
	}
	else
	{
		*monthp=i;
		*dayp=yearday;
	}
}






