#include<stdio.h>
int main()
{
	int score;
	printf("Please enter grades to view the grades:\n");
	while(1)
	{
		scanf("%d",&score);
		if(!(score>=0&&score<=100))
		
			printf("成绩格式输入错误，请重新输入：\n");
		
		else if(score>=90){
		
			printf("成绩为'A'\n");
		}
		else if(score>=70)
		
			printf("成绩为'B'\n");
	
		else if(score>=60)
		
			printf("成绩为'C'\n");
		
		else
		
			printf("成绩为'D'\n");
		
	}
	return;
}

