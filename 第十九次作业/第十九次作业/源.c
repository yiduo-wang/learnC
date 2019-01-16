//实现strncpy
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char* Strncpy(char* destination, const char* source, size_t num)
{
	assert(destination != NULL);
	assert(source != NULL);
	int i = 0;
	for (i = 0; i < num; ++i)
		destination[i] = source[i];
	return destination;
}

int main()
{
	char str1[10]="123456789";
	char str2[20]="qweaQW";
	Strncpy(str1,str2,5);
	puts(str1);
	system("pause");
}

//实现strncat
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char* Strncat(char* destination, const char* source, size_t num)
{
	assert(destination != NULL);
	assert(source != NULL);
	int end = strlen(destination) - 1;
	int i = 0;
	for (; i < num; ++i)
		destination[end + i] = source[i];
	destination[end + i] = '\0';
	return destination;
}

int main()
{
	char str1[30];
	char str2[20];
	printf("请输入两个数组:\n");
	gets(str1);
	gets(str2);
	Strncat(str1, str2, 5);
	puts(str1);
	system("pause");
}

//实现strncmp
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int Strncmp(const char* str1, const char* str2, size_t num)
{
	int i = 0;
	for (; i < num; ++i)
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	return 0;
}

int main()
{
	char str1[20];
	char str2[20];
	printf("请输入两个字符串:\n");
	gets(str1);
	gets(str2);
	printf("%d\n", Strncmp(str1,str2,3));
	system("pause");
}