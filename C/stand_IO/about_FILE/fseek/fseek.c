#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1],"r+");
	fseek(fp, 0, SEEK_END);
	fputc('t',fp);
	fclose(fp);
	if((fp = fopen(argv[1],"a+")) == NULL){
		perror("fopen");
		return -1;
	}
	fputc('i',fp);
	fputc('\n',fp);
	
	return 0;
}
