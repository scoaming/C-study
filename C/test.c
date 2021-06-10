#include <stdio.h>  
int main() {
  	unsigned int x = 0x12345678;  
	char *p = (char *)&x;  
	int i = 0;  int sum = 0;   
	for(i = 0; i < sizeof(int); i++)  
	{   
		sum += *p++;   
	}   
	printf("sum = %#x\n",sum); 
	return 0;  
}
	
