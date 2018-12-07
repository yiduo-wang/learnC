#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	int i = 1,count=0;
	while (i < 32)
	{
		if ((value & 1) == 1)
			++count;
		value >>= 1;
		++i;
	}
	return count;
}

void Odd_Even_Bit(int n)
{
	int i = 0;
	printf("奇数位为： ");
	for (i = 30; i >= 0; i -= 2)
		printf("%d ", (n >> i) & 1);
	printf("\n");
	printf("偶数位为： ");
	for (i = 31; i >= 1; i -= 2)
		printf("%d ", (n >> i) & 1);
	printf("\n");
}

void Print(int n)
{
	if (n > 9)
		Print(n / 10);
	printf("%d\t", n % 10);
}

void Print_Bits(int n)
{
	int i = 0;
	for (i = 31; i >= 0; --i)
		printf("%d ", (n >> i) & 1);
}

int Print_Different_Bits(int n,int m)
{
	int i = 0,count=0;
	int tmp = n ^ m;
	for (i = 31; i >= 0; --i)
	{
		if (((tmp >> i) & 1) == 1)
			++count;
	}
	return count;
}

int main()
{


	int n = 0, m = 0;
	printf("请输入两个数字：\n");
	scanf("%d %d", &n, &m);
	printf("%d\n",Print_Different_Bits(n, m));

	//int n = 15;
	//Print_Bits(n);

	//int n = 123456;
	//Print(n);

	//int n = 15;
	//Odd_Even_Bit(n);

	//int n = 15;
	//printf("%d\n", count_one_bits(n));
	system("pause");
}