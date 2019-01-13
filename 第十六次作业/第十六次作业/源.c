//实现strcpy
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* Strcpy(char* destination, const char* source)
{
	int i = 0;
	assert(destination != NULL);
	assert(destination != NULL);
	for (i = 0; source[i] != '\0'; ++i)
		destination[i] = source[i];
	destination[i] = '\0';
	return destination;
}

int main()
{
	char str1[20];
	char str2[20];
	gets(str1);
	gets(str2);
	printf("%s\n", Strcpy(str1, str2));
	system("pause");
}

//实现strcat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char* Strcat(char* destination, char* source)
{
	int i = 0;
	assert(destination != NULL);
	assert(destination != NULL);
	int end = strlen(destination);
	for (i = 0; source[i] != '\0'; ++i)
		destination[end + i] = source[i];
	destination[end + i] = '\0';
	return destination;
}

int main()
{
	char str1[30];
	char str2[30];
	gets(str1);
	gets(str2);
	printf("%s\n", Strcat(str1, str2));
	system("pause");
}

//实现strstr
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char* Strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str1 == '\0')
		return NULL;
	if (*str2 == '\0')
		return NULL;
	const char* start1 = str1;
	while (*start1)
	{
		const char* tmp = start1;
		const char* start2 = str2;
		while (*tmp != '\0' && *start2 != '\0' && *start2 == *tmp)
		{
			++start2;
			++tmp;
		}
		if (*start2 == '\0')
			return start1;
		++start1;
	}
	return NULL;
}

int main()
{
	char str1[]="this thisis a c programming";
	char str2[] = "thisis";
	printf("%s\n", Strstr(str1,str2));
	system("pause");
}

//实现strcmp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int Strcmp(const char* destination, const char* source)
{
	assert(destination != NULL);
	assert(source != NULL);
	while (*destination != '\0' && *source != '\0' && *destination == *source)
	{
		++destination;
		++source;
	}
	if (*destination < *source)
		return -1;
	else if (*destination > *source)
		return 1;
	else
		return 0;
}

int main()
{
	char str1[20];
	char str2[20];
	gets(str1);
	gets(str2);
	printf("%d\n", Strcmp(str1, str2));
	system("pause");
}

//实现strchr
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* Strchr(const char* str, int character)
{
	assert(str != NULL);
	while (*str != '\0')
	{
		if (*str == (char)character)
			return str;
		++str;
	}
	return NULL;
}

int main()
{
	char str[] = "This is a sample string";
	char* p;
	p = Strchr(str, 's');
	while (p != NULL)
	{
		printf("%d\n", p - str + 1);
		p = Strchr(p + 1, 's');
	}
	system("pause");
}

//实现strtok
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char* Strtok(char* str1, const char* str2)
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
	
		if ( *str1_tmp == *str2 && cnt != 0)//遇到分隔符,而且要保证不是字符串的起始位置
		{		
			++str1_tmp;
			*(str1+cnt) = '\0';
			return str1;
		}
		if (*str1_tmp == *str2 && cnt == 0)//遇到在字符串起始位置的分隔符
		{
			++str1_tmp;
			++str1;
			str2 = str2_tmp;
		}
		if(*str2=='\0')//没遇到分隔符
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
	char str1[] = ":  l:so\t\tiu  -l /a : asa";
	char str2[] = " \t:";
	char* p = Strtok(str1, str2);
	while (p != NULL)
	{
		printf("%s\n", p);
		p = Strtok(NULL, str2);
	}
	system("pause");
}

//实现memcpy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void* Memcpy(void* destination, void* source, size_t size)
{
	int i = 0;
	char* pdest = (char*)destination;
	char* psrc = (char*)source;
	for (i = 0; i < size; ++i)
		pdest[i] = psrc[i];
	return destination;
}

int main()
{
	int arr1[] = { 1,2,3,4 };
	int arr2[20];
	int size = sizeof(arr1);
	Memcpy(arr2,arr1,size);
	for (int i = 0; i < size / sizeof(arr1[0]); ++i)
		printf("%d ", arr2[i]);
	printf("\n");
	system("pause"); 
}

//实现memmove
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdint.h>

void* Memmove(void* destination, void* source, size_t size)
{
	int64_t i = 0;
	assert(destination != NULL);
	assert(source != NULL);
	char* pdest = (char*)destination;
	char* psrc = (char*)source;
	if (pdest > psrc && pdest < psrc + size)
	{
		for (i = size - 1; i >= 0; --i)
			pdest[i] = psrc[i];
	}
	else
	{
		for (i = 0; i < size; ++i)
			pdest[i] = psrc[i];
	}
}

int main()
{
	char str[] = "memmove can be very useful......";
	Memmove(str+20, str+15, 11);
	puts(str+20);
	system("pause");
}