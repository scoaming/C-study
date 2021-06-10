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

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("sockfd");
		return -1;
	}

	struct sockaddr_in saddr = 
	{
		.sin_family = PF_INET,
		.sin_port = htons(9999),
		.sin_addr.s_addr = inet_addr("192.168.43.216"),
		.sin_zero = {0},
	};
	int s_len = sizeof(saddr);
	int ret = connect(sockfd, (struct sockaddr*)&saddr, s_len);
	if(ret < 0)
	{
		perror("connect");
		return -1;
	}

	printf("link successful!\n");
	char buf[64] = {0};
	scanf("%s",buf);
	ret=write(sockfd,buf,strlen(buf));
	if(ret<0)
	{
		perror("write");
		return -1;
	}
	while(1)
	{
		ret=read(sockfd,buf,64);
		if(ret<0)
		{
			break;
		}
		printf("%s\n",buf);
	}




	close(sockfd);
	return 0;
}

