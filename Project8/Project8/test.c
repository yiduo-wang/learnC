#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//int Isprime(i)
//{
//	for (int n = 2; n <= i - 1; n++)
//	{
//		if (i % n == 0)
//			return 0;
//	}
//	return 1;
//}

//int Isleapyear(i)
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

int Shunxu(int* x,int* y,int* z)
{
	if (*x < *y)
	{
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
	if (*x < *z)
	{
		int tmp = *x;
		*x = *z;
		*z = tmp;
	}
	if (*y < *z)
	{
		int tmp = *y;
		*y = *z;
		*z = tmp;
	}
	printf("%d,%d,%d", *x, *y, *z);
}

int Max_gongyue(int a,int b)
{
	int num = 1,max=0;
	while (num <= a&&num <= b)
	{
		if (a%num == 0 && b%num == 0)
			max = num;
		num++;
	}
	return max;
}

int main()
{
	//int i = 0,count=0;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 10 == 9)
	//		count++;
	//	if (i / 10 == 9)
	//		count++;
	//}
	//printf("%d\n", count);

	//int i = 1; 
	//double  sum = 0,sum1=0,sum2=0;
	//for (; i <= 100; i++)
	//{
	//	if (i % 2 == 0)
	//		sum1 +=- (double)1 / (double)i;
	//	else
	//		sum2 +=(double) 1 / (double)i;
	//}
	//sum = sum1 + sum2;
	//printf("%f", sum);

	
	//int arr1[] = { 1, 2, 3, 4 };
	//int arr2[] = { 4, 3, 2, 1 };
	//int i = 0;
	//for (; i <= sizeof(arr1) / sizeof(arr1[0]) - 1; i++)
	//{
	//	int tmp = arr1[i];
	//	arr1[i] = arr2[i];
	//	arr2[i] = tmp;
	//}
	//for (i=0; i <= sizeof(arr1) / sizeof(arr1[0]) - 1; i++)
	//	printf("%d\t", arr1[i]);
	//for (i=0; i <= sizeof(arr1) / sizeof(arr1[0]) - 1; i++)
	//	printf("%d\n", arr2[i]);

	//int a, b;
	//printf("请输入两个数字");
	//scanf("%d,%d", &a, &b);
	//printf("%d\n", Max_gongyue(a, b));

	//int a, b, c;
	//printf("请输入3个数字：");
	//scanf("%d,%d,%d", &a, &b, &c);
	//Shunxu(&a, &b, &c);

	//int i;
	//int arr[10] = { 0 };
	//for (i = 0; i <= sizeof(arr) / sizeof(arr[0])-1; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}
	//int max = arr[0];
	//for ( i = 1; i <= sizeof(arr)/sizeof(arr[0])-1; i++)
	//{
	//	if (max< arr[i])
	//		max = arr[i];
	//}
	//printf("%d\n", max);

	//int a = 10, b = 20;
	//a = a^b;
	//b = a^b;
	//a = a^b;
	//printf("%d，%d", a, b);

	//int a = 10, b = 20;
	//a = a + b;
	//b = a - b;
	//a = a - b;
	//printf("%d，%d", a, b);

	//int tmp=0, a = 10, b = 20;
	//tmp = a;
	//a = b; 
	//b = tmp;
	//printf("%d，%d", a, b);

	//int i = 1000;
	//for (; i <= 2000; i++)
	//{
	//	if (Isleapyear(i))
	//		printf("%d\t", i);
	//}

	//int row = 0,col=0;
	//for (row = 1; row <= 9; row++)
	//{
	//	for (col = 1; col <= row; col++)
	//		printf("%d*%d=%d\t", col, row, col*row);
	//	printf("\n");
	//}

	//int i = 100;
	//for (; i <= 200; i++)
	//{
	//	if (Isprime(i))
	//		printf("%d\t", i);
	//}
	system("pause");
}