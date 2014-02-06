#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 1000
#define TABSIZE 8
#define YES 1
#define NO 0
void settab(int argc,char *argv[],char *tab);
void entab(char *tab);
int tabpos(int pos,char *tab);
int main(int argc,char *argv[])
{
	char tab[MAXLINE+1];
	settab(argc,argv,tab);/*根据命令行参数，在tab的停止位进行标记*/
	entab(tab);/*调用entab函数，进行替换操作*/
	return 0;
}
/*把空格替换成制表符和少量的空格*/
void entab(char *tab)
{
	int c,pos;
	int nb=0;/*空格数*/
	int nt=0;/*制表符数*/
	for(pos=1;(c=getchar())!=EOF;pos++)
		if(c==' ')/*当遇到空格的时候*/
		{
			if(tabpos(pos,tab)==NO)/*该位置不是tab停止位*/
				++nb;/*空格数++*/
			else
			{
				nb=0;/*空格清零*/
				++nt;/*制表符++*/
			}
		}
		else/*不是空格*/
		{
			for(;nt>0;nt--)/*打印nt个制表符*/
				putchar('\t');
			if(c=='\t')/*如果遇到一个制表符*/
				nb=0;/*空格清零*/
			else
				for(;nb>0;nb--)
					putchar(' ');/*打印nb个空格*/
			putchar(c);/*打印字符*/
			if(c=='\n')/*如果遇到换行*/
				pos=0;/*位标清零*/
			else if(c=='\t')/*如果遇到一个制表符*/
				while(tabpos(pos,tab)!=YES)/*若没有到制表符停止位*/
					++pos;/*移动到停止位*/
		}
}



void settab(int argc,char *argv[],char *tab)
{
	int i,pos;
	if(argc<=1)/*如果命令行参数只有一个*/
		for(i=1;i<MAXLINE;i++)/*对于tab的个元素进行赋值*/
			if(i%TABSIZE==0)/*每隔TABSIZE，就是一个停止位*/
				tab[i]=YES;/*赋值YES：1*/
			else
				tab[i]=NO;
	else/*如果通过命令行参数规定了制表符长度*/
	{
		for(i=1;i<=MAXLINE;i++)/*首先把tab全部初始化为0*/
			tab[i]=NO;
		while(--argc>0)/*依次处理命令行参数*/
		{
			pos=atoi(*++argv);/*pos等于长度值，但要转换为整型*/
			if(pos>0&&pos<=MAXLINE)/*如果pos在tab内*/
				tab[pos]=YES;/*对该位置赋值1，表示停止位*/
		}
	}
}

/*超出返回YES，没超出返回tab[i]，得到该位是否是tab停止位*/

int tabpos(int pos,char *tab)
{
	if(pos>MAXLINE)
		return YES;
	else
		return tab[pos];
}




















