/*按字母顺序排列，不是按长度*/
#include<stdio.h>
#include<string.h>
#include<stddef.h>
#define MAXLINE 1000/*能处理的最大行数*/
#define MAXSTOR 5000
char *lineptr[MAXLINE];
char linestor[MAXSTOR];
int readlines(char *lineptr[],int maxlines);
void writelines(char *lineptr[],int nlines);
void qsort(char *lineptr[],int left,int right);/*对指针数组排序*/
main()
{
	
	int nlines;/*输入行的数目*/
	if((nlines=readlines(lineptr,MAXLINE))>=0)
	{
		qsort(lineptr,0,nlines-1);/*调用qsort对该指针数组排序*/
		writelines(lineptr,nlines);
		return 0;
	}
	else/*nline<0,即readlines返回-1*/
	{
		printf("error:input too big to sort!\n");
		return 1;
	}
}

#define MAXLEN 100 /*每行最大长度*/

int Getline(char *,int lim);
/*输入函数：读取每行的字符，创建指针数组保存每行的指针，返回行数*/
int readlines(char *lineptr[],int maxlines)
{
	int len;
	int nlines=0;
	char line[MAXLEN];
	char *p=linestor;/*字符指针首先指向linestor第一个元素*/
	char *linestop=linestor+MAXSTOR; /*结束位置的指针*/
	while((len=Getline(line,MAXLEN))>0)/*Getline各行并返回各行长度*/
	{
		if(nlines>=maxlines||(p+len>linestop))/*超过结束位置*/
			return -1;
		else
		{
			line[len-1]='\0';
			strcpy(p,line);
			lineptr[nlines++]=p;
			p+=len;/*每次把p指针向前移动len*/
		}
	}
	return nlines;/*返回行数，即指针数组的元素序数+1*/
}
	
	

/*打印函数*/
void writelines(char *lineptr[],int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",lineptr[i]);/*循环打印所有指针*/
}	

/*排序函数*/
void qsort(char *v[],int left,int right)
{
	int i,last;
	void swap(char *v[],int i,int j);
	if(left>=right)
		return;
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if(strcmp(v[i],v[left])<0)/*小于则交换，即按递增排序*/
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}
/*调序函数：交换i,j两个元素的值*/
void swap(char *v[],int i,int j)
{
	char *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

int Getline(char s[],int lim)
{
	int c;
	int i=0;
	while(lim--&&(c=getchar())!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}


















