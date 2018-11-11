#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"БъЭЗ.h"

int Max(int x, int y)
{
	return(x > y) ? (x) : (y);
}

void swap1(int x,int y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void swap2(int*x,int*y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int Prime(int n)
{
	int i = 0;
	if (n == 2)
		return 1;
	if (n == 1)
		return 1;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

//int Leap(int i)
//{
//	if (i % 100 == 0)
//	{
//		if (i % 400 == 0)
//			return 1;
//		return 0;
//	}
//	if (i % 4 == 0)
//		return 1;
//	return 0;
//}

int Binarysearch(int* arr, int to_find, int left, int right)
{
	int mid = 0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (to_find < arr[mid])
			right = mid - 1;
		else if (to_find>arr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

//void Founc(int* num)
//{
//	++*num;
//}

int main()
//{
//	int i = 0, num=0;
//	for (; i < 10; i++)
//	{
//		Founc(num);
//		printf("%d",num);
//	}

	int arr[] = { 1, 2, 3, 4, 5, 6 ,7,8,9};
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0]))-1;
	printf("%d\n", Binarysearch(arr, 2, left, right));


	//int i = 1000;
	//for (i = 1000; i <= 2000; i++)
	//{
	//	if (Leap(i))
	//	printf("%d\t",i);
	//}	

	//int i = 1;
	//for (; i <= 100; i++)
	//{
	//	if (Prime(i))
	//	printf("%d\n", i);
	//}


	//int a = 10, b = 20;
	//swap1(a, b);
	//printf("swap1:%d,%d\n",a,b);
	//swap2(&a ,&b);
	//printf("swap2:%d,%d\n",a,b);


	//int a = 10, b = 20;
	//printf("%d\n", Max(a, b));
	system("pause");
}