#include<stdio.h>
int main()
{
	int num = 0;
	
	FILE *fp;
	while(fp){
		if((fp = fopen("test.txt","w+")) == NULL){
			perror("fopen");
			//return -1;
		}
		else{
			num += 1;		
		}
	}
	printf("number of open : %d\n",num);
	return 0;
}
