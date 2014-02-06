#include<stido.h>
#include<stdlib.h>
#define MAXLINE 1000
#define YES 1
#define NO 0
#define TABSIZE 8

void settab(int argc,char *argv[],char *tab);
void detab(char *tab);
int tabpos(int pos ,char *tab);

int main(int argc,char *argv[])
{
	char tab[MAXLINE+1];
	
	settab(argc,argv,tab);
	detab(tab);
	return 0;
}

void detab(char *tab)
{
	int c,pos=1;
	while((c=getchar())!=EOF)
		if(c=='\t')
		{
			do
				putchar(' ');
			while(tabpos(pos++,tab)!=YES)/*打印空格直到tab结束位*/
		}
		else if(c=='\n')
		{
			putchar(c);
			pos=1;
		}
		else
		{
			putchar(c);
			pos++;
		}
}





void settab(int argc,char *argv[],char *tab)
{
	int i,pos;
	if(argc<=1)
		for(i=0;i<MAXLINE;i++)
			if(i%TABSIZE==0)
				tab[i]=YES;
			else
				tab[i]=NO;
	else
	{
		for(i=0;i<MAXLINE;i++)
			tab[i]=NO;
		while(--argc>0)
		{
			pos=atoi(*++argv);
			if(pos>1&&pos<MAXLINE)
				tab[pos]=YES;
		}
	}	
}




int tabpos(int pos,char *tab)
{
	if(pos>MAXLINE)
		return YES;
	else
		return tab[pos];
}
		












