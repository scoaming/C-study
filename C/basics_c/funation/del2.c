#include<stdio.h>


void fun_del(char *s1, int n);
int main()
{
	char a[] = {"A  B C D"};
	
	puts(a);

	return 0;
}
void fun_del(char *s1, int n)
{	
	char *s2 = s1;
	while(*s1){
		if(*s1 != ' '){
			*s2++ = *s1++;
			//s1++;
			//s2++;
		}
		else
			s1++;
		
	}
	*s2 = '\0';
	
}
