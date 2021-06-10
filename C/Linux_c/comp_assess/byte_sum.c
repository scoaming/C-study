#include<stdio.h>
int main()
{
	unsigned int a = 0x12345678;
	char * p = (char *)&a;
	int i = 0, sum = 0;

	for(i = 0; i < sizeof(int); i++)
		sum += *p++;

	printf("sum = %#x\n",sum);
	return 0;
}
