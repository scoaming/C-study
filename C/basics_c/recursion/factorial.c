#include<stdio.h>
int fact(int n);
int main(){
	int i;
	printf("Please input number:");
	scanf("%d",&i);
	printf("%d的阶乘为：%d\n",i,fact(i));
	return 0;
}
int fact(int n){

	if(n == 0 || n == 1)
		return 1;
	return(n*fact(n-1));
}

