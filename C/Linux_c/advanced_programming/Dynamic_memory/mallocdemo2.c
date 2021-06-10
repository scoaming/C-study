#include<stdio.h>
#include<stdlib.h>

char * get_string() {
	//char s[] = "welcome";
	//static char s[] = "welcome";
	//char * s = "welcome";
	char * s;
	
	s = (char *)malloc(10 * sizeof(char));
	if (s == NULL) {
		printf("malloc failed\n");
		return 0;
	}
	
	printf("input:");
	scanf("%s",s);
	printf("s=%s\n",s);
	
	return s;
}
int main(int argc, const char *argv[])
{
	char * p;

	p = get_string();
	printf("%s\n",p);
	free(p);
	p = NULL;

	return 0;
}
