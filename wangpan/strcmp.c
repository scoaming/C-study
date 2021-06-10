#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
	char a[50] = "hello";
	char b[50] = "hsd";

	int ret = strcmp(a, b);

	printf("ret = %d\n", ret);


	return 0;
}
