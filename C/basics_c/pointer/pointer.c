#include<stdio.h>
#define N 20
int main(){
	char a[50]="I love china";
	char *x = a;
	char *y = &a[2];
	char *z = &a[7];
	a[N] = *x;
	int i;
	for(i = 0;i < 4; i++){
		a[N+i+1] = *(y+i);
	}
	for(i = 0;i < 5; i++){
		a[i] = *(z+i);
	}
	a[5] = ' ';
	for(i = 0;i < 4;i++){
		a[6+i] = a[21+i];
	}
	a[10] = ' ';
	a[11] = a[N];
	puts(a);

	
	return 0;
}
