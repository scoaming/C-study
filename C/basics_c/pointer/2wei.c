#include<stdio.h>
int main()
{
	int a[3][2] = { {12,32}, {41,67}, {95,83} };
	int n, *p, i;
	n = sizeof(a) / sizeof(int);
	p = a[0];
	printf("%p %p\n",a,p);
	for(i = 0; i < n; i++)
		printf("%d ",*p++);
	putchar('\n');
	return 0;
}
