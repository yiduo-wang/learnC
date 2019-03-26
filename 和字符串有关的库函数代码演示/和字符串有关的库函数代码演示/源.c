#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>

int my_strlen1(char* str)
{
	//利用递归
	if (*str == '\0')
		return 0;
	return 1 + my_strlen1(str + 1);
}

int my_strlen2(char* str)
{
	//利用指针相减
	char* p = str;
	while(*str != '\0')
		++str;
	return str - p;
}

char* my_strcpy(char* destination, const char* source)
{
	char* start1 = destination;
	while (*source != '\0')
	{
		*start1 = *source;
		++start1;
		++source;
	}
	*start1 = '\0';
	return destination;
}

int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 == *str2)
	{
		++str1;
		++str2;
	}
	if (*str1 > *str2)
		return 1;
	else if (*str1 == *str2)
		return 0;
	else
		return -1;
}

char* my_strcat(char* destination, const char* source)
{
	char* start = destination;
	while (*destination != '\0')
		++destination;
	while (*source != '\0')
	{
		*destination = *source;
		++destination;
		++source;
	}
	*destination = '\0';
	return start;
}

char* my_strstr(const char* str1, const char* str2)
{
	const char* p1 = str1;
	const char* p2 = str2;
	while (*p1 != '\0')
	{
		while (*str1 == *str2)
		{
			++str1;
			++str2;
		}
		if (*str2 == '\0')
			return p1;	
		++p1;
		str1 = p1;
		str2 = p2;
	}
	return NULL;
}

void* my_memcpy(void* destination, const void* source, size_t num)
{
	while (num > 0)
	{
		*(char*)destination = *(char*)source;
		--num;
		++(char*)destination;
		++(char*)source;
	}
}

void* my_memmove(void* destination, const void* source,size_t num)
{
	//缓冲区重合
	if ((char*)source < (char*)destination&&(char*)destination <= (char*)source + num)
	{
		(char*)destination = (char*)destination + num - 1;
		(char*)source = (char*)source + num - 1;
		while (num > 0)
		{
			*(char*)destination = *(char*)source;
			--num;
			--(char*)destination;
			--(char*)source;
		}
	}
	//缓冲区没重合
	else
	{
		while (num > 0)
		{
			*(char*)destination = *(char*)source;
			--num;
			++(char*)destination;
			++(char*)source;
		}
	}
}

char* my_strtok(char* str1, const char* str2)
{
	assert(str2 != NULL);
	static char* str1_tmp;
	if (str1 == NULL)
		str1 = str1_tmp;
	else//起始赋值
		str1_tmp = str1;
	int cnt = 0;
	const char* str2_tmp = str2;
	while (*str1)
	{
		while (*str1_tmp != '\0' && *str2 != '\0' && *str1_tmp != *str2)//判断是否为分隔符
			++str2;
		if (*str1_tmp == '\0')//不写会让str1_tmp+1变成无效字符串,使它指向\0的后面
		{
			*(str1 + cnt) = '\0';//让在str1中的分隔符变成'\0'
			return str1;
		}

		if (*str1_tmp == *str2 && cnt != 0)//遇到分隔符,而且要保证不是字符串的起始位置
		{
			++str1_tmp;
			*(str1 + cnt) = '\0';
			return str1;
		}
		if (*str1_tmp == *str2 && cnt == 0)//遇到在字符串起始位置的分隔符
		{
			++str1_tmp;
			++str1;
			str2 = str2_tmp;
		}
		if (*str2 == '\0')//没遇到分隔符
		{
			++str1_tmp;
			++cnt;//用来记str1的起始位置到分隔符的位置,相当于分隔符所在的下标
			str2 = str2_tmp;
		}
	}
	return NULL;
}


int main()
{

	char str[] = "= :hello>,wo?rd";
	char *p;
	printf("要分割的字符转为:\"%s\"\n分割好的字符串为:\n", str);
	p = my_strtok(str, "= :>?");
	while (p != NULL)
	{
		printf("%s\n", p);
		p = my_strtok(NULL, "= :>?");
	}


	//char str[] = "123456";
	//memmove(str+1, str,7);
	//my_memmove(str + 1, str, 7);
	//puts(str+1);

	//char str1[] = "1455456789";
	//char str2[] = "456";
	//char str3[] = "457";
	//printf("%s\n", my_strstr(str1, str2));
	//printf("%s\n", my_strstr(str1, str3));

	//char str1[100];
	//char str2[40];
	//gets(str1);
	//gets(str2);
	//my_strcat(str1, str2);
	//puts(str1);

	//char str1[] = "123";
	//char str2[] = "24";
	//printf("%d\n", strcmp(str1, str2));
	//printf("%d\n", my_strcmp(str1, str2));

	//char str1[] = "Sample string";
	//char str2[40];
	//strcpy(str2, str1);
	//printf("str1: %s\nstr2: %s\n", str1,my_strcpy(str2, str1));

	//char str[256];
	//printf("请输入需要计算长度的字符串: ");
	//gets(str);
	//printf("输入的字符串%s的长度为:%lu\n", str,(unsigned)strlen(str));
	//printf("输入的字符串%s的长度为:%d\n", str, my_strlen1(str));
	//printf("输入的字符串%s的长度为:%d\n", str,my_strlen2(str));
	system("pause");
}
