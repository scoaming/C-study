#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define N 64

int main(int argc, char *argv[])
{
	int fds, fdt, n;
	char buf[N];

	if(argc < 3){
		printf("Usages: %s <src_file> <dst_file>\n",argv[0]);
		return -1;
	}
	
	if((fds = open(argv[1], O_RDONLY)) == -1){
		fprintf(stderr, "open %s : %s\n",argv[1], strerror(errno));
		return -1;
	}

	if((fdt = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1){
		fprintf(stderr, "open %s : %s\n",argv[2], strerror(errno));
		return -1;
	}
	
	while((n = read(fds, buf, N)) > 0){
		write(fdt, buf, n);
	}
	close(fds);
	close(fdt);

	return 0;
}
