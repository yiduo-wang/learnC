//19.输出菱形(同比特作业)
//#include<stdio.h>
//#include<stdlib.h>
//void Print(int x, int y)
//{
//	int i = 0;
//	for (i = 1; i <= x; ++i)
//		printf(" ");
//	for (i = 1; i <= 2 * y - 1; ++i)
//		printf("*");
//}
//
//int main()
//{
//	int row = 0,height=4,i=0;
//	for (row = 1; row < height; ++row)
//	{
//		Print(height-row, row);
//		printf("\n");
//	}
//	for (i = 1; i <= 2 * height - 1; ++i)
//		printf("*");
//	printf("\n");
//	for (row = height - 1; row >= 1; --row)
//	{
//		Print(height - row, row);
//		printf("\n");
//	}
//	system("pause");
//}

//20.a,b,三人和x,y,z进行比赛,a不和x比,c不和x,z比,请输出比赛名单
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a, b, c;
//	for (a = 'x'; a <= 'z';++a)
//	{
//		for (b = 'x'; b <= 'z'; ++b)
//		{
//			for (c = 'x'; c <= 'z'; ++c)
//			{
//				if (a != 'x'&&c != 'x'&&c != 'z')
//				{
//					if(a != b && a!=c && b !=c)
//						printf("a vs %c\nb vs %c\nc vs %c\n",a,b,c);
//				}
//			}
//		}
//	}
//	system("pause");
//}

//21.冒泡排序(从后往前排)(从后往前排)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//void BubbleSort(int* arr, int size)
//{
//	int i = 0,j=0;
//	for (j = size - 1; j > 0; --j)
//	{
//		for (i = 0; i < j; ++i)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < size; ++i)
//		printf("%d ",arr[i]);
//	printf("\n");
//}

//void BubbleSort(int* arr, int size)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < size - 1; ++i)
//	{
//		for (j = size - 1; j > i; --j)
//		{
//			if (arr[j] < arr[j - 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < size; ++i)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	printf("请输入要排序的数字:\n");
//	for (i = 0; i < 10; ++i)
//		scanf("%d,", &arr[i]);
//	int size = sizeof arr / sizeof arr[0];
//	BubbleSort(arr, size);
//	system("pause");
//}

//22.
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c;
	for (a = 'x'; a <= 'z';++a)
	{
		for (b = 'x'; b <= 'z'; ++b)
		{
			for (c = 'x'; c <= 'z'; ++c)
			{
				if (a != 'x'&&c != 'x'&&c != 'z')
				{
					if(a != b && a!=c && b !=c)
						printf("a vs %c\nb vs %c\nc vs %c\n",a,b,c);
				}
			}
		}
	}
	system("pause");
}