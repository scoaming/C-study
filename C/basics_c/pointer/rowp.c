#include<stdio.h>
int main()
{
	int a[3][2] = { {12,45}, {21,57}, {89,36} };
	int (*p)[2], i, j;
	
	p = a;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++)
			printf("%d %d %d %d ",a[i][j],p[i][j],*(*(a+i)+j),*(*(p+i)+j));
		puts("");
	}
	
	return 0;
}
