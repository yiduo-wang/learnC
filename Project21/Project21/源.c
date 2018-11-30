#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Founc(int x,int y)
{
	int sum = 0;
	for (int i = 0; i < x; ++i)
		sum += y * (int)pow(10, i);
	return sum;
}

void Print(int x)
{
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= i; ++j)
			printf("%d*%d=%d\t", j, i, i*j);
		printf("\n");
	}
}

void ChangeNum(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
	printf("a=%d\tb=%d", *x, *y);
}

int RunYear(int x)
{
	if (x % 100 == 0)
	{
		if (x % 400 == 0)
			return 1;
	}
	else if (x % 4 == 0)
		return 1;
	else
		return 0;
}

void Init(int* arr,int size)
{
	for (int i = 0; i <= size - 1; ++i)
		arr[i] = 0;
}

void Empty(int* arr, int size)
{
	Init(arr, size);
}

void Reverse(int* arr, int size)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	for (int i = 0; i <= size - 1; ++i)
		printf("%d\t", arr[i]);
}

int IsPrime(int x)
{
	if (x <= 2)
		return 0;
	for (int i = 2; i < x; ++i)
	{
		if (x % i == 0)
			return 0;
		else
			continue;
	}
	return 1;
}

int main()
{
	int num = 9;
	printf("%d\n",IsPrime(num));

	//int arr[5] = { 1,2,3,4,5 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	//Reverse(arr, size);

	//int size = 0;
	//int arr[10];
	//size = sizeof(arr) / sizeof(arr[0]);
	//Init(arr,size);
	//Empty(arr, size);

	//int year = 2000;
	//printf("%d\n",RunYear(year));

	//int a = 10,b=20;
	//printf("a=%d\tb=%d\n", a, b);
	//ChangeNum(&a, &b);


	//int row = 9;
	//Print(row);

	//char world = 0;
	//while ((world=getchar())!=EOF)
	//{
	//	if ('a' < world&&world < 'z')
	//		putchar(world = (world - ('a' - 'A')));
	//	else if (world<'Z'&&world>'A')
	//		putchar(world = (world + ('a' - 'A')));
	//	else
	//		continue;
	//}

	//int a = 1, sum = 0;
	//for(int i=1;i<=5;++i)
	//	sum += Founc(i, a);
	//printf("%d\n", sum);

	system("pause");
}