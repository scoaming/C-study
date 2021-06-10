/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：server.c
*   创 建 者：zhouh
*   创建日期：2020年12月08日
*   描    述：
*
*   更新日志：
*
================================================================*/
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
	/************** 创建套接字 *************/
	int sockfd = socket(PF_INET, SOCK_STREAM, 0); //选择的是internet协议以及流式套接字
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	printf("success! sockfd = %d\n", sockfd);
	
	/************* 绑定本机地址和端口号 ***************/

	struct sockaddr_in saddr = {
		.sin_family = PF_INET,
		.sin_port = htons(8888),
		//.sin_addr.s_addr = inet_addr("192.168.43.216"),
		.sin_addr.s_addr = INADDR_ANY,
		.sin_zero = {0},
	};
	int s_len = sizeof(saddr);

	int ret = bind(sockfd, (struct sockaddr *)&saddr, s_len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}

	/*************** 设置监听套接字 ******************/

	ret = listen(sockfd, 5);
	if(ret < 0)
	{
		perror("listen");
		return -1;
	}

	/************** 等待客户端连接 *******************/

	struct sockaddr_in caddr;
	int c_len = sizeof(caddr);

	printf("wait for a new client...\n");

	while(1)
	{
		int rws = accept(sockfd, (struct sockaddr*)&caddr, &c_len);
		if(rws < 0)
		{
			perror("accept");
			return -1;
		}

		printf("link successful!\n");

		/*************** 传输数据 **********************/
		char buf[64]={0};
		while(1)
		{
			memset(buf,0,sizeof(buf));
			ret=read(rws,buf,64);
			if(ret<0)
			{
				perror("read");
				return -1;
			}
			if(ret==0)
			{
				printf("此客户端已结束\n");
				break;
			}
			printf("recv%dbytes:%s\n",ret,buf);
		}
		close(rws);
	}
	close(sockfd);

	return 0;
}
