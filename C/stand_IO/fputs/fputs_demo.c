#include<stdio.h>
int main(int argc, char *argv[])
{
	puts("Good moring!");

	FILE *fp;
	char buf[] = "Hello World!\n";
	if((fp = fopen(argv[1],"a")) == NULL){
		perror("fopen");
		return -1;
	}
	fputs(buf,fp);
	return 0;
}
