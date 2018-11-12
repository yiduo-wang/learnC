#include<stdio.h>
#include<stdlib.h>

void Print(int num)
{
	if (num > 9)
		Print(num / 10);
	printf("%d\t", num % 10);
}

int Strlen(char* arr)
{ 
	if (arr[0] == '\0')
		return 0;
	return(Strlen(arr + 1) + 1);
	
	//int size = 0;
	//while (arr[size] != 0)
	//	size++;
	//return size;
}

int Factorial(int n)
{
	if (n == 1)
		return 1;
	return n*Factorial(n - 1);

	//int i = 1,result=1;
	//for (; i <= n; i++)
	//	result *= i;
	//return result;
}

int Fib(int n)
{
	int result;
	if (n <= 2)
		return 1;
	return Fib(n - 1) + Fib(n - 2);

	//if (n <= 2)
	//	return 1;
	//int i = 3,result=0,pre=1,ppre=1;
	//for (; i <= n; i++)
	//{
	//	result = pre + ppre;
	//	ppre = pre;
	//	pre = result;
	//}
	//return result;
}

int main()
{ 
	int n = 12;
	printf("%d\n", Fib(n));
	//int n = 5;
	//printf("%d\n", Factorial(n));
	
	//char arr[] =  "abcd";
	//printf("%d\n", Strlen(arr));
	
	//int num = 1234;
	//Print(num);

	//int num = 1234;
	//int num1 = num / 1000;
	//int num11 = num % 1000;
	//int num2 = num11 / 100;
	//int num22 = num11 % 100;
	//int num3 = num22 / 10;
	//int num33 = num22 % 10;
	//printf("%d,%d,%d,%d", num1, num2, num3, num33);
	system("pause");
}