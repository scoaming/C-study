#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
int main()
{
	char a[50] = "hello";
	char b[20] = "asd";


	strcpy(a, b);

	printf("%s\n", a);



	return 0;
}

