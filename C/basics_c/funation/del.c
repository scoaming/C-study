#include<stdio.h>


void fun_del(char *ch, int n);
int main()
{
	char a[] = {"A  B C D"};
	
	puts(a);
	fun_del(a,sizeof(a)/sizeof(char));
	puts(a);

	return 0;
}
void fun_del(char *ch, int n)
{
	int i = 0, t;
	while(*(ch+i)){
		if(*(ch+i) == ' '){
			n--;
			t = i;
			for(i = i; i < n; i++)
				*(ch+i) = *(ch+i+1);
			i = t-1;
		}
	i++;
	}
}
