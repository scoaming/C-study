#include<stdio.h>
int add(int x,int y);
int main()
{
	int a,b;
	scanf("%d,%d",&a,&b);
	int sum=add(a,b);
	printf("sum=%d\n",sum);
	return 0;
	
}
int add(int x,int y)
{
	int sum;
	sum=x+y;
	return sum;
}
