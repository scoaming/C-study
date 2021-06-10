#include<stdio.h>
#include<string.h>
int main()
{
	int i, n;
	char a[20] = {0};
	gets(a);
	/*for(i = 0;i < 20;i++){
	scanf("%c",&a[i]);
	}*/
	//scanf("%s",&a);
	n = strlen(a);
	//n = sizeof(a) / sizeof(char);
	for(i = n-1;i >= 0;i--)
			putchar(a[i]);
		
	
	puts("");

	return 0;
}
