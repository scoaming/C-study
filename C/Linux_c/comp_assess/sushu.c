#include<stdio.h>
#include<math.h>
int main(){
	int i = 100,j = 0,k = 2;
	int sum = 0;
	//scanf("%d",&i);
	//printf("%.2f\n",sqrt(i));
	for(i = 101; i < 201; i++){
		j = (int)sqrt(i);
		for(k = 2; k <= j; k++){
			if(i % k == 0)
				break;
		}
		if(k == j+1){	
			printf("%d  ",i);
			sum += i; 
		}
	}
	puts("");
	printf("sum = %d\n",sum);
	return 0;
}
