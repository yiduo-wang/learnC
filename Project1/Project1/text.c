#include<stdio.h>
#include<stdlib.h>
int main()
{
	for (int a = 100; a <= 200; a++)
	{
		int c = 0;
		for (int b = 2; b < a; b++)
		{
			if (a%b == 0)
				c = 1;
		}
		{
			if (c == 0)
				printf("%d\t", a);
		}
	}
	system("pause");
}

