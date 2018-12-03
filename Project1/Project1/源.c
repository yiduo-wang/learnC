#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

char g_map[ROW][COL];

void Game()
{

}

void Mnue()
{
	int choice = 0;
	printf("===============\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("===============\n");
	printf("\n");
	printf("-------------\n");
	for (int row = 0; row < ROW; ++row)
	{
		printf("| %c | %c | %c |\n", g_map[row][0], g_map[row][1], g_map[row][2]);
		printf("-------------\n");
	}
	while (1)
	{
		printf("\n请输入你的选择\n");
		scanf("%d", &choice);
		if (choice == 1)
			Game();
		else if (choice == 0)
		{
			printf("退出游戏\n");
			break;
		}
		else
			printf("你输入的有误，请重新输入，只能输入0(退出游戏）或1（开始游戏）\n");
	}
}

void Init()
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col <= COL; ++col)
			g_map[row][col] = ' ';
	}
}

int main()
{
	Init();
	Mnue();
	system("pause");
}