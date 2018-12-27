//45.写一个函数,使输入一个字符串按反序存放,在主函数中输入和输出字符串
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Reverse(char* str, int size)
{
	char* start = str;
	char* end = str + size - 1;
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		++start; --end;
	}
}

int main()
{
	char str[10];
	gets(str);
	int size = strlen(str);
	Reverse(str, size);
	puts(str);
	system("pause");
}

//46.写一个函数,将一个字符串中的元音字母复制到另一个字符串,然后输出
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void StrcpyVowel(char* str1, char* str2)
{
	char* start1 = str1;
	char* start2 = str2;
	while (*start1)
	{
		if (*start1 == 'a' || *start1 == 'e' || *start1 == 'i' || *start1 == 'o' || *start1 == 'u' || *start1 == 'A' || *start1 == 'E' || *start1 == 'I' || *start1 == 'O' || *start1 == 'U')
		{
			*start1 = *start2;
			++start2;
		}
		++start1;
	}
	*start2 = '\0';
}

int main()
{
	char str1[20];
	char str2[20];
	gets(str1);
	StrcpyVowel(str1, str2);
	puts(str2);
  system("pause");
}

//47.写一个函数,输入一个4位数字,输出这四个数字的字符,但每两个字符之间要有一个空格,如输入:1990,输出:"1 9 9 0"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void Strhua(char* str, int n)
{
	int i = 0,b=0;
	char* start = str;
	for (i = 3; i >= 0; --i)
	{
		b = n / (unsigned int)pow(10, i);
		*start = (char)(b+48);
		++start;
		if (i != 0)
		{
			*start = ' ';
			++start;
		}
		n %= (unsigned int)pow(10, i);
	}
	*start = '\0';
}

int main()
{
	char str[10];
	int n;
	scanf("%d", &n);
	Strhua(str, n);
	puts(str);
	system("pause");
}

//48.写一个函数,输入一行字符,输出此字符串中的最长单词
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void PrintLwrd(char str[])
{
	int i,start=0,end,length=0,tmp_end,tmp_start,tmp;
	for (i = 0; i < (strlen(str)); ++i)
	{
		tmp = 0;//最长单词长度
		start = i;//单词起始的下标
		while(str[i] != ' ' && str[i] != '\0')
		{
			++tmp;
			++i;
		}
		end = i-1;//单词结束的下标
		if (tmp > length)
		{
			length = tmp;//上一个单词的长度
			tmp_start = start;//最长单词的起始坐标
			tmp_end = end;//最长单词的结束坐标
		}
	}
	for (i = tmp_start; i <= tmp_end; ++i)
		printf("%c", str[i]);
	printf("\n");
}

int main()
{
	char str[60];
	gets(str);
	PrintLwrd(str);
	system("pause");
}

//49.写一个函数,用"起泡法"对输入10个字符按照由大到小排列
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BubbleSort(char str[])
{
	int i = 0,j=0;
	for (j = strlen(str); j >= 0; --j)
	{
		for (i = 0; i < j; ++i)
		{
			if (str[i] < str[i + 1])
			{
				char tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
		}
	}
	
	
}

int main()
{
	char str[10];
	gets(str);
	BubbleSort(str);
	puts(str);
	system("pause");
}

////50.写一个函数,输入十六进制数,输出相应的十进制数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void Convert(char str[])
{
	int i = 0,num=0;
	for (i = 0; i < strlen(str); ++i)
	{
		if ('a' <= str[i] && str[i] <= 'f')
			num += ((str[i] - 'a') + 10)*(int)pow(16, strlen(str) - 1 - i);
		if ('A' <= str[i] && str[i] <= 'F')
			num += ((str[i] - 'A') + 10)*(int)pow(16, strlen(str) - 1 - i);
		if ('0' <= str[i] && str[i] <= '9')
			num += (str[i] - '0')*(int)pow(16, strlen(str) - 1 - i);
	}	
	printf("转化的十进制结果:\n");
	printf("%d\n", num);
}

int main()
{
	char str[10];
	gets(str);
	Convert(str);
	system("pause");
}

//51.用递归法将一个整数n转化成字符串.如:输入483,输出字符串"483",n的位数不确定.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void Symbol_hua(int n, int cnt)
{
	int i = 0;
	char c;
	for (i = 0; i < cnt; ++i)
	{
		c = (char) ((n / ((int)pow(10, cnt-1-i)))+48);
		n %= (int)pow(10, cnt - 1 - i);
		printf("%c", c);
	}
	printf("\n");
}

int main()
{
	int n,cnt = 0;
	scanf("%d", &n);
	int tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		++cnt;
	}
	Symbol_hua(n, cnt);
	system("pause");
}