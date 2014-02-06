#include<stdio.h>
int binsearch(int x,int v[],int n);
main()
{
	int x[10];
	int i;
	int n;
	int loc;
	for(i=0;i<10;i++)
	{
		x[i]=i+15;
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("i want to search:");
	scanf("%d",&n);
	loc=binsearch(n,x,10);
	printf("the location of %d is %d:\n",n,loc);


}
/*数组v必须是已经排序过的*/
int binsearch(int x,int v[],int n)
{
	int low,high,mid;
	low=0;	/*数组起始索引号*/
	high=n-1;/*数组最大索引号*/
	mid=(low+high)/2;
	while(low<=high&&x!=v[mid])
	{
		if(x<v[mid])
			high=mid-1;
		else 
			low=mid+1;/*把下限放大到中间值后一个*/
	}
	if(x==v[mid])
		return mid+1;
	else
		return -1;
}









