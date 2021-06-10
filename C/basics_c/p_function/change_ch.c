#include<stdio.h>

char *itoa(char *p,int n);
int main()
{
	int x;
	char s[50], * a;
	printf("input:");
	scanf("%d",&x);
	a = itoa(s,x);
	puts(s);
	puts(a);
	return 0;
}
char *itoa(char *p,int n)
{
	int r,i = 0,j;
	char t;
	while(n){
		r = n % 10;
		p[i] = r +'0';
		n /= 10;
		i++;
	}
	p[i] = '\0';
	j = i-1;
	i = 0;
	while(i < j){
		t = p[i];
		p[i] = p [j];
		p[j] = t;
		i++;
		j--;
	}
	return p;
}
