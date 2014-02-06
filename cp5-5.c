#include<stdio.h>
#define SIZE 50
void Strncpy(char *s,char *t,int n);
void Strncat(char *s,char *t,int n);
int Strncmp(char *s,char *t,int n);
int main()
{
	int n;
	int text_num=1;
	char a[SIZE],b[SIZE];
	int c;
	printf("-------------------------------\n");
	printf("*     1.test strncpy          *\n");
	printf("*     2.test strncat          *\n");
	printf("*     3.test strncmp          *\n");
	printf("-------------------------------\n");
	printf("witch test do you need?\n");
	scanf("%d",&text_num);
	//__fpurge(stdin);/*linux下的fflush(stdin)，清空输入缓存*/
	while((c = getchar()) != '\n' && c != EOF)
		;/*跳过换行符，同样有效*/
	switch (text_num)
	{
		case 1:
			printf("strncpy test is running....\n");
			printf("it will copy B to A then print A\n");
			printf("-------------------------------\n");
			printf("please set array B:\n");
			gets(b);/*若不清空输入缓存，gets接受到的是回车*/
			printf("please input n:");
			scanf("%d",&n);
			Strncpy(a,b,n);
			printf("resulet:\n%s\n",a);
			break;
		case 2:
			printf("strncat test is running....\n");
			printf("please set array A: ");
			gets(a);
			printf("please set array B: ");
			gets(b);
			printf("please input n:");
			scanf("%d",&n);
			Strncat(a,b,n);
			printf("resulet:\n%s\n",a);
			break;
		case 3:
			printf("strncmp test is running....\n");
		   	printf("please set array A: ");
			gets(a);
			printf("please set array B: ");
			gets(b);
			printf("please input n:");
			scanf("%d",&n);
			printf("resulet:\n%d\n",Strncmp(a,b,n));
			break;
	}
	
	
}

void Strncpy(char *s,char *t,int n)
{
	while(n-->0&&(*s++=*t++)!='\0')
		;
	while(n-->0)
		*s++='\0';
}

void Strncat(char *s,char *t,int n)
{
	while(*s)
		s++;
	while(n--&&(*s++=*t++)!='\0')
		;
	while(n-->0)
		*s++='\0';
}

int Strncmp(char *s,char *t,int n)
{
	while(*s==*t)
	{
		s++;
		t++;
		if(*s=='\0'||n--<=0)
			return 0;
	}
	return *s-*t;


}

/*主函数里面的scanf输入后需要一个回车，但是这个回车会被gets接收，于是就不能输入了，只能用for+scanf循环赋值*/


 
