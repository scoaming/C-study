#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
void get_list(struct sockaddr_in saddr);
void get_down(struct sockaddr_in saddr,char *filename);
void get_upload(struct sockaddr_in saddr,char *filename);
int main()
{

	struct sockaddr_in saddr = 
	{
		.sin_family = PF_INET,
		.sin_port = htons(9999),
		.sin_addr.s_addr = inet_addr("172.27.35.20"),
		.sin_zero = {0},
	};


	char cmd[64] = {0};

	//打印操作提示信息
	puts("======================================================");
	puts("1、list  2、down filename  3、upload filename  4、quit");
	puts("======================================================");

	while(1)
	{
		puts("input cmd >>>");
		gets(cmd);

		switch(cmd[0])
		{
			case 'l':
				get_list(saddr); break;
			case 'd':
				get_down(saddr,cmd+5); break;
			case 'u':
				get_upload(saddr,cmd+7); break;

		}

	}

	return 0;
}

void get_list(struct sockaddr_in saddr)
{
	char buf[64] = "L";
	int s_len = sizeof(saddr);
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);


	int ret = connect(sockfd, (struct sockaddr*)&saddr, s_len);


	write(sockfd, buf, strlen(buf));
	ret=read(sockfd, buf, 64);
	if(strncmp(buf,"OK",2)==0)
	{
		puts("********************************");
		while(1)
		{
			memset(buf, 0, sizeof(buf));
			ret = read(sockfd, buf, 64);
			if(ret <= 0)
			{
				break;
			}
			printf("%s\n", buf);
		}
		puts("*********************************");

		close(sockfd);

	}
	else
	{
		printf("get list error\n");
		close(sockfd);
	}

}
void get_down(struct sockaddr_in saddr,char *filename)
{
	int fd=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd<0)
	{
		perror("open");
		return;
	}

	int s_len = sizeof(saddr);
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd<0)
	{
		perror("socket");
		return ;
	}
	int ret = connect(sockfd, (struct sockaddr*)&saddr, s_len);
	if(ret<0)
	{
		perror("connect");
		return;
	}
	char buf[64] ={0};
	sprintf(buf, "D %s", filename);
	ret=write(sockfd,buf,strlen(buf));
	if(ret<0)
	{
		perror("write");
		return;
	}
	read(sockfd,buf,64);
	if(strncmp(buf,"YES",3)==0)

	{

		while(1)
		{
			memset(buf,0,64);
			ret=read(sockfd,buf,64);
			//printf("ret=%d\n",ret);
			if(ret<=0)
			{
				break;
			}
			else
			{
				write(fd,buf,ret);
			}
		}
		printf("down successful!\n");
		close(fd);
		close(sockfd);
		return;

	}
	else
	{
		printf("recive error\n");
		close(fd);
		close(sockfd);
		return;
	}
}
void get_upload(struct sockaddr_in saddr,char *filename)
{
	int fd = open(filename, O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}

	int s_len = sizeof(saddr);
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd<0)
	{
		perror("socket");
		return ;
	}
	int ret = connect(sockfd, (struct sockaddr*)&saddr, s_len);
	if(ret<0)
	{
		perror("connect");
		return;
	}
	char buf[64] ={0};
	sprintf(buf,"U %s",filename);
	write(sockfd,buf,sizeof(buf));
	read(sockfd,buf,64);
	if(strncmp(buf,"OK",2)==0)
	{
		while(1)
		{
			memset(buf, 0, 64);
			ret=read(fd,buf,64);
			if(ret<=0)
			{
				break;
			}
			write(sockfd,buf,ret);
			usleep(1000);
		}
		printf("upload successful!\n");
		close(fd);
		close(sockfd);
		return;
	}
	else
	{
		printf("fail to upload!\n");
		close(fd);
		close(sockfd);
		return;
	}
}
