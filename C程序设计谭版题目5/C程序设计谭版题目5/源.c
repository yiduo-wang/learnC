//30.折半查找法(15个数)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 15

void BinarySearch(int* arr, int size, int num)
{
	int i=0,left = 0;
	int right = size - 1;
	while(left<=right)
	{
		int mid = (left + right) / 2;
		if (num < arr[mid])
			left=mid+1;
		if (num > arr[mid])
			right=mid-1;
		if (num == arr[mid])
		{
			printf("%d在这个数组里面,是数组的第%d个元素\n", num, mid + 1);
			break;
		}
	}
	if (left > right)
		printf("无此数\n");
}

int main()
{
	int arr[N];
	int i = 0,num=0;
	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("请输入要查询的数:\n");
	scanf("%d", &num);
	BinarySearch(arr, size, num);
	system("pause");
}

//31.输出5X5的星号平行四边形
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Print(int blank,int height)
{
	int row = 0;
	for (row = 0; row < blank; ++row)
		printf(" ");
	for (row = 0; row <= height; ++row)
		printf("* ");
	printf("\n");
}

int main()
{
	int height = 5;
	int row = 0;
	for(row=0;row<height;++row)
		Print(row, height);
	system("pause");
}

//32.写一段程序,将第1个字母变成第26个字母,第i个字母编程第(26-i+1)个字母,非字母不变,A->Z,B->Y,a->z,b->y
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c = 0;
	while ((c = getchar()) != EOF)
	{
		if ('A' <= c && c <= 'Z')
			//'A' - putchar(c) + 26 计算的是putchar(c)转化的字母是第几个字母
			//'A'+'A'-putchar(c)+26-1  计算的是putchar(c)转化的字母是谁
			putchar(2 * 'A' - c + 25);
		else if ('a' <= c && c <= 'z')
			putchar(2 * 'a' - c + 25);
		else
			continue;
	}
	system("pause");
}

//33.实现strcat函数,但不能使用strcat函数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Strcat(char* str1, char* str2)
{
	char* start1 = str1;
	while (*start1)
		++start1;
	char* start2 = str2;
	while (*start2)
	{
		*start1 = *start2;
		++start1;
		++start2;
	}
	*start1 = '\0';
}

int main()
{
	char str1[20]; char str2[20];
	gets(str1); gets(str2);//strlen(str1)+strlen(str2)+1<=str1初始化的大小,在这里是[20];
	int length1 = strlen(str1);
	Strcat(str1, str2);
	puts(str1);
	system("pause");
}

//34.实现strcmp函数,不能直接使用strcmp函数,字符串用gets函数读入,输出的正数或者负数的值应为两个字符的差值
   //如'A'与'C'相比较,'A'-'C'=-2,所以输出-2,'E'与'D'相比较,'E'-'D'=1,所以输出1,相减为0,则输出0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Strcmp(char* str1, char* str2)
{
	char* start1 = str1;
	char* start2 = str2;
	while (*start1 && *start2)
	{
		if (*start1 - *start2 != 0)
			return *start1 - *start2;
		++start1; ++start2;
	}
	if(*start1)
		return *start1-'\0';
	else if(*start2)
		return '\0'-*start2;
	else
		return 0;
}

int main()
{
	char str1[20]; char str2[20];
	gets(str1); gets(str2);
	printf("%d\n",Strcmp(str1, str2));
	system("pause");
}

//35.实现strcpy函数,不能直接使用strcpy函数.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Strcpy(char* str1, char* str2)
{
	char* start1 = str1;
	char* start2 = str2;
	while (*start2)
	{
		*start1 = *start2;
		++start1;
		++start2;
	}
	*start1 = '\0';
}

int main()
{
	char str1[20]; char str2[20];
	gets(str1);
	gets(str2);
	Strcpy(str1, str2);
	puts(str1);
	system("pause");
}

//36.求第五个学生的年龄,第五个比第四个大2岁,第四个比第三个大2岁,第三个比第二个大2岁,第二个比第一个大2岁
   //第一个10岁.
#include<stdio.h>
#include<stdlib.h>

int Age(int n)
{
	if (n == 1)
		return 10;
	else
		return 2 + Age(n - 1);
}

int main()
{
	int n = 5;
	printf("%d\n", Age(n));
	system("pause");
}

//37.用递归求n!
#include<stdio.h>
#include<stdlib.h>

int Factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main()
{
	int n = 5;
	printf("%d\n", Factorial(n));
	system("pause");
}