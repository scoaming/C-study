#include<stdio.h>
#include<math.h>
int main()
{
	int x=100,a,b,c,i=0;
	printf("三位水仙花数为：\n");
	while(x<=999){
		a=x/100;
		b=x/10-a*10;
		c=x-a*100-b*10;
		//if(a*a*a+b*b*b+c*c*c==x){
		if( pow(a,3)+pow(b,3)+pow(c,3)==x){
			printf("%d ",x);
			i++;
		}
		x++;
	}

	printf("count:%d\n",i);
	return 0;
}
