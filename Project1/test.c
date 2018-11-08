#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch<'0' || ch>'9')
			continue;
		putchar(ch);
	}
	system("pause");
}