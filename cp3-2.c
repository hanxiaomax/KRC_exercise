#include<stdio.h>
void escape(char s[],char t[]);
void re_escape(char s[],char t[]);
main()
{
	char a[100];
	char b[100];
	int c;
	int i=0;
	int j;
	/*for(j=0;j<20;j++)
		b[j]=0;*/
	printf("please input the words:\n\n");
	gets(a); /*用gets()来替代getchar()*/
	escape(b,a);
	printf("esacpe:\n%s\n",b);
	printf("here we will make it back.... \n\n");
	re_escape(a,b);
	printf("unescape:\n%s\n\n",a);

}
void escape(char s[],char t[])
{
	int i;
	int j;/*需要两组索引号*/
	for(i=j=0;t[i]!='\0';i++)
		switch (t[i])
		{
			case ' ':
				s[j++]='\\';/*先用j再加1*/
				s[j++]='b';
				break;
			case '\n':
				s[j++]='\\';
				s[j++]='n';
				break;
			case '\t':
				s[j++]='\\';
				s[j++]='t';
				break;
			default:
				s[j++]=t[i];
				break;
		}
	s[j]='\0';/*不在for循环中*/
}

void re_escape(char s[],char t[])
{
	int i;
	int j;/*需要两组索引号*/
	for(i=j=0;t[i]!='\0';i++)
		if(t[i]!='\\')
			s[j++]=t[i];
		else
		{
			switch (t[++i])/*要让i先变成后一个位*/
			{
				case 'b':
				s[j++]=' ';
				break;
			case 'n':
				s[j++]='\n';
				break;
			case 't':
				s[j++]='\t';
				break;
			default:
				s[j++]='\\';/*如果没有上述字符，说明是一个\号*/
				s[j++]=t[i];
				break;
			}
		}
	s[j]='\0';/*不在for循环中*/
}

