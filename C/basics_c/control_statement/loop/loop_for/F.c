#include<stdio.h>
int main()
{
	int i,j;
	char ch;
	printf("Please input char:");
	scanf("%c",&ch);
	for(i=0;i<=ch-'A';i++){
		for(j=0;j<i;j++)
			printf("_");
		for(j=0;j<=i;j++)
			printf("%c",ch-j);
		//printf("\n");
		//puts("");
		putchar('\n');
	}
	return 0;
}
