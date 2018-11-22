#include<stdio.h>
#include<stdlib.h>
#include<st.h>

int main()
{
	int num = 10;
	int* p = &num;
	if (p == NULL)//空指针，无效指针代表，如果不为空，
		          //不能确定是否有效，但是为空，则肯定无效
	{

	}
	
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