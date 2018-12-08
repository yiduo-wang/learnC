#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int reverse_bit(unsigned int value)
{
	int i = 1,num=0;
	for (i = 1; i < 32; ++i)
	{
		num+=(value & 1) * pow(2, 32 - i);
		value >>= 1;
	}
	return num;
}

int reverse_bit1(unsigned int value)
{
	int i = 0,tmp=0;
	for (i = 0; i < 32; ++i)
	{
		tmp <<= 1;
		tmp |= ((value >> i) & 1);
	}
	return tmp;
}

int main()
{
	int value = 0;
	printf("请输入一个数字：\n");
	scanf("%d", &value);
	printf("%u\n",reverse_bit1(value));
	system("pause");
}