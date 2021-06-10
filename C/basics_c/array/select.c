#include<stdio.h>
int main()
{
	int a[10] = {};
	int i,j,t,n;
	printf("please input 10 numbers:\n");
	for(i = 0; i < 10; i++){
	scanf("%d",&a[i]);
	}
	n = sizeof(a)/sizeof(a[0]);

	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if(a[i] > a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;	
			}
		}
	}
	for(i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	puts("");
return 0;
}
