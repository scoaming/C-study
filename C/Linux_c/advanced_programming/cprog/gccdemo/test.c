#include<stdio.h>
#include<math.h>

#define N 10
#define _DEBUG_

int main(int argc, const char *argv[])
{
	double m = 615, n;

	m += N;
	n = sqrt(m);

#ifdef _DEBUG_
	printf("debug:m=%lf n=%lf\n", m, n);
#else
	printf("release:m=%lf n=%lf\n", m, n);
#endif

	return 0;
}
