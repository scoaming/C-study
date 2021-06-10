#include<stdio.h>
int main()
{
	int i,n = 4,x;
	char a[10] = "abcdefg";
	char b[10] = "abcDefg";
	char *p,*q;
	p = a;
	q = b;
	for(i = 0; i < n; i++){
		if(p[i] > q[i]){
			x  = p[i] - q[i];
			break;
		}
		if(p[i] < q[i]){
			x  = p[i] - q[i];
			break;
		}
		if(p[i] == q[i]){
			x = 0;
		}
	}
	printf("%d\n",x);
return 0;	
}
