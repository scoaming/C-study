#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	if((fp = fopen(argv[1],"r+")) == NULL){
		perror("fopen");
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	printf("length is %ld\n",ftell(fp));
	return 0;
}
