#include<stdio.h>
int main()
{
	int a[3][2] = {{21,51}, {41,25}, {62,78}};
	int *p[] = {a[0], a[1], a[2]};
	printf("%d\n ",*(p[1]+1));
	return 0;
}
