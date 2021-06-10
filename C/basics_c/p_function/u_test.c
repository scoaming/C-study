#include<stdio.h>
#define N 50
char *scat(char * a, char *b);
int main(){
	char x[N] = {0}, y[N] = {0};
	gets(x);
	gets(y);
	char *p = scat(x,y);
	puts(p);
	puts(x);
	puts(y);
	return 0;
}
char *scat(char a[N], char b[N]){
	int i = 0, r = 0;
	while(a[i]){
		i++;
	}
	while(b[r]){
		a[i] = b[r];
		i++;
		r++;
	}
	a[i] = b[r];
	return a;
}
