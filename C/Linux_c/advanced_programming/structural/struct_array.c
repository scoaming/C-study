#include<stdio.h>
#include<string.h>
#define N 20
struct student{
	int no;
	char name[N];
	float score;
}s2[5];
int main(){
	int i;
	struct student s1[] = {{0, "s0", 100},{1,"s1",90},{2,"s2",99}};
	s2[0] = s1[0];
	s2[1] = s1[1];
	s2[2] = s1[2];
for(i = 0; i < sizeof(s1)/sizeof(struct student); i++)
	printf("%d-%s-%f\n",s1[i].no,s1[i].name,s1[i].score);

for(i = 0; i < sizeof(s2)/sizeof(struct student); i++)
	printf("%d-%s-%f\n",s2[i].no,s2[i].name,s2[i].score);

	
	return 0;
}
