#include<stdio.h>
int main()
{
	float score;
	printf("Please input score:\n");
	while(1)
	{
		scanf("%f",&score);
		if(! (score>=0 && score<=100) )

			printf("not in [0,100],please input again!\n");
		//else{
			switch((int)score/10){
				case 10:
				case 9:
					printf("A.excellent!\n");
					break;
				case 8:
				case 7:
					printf("B.good!\n");
					break;
				case 6:
					printf("C.OK!\n");
					break;
				default:
					printf("D.not pass!\n");

			}
		//}
	}
	return 0;
}
