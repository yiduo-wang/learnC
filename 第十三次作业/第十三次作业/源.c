#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int IsEven(int x)
{
	if (x % 2 == 0)
		return 1;
	else
		return 0;
}

void Reverse_Odd_Even_Num(int* arr, int size)
{
	for (int j = size-1; j > 0; --j)
	{
		for (int i = 0; i < j; ++i)
		{
			if (IsEven(arr[i]))
				Swap(&arr[i], &arr[i + 1]);
		}
	}
}
//2.//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。 
//时间复杂度小于O(N);
//数组： 
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
# define ROW 3
# define COL 3

int Have(int x,int arr[ROW][COL])
{
	int r = 0, c = COL - 1;
	int tmp = arr[r][c];
	while (1)
	{
		if (x == tmp)
			return 1;
		else if (x < tmp && c > 0)
			tmp = arr[r][--c];
		else if (x > tmp && r <(ROW-1))
			tmp = arr[++r][c];
		else
			return 0;
	}

}

int main()
{
	int r = 0, c = 0,num=0;
	int arr[ROW][COL] = { 0 };
	printf("请输入一个二维递增数组:\n");
	for (r = 0; r < ROW; ++r)
	{
		for (c = 0; c < COL; ++c)
			scanf("%d", &arr[r][c]);
		printf("\n");
	}
	printf("请输入要找的数:\n");
	scanf("%d", &num);
	if (Have(num,arr))
		printf("%d存在于这个矩阵中\n",num);
	else
		printf("%d不存在于这个矩阵中\n",num);


	//int i = 0;
	//int arr[10] = { 0 };
	//printf("请输入一个数组\n");
	//int size = sizeof arr / sizeof arr[0];
	//int right = size - 1;
	//for (i = 0; i < size; ++i)
	//	scanf("%d", &arr[i]);
	//int left = 0;
	//while (left < right)
	//{
	//	while (arr[left] %2 != 0)
	//		++left;
	//	while (arr[right] %2 ==0)
	//		--right;
	//	Swap(&arr[left], &arr[right]);
	//}
	//for (i = 0; i < size; ++i)
	//		printf("%d ", arr[i]);
	//printf("\n");

	//int i = 0;
	//int arr[10] = {0};
	//int size = sizeof arr / sizeof arr[0];
	//printf("请输入一个数组\n");
	//for(i=0;i<size;++i)
	//	scanf("%d", &arr[i]);
	//Reverse_Odd_Even_Num(arr,size);
	//for(i=0;i<size;++i)
	//	printf("%d ", arr[i]);
	//printf("\n");

	system("pause");
}