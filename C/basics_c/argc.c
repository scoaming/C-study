#include <stdio.h>
//using namespace std;
 
int main(int argc, char ** argv)
{
	    int i;
		    for (i = 0; i < argc; i++)
				        printf("Argument %d is %s\n", i, argv[i]);
			printf("%d\n",argc);    
			return 0;
}
