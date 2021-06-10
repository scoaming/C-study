#include <stdio.h>
#include <string.h>

int main ()
{
	char src[50], dest[50];

	strcpy(src,  "This is source");
	strcpy(dest, "This is destination");

	strcat(dest, src);

	printf("最终的目标字符串： |%s|", dest);

	return(0);
}
