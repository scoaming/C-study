#include<stdio.h>
int main()
{
	char a[100] = "Welcome to ";
	char *q, *p = "LAN ZHOU!";
	q = p;
	int i = 0;

	while(*(a+i) != '\0'){
		i++;
	}		
	while(*p != '\0'){
		a[i] = *p++;
		i++;
		//p++;
	}
	*(a+i) = *p;
	p = q;
	puts(a);
	puts(p);
	return 0;
}
