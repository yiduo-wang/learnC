#include<stdio.h>
#include<stdlib.h>

void Print(int x)
{
	if (x > 9)
		 Print(x / 10);
	/*else*/
		printf("%d\t", x % 10);
}

int Strlen(char* arr)
{
	int count = 0,i=0;
	while (1)
	{
		if (arr[i] == '\0')
			break;
		else
			i++;
	}
	return i;

	//if (arr[0] == '\0')
	//	return 0;
	//return Strlen(arr +1) + 1;
}

int Factorial(int x)
{
	if (x <= 1)
		return 1;
	return x*Factorial(x - 1);
}

int Fib(int x)
{
	if (x <= 2)
		return 1;
	return Fib(x - 1) + Fib(x -2);

//	int result =0, pre = 1, ppre = 1;
//	if (x <= 2)
//		return 1;
//	while (x > 2)
//	{
//		result = pre + ppre;
//	    ppre = pre;
//pre = result;
//		x--;	
//	}
//	return result;
}

int main()
{
	//int n = 12;
	//printf("%d\n", Fib(n));

	//int n = 5;
	//printf("%d\n", Factorial(n));

	//char arr[] = "abcd";
	//printf("%d\n", Strlen(arr));

	int num = 1234;
	Print(num);
	system("pause");
}
