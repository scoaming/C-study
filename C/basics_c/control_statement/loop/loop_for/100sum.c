#include<stdio.h>
int main()
{
	int i=1,sum=0;
	for(;i<101;){
		sum+=i;
		i++;
	}
	printf("%d\n",sum);
	return 0;
}
