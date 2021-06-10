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

int main()
{
	/*************** 创建套接字 ***************/
	int sockfd = socket(PF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("socket");
		return -1;
	}
	printf("success! socketfd=%d\n",sockfd);

	/**************** 建立连接*********************/

	struct sockaddr_in saddr=
	{
		.sin_family=PF_INET,
		.sin_port=htons(8888),
		.sin_addr.s_addr=inet_addr("192.168.43.216"),
		.sin_zero={0},
	};
	int s_len=sizeof(saddr);
	int ret=connect(sockfd,(struct sockaddr*)&saddr,s_len);
	if(ret<0)
	{
		perror("connect");
		return -1;
	} 
	printf("link stccessful!\n");

	/****************传输数据*******************/

	char buf[64]={0};
	int fd = open("1.txt", O_RDONLY, 0664);
	if(fd < 0)
	{
		perror("open 1.txt");
		return -1;
	}
	while(1)
	{
		ret = read(fd, buf, 64);
		if(ret <= 0)
		{
			break;
		}
		printf("%s\n",buf);
		ret = write(sockfd, buf, ret);
	}
	close(fd);

	return 0;
}

