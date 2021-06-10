#include<stdio.h>
int main()
{
	//char s[] = "abc de fg";
	char s[50] = {0};
	printf("input have blank space string:\n");
	gets(s);
	char a[50] = {0};
	int i = 0, j = 0;

	while(s[i]){

		if(s[i]!=' ')
			a[j++] = s[i];
		i++;
	}
	a[j] = '\0';
	//printf("%s\n",a);
	puts(a);
	return 0;
}
