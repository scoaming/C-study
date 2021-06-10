#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int fd1=open("1.txt",O_RDONLY,0644);
	if(fd1<0)
	{
		perror("open 1.txt");
		return -1;
	}
	int fd2=open("2.txt",O_WRONLY,0664);
    if(fd2<0)
	{
		perror("open 2.txt");
		return -1;
	}
	char buf[64]={0};
	int rd=0;		
	while(1)
	{
	rd=read(fd1,buf,64);
	if(rd<=0)
	{		
		break;
	}
	rd=write(fd2,buf,rd);
	if(rd<0)
	{
		perror("write");
	}

	}
	close(fd1);
	close(fd2);
	return 0;
} 
