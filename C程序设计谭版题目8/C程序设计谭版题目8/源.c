//52.将数组a中n个数安相反的顺序排放
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#define n 10
//
//void Reverse(int* a, int N)
//{
//	int i = 0;
//	int *left = a;
//	int *right = a + N-1;
//	while (left < right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		--right;
//		++left;
//	}
//	for (i = 0; i < N; ++i)
//		printf("%d ", a[i]);
//	printf("\n");
//}
//
//int main()
//{
//	int i=0;
//	int a[n];
//	printf("请输入10个数字:");
//	for (i = 0; i < n; ++i)
//		scanf("%d", &a[i]);
//	Reverse(a, n);
//	system("pause");
//}

//53.用指针方法对10个整数按由大到小排序
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//void Sort(int* p, int n)
//{
//	int i = 0; int j =0 ;
//	for (i = 0; i< n - 1 ; ++i)
//	{
//		for (j = i+1; j < n; ++j)
//		{
//			if (*(p+j) > *(p + i))
//			{
//				int tmp = *(p+i);
//				*(p+i) = *(p + j);
//				*(p + j) = tmp;
//			}
//		}
//	}
//	
//}
//
//int main()
//{
//	int i = 0;
//	int arr[10];
//	int* p = arr;
//	printf("请输入10个整数:");
//	for (i = 0; i < 10; ++i)
//		scanf("%d", p++);
//	//p++指先给p[0]赋值在给p加上1;
//	//若此句为scanf("%d",++p);++p指先给p+1再给p赋值;相当于是从p[0+1]开始用键盘赋值附到p[8+1],但要循环10次,所以还要越界赋值p[10]
//	p = arr;//此时p为arr的末元素的地址,所以要将p刷新成为arr首元素地址
//	Sort(p, 10);
//	for (p=arr,i = 0; i < 10; ++i)
//		printf("%d ", *(p++));
//	system("pause");
//}
//此题结论:再循环输入或者输出时,尽量不要再输入或者输出变量的后面或前面直接++以及--,尤其是指针变量,应该再紧接着的下一行中进行++或--;
//错误事例:for (.........)
//       printf("%d",--p);printf("%d",++p);
//        printf("%d",p++);printf("%d",p++);      
//正确事例:for (.........)
//		   {printf("%d",p);
//			--p;或者p--;都行}		
    
//54.要求用指向元素的指针变量来输出3x4的二维数组的各元素值
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
//	int* p = a[0];
//	for (p = a[0]; p < a[0] + 12; ++p)
//	{
//		if ((p - a[0]) % 4 == 0 && p - a[0] >=4)
//			printf("\n");
//		printf("%-3d", *p);
//	}
//	system("pause");
//}
	
//55.54题的变形,让p不指向a[0]的首元素,让p指向a[0]的的址值(p=&a[0],并不是p=a[0])
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int row = 0;
//	int col = 0;
//	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
//	int(*p)[4];
//	p = a;
//	for (row = 0; row < 3; ++row)
//	{
//		for (col = 0; col < 4; ++col)
//		{
//			printf("%-3d ", *(*(p + row) + col));
//		}
//		printf("\n");
//	}
//	system("pause");
//}

//56.有一个班有3名同学,各学4门学科,计算总平均分数以及第n个学生的成绩
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdint.h>
//
//float Avg(int a[3][4],int size)
//{
//	int i = 0;
//	float sum=0;
//	int* p = a[0];
//	for (i=0; i < size; ++i)
//	{
//		sum += (float)*p;
//		++p;
//	}
//	return sum / size;
//}
//
//void Search(int n,int a[3][4])
//{
//	int(*p)[4];
//	p = a; 
//	printf("第%d个同学的成绩为: ");
//	for (int i = 0; i < 4; ++i)
//		printf("%d ", *(*(p + n-1) + i));
//	printf("\n");
//}
//
//int main()
//{
//	int a[3][4] = {
//		{65,67,70,60},
//		{80,87,90,81},
//		{90,99,100,98}
//	};
//	int size = sizeof(a) / sizeof(a[0][0]);
//	printf("总平均分=%0.2f\n",Avg(a,size));
//	Search(2,a);
//	system("pause");
//}  

//57.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetMemory(char** p,int num)
{
	*p="hello,world";
}

int main()
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf("%s\n", str);
	}
	system("pause");
}