//3.在屏幕上打印杨辉三角。 
//1
//1 1
//1 2 1
//1 3 3 1


#include<stdio.h>
#include<stdlib.h>

#define N 11

int main()
{
	int arr[N][N];
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			arr[i][0] = 1;
			arr[i][i] = 1;

		}
	}
	for (i = 2; i < N; ++i)
	{
		for (j = 1; j < i; ++j)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	}
	for (i = 0; i < N; ++i)
	{
		//for (j = 0; j <=2*(N - i); ++j)
			//printf(" ");
		for (j = 0; j <= i; ++j)
			printf("%-3d ", arr[i][j]);
		printf("\n");
	}
	system("pause");
}