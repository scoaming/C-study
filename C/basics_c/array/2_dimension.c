#include<stdio.h>
int main()
{
	int a[3][4] = { {21,41,22,11},{42,51,61,77},{12,93,73,25} };
	int i, j, x, y;
	//int t;
	x = y = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			if(a[x][y]<a[i][j]){
				x = i;
				y = j;
			}
		}
	}		
	/*t=a[0][0];

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(a[i][j+1] > t){

				t = a[i][j+1];
				x = i+1;
				y = j+2;
			}
		}
	}*/
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			printf("%5d ",a[i][j]);
		putchar('\n');
	}

	printf("Max = %d line: %d column: %d\n",a[x][y],x+1,y+1);
	//printf("Max=%d\nline:%d column:%d\n",t,x,y);
	
	return 0;
}
