#include<stdio.h>
char * f_cat(char * x, char * y);
int main()
{
	char * r;
	char a[100] = {"Welcome to "};
	char b[] = {"YIN CHUAN!"};
	r = f_cat(a,b);
	puts(a);
	puts(b);
	puts(r);

	return 0;
}
char * f_cat(char * x, char * y)
{	
	char *p = y;
	int i;
	while(*(x+i)){
		i++;
	}
	while(*y){
		*(x+i) = *y++;
		i++;
	}
	*(x+i) = *y;
	y = p;
	return x;
	//printf("%d\n",i);
}
