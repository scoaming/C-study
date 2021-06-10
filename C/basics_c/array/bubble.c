#include<stdio.h>
int main()
{
	int a[] = {12,2,5,7,99,53,71,62};
	int n,i,j,t;

	n=sizeof(a)/sizeof(int);

	for(i = 0;i < n - 1;i++){
		for(j = 0;j < n-i-1;j++){
			if(a [j] > a [j+1]){
				t = a [j];
				a [j] = a [j+1];
				a [j+1] = t;
			}
		}
	}

	for(i=0;i<=n-1;i++)
		printf("%d ",a[i]);
	puts("");
	return 0;
}
