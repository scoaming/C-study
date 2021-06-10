#include<stdio.h>

void ch(char *ch,int k);
int main()
{
	char str[] = {"Good boy!"};
	int n;
	n = sizeof(str) / sizeof(char);
	ch(str,n);
	puts(str);
		
	return 0;
}
void ch(char *ch,int k)
{

	int i, a = 0;
	for(i = 0; i < k; i++){
		if(i < k){
			if(*(ch+i) <= 'z' && *(ch+i) >= 'a'){
				a++;
				*(ch+i) -= 32;
			}
		}
	}
	printf("%d\n",a);
					
}
