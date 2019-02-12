#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1;
	int b = 2;
	int x1 = a & b;
	//a二进制为:00000000000000000000000000000001
	//b二进制为:00000000000000000000000000000010
	//a&b=     00000000000000000000000000000000
	int x2 = a | b;
	//a|b=     00000000000000000000000000000011
	int x3 = a ^ b;
		//a^b=     00000000000000000000000000000011
	unsigned int x4 = ~a;
	//a~=11111111111111111111111111111110
	printf("x1=%d,x2=%d,x3=%d,x4=%lu\n", x1, x2, x3, x4);
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = -10;
	int* p = NULL;
	a = -a;
	p = &a;
	printf("!2=%d\n", !2);
	printf("!0=%d\n", !0);
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("*p=%d\n", *p);
	printf("&a=%p\n", &a);
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1;
	int b = a++;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	int c = a--;
	printf("a=%d\n", a);
	printf("c=%d\n", c);
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 2, c = 3;
	int x = a++&&++b&&c++;
	printf("x=%d,a=%d,b=%d,c=%d\n", x, a, b, c);
	a = 0; b = 2; c = 3;
	int y = a++ || ++b || c++;
	printf("y=%d,a=%d,b=%d,c=%d\n", y, a, b, c);
	system("pause");
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = -10;
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; ++i)
	{
		if (((a >> 1) & 1) == 1)
			++count;
	}
	printf("count=%d\n", count);
	system("pause");
}