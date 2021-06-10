#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20
typedef struct student{
	int no;
	char name[N];
	float score;
}Stu;

Stu * get_info() {
	Stu * p;

	if((p = (Stu *)malloc(sizeof(Stu))) == NULL) {
		printf("malloc failed\n");
		return NULL;
	}

	p->no = 1;
	strcpy(p->name,"TOM");
	p->score = 90;

	return p;
}

int main(int argc, const char *argv[])
{
	Stu * s;

	if ((s = get_info()) == NULL) {
		return 0;
	}
	printf("Student info:\n%d %s %.2f\n",s->no, s->name, s->score);
	free(s);
	s = NULL;

	return 0;
}
