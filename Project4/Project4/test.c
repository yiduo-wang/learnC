//二分查找法
#include<stdio.h>
#include<stdlib.h>
int Binarysearch(int* arr,int key,int left,int right )
{
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < key)
			left=mid+1;
		else if (arr[mid]>key)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	printf("%d\n",Binarysearch(arr,6,left,right));
	system("pause");
}

//关机程序
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main()
{
	char input[1024] = { 0 };
	system("shutdown -s -t 120");
	while (1)
	{
		printf("你的电脑将在120s后关机，如果输入：我是猪，可以取消关机\n");
		scanf("%s", &input);
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}

	}
	system("pause");
	return 0;
}

//猜数字游戏
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Menu()
{
	int choice = 0;
	printf("1.开始游戏     2.退出游戏\n请输入您的选择\n");
	scanf("%d", &choice);
	return choice;
}
void Game()
{
	int input = 0;
	srand((unsigned)time(0));  //设置了一个时间戳，使得随机种子在每次第一次运行时得以初始化。
	int cpt_rand_num= rand() % 100 + 1;   //电脑给的随机数为1-100
	while (1)
	{
		printf("请输入一个数字\n");
		scanf("%d", &input);
		if (input > cpt_rand_num)
			printf("高了\n");
		else if (input < cpt_rand_num)
			printf("低了\n");
		else
		{
			printf("congratulations  猜对了\n");
			break;
		}
	}
}
int main()
{
	while (1)
	{
		int choice = 0;
		choice = Menu();  //登陆界面
		if (choice == 1)
		{
			printf("开始游戏 welcome\n");
			Game();   //游戏开始界面
		}
		if (choice == 2)
		{
			printf("退出游戏 goodbye\n");
			break;
		}
	}
	system("pause");
}