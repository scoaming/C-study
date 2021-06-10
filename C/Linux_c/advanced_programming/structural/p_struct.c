#include<stdio.h>
#define N 20
struct student {
	int no;
	char name[N];
	struct{
		int year;
		int moth;
		int day;
	}data;
	float score;
};

void printf_into(struct student * p,int n){
	int i;
	for(i = 0; i < n; i++) {
		printf("---%d,%s,%d-%d-%d,%.2f---\n",(p+i)->no,(p+i)->name,(p+i)->data.year,p[i].data.moth,p[i].data.day,(p+i)->score);
	}
}

int main(){

	struct student s1[] = {{0,"U",1997,4,5,98}, {0,"Z",1997,4,5,99}, {6,"I",1997,4,5,100}};
	printf_into(s1, sizeof(s1)/sizeof(s1[0]));
return 0;
}
