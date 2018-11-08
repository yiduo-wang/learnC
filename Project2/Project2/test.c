//1-100之间的素数
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


//输出乘法口诀表
//规律：1.每行的行数等于列数
//      2.第一个乘数为它所在列的列数
//	    3.第二个乘数为他所在行的行数
#include<stdio.h>
#include<stdlib.h>
int main()
{
	{
		int row = 1, col = 1;
		for (row = 1; row <= 9; row++)
		{
			for (col = 1; col <= row; col++)
			{
				printf("%d*%d=%d\t", col, row, col*row);
			}
			printf("\n");
		}
		
	}
	system("pause");
}

