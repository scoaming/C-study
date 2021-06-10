#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	if((fp = fopen(argv[1],"w")) == NULL){
		perror("fopen");
		return -1;
	}
	fputc('a',fp);
	fflush(fp);
	while(1);
	return 0;
}
