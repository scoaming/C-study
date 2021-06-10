#include<stdio.h>
int main()
{
	int x=0;
	int a=1;
	int sum=0;
	while(x<100)
	{
		a++;
		sum=sum+a;
		x++;
	}
printf("sum=%d",sum);
return 0;
}
