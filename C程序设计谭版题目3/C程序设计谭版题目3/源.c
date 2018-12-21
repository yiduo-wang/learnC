//19.输出菱形(同比特作业)
#include<stdio.h>
#include<stdlib.h>
void Print(int x, int y)
{
	int i = 0;
	for (i = 1; i <= x; ++i)
		printf(" ");
	for (i = 1; i <= 2 * y - 1; ++i)
		printf("*");
}

int main()
{
	int row = 0,height=4,i=0;
	for (row = 1; row < height; ++row)
	{
		Print(height-row, row);
		printf("\n");
	}
	for (i = 1; i <= 2 * height - 1; ++i)
		printf("*");
	printf("\n");
	for (row = height - 1; row >= 1; --row)
	{
		Print(height - row, row);
		printf("\n");
	}
	system("pause");
}

//20.a,b,三人和x,y,z进行比赛,a不和x比,c不和x,z比,请输出比赛名单
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

//21.冒泡排序(从后往前排)(从后往前排)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int* arr, int size)
{
	int i = 0,j=0;
	for (j = size - 1; j > 0; --j)
	{
		for (i = 0; i < j; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	for (i = 0; i < size; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}

void BubbleSort(int* arr, int size)
{
	int i = 0, j = 0;
	for (i = 0; i < size - 1; ++i)
	{
		for (j = size - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[10];
	int i = 0;
	printf("请输入要排序的数字:\n");
	for (i = 0; i < 10; ++i)
		scanf("%d,", &arr[i]);
	int size = sizeof arr / sizeof arr[0];
	BubbleSort(arr, size);
	system("pause");
}

//22.讲一个二维数组的行跟列互换,存到另一个二维数组中  如:a={{1,2,3},{4,5,6}}
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[2][3] = { 1,2,3,4,5,6 };
	int b[3][2];
	int i = 0, j = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			b[j][i] = a[i][j];
	}
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 2; ++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	system("pause");
}

//23.有一个3X4的矩阵,要求编程序求出其中最大的那个元素的值,以及其所在的行号和列号
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[3][4], i=0, j=0, a=0, b=0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			scanf("%d", &arr[i][j]);
	}
	int max = arr[0][3];
	printf("%d\n", arr[0][0]);
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				a = i; b = j;
			}
		}
	}
	printf("最大的元素为:%d\nrow=%d,col=%d\n",max,a,b);
	system("pause");
}

//24.有三个字符串要求找出其中最大者
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[3][30];
	char string[50];
	int i = 0;
	for (i = 0; i<3; ++i)
		gets(str[i]);
	if (strcmp(str[0], str[1]) > 0)
		strcpy(string, str[0]);
	else
		strcpy(string, str[1]);
	if (strcmp(str[2], string) > 0)
		strcpy(string, str[2]);
	printf("最大字符串为:%s\n", string);
	system("pause");
}

//25.求一个3X3的整形矩阵对角线之和
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int arr[3][3],i=0,j=0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
			scanf("%d", &arr[i][j]);
	}
	printf("左对角线的和为:%d\n右对角线的和为:%d\n", arr[0][0] + arr[1][1] + arr[2][2],
		arr[0][2] + arr[1][1] + arr[2][0]);
	system("pause");
}