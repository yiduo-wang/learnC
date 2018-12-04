#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define ROW 3
#define COL 3

char g_map[ROW][COL];

void Print()
{
	printf("_____________\n");
	for (int row = 0; row < ROW; ++row)
	{
		printf("| %c | %c | %c |\n", g_map[row][0], g_map[row][1], g_map[row][2]);
		printf("|___|___|___|\n");
	}
	printf("\n");
}

void PlayerMove()
{
	int row = 0, col = 0;
	printf("请玩家落子\n");
	while (1)
	{
		scanf("%d %d", &row, &col);
		if (row < 0 || row>2 || col < 0 || col>2)
		{
			printf("你输入的坐标有误，请重新输入\n");
			continue;
		}
		else if (g_map[row][col] != ' ')
		{
			printf("此处已经有棋子了，请重新落子\n");
			continue;
		}
		else
			break;
	}
	g_map[row][col] = 'X';
}

void ComputerMove()
{
	int row = 0, col = 0;
	printf("请电脑落子\n");
	while (1)
	{
		row = rand() % 3;
		col = rand() % 3;
		printf("%d,%d\n", row, col);
		if (g_map[row][col] != ' ')
		{
			printf("此处已经有棋子了，请电脑重新落子\n");
			continue;
		}
		else
			break;
	}
	g_map[row][col] = 'O';
}

char CheckWinner()
{
	int row = 0, col = 0;
	for ( row = 0; row < ROW; ++row)
	{
		if (g_map[row][0] == g_map[row][1] && g_map[row][0] == g_map[row][2])
			return g_map[row][0];
	}
	for ( col = 0; col < ROW; ++col)
	{
		if (g_map[0][col] == g_map[1][col] && g_map[0][col] == g_map[2][col])
			return g_map[0][col];
	}
	if (g_map[0][0] == g_map[1][1] && g_map[0][0] == g_map[2][2])
		return g_map[0][0];
	if (g_map[0][2] == g_map[1][1] && g_map[0][2] == g_map[2][0])
		return g_map[0][2];
	for ( row = 0; row < ROW; ++row)
	{
		for ( col = 0; col < COL; ++col)
		{
			if (g_map[row][col] == ' ')
			{
				return ' ';
				break;
			}
		}	
	}
	if (row == col)
		return 'Q';
}

void Init()
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col <= COL; ++col)
			g_map[row][col] = ' ';
	}
}

void Game()
{
	char winner = 0;
	Init();
	while (1)
	{
		PlayerMove();
		Print();
		winner = CheckWinner();
		if (winner != ' ')
			break;
		ComputerMove();
		Print();
		winner = CheckWinner();
		if (winner != ' ')
			break;
	}
	if (winner == 'X')
		printf("玩家胜利\n");
	if (winner == 'O')
		printf("电脑胜利\n");
	if (winner == 'Q')
		printf("和棋\n");
}

void Mnue()
{
	int choice = 0;
	printf("===============\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("===============\n");
	printf("\n");
	Print();
	while (1)
	{
		printf("请输入你的选择,输入1（开始游戏） 0(退出游戏）\n");
		scanf("%d", &choice);
		if (choice == 1)
			Game();
		else if (choice == 0)
		{
			printf("退出游戏\n");
			break;
		}
		else
			printf("你输入的有误\n");
	}
}

int main()
{
	srand((unsigned)time(0));
	Mnue();
	system("pause");
}