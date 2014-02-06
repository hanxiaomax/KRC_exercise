#include<stdio.h>
#define TABSIZE 8
#define MAXCOL 10
char line[MAXCOL];//输入行
int exptab(int pos);//将tab扩展为等量的空格
int findblnk(int pos);//寻找空格的位置pos
int newpos(int pos);//安排新的位置
void printl(int pos);//打印行，直到pos列？
main()
{
	int c,pos;//c用来接收字符，pos用来记录当前位置
	pos=0;//首先将pos置0
	while((c=getchar())!=EOF)//如果不是文件结尾，则持续读入字符c
	{
		line[pos]=c;//把字符c记录在line[MAXCOL]这个数组中的pos这个位置
		if(c=='\t')//如果字符c是一个制表符
			pos=exptab(pos);//用exptab函数处理pos，并返回新的pos
		else if(c=='\n')//如果字符c是一个换行符
		{
			printl(pos);//打印当前的输入行
			pos=0;//并且把pos归零
		}
		else if(++pos>=MAXCOL)//pos自增，如果一段时间后大于了MAXCOL
		{	
			pos=findblnk(pos);//用findblnk函数处理pos，得到新的pos值
			printl(pos);//打印当前的输入行
			pos=newpos(pos);//用newpos函数处理pos，得到新的位置
		}
	}
}
void printl(int pos)//打印当前行
{
	int i;
	for(i=0;i<pos;i++)//依次打印所有下标小于pos的数组元素
		putchar(line[i]);
	if(pos>0)//如果pos大于0，即确实打印了一行
	putchar('\n');//打印一个换行符
}

int exptab(int pos)//exptab函数，把tab变成空格，并返回pos值或0
{
	line[pos]=' ';//tab至少会有一个空格
	for(++pos;pos<MAXCOL&&pos%TABSIZE!=0;pos++)//pos+1为初值，如果pos小于MAXCOL而且pos对TABSIZE求余不为0（后面还有tab），让pos自增
		line[pos]=' ';//依次将空格赋值给line[]
	if(pos<MAXCOL)//之后，如果pos依旧小于MAXCOL
		return pos;//返回pos值
	else//如果pos依旧大于等于MAXCOL
	{
		printl(pos);//调用printl函数打印当前行
		return 0;//返回0
	}
}


int findblnk(int pos)//findblnk函数，用于寻找空格
{
	while(pos>0&&line[pos]!=' ')//当pos大于0且当前位置不是一个空格
		--pos;//pos自减，即倒着寻找空格
	if(pos==0)//如果pos=0
		return MAXCOL;//返回MAXCOL，无空格
	else
		return pos+1;//否则返回pos+1，此处是空格
}	
			
int newpos(int pos)//newpos函数用来重新安排pos
{
	int i,j;
	if(pos<=0||pos>MAXCOL)//如果pos小于0或大于MAXCOL
		return 0;//返回0
	else
	{
		i=0;
		for(j=pos;j<MAXCOL;j++)//从pos开始，j自增，不超过MAXCOL
		{
			line[i]=line[j];//把line[j]复制到line[i]（i是从0开始的），即把大于pos的，复制到前面来。
			++i;//i自增
		}

		return i;//返回i，也就是新的pos
	}
}
















