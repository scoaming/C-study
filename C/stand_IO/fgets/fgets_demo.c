#include<stdio.h>
#define N 20
int main(int argc, char *argv[])
{
	char buf[N];
	fgets(buf,N,stdin);
	printf("%s\n",buf);
	return 0;
}
