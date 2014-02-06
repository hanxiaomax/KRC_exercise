#include<stdio.h>
void rcomment(int c);
void in_comment(void);
void echo_quote(int c);


main()
{
	int c,d;
	while((c=getchar())!=EOF)							/*读入一个字符给c，如果不是文件结束*/
		rcomment(c);												/*调用rcomment函数处理*/
	return 0;
}


/*rcomment:处理读入的每个字符，删除注释，首先是搜索起始标志*/
void rcomment(int c)
{
	int d;																	/*用来储存c后面读入的一个字符*/
	if(c=='/')															/*当遇到一个/时，需要进行后续的判断*/
	{
		if((d=getchar())=='*')								/*  再读入一个字符，如果是*号，d已经读入，后续不需读入，而且必须输出  */
			in_comment();												/*  说明进入注释，调用in_comment()函数寻找结束标志，删除注释 */
		else if (d=='/') 										 /*   如果又出现一个/   */
		{
			putchar(c); 										   /*则c一定不是属于注释，把c原样输出*/
			rcomment(d);											/*****递归调用rcomment函数，继续对d进行检测，而实际上只是c==‘/’的情况******/
		}
		else   														 /* 第一个/出现后，之后读入的一个字符，不是/也不是*    */
		{
			putchar(c);   /*c,d均不属于注释，c，d均原样输出*/
			putchar(d);	
		}
	}
	else if(c=='\''||c=='"') /*出现单引号或双引号*/
		echo_quote(c);/*调用echo_quote函数处理*/
	else /*其他情况表示即不是/也不是引号*/
		putchar(c);/*原样输出*/
}

/*in_comment:进入注释后，寻找注释结束标志，在找到前，没有任何的输出语句，则注释内的字符相当于被忽略掉了*/
void in_comment(void)  /*如果结束标志出现在引号里面？ */
{
	int c,d;
	c=getchar();   /* 读入一个字符给c */
	d=getchar();   /* 读入一个字符给d */
	while(c!='*'||d!='/') /* 当c不是*，d不是/时 *（寻找注释的结束标志）*/
	{
		c=d;                 /*把之前的d赋值给c，然后d再向后读一个字符*/
		d=getchar();
	}
}

/*echo_quote:*/
void echo_quote(int c)  
{
	int d;
	putchar(c);/*遇到单，双引号，调用echo_quote，首先肯定要把c先原样输出（c是引号）*/
	while((d=getchar())!=c)	/*再读入后面一个字符给d，如果d不是引号（c），即引号没结束*/
	{
		putchar(d);/*保持d原样输出，即引号内部原样输出*/
		if(d=='\\')/*    如果d是一个\（反斜杠）  */
			putchar(getchar()); /*那么把后面一个字符原样输出（反斜杠后面的引号不是结束，而且引号内要原样输出，因此不论反斜杠后面是什么都要原样输出）*/
	}
	putchar(d);/*d==c的时候，即d是引号，循环结束。此时引号内容结束且已经原样输出，再把这个结束引号输出就可以了*/
}
















