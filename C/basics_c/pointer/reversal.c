#include<stdio.h>
int main()
{
	int n, g, *p, *q;
	int a[] = {12, 23, 41, 55, 62, 70, 99};
	n = sizeof(a) / sizeof(int);
	p = a;
	q = &a[n-1];
	
	while(p < q){
		g = *p;
		*p = *q;
		*q = g;
		++p;
		--q;
	}

	for(g = 0; g < 7; g++)
		printf("%d ", a[g]);

	puts("");

	return 0;
}
