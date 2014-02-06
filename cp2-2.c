enum loop{NO,YES};/*没有显式说明的情况下，枚举变量的第一个枚举名值为0，第二个为1*/
enum loop okloop==YES;/*okloop是一个枚举变量,初值为YES（1）*/
i=0;
while(okloop==YES) /*okloop==YES就进行循环，当满足判断条件后，把okloop置为NO，则循环中断*/
{
	if(i>=lim-1)
		okloop=NO;
	else if((c=getchar())=='\n')
		okloop=NO;
	else if(c==EOF)
		okloop=NO;
	else 
	{	
		s[i]=c;
		i++;
	}	
}
