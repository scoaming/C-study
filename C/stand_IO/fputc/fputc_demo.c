#include<stdio.h>
int main(int argc, char *argv[])
{
	fputc('b',stdout);
	putchar('\n');

	FILE *fp;
	int ch;
	if((fp = fopen(argv[1],"w")) == NULL){
		perror("fopen");
		return -1;
	}
	for(ch = 'a'; ch <= 'z'; ch++)

		fputc(ch,fp);

	return 0;
}

