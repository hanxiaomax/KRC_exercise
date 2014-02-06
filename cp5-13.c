#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEFAULT 10
#define LINES 100 /*最大行数*/
#define MAXLEN 100 /*每行最大长度*/


int Getline(char *,int);
int main(int argc,char *argv[])
{
	char *p;
	char *buf;
	char *bufend;
	char line[MAXLEN];/*存放当前行*/
	char *lineptr[LINES];/*储存各个行的指针*/
	int first,i,last,len,n,nlines;
	if(argc==1)/*默认情况*/
		n=DEFAULT;
	else if(argc==2&&*argv[1]=='-')/**/
		n=atoi(argv[1]+1);/*把argv[1]中数字转换成整数*/
	else
	{
		printf("usage:tail [-n]\n");
		return 0;
	}
	if(n<1||n>LINES)/*如果n不在合理范围内*/
		n=LINES;/*n赋值为总行数*/
	for(i=0;i<LINES;i++)/*把所有lineptr中指针初始化为0*/
		lineptr[i]=NULL;
	/*分配储存空间并返回指针，不成功返回NULL*/
	if((p=buf=malloc(LINES+MAXLEN))==NULL)/*分配不成功*/
	{
		printf("tail:cannot allocate buf\n");
		return 0;
	}
	bufend=buf+LINES+MAXLEN;/*分配成功，计算储存区末尾指针*/
	last=0;/*最后一个读入句的索引*/
	nlines=0;/*读入的句数*/
	while((len=Getline(line,MAXLEN))>0)/*当读入句子时*/
	{
		if(p+len+1>=bufend)/*如果p指针后移动len+1位到达或超过末尾*/
			p=buf;/*p重新指向起始位置*/
		lineptr[last]=p;/*把该p指针储存在指针数组里*/
		strcpy(lineptr[last],line);/*把该行拷贝到lineptr[last]所指的空间*/
		if(++last>=LINES)/*如果最后一句大于最大允许句数*/
			last=0;/*归零*/
		p+=len+1;/*每次读入一句后，p指针向后移动len+1*/
		nlines++;/*读入行数增加1*/
	}
	if(n>nlines)/*如果要打印的行数大于读入行数*/
		n=nlines;/*打印全部*/
	first=last-n;/*要打印的第一个指针，是最后一个指针减去n*/
	if(first<0)/*如果第一个指针小于0*/
		first+=LINES;/*first加上数组长度,调整起始索引*/
	for(i=first;n-->0;i=(i+1)%LINES)/*当i大于LINES时会重复打印，以此避免*/
		printf("%s",lineptr[i]);/*打印各个指针所指的字符串*/
	return 0;
}


int Getline(char s[],int lim)
{
	int i=0,c;/*i要有初值*/
	while(--lim>0&(c=getchar())!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}























