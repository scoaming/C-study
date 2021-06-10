#include<stdio.h>
#include<math.h>
int main()
{
	int ret,n,i;
	int ch;

	printf("please input a int:");
	while(1){
		ret=scanf("%d",&n);
		if(ret == 0){
			if( (ch = getchar() ) == '#')
				return 0;
			else{
				printf("input error! please input again:");
				continue;
			}
		}

		int tmp = sqrt(n);
		for(i = 2;i <= tmp;i++){
			if(n%i == 0)
				break;
		}
		if(n%i==0)	
			printf("%d not prime number\n",n);
		else
			printf("%d yes prime number\n",n);
	}
	return 0;
}
