//11.输入一行字符,分别统计出其中英文字母,空格,数字和其他字符的个数
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	int world_cnt = 0, blank_cnt=0,num_cnt=0,other_cnt=0;
//	char str[100];
//	gets(str);
//	char* start = str;
//	while (*start)
//	{
//		if ('a' <= *start&&*start <= 'z' || 'A' <= *start&&*start <= 'Z')
//			++world_cnt;
//		else if (*start == ' ')
//			++blank_cnt;
//		else if ('0' <= *start && *start <= '9')
//			++num_cnt;
//		else
//			++other_cnt;
//		++start;
//	}
//	printf("world_cnt=%d blank_cnt=%d num_cnt=%d other_cnt=%d\n", world_cnt, blank_cnt, num_cnt, other_cnt);
//	system("pause");
//}

//12.求Sn=a+aa+aaa+aaaa+aaaaa的值,a是一个数字,n表示它的位数,例如:2+22+222+2222+22222(此时n=5)
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int Func(int x, int y)
//{
//	if (x < 1 || x>9)
//		return 0;
// 	int i = 0,sum=0;
//	for (i = 0; i < y; ++i)
//		sum += x * (int)pow(10, i);
//	return sum;
//}
//
//int main()
//{
//	int a = 2,i=1,sum=0,n=5;
//	for (i = 1; i <= n; ++i)
//		sum += Func(a,i);
//	printf("Sn=%d\n", sum);
//	system("pause");
//}

//13.求20!+19!+18!+.....1!
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int Factorial(int x)
//{
//	if (x == 1)
//		return 1;
//	else
//		return x * Factorial(x - 1);
//}
//
//int main()
//{
//	int i = 1,sum=0;
//	for (i = 1; i <= 20; ++i)
//		sum += Factorial(i);
//	printf("%d\n", sum);
//	system("pause");
//}

//14.输出所有的水仙花数
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int Narc(int x)
//{
//	int tmp1 = x % 10;
//	int tmp2 = (x / 10)%10;
//	int tmp3 = x / 100;
//	if (x == (int)pow(tmp1, 3) + (int)pow(tmp2, 3) + (int)pow(tmp3, 3))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int num = 0;
//	for (num = 100; num <= 999; num++)
//	{
//		if(Narc(num))
//			printf("%d ", num);
//	}
//	system("pause");
//}

//15.一个数如果从100m高度自由下落,每次落地后反弹回原来高度的一半,求在第10次落地时,共经过多少米,第10次反弹多少米
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int main()
//{
//	double height = 100,sum=0,tmp;
//	tmp = height;
//	int i = 1;
//	for (i = 1; i <= 10; ++i)
//	{
//		sum += height / 2.0;
//		if (i == 10)
//			break;
//		height /= 2.0;
//	}
//	printf("sum=%10.8f\nheight=%10.8f\n", sum, height);
//	system("pause");
//}

//16.一个数如果恰好等于它的因子之和,这个数就称为"完数",6=1+2+3,输出1000内的所有完数.
#include<stdio.h>
#include<stdlib.h>

void Perfect(int i)
{
	int j = 0,tmp=0,a=0;
	int arr[100];
	for (j = 1; j < i; ++j)
	{
		if (i % j == 0)
		{
			arr[a] = j;
			++a;
			tmp += j;
		}
	}
	if (i == tmp)
	{
		printf("%d its factors are ", i);
		for (int b = 0; b < a; ++b)
		{
			if (b == a-1 )
				printf("%d", arr[b]);
			else
				printf("%d,", arr[b]);
		}
		printf("\n");
	}
}

int main()
{
	int i = 0;
	for (i = 2; i <= 1000; ++i)
		Perfect(i);
	system("pause");
}

//17.数列 2/1,3/2,5/3,8/5,13/8,......    求这个数列的前20项的和
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 1;
	double result, result1 = 0, ppre1 = 2, pre1 = 3, result2 = 0, ppre2 = 1, pre2 = 2;
	result = ppre1 / ppre2+pre1/pre2;
	for (i = 3; i <= 20; ++i)
	{
		result1 = pre1 + ppre1;
		result2 = pre2 + ppre2;
		result += result1 / result2;
		ppre1 = pre1;
		pre1 = result1;
		ppre2 = pre2;
		pre2 = result2;
	}
	printf("%f\n", result);
	system("pause");
}

//18.猴子吃桃问题.每次吃的桃是上一次总数的一半再多一个,第10次吃的时候就只剩了一个,求开始的总数
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0,x=1,sum=0;
	for (i = 1; i <= 9; ++i)
	{
		sum = (x + 1) * 2;
		x = sum;
	}
	printf("%d\n", x);
	system("pause");
}

