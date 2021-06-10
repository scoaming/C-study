#include<stdio.h>
int main()
{
	printf("欢迎进入猜硬币小游戏!\n");
	printf("游戏规则：'1'--正面 '0'--反面 '-1'-- 退出游戏!\n");
	int num;
	int i;
	scanf("%d",&i);
	srand((unsigned)time(NULL));
	while(i!=-1)
	{
	num=rand()%2;
	printf("num=%d/n\n",num);
		if(i==num)
		{
			printf("You are right!\n");
		}
		else
		{
			printf("error!\n");
		}
		scanf("%d",&i);
	}
	printf("33!");
	return 0;
}
