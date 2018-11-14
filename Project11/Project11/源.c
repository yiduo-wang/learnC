#include<stdio.h>
#include<stdlib.h>

//void Swap(int* x, int* y)
//{
//	if (*x < *y)
//	{
//		int tmp = *x;
//		*x = *y;
//		*y = tmp;
//	}
//}

//void Bubblesort(int* arr, int size)
//{
//	int bound = 0;
//	for (; bound < size; bound++)
//	{
//		int cul = size-1;
//		for (; cul>bound; cul--)
//		{
//			if (arr[cul] < arr[cul - 1])
//			{
//				Swap(&arr[cul], &arr[cul - 1]);
//			}
//		}
//	}
//}

void Swap(int* x, int* y)
{
	if (*x > *y)
	{
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
}

void Bubblesort(int* arr, int size)
{
	int bound = size - 1;
	for (; bound > 0; bound--)
	{
		int cul = 0;
		for (; cul < bound; cul++)
		{
			if (arr[cul]>arr[cul + 1])
				Swap(&arr[cul], &arr[cul + 1]);
		}
	}
}

int main()
{
	int arr[] = { 3,1,7,5,8,9,0,2,4,6};
	int size = sizeof(arr) / sizeof(arr[0]);
	Bubblesort(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}

	//int arr[3][4] = { 0 };
	//for (int row = 0; row < 3; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		arr[row][col] = row * 4 + col;
	//	}
	//}
	//for (int row = 0; row < 3; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		printf("%d\t", arr[row][col]);
	//	}
	//	printf("\n");
	//}
	
	//int arr[3][4] =
	//{
	//	{ 1, 2 }, { 3, 4 }
	//

	//};
	//for (int row = 0; row < 3; row++)
	//{
	//	for (int col = 0; col < 4; col++)
	//	{
	//		printf("%p\t", &arr[row][col]);
	//	}
	//	printf("\n");
	//}

	//int a = 100; 
	//int arr[10] = { 0 };
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%p\n", &arr[i]);
	//}
	//printf("%p\n", &a);
	//printf("%p,%d\n", &arr[12], arr[12]);
 //   arr[12] = 200;
	//printf("%d\n", a);
	system("pause");
}