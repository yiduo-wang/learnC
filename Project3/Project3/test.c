//多个字符从两端移动，向中间汇聚
//规律：1.需要两个字符串数组
//      2.需要Left和right
//	    3.循环，两个字符串每次都要交换
//	    4.交换完后Left加1，Right减1，直到Left=Right
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	int left = 0, right = 0;
	char arr1[] = "welcome to bit";
	char arr2[] = "**************";
	for (left = 0,right=strlen(arr1)-1; left <= right; left++,right--)
	{
		Sleep(500);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);

	}
	system("pause");
}

//密码登录情景，只能输三次，错误退出程序
//规律：1.需要一个数组来表示密码
//      2.用for循环三次
//	  3.每次循环都要判断输入密码是否正确
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char arr[1024] = "123456";
	int i = 0; 
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：\n");
		scanf("%s",&arr);
		if (strcmp(arr, "123456") == 0)
			break;
	}
	if (i == 3)
		printf("exit\n");
	else
	    printf("log in\n");
	system("pause");
}

//计算1!+2!+3!+...+10!的阶乘
//规律：1.构建阶乘函数（for循环）
//      2.将阶乘函数的得数相加（for循环）
#include<stdio.h>
#include<stdlib.h>
int jiecheng(int n)
{
	int i = 0,result=1;
	for (i = 1; i <= n; i++)
	{
		result *= i;
	} 
	return result;
}

int main()
{
	int i = 0,sum=0;
	for (i = 1; i <= 10; i++)
	{
		sum += jiecheng(i);
	}
	printf("sum=%d\n",sum );
	system("pause");
}