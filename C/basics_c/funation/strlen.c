#include<stdio.h>
#include<string.h>
#define N 20
int strle(char a[N]);
int main(){
	int i, r;
	char s[N] = {0};
	gets(s);
	i = strle(s);
	r = strlen(s);
	printf("%d\n%d\n",i,r);
return 0;
}
int strle(char a[N]){
	int i = 0;
	while(a[i]){
		++i;
	}
	return i;
}
