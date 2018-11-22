#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void test1(int* arr)
{
	printf("%d\n", sizeof(arr));//数组名做参数时此时会隐式转化为指针，指向此数组的首元素，所以这里的sizeof(ch)等价于sizeof（0）
}

void test2(char* ch)
{
	printf("%d\n", sizeof(ch));//数组名做参数时此时会隐式转化为指针，指向此数组的首元素,所以这里的sizeof(ch)等价于sizeof（0）
}

int Max(int x, int y)
{
	return x > y ? x : y;
}

struct student
{
	char name[1024];
	int score;
};

int main()
{
	//.给结构体变量使用
	//->给结构体指针使用,->也相当于对指针进行解引用，所以要保证解引用的指针是有效的
	struct student stu;
	stu.score = 100;
	printf("%d\n", stu.score);

	struct student* p = &stu;
	p->score = 100;//等价于(*p).score=100


	//int arr[10] = { 0 };
	//int* p = arr;//等价于int* p=&arr[0]
	//printf("%d\n", p[5]);

	//int a = 1, b = 2;
	//int c = (a > b, a = b + 10, a, b = a + 1);
	//printf("%d\n", c);

	//int a = 10, b = 20;
	//printf("%d\n", Max(a, b));

	//int a = 4,b=0;
	//b = a > 5 ? 3 : -3;
	//printf("%d\n", b);

	 //三目运算符的优先级比较低，使用时要注意
	//int a = 10, b = 20,max=0;
	//max = (a > b) ? (a) : (b);
	//printf("%d\n", max);
	//if(a>b)
	//	max=a;
	//else
	//	max=b;
		
	//短路求值
	//在&&中如果左侧表达式为假，则右侧所有表达式都不会起任何作用
	//在||中如果左侧表达式为真，则右侧所有表达式都不会起任何作用
	//int i = 0, a = 0, b = 2,d = 4;
	//i = a++&&++b&&d++;//a++的返回值为0，所以为假
	//printf("a=%d b=%d d=%d\n", a, b, d);//a=1,b=2,d=4
	//i = a++ || ++b || d++;//++b为真
	//printf("a=%d b=%d d=%d\n", a, b, d);//a=1,b=3,d=4

	//int a = 1;
	//int b = 2;
	//printf("%d\n", a&b);
	//printf("%d\n", a&&b);
	//printf("%d\n", a | b);
	//printf("%d\n", a || b);

	//int a = 10;
	//int x = ++a;
	//int y = --a;
	//printf("%d\t%d\n", x, y);//x=11,y=10
	//a = 10;
	//int i = a++;//此时a++的返回值为10，所以i==10,但是a加了1，所以此时a==11
	//int j = a--;//此时a--的返回值为a的值，所以j=11，但是a减了1，所以此时a==10
	//printf("%d\t%d\n", i, j);//i=10,j=11

	//int arr[10] = { 0 };
	//char ch[10] = { 0 };
	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(ch));
	//test1(arr);
	//test2(ch);

	//int a = -10;
	//int* p = NULL;
	//printf("%d\n", !2);
	//printf("%d\n", !0);
	//a = -a;
	//p = &a;
	//printf("%d\n", sizeof(a));

	//srand((unsigned)time(0));强制类型转换

	//int num = 10;
	//int count = 0;
	//while (num)
	//{
	//	if (num % 2 == 1)
	//		++count;
	//	num /= 2;
	//}

	//int count = 0;
	//int num = -3;
	//for (int i = 0; i < 32; i++)
	//{
	//	if ((num >> i) & 1)
	//		++count;
	//}

	//int num = 1;
	//printf("%d\n", num++);

	//int num = 1;
	//printf("%d\n", num++);
	//printf("%d\n", num);

	//后置++可以理解为以下代码,等于说是自定义了一个int型的后置++函数，但是返回值为另一个变量tmp，
	//要求返回值时，前置++和后置++才不一样
	//int tmp = num;
	//num += 1;
	//return tmp;
	system("pause");
}