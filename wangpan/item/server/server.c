#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

void process_list(int rws);
void process_down(int rws,char *filename);
void process_upload(int rws, char *filename);

int main()
{
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in saddr = 
	{
		.sin_family = PF_INET,
		.sin_port = htons(9999),
		.sin_addr.s_addr = INADDR_ANY,
		.sin_zero = {0},

	};
	int s_len = sizeof(saddr);

	int ret = bind(sockfd,(struct sockaddr*)&saddr, s_len);

	ret = listen(sockfd, 5);


	struct sockaddr_in caddr;
	int c_len = sizeof(caddr);

	while(1)
	{
		int rws = accept(sockfd, (struct sockaddr*)&caddr, &c_len);
		if(rws < 0)
		{
			perror("accept");
			return -1;
		}

		char buf[64] = {0};

		read(rws, buf, 64);

		switch(buf[0])
		{
			case 'L':
				process_list(rws); break;
			case 'D':
				process_down(rws,buf+2); break;
			case 'U':
				process_upload(rws,buf+2); break;
		}




		close(rws);
	}		

	close(sockfd);
	return 0;
}


void process_list(int rws)
{
	char buf[64] = {0};
	DIR *dir = opendir(".");
	struct dirent *ent;
	if(dir == NULL)
	{
		strcpy(buf, "Fail");
		write(rws, buf, strlen(buf));
		return;
	}
	else
	{
		strcpy(buf, "OK");
		write(rws, buf, sizeof(buf));

		while((ent = readdir(dir)) != NULL)
		{
			memset(buf, 0 ,sizeof(buf));
			if(ent->d_name[0] != '.')
			{
				strcpy(buf, ent->d_name);
				write(rws, buf, strlen(buf));
				usleep(1000);
			}

		}
		return;

	}

}
void process_down(int rws, char *filename)
{
	printf("%s\n",filename);
	char buf[64]={0};
	int fd=open(filename,O_RDONLY);
	if(fd<0)
	{
		perror("open");
		strcpy(buf,"NO");
		write(rws,buf,strlen(buf));
		return;
	}
	else
	{

		strcpy(buf,"YES");

		write(rws,buf,sizeof(buf));
		while(1)
		{
			memset(buf,0,sizeof(buf));
			int ret=read(fd,buf,64);
			if(ret<=0)
			{
				break;
			}
			write(rws,buf,ret);
			usleep(1000);
		}	
		printf("down successful!\n");
		close(fd);
		return;
	}
}
void process_upload(int rws, char *filename)
{
	printf("%s",filename);
	char buf[64]={0};
	int fd=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd<0)
	{
		perror("open");
		strcpy(buf,"Fail");
		write(rws,buf,sizeof(buf));
		return;
	}
	else
	{
		strcpy(buf,"OK");
		write(rws,buf,strlen(buf));
		while(1)
		{
			int ret=read(rws,buf,sizeof(buf));
			if(ret<=0)
			{
				break;
			}
			write(fd,buf,ret);
		}
		printf("upload successful!\n");
		close(fd);
	}
	return;
}
