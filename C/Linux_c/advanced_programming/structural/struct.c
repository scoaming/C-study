#include<stdio.h>
#include<string.h>
#define N 20
struct student{
	int no;
	char name[N];
	struct {
		int year;
		int moth;
		int day;
	}birthday;
	float score;
};

int main()
{
	struct student s1;
		s1.no = 006;
		strcpy(s1.name, "UZI");
		s1.birthday.year = 1997;
		s1.birthday.moth = 10;
		s1.birthday.day = 27;
		s1.score = 99;
	
	printf("%d,%s,%d-%d-%d,%.2f\n",s1.no,s1.name,s1.birthday.year,s1.birthday.moth,s1.birthday.day,s1.score);
return 0;
}
