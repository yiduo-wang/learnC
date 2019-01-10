#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a+0));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a+1));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(*&a));
	printf("%d\n", sizeof(&a+1));
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0]+1));




	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr+1));
	printf("%d\n", sizeof(&arr[0] + 1));

	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr+0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr+1));
	printf("%d\n", strlen(&arr[0]+1));




	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr+0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr+1));
	printf("%d\n", sizeof(&arr[0] + 1));

	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr+0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));




	char*p = "abcdef";
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p+1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p+1));
	printf("%d\n", sizeof(&p[0]+1));

	printf("%d\n", strlen(p));
	printf("%d\n", strlen(p+1));
	printf("%d\n", strlen(*p));
	printf("%d\n", strlen(p[0]));
	printf("%d\n", strlen(&p));
	printf("%d\n", strlen(&p+1));
	printf("%d\n", strlen(&p[0] + 1));
	



	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0]+1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a+1));
	printf("%d\n", sizeof(*(a + 1)));
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));




	char a[3][5] = { '0' };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(*(a + 1)));
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));


	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d\n", *(a + 1), *(ptr - 1));


	struct Test 
	{
		int Num;
		char* pcName;
		shortsDate;
		char cha[2];
		shortsBa[4];
	}*p;
	//此结构体的大小为20个字节,假设p的值为0x100000,请问a,b,c分别是多少?(按16进制输出)
	a=p + 0x1;
	b = (unsigned long)p + 0x1;
	c = (unsigned int*)p + 0x1;


	int a[4] = { 1,2,3,4 };
	int* ptr = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr[-1], *ptr2);
	

	int a[3][2] = { (0,1),(2,3),(4,5) };
	int* p;
	p = a[0];
	printf("%d\n", p[0]);
	

	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);

	
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("&a[4][2]=%p,&p[4][2]=%p\n", &a[4][2], &p[4][2]);
	printf("&a[4][2]-&p[4][2]=%p,&a[4][2]-&p[4][2]=%d\n", &a[4][2]-&p[4][2], &a[4][2] - &p[4][2]);

	char* c[] = { "enter","new","point","first" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp+3);
	printf("%s\n", *cpp[-2]+3);
	printf("%s\n", cpp[-1][-1]+1);

	system("pause");
}