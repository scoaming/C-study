#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char ID[16]={"001"};
	char pw[32]={"yyds"};
	char ac[16]={0};
	char cd[32]={0};
	int x;
	int y;
	printf("欢迎登陆！\n");
	printf("请输入帐号：\n");
	scanf("%s",ac);
	x=strcmp(ID,ac);
	if(x==0)
	{
		printf("请输入密码：\n");
		scanf("%s",cd);
		y=strcmp(pw,cd);
		if(y==0)
		{
			printf("欢迎进入！\n");
		}
		else
		{
			printf("密码错误！\n");
		}
	}
	else
	{
		printf("帐号错误！\n");
	}

	return 0;
}
