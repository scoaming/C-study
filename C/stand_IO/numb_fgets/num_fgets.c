#include<stdio.h>
#include<string.h>
#define N 6
int main(int argc, char *argv[])
{
	char buf[N];
	int count = 0;
	if(argc < 2){
		printf("usage: %s <filename>\n",argv[0]);
		return 0;
	}

	FILE *fp;
	if((fp = fopen(argv[1],"r")) == NULL){
		perror("fopen");
		return -1;
	}

	while(fgets(buf,N,fp)){

		if(buf[strlen(buf) - 1] == '\n'){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
