#include<stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};
	int *p=a;
	int i;
	for(i=0; i<5; i++)
	{
		printf("a[i]=%d\n",*(p+i));
	}
	return 0;
}
