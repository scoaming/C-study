#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dp;
	
	if(argc < 2){
		printf("Usage: %s <directory>\n", argv[0]);
		return -1;
	}

	if((dirp = opendir(argv[1])) == NULL ){
		perror("opendir");
		return -1;
	}
	
	while((dp = readdir(dirp)) != NULL){
		printf("%s\n", dp->d_name);
	}
	closedir(dirp);

	return 0;
}
