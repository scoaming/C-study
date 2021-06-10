#include<stdio.h>

void swap(int *x,int * y);

int main()
{

	int a = 2, b = 7;
	
	printf("before:%d %d\n",a,b);
	swap(&a,&b);
	
	printf("later: %d %d\n",a,b);

return 0;
}

void swap(int *x,int * y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
