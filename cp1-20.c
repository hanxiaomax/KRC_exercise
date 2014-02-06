#include<stdio.h>
#define TABSIZE 8 //我们规定每隔8个位置会有一个制表位
main()
{
	int c; //记录字符
	int nb;//记录所需空格数
	int pos;//记录当前的位置
	nb=0;
	pos=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\t')//如果遇到制表符
		{
			nb=TABSIZE-(pos-1)%TABSIZE;//计算所需空格，当前位置-1（当前为'\t'），对制表符的长度求余。在用制表符的长ls度去减，得到所需空格
			while(nb>0)
			{	
				putchar(' ');
				pos++;
				--nb;//每打印一个空格，所需空格数减1，打印所需的所有空格
			}
		}
		else if(c=='\n')
		{	
			putchar(c);
			pos=1;//遇到换行符则打印换行符并把位置重新至为1
		}
		else
		{
			putchar(c);
			++pos;
		}
	}
}


/*
1.用数组处理不如用字符方便
2.制表符跳过的长度是不固定的，而是从当前位置跳到下一个制表位








