#include <stdio.h>
#include <unistd.h> //sleep
#include <time.h> //time /localtime
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int line = 0;
	char buf[64];
	time_t t;
	struct tm *tp;

	if(argc < 2){
		printf("Usages: %s <file>\n",argv[0]);
		return -1;
	}

	if ((fp = fopen(argv[1],"a+")) == NULL){
		perror("fopen");
		return -1;
	}

	while (fgets(buf, 64, fp) != NULL){
	
		if (buf[strlen(buf)-1] == '\n')
			line++;
	}

	while(1){
		time(&t);
		tp = localtime(&t);
		fprintf(fp, "%02d, %d-%02d-%02d %02d:%02d:%02d\n",++line, tp->tm_year+1900, 
				tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
		fflush(fp);
		sleep(1);
	}


	return 0;
}
