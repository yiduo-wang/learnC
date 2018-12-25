//38.Hanoi(汉诺)塔问题.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Hanoi(int m,char A,char B,char C)
{
	if (m == 1)
		printf("%c->%c\n", A, C);
	else
	{
		Hanoi(m - 1, A, C, B); 
		printf("%c->%c\n", A, C);
		Hanoi(m - 1, B, A, C);
	}
}

int main()
{
	int m = 3;
	printf("转移%d个盘子的过程为:\n", m);
	Hanoi(m, 'A', 'B', 'C');
	system("pause");
}

//39.输入10个数字,要求输出最大的元素和该数是第几个元素
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10

void Max(int* arr, int x)
{
	int i = 0,j=0;
	int m = arr[0];
	for (i = 0; i < x; ++i)
	{
		if (m < arr[i])
		{
			m = arr[i];
			j = i;
		}
	}
	printf("最大的元素为:%d\n是第%d个数\n", m, j+1);
}

int main()
{
	int arr[N],i=0;
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	Max(arr, N);
	system("pause");
}

//40.有一个数组,求其平均数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10

void Avg(int* arr, int x)
{
	int i = 0;
	float sum = 0;
	for (i = 0; i < N; ++i)
		sum += arr[i];
	printf("%.2f\n", sum / N);
}

int main()
{
	int arr[N];
	int i = 0;
	for (i = 0; i < N; ++i)
		scanf("%d",&arr[i]);
	Avg(arr, N);
	system("pause");
}

//41.冒泡排序(找最小,从前往后排)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10

void BubbleSort(int* arr, int x)
{
	int i = 0,j=0;
	for (i = 0; i < N - 1; ++i)
	{
		for (j = N - 1; j > i; --j)
		{
			if (arr[j] < arr[j-1])
			{
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}	
	
}

int main()
{
	int arr[N],i=0;
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	BubbleSort(arr, N);
	for (i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}

//42.有一个3X4的矩阵,求所有元素的最大值
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 4

int main()
{
	int arr[ROW][COL];
	int row = 0,col=0;
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
			scanf("%d", &arr[row][col]);
	}
	int max = arr[0][0];
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
		{
			if (max < arr[row][col])
				max = arr[row][col];
		}
	}
	printf("最大的元素为:%d\n", max);
	system("pause");
}

//43.利用static输出1-5的阶乘
#include<stdio.h>
#include<stdlib.h>

int Factorial(int i)
{
	static int f = 1;
	 return f *= i;
}

int main()
{
	int i=0;
	for (i = 1; i <= 5; ++i)
		printf("%d!=%d\n", i,Factorial(i));
	system("pause");
}

//44.写一个函数,使得3X3的二维整形数组达到行列互换
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

void Transpose(int arr[ROW][COL])
{
	int row = 0, col = 0;
	int arr1[ROW][COL];
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
			arr1[row][col] = arr[col][row];
	}
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
			arr[row][col] = arr1[row][col];
	}
}

int main()
{
	int row, col;
	int arr[ROW][COL];
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
			scanf("%d", &arr[row][col]);
	}
	Transpose(arr);
	for (row = 0; row < ROW; ++row)
	{
		for (col = 0; col < COL; ++col)
			printf("%d ", arr[row][col]);
		printf("\n");
	}
	system("pause");
}

