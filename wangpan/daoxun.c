#include<stdio.h>
int main()
{
	int i;
	int num;
	char a[50]={0};
	sacanf("%s",a);
	for(i=0,i<50,i++)
	{
		if(a[i]==/0)
		{	
			break;
		}
		printf("num=%d\n",i)
	}

	return 0;
}
