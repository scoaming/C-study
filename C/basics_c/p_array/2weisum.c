#include<stdio.h>
int main()
{
	int a[2][3] = {{2,1,5}, {41,66,72}};
	/*int *p[2];
	p[0] = a[0];
	p[1] = a[1];*/
	int *p[] = {a[0], a[1]};
	int n = 0, i, j;

	
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++)
			printf("%d ",*(p[i]+j));
		puts("");
	}
	putchar('\n');
	
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++)
			n += *(p[i]+j);
	}
	
	printf("%d\n",n);
	return 0;
}
