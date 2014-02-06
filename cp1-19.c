#include<stdio.h>
#define LIMIT 1000
void Reverse(char s[]) //Reverse为空类型,无返回值，则对s本身进行操作，不引进新的数组

	int i=0;
	int j=0;
	char temp;
	while(s[i]!='\0')    /*使索引数i进行到最后一位*/
		i++;
	--i;/*回退一位开始处理*/
	if(s[i]=='\n')/*如果有换行，再回退一位*/
		--i;
	while(j<i)  //对s本身操作需要一个暂时的容器
	{	
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		--i;
		++j;
	}
}
int Getline(char line[],int limit)
{
	int i;
	char c;
	for(i=0;i<limit-1&&(c=getchar())!=EOF&&c!='\n';i++)
		line[i]=c;
	if(c=='\n')
	{
		line[i]=c;
		++i;
	}
	line[i]='\0';
	return i;
	
}
main()
{	
	char s[LIMIT];
	while(Getline(s,LIMIT)>0)
	{
		Reverse(s);
		printf("%s\n",s);
	}
}
