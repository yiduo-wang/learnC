#include<stdio.h>
#include<stdlib.h>

void Print1(int(*arr)[3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < col; ++j)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void Print2(int arr[2][3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (int j = 0; j < col; ++j)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int main()
{
	char* c[] = { "enter","new","point","first" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);

	//char* a[] = { "work","at","alibaba" };
	//char** pa = a;
	//pa++;
	//printf("%s\n", *pa);

	//int a[5][5];
	//int(*p)[4];
	//p = a;
	//printf("&a[4][2]=%p,&p[4][2]=%p\n", &a[4][2], &p[4][2]);
	//printf("&a[4][2]-&p[4][2]=%p,&a[4][2]-&p[4][2]=%d\n", &a[4][2] - &p[4][2], &a[4][2] - &p[4][2]);

	//int a[3][2] = { (0,1),(2,3),(4,5) };
	//int* p;
	//p = a[0];
	//printf("%d\n", p[0]);

	//int a[4] = { 1,2,3,4 };
	//int* p1 = (int*)(&a + 1);
	//int* p2 = (int*)((int)a + 1);
	//printf("%x,%x\n", p1[-1], *p2);

	//int a[5] = { 1,2,3,4,5 };
	//int* p = (int*)(&a + 1);
	//printf("%d,%d\n", *(a + 1), *(p - 1));

	//int arr[2][3] = { 1,2,3,4,5,6 };
	//Print1(arr, 2, 3);
	//printf("\n");
	//Print2(arr, 2, 3);

	//char str1[] = "hello,world";
	//char str2[] = "hello,world";
	//char* str3 = "hello,world";
	//char* str4 = "hello,world";
	//if (str1 == str2)
	//	printf("str1和str2相同\n");
	//else
	//	printf("str1和str2不同\n");
	//if (str3 == str4)
	//	printf("str3hestr4相同\n");
	//else
	//	printf("str3hestr4不同\n");
	system("pause");
}