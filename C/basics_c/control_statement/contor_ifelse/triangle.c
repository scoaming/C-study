#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,p,s;
	printf("**************************************\n");
	printf("*********三角形面积计算小工具*********\n");
	printf("**************************************\n");
	printf("请依次输入三角形的边长（用逗号隔开）：\n");
	while(1)
	{
		scanf("%f,%f,%f",&a,&b,&c);
		if(!((a+b>c&&a+c>b&&b+c>a)&&(a-b<c&&a-c<b&&b-a<c&&b-c<a&&c-a<b&&c-b<a)))
			printf("无法构成三角形，请重新输入：\n");
		else
		{
			p=(a+b+c)/2;
			s=sqrt((double)(p*(p-a)*(p-b)*(p-c)));
			printf("The area of this triangle is：%5.2f\n",s/*sqrt((double)s)*/);
		}
	}
	return;
}
