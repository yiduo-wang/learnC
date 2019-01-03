//1.实现一个函数，可以左旋字符串中的k个字符。 
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Rotation(char str[], int k)
{
	int i = 0, j = 0;
	int end = strlen(str) - 1;
	for (i = 0; i < k; ++i)
	{
		char tmp = str[0];
		for (j = 0; j < end; ++j)
			str[j] = str[j + 1];
		str[end] = tmp;
	}
}

int main()
{
	int k = 3;
	printf("\n请输入你要旋转的字符串:\n");
	char str[10];
	gets(str);
	Rotation(str,k);
	puts(str);
	system("pause");
}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int IsRotation(char str1[], char* str2)
{
	int i = 0,j=0;
	int k = strlen(str1);
	int end = k -1;
	for (i = 1; i <= k; ++i)
	{
		char tmp = str1[0];
		for (j = 0; j < end; ++j)
			str1[j] = str1[j+1];
		str1[end] = tmp;
		if (strcmp(str1, str2) == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char str1[10];
	char str2[10];
	printf("请给定两个字符串:\n");
	gets(str1);
	gets(str2);
	printf("%d\n", IsRotation(str1, str2));
	system("pause");
}