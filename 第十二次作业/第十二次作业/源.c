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

int M_Avg(int x, int y)
{
	if (x > y)
		return y + (x - y) / 2;
	if (x < y)
		return x + (y - x) / 2;
}

int M_Avg1(int x, int y)
{
	return(x & y) + ((x^y) >> 1);
}


int Diff(int arr[],int size)
{
	int start = arr[0];
	int i = 0;
	for (i = 1; i < size; ++i)
		start ^= arr[i];
	return start;
}

int Strlen(char* str)
{
	char*start = str;
	int count = 0;
	while (*start)
	{
		++start;
		++count;
	}
	return count;
}

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start;
		--end;
	}
}

void Reverse(char* str)
{
	char* start = str;
	char* end = str + Strlen(str) - 1 ;
	char* cur = str;
	//整体逆转
	reverse(start, end);
	//逆转子串
	while (*cur)
	{
		char*st = cur;
		while (*cur != ' '&&*cur != '\0')
			++cur;
		reverse(st, cur-1);
		if (*cur == ' ')
			++cur;
	}
}

int main()
{
	
	char str[1024];
	printf("请输入字符串:\n");
	//scanf("%s",&str);当遇到空格时,用scanf输出的字符串会将其看为\0
	gets(str);
	Reverse(str);
	printf("%s\n", str);

	//int arr[] = {0};
	//int i = 0;
	//int size = 5;
	//printf("请输入数组的内容：");
	//for (i = 0; i < size; ++i)
	//{
	//	scanf("%d", &arr[i]);
	//}

	//printf("%d\n", Diff(arr,size));

	//int a = 10;
	//int b = 20;
	//printf("%d\b\n",M_Avg1(a, b));

	//int value = 0;
	//printf("请输入一个数字：\n");
	//scanf("%d", &value);
	//printf("%u\n",reverse_bit1(value));
	system("pause");
}

