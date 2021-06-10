#include<stdio.h>
void main()
{
	char x[80]={};
	printf("请输入一组字符串：\n");
	gets(x);
	printf("%s\n",x);
	printf("************\n");
	puts(x);
	
	return ;
}
