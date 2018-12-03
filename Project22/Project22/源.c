#include<stdio.h>
#include<stdlib.h>

int fib(int x)//·ÇµÝ¹é
{
	int result = 0;
	int pre_num = 1;
	int ppre_num = 1;
	if (x <= 2)
		return 1;
	else
	{
		for (int i = 2; i < x; ++i)
		{
			result = pre_num + ppre_num;
			ppre_num = pre_num;
			pre_num = result;
		}
		return result;
	}
}

int Fib(int x)//µÝ¹é
{
	if (x <= 2)
		return 1;
	else
		return Fib(x - 1) + Fib(x-2);
}

int Pow(int n, int k)
{
	if (k == 1)
		return n;
	else
		return n * Pow(n, k - 1);
}

int Digitsum(int x)
{
	int n = 0;
	if (x < 10)
		return x;
	else
	{
		n = x % 10;
		x=x / 10;
		return n + Digitsum(x);
	}
}

int  Strlen(char* arr)//µÝ¹é
{
	if (*arr)
	{
		char* start = arr;
		return 1 + Strlen(start + 1);
	}
	else
		return 0;
}

//int Strlen(char* arr)//·ÇµÝ¹é
//{
//	int count = 0;
//	char* start = arr;
//	if (*start == '\0')
//		return 0;
//	while (*start)
//	{
//		++count; 
//		start++;
//	}
//	return count;
//}

void Reverse(char* arr)
{
	if (*arr)
	{
		char* start = arr;
		char* end = arr + Strlen(arr) - 1;
		char tmp = *start;
		*start = *end;
		*end = '\0';
		Reverse(start + 1);
		*end = tmp;
	}
}

//int Factorial(int n)//µÝ¹é
//{
//	if (n == 1)
//		return 1;
//	return n * Factorial(n - 1);
//}

void Print(int x)
{
	if (x>9)
		Print(x/10);
	printf("%d\n",x%10);
}

int main()
{
	
	int n = 12345;
	Print(n);

	//int n = 5;
	//int num = 1;
	//for (; n > 0; --n)
	//	num *= n;
	//printf("%d\n",num);

	//char arr[] = "abcdef";
	//if (Strlen(arr))
	//	printf("%d\n", Strlen(arr));

	//char arr[] = "abcdef";
	//Reverse(arr);
	//printf("%s\t",arr);
	

	//int num = 1729;
	//printf("%d\n",Digitsum(num));

	//int n = 2;
	//int k = 10;
	//printf("%d\n",Pow(n, k));

	//int n = 9;
	//printf("%d\n",Fib(n));
	system("pause");
}