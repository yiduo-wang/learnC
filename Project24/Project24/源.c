#include<stdio.h>
#include<stdlib.h>
int	Fib(int x)
{
	if (x <= 2)
		return 1;
	else
		return Fib(x - 1) + Fib(x - 2);
}
int main()
{
	int n = 5;
	int fib = Fib(n);
	printf("fib=%d\n", fib);
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int IsPrime(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	int i = 0;
	for (i = 2; i < x; ++i)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int n = 9;
	printf("%d", IsPrime(n));//1是素数,0不是素数
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int IsLeepYear(int n)
{
	if (n % 100 == 0)
	{
		if (n % 400 == 0)
			return 1;
		else
			return 0;
	}
	else if (n % 4 == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int n = 1996;
	printf("%d\n", IsLeepYear(n));
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int Strlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		if (*str != '\0')
		{
			++count;
			++str;
		}
	}
	return count;
}
int main()
{
	char str[] = "hello,world";
	printf("%d\n", Strlen(str));
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
void Print(int x)
{
	if (x > 9)
		Print(x / 10);
	printf("%d ", x%10);
}
int main()
{
	int n = 1234;
	Print(n);
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int Strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str + 1);
}
int main()
{
	char str[] = "hello,world";
	printf("%d\n", Strlen(str));
	system("pause");
}