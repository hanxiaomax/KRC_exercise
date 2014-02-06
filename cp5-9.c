#include<stdio.h>
char daytable[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
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
/*指针方式*/
int day_of_year(int year,int month,int day)
{
	int leap;
	char *p;/*建立一个字符指针，如果是整型，会出现从不兼容指针赋值警告*/
	
	if(year<1)
		return 0;
	else
		leap=(year%4==0&&year%4!=100||year%400==0);
	p=daytable[leap];/*p指向daytable[1]或[0]的首地址*/
	if(month<1||month>12)
		return 0;
	if(day<1||day>*(p+month))/*注意是取*(p+month)*/
		return 0;
	while(--month)
		day+=*++p;
	return day;
}
/*指针方式*/
void month_day(int year,int yearday,int *monthp,int *dayp)
{
	int leap;
	char *p;
	char *first_add;  /*用来储存首地址*/
	if(year<1)
	{
		*monthp=0;
		*dayp=0;
		return ;
	}
	else
		leap=(year%4==0&&year%4!=100||year%400==0);	
	p=daytable[leap];/*p指向daytable[1]或[0]的首地址*/
	first_add=p;/*储存首地址*/
	while(yearday>*++p)/*如果剩余天数大于p指针指向数组的有效地址的天数值*/
		yearday-=*p;/*减去该地址储存的天数*/
	if((p-first_add)>12||yearday>*(first_add+12))
	/*循环结束后month>12或yearday仍大于12月份天数*/
	//if((p-*(daytable+leap))>12||yearday>*(*(daytable+leap)+12))
	{
		*monthp=0;
		*dayp=0;
	}
	else
	{
		*monthp=p-*(daytable+leap);
/*现在指针地址-dayteble数组leap行的首地址，注意要*取值，因为存放的是指针 */
		*dayp=yearday;
	}
}
/*上面检查条件，取首地址比较繁琐，使用了二维数组的指针得到首地址，因为首地址没有保存，p进行了自增运算，首地址被忘记了。修改为新建一个指针保存首地址，但如何利用二维数组的行来取列的首地址不能忘记*/





