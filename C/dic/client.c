#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32


typedef struct {
	int type;
	char name[N];
	char data[256];
}MSG;

int main(int agrc, const char *argv[])
{
	int socket;
	struct sockaddr_in serveraddr;
	int n;
	MSG msg;

	if(argc != 3)
	{
		printf("Usages:%s serverip port.\n", argv[0]);
		return -1;
	}

	if((sockfd = socket(AF_INET, SOCK_STEAM, 0)) < 0)
	{
		perror("fail to socket.\n");
		return -1;
	}

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons(atoi(argv[2]));

	if(connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
	{
		perror("fail to connect");
		return -1;
	}

	while(1)
	{
		printf("************************************************\n");
		printf("*   1.register   2.login      3.quit           *\n");
		printf("************************************************\n");
		printf("Please choose:");
		scanf("%d", &n);
		getchar();

		switch(n)
		{
		case 1:
			do_register(sockfd, &msg);
			break;
		case 2:
			if(do_login(sockfd, &msg) == 1)
			{
				goto next;
			}
			break;
		case 3:
			close(sockfd);
			exit(0);
			break;
		default:
			printf("Invalid data cmd.\n");
		}
	}
next:
	while(1)
	{
		printf("************************************************\n");
		printf("*1.querry_word   2.history_record    3.quit    *\n");
		printf("************************************************\n");
		printf("Please choose:");
		scanf("%d", &n);
		getchar();

		switch(n)
		{
			case 1:
				do_query(sockfd, &msg);
				break;
			case 2:
				do_history(sockfd, &msg);
				break;
			case 3:
				close(sockfd);
				exit(0);
				break;
			default:
				printf("Invalid data cmd.\n");
		}
	}

	return 0;
}
