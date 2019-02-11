#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp1(const int* a, const int* b)
{
	return *a > *b ? 1 : -1;
}

int cmp2(const int* a, const int* b)
{
	return *a > *b ? 1 : -1;
}

int cmp3(const char* a, const char* b)
{
	return strcmp(a, b);//字典序由小到大
	//return strcmp(a,b);//字典序由大到小
}

int cmp4(const double* a, const double* b)
{
	return *a > *b ? 1 : -1;
}

typedef struct structure1
{
	int x;
	int y;
}S1;

int cmp5(const S1* a, const S1* b)
{
	return (*a).x > (*b).x ? 1 : -1;
}

int cmp6(const S1* a, const S1* b)
{
	if ((*a).x == (*b).x)
		return (*a).y > (*b).y ? 1 : -1;
	return (*a).x > (*b).x ? 1 : -1;
}

typedef struct structure2
{
	char name[30];
	int age;
}S2;

int cmp7(const S2* a, const S2* b)
{
	return strcmp((*a).name, (*b).name);
}

int Desc(const int* a, const int* b)
{
	return *a > *b ? 1 : -1;
}

int Asc(const int* a, const int* b)
{
	return *a < *b ? 1 : -1;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

BubbleSort(int* arr, int size, int(*cmp)(const int*, const int*))
{
	int i = 0,j=0;
	for (; i < size - 1; ++i)
	{
		for (j = size-1; j > i; --j)
		{
			if (cmp(&arr[j], &arr[j - 1]) > 0)
				Swap(&arr[j], &arr[j - 1]);
		}
	}
}

int main()
{
	////qsort对一维数组排序(int)
	//int arr[] = { 1,5,3,4,2 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, size, sizeof(int), cmp1);
	//for (int i = 0; i < size; ++i)
	//	printf("%d ", arr[i]);
	//printf("\n");

	////qsort对一维数组排序(double)
	//double arr[] = { 8.34,2.14,5.64,3.14,4.21 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, size, sizeof(arr[0]), cmp4);
	//for (int i = 0; i < size; ++i)
	//	printf("%1.2f ", arr[i]);
	//printf("\n");

	////qsort对二维数组排序(int)
	//int arr[3][3]=
	//{
	//	{2,1,3},
	//	{1,2,4},
	//	{5,3,4}
	//};
	//int size = sizeof(arr) / sizeof(arr[0]);
	//int capacity = sizeof(arr[0]) / sizeof(arr[0][0]);
	//qsort(arr, size, sizeof(int)*capacity, cmp2);
	//for (int row = 0; row < size; ++row)
	//{
	//	for (int col = 0; col < capacity; ++col)
	//		printf("%d ", arr[row][col]);
	//	printf("\n");
	//}

	////qsort对字符串的排序
	//char str[][5] = { "3333","5555","2222","1111" };//str的每一个元素都是字符串所以都有\0
	//int size = sizeof(str) / sizeof(str[0]);
	//qsort(str, size, sizeof(str[0]), cmp3);
	//for (int i = 0; i < size; ++i)
	//	printf("%s\n", str[i]);

	////qsort在结构体中对某个关键字排序(一级排序,以x大小来排序)
	//S1 s[6];
	//int i = 0;
	//for (i = 0; i < 6; ++i)
	//	scanf("%d %d", &s[i].x, &s[i].y);
	//qsort(s, 6, sizeof(S1), cmp5);
	//for (i = 0; i < 6; ++i)
	//	printf("s[%d]={%d,%d}\n", i, s[i].x, s[i].y);

	////qsort在结构体中对多个关键字排序(二级排序,先以x来排序,当x相同时,用y来排序)
	//S1 s[6];
	//int i = 0;
	//for (; i < 6; ++i)
	//	scanf("%d %d", &s[i].x, &s[i].y);
	//qsort(s, 6, sizeof(S1), cmp6);
	//for (i = 0; i < 6; ++i)
	//	printf("s[%d]={%d,%d}\n", i, s[i].x, s[i].y);

	////qsort在结构体中对字符串进行排序
	//S2 s2[5];
	//int i = 0;
	//for (; i < 5; ++i)
	//{
	//	printf("name:");
	//	scanf("%s", &s2[i].name);
	//	printf("age:");
	//	scanf("%d", &s2[i].age);
	//}
	//qsort(s2, 5, sizeof(S2), cmp7);
	//for (i = 0; i < 5; ++i)
	//	printf("s2[%d]={%s,%d}\n", i, s2[i].name, s2[i].age);

	//自制qsort函数(冒泡排序)
	int arr[10];
	printf("请输入你要排序的数字:\n");
	int i = 0;
	for (i = 0; i < 10; ++i)
		scanf("%d ", &arr[i]);
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr,size,Desc);
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	BubbleSort(arr, size, Asc);
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}