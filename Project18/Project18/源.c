#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	//关于数组和指针的常见笔试题
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));//16       整个数组的大小
	//printf("%d\n",sizeof(a + 1));//4     a+0变成了指针
	//printf("%d\n", sizeof(*a));//4       *a为数组的首元素1
	//printf("%d\n", sizeof(a+1));//4      a+1变成了指针
	//printf("%d\n", sizeof(a[1]));//4     数组第二个元素的类型大小
	//printf("%d\n", sizeof(&a));//4       数组指针还是指针所以占4个字节
	//printf("%d\n", sizeof(*&a));//16     这个数组的大小
	//printf("%d\n", sizeof(&a+1));//4     数组指针还是指针
	//printf("%d\n", sizeof(&a[0]));//4    数组首元素取地址，就为指针

	//char a[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(a));//6               整个数组的大小
	//printf("%d\n", sizeof(a+0));//4             a+1变成了指针
	//printf("%d\n", sizeof(*a));//1              首元素的地址解引用       
	//printf("%d\n", sizeof(a[1]));//1            数组第二个元素
	//printf("%d\n", sizeof(&a));//4              数组指针为指针
	//printf("%d\n", sizeof(&a+1));//4            数组指针为指针  
	//printf("%d\n", sizeof(&a[0]+1));//4         数组指针为指针
	//printf("%d\n", strlen(a));//未定义行为      找不到\0,数组越界
	//printf("%d\n", strlen(a+0));//未定义行为    找不到\0,数组越界
	//printf("%d\n", strlen(*a));//未定义行为     找不到\0,数组越界
	//printf("%d\n", strlen(a[1]));//未定义行为   找不到\0,数组越界
	//printf("%d\n", strlen(&a));//未定义行为     找不到\0,数组越界
	
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));//4         p为指针，求指针大小
	//printf("%d\n", sizeof(p+1));//4       p+1为指针
	//printf("%d\n", sizeof(*p));//1        首元素地址的解引用
	//printf("%d\n", sizeof(p[0]));//1      首元素的大小
	//printf("%d\n", sizeof(&p));//4        二级指针的大小
	//printf("%d\n", sizeof(&p+1));//4      二级指针的大小
	//printf("%d\n", sizeof(&p[0]+1));//4   b指针的的大小
	//printf("%d\n",strlen(p));//6          数组的实际长度
	//printf("%d\n", strlen(p+1));//5       从数组的第二个元素开始的实际长度
	//printf("%d\n", strlen(*p));//未定义行为    字符a无\0
	//printf("%d\n", strlen(p[0]));//未定义行为    字符a无\0
	//printf("%d\n", strlen(&p));//未定义行为    二级指针无法求strlen
	//printf("%d\n", strlen(&p[0]+1));//5          b的指针

	//char a[] = "abcdef";
	//printf("%d\n", sizeof(a));//7         sizeof计算占的字节(内存）
	//printf("%d\n", sizeof(a+0));//4       首元素地址所占的字节   
	//printf("%d\n", sizeof(*a));//1        首元素地址解引用
	//printf("%d\n", sizeof(a[1]));//1      数组第二个元素
	//printf("%d\n", sizeof(&a));//4        二级指针的大小
	//printf("%d\n", sizeof(&a[0]+1));//4   b的地址所占的字节
	//printf("%d\n", strlen(a));//6         数组a的实际长度
	//printf("%d\n", strlen(a+0));//6       数组a的实际长度
	//printf("%d\n", strlen(*a));//未定义行为    字符a无法计算strlen
	//printf("%d\n", strlen(a[1]));//未定义行为    字符b无法计算strlen
	//printf("%d\n", strlen(&a));//6          数组a的实际长度 
	//printf("%d\n", strlen(&a+1));//未定义行为   数组越界了
    //printf("%d\n", strlen(&a[0]+1));//5       字符b以后的实际长度  

	int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));//48       4*4*3 4*4为第一行所占的字节，在*3是指三行总共占的字节
	//printf("%d\n", sizeof(a[0][0]));//4    第一行第一列的元素所占字节数
	//printf("%d\n", sizeof(a[0]));//16      第一行的所有元素所占的字节数
	//printf("%d\n", sizeof(a[0]+1));//4       第一行第二列的元素所占的字节
	//printf("%d\n", sizeof(*(a[0]+1)));//4    第一行第二列元素地址解引用
	//printf("%d\n", sizeof(a+1));//4            第二行数组的地址所占的字节
	//printf("%d\n", sizeof(*(a + 1)));//16      第二行地址的解引用
	//printf("%d\n", sizeof(&a[0]+1));//4        第二行地址所占的字节
	//printf("%d\n", sizeof(*(&a[0]+1)));//16    第二行数组所占的字节
	//printf("%d\n", sizeof(*a));//16           第一行数组地址解引用
	//printf("%d\n", sizeof(a[3]));//16      sizeof在编译过程中计算，未定义行为是在运行过程中访问非法内存所以不影响    


	//API  应用程序编程接口
	//ABI  应用程序二进制接口
	//size_t__cdecl strlen(const char* str);
	//__cdecl，__stdcall 调用约定

	//指针数组VS数组指针
	//int a[] = { 1,2,3,4 };
	//printf("%p\n", a+1);
	//printf("%p\n", &a+1);
	//printf("%p\n", a);

	//int* a[] = { 0 };//指针数组

	//int num = 10;
	//int* p = &num;
	//int** pp = &p; 

	//const int* p=>p指向的内容不能更改
	//int const*p=>p指向的内容不能更改
	//int* const p=>p的指向不能更改
	//int a = 10,b=20;
	//int* const p = &a;
	//printf("%d\t%p\n", *p, p);

	//void* 类型指针不能解引用
	//void* 类型指针不能进行加减
	//void* 不关注类型，能保存任意类型的指针
	//泛型编程：写了一个函数可以接受不同类型的参数，等于说是一个函数可以给不同类型的数据用
	//int a = 10;
	//int* p = &a;
	//char b = 'a';
	//p = &b;
	//
	//printf("%p\n", p+1);

	//int num = 10;
	//int* p = &num;
	//if (p == NULL)//空指针，无效指针代表，如果不为空，
		          //不能确定是否有效，但是为空，则肯定无效
	
	//char arr[] = "hehe";
	//char arr1[] = "hehe";

	//if (strcmp(arr1, arr) == 0)
	//	printf("ok\n");
	//else
	//	printf("faild\n");

	//int* p1 = arr;
	//int* p2 = arr;
	//if (arr1 == arr)
	//	printf("ok\n");
	//else
	//	printf("faild\n");

	//int* p1 = arr;
	//int* p2 = arr + 3;
	//printf("%d\n", p2-p1);

	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr+1));

	//int a = 10;
	//double* p = 20;
	//p = p - 1;
	//printf("%p\n", p);
	//&取地址操作符，获取到某个变量的地址
	//%p这个格式或字符串是专门用来打印地址的
	//printf("%p\n", p);
	//*解引用操作符(知道内存房间号，获取到内存中所对应的具体内容）
	//printf("%d\n",*p);
	//int* p = 10;
	//printf("%d\n", *p);*p不能打印出来

	//空指针，不能读也不能写
	//int* p = NULL;0和NULL等价  

	system("pause");
}