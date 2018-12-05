#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10

char g_show_map[ROW + 2][COL + 2];
char g_mine_map[ROW + 2][COL + 2];

#define DEFAULT_MINE_NUM 10

void Init()
{
	int row = 1, col = 1;
	for (row = 0; row < ROW+2; ++row)
	{
		for (col = 0; col < COL+2; ++col)
			g_show_map[row][col] = '*';
	}
	for (row = 0; row < ROW+2; ++row)
	{
		for (col = 0; col < COL+2; ++col)
			g_mine_map[row][col] = '0';
	}
	int mine_count = DEFAULT_MINE_NUM;
	while (mine_count > 0)
	{
		row = rand() % 10 + 1;
		col = rand() % 10 + 1;
		if (g_mine_map[row][col] == '1')
			continue;
		g_mine_map[row][col] = '1';
		--mine_count;
	}
}

void Print(char map[ROW+2][COL+2])
{
	int i = 1,row=0,col=0;
	printf("    ");
	for (i = 1; i <= 10; ++i)
		printf("%d ", i);
	printf("\n");
	printf("   ----------------------");
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
		printf("%2d| ", row);
		for (col = 1; col <= COL; ++col)
			printf("%c ", map[row][col]);
		printf("\n");
	}
}

void UpdateMap(char g_show_map[ROW + 2][COL + 2], char g_mine_map[ROW + 2][COL + 2], int row, int col)
{
	int tmp1 = row,tmp2=col;
	int mine_cnt = (g_mine_map[row - 1][col - 1] - '0') + (g_mine_map[row - 1][col] - '0')
		+ (g_mine_map[row][col - 1] - '0') + (g_mine_map[row][col + 1] - '0')
		+ (g_mine_map[row + 1][col - 1] - '0') + (g_mine_map[row + 1][col] - '0')
		+ (g_mine_map[row + 1][col + 1] - '0') + (g_mine_map[row - 1][col + 1] - '0');
	g_show_map[row][col] = '0' + mine_cnt;
	if(g_show_map[row][col]=='0')
		for (row = tmp1 - 1; row <= tmp1 + 1; ++row)
		{
			if (row < 1 || row>10)
				continue;
			for (col = tmp2 - 1; col <= tmp2+1; ++col)
			{
				if (col < 1 || col>10)
					continue;
				int mine_cnt = (g_mine_map[row - 1][col - 1] - '0') + (g_mine_map[row - 1][col] - '0')
					+ (g_mine_map[row][col - 1] - '0') + (g_mine_map[row][col + 1] - '0')
					+ (g_mine_map[row + 1][col - 1] - '0') + (g_mine_map[row + 1][col] - '0')
					+ (g_mine_map[row + 1][col + 1] - '0') + (g_mine_map[row - 1][col + 1] - '0');
				g_show_map[row][col] = '0' + mine_cnt;
			}
		}
}

void Game()
{
	Init();
	Print(g_show_map);
	int row = 0, col = 0, blank_cnt=0;;
	while (1)
	{
		printf("请输入你要掀开的位置\n");
		scanf("%d %d", &row, &col);
		if (row < 1 || row>ROW || col < 1 || col>COL)
		{
			printf("输入错误，请重新输入\n");
			continue;
		}
		if (g_mine_map[row][col] == '1')
		{
			Print(g_mine_map);
			printf("踩雷了，游戏结束\n");
			break;
		}
		UpdateMap(g_show_map, g_mine_map, row, col);
		Print(g_show_map);
		printf("\n");
		for (row = 1; row <= ROW; ++row)
		{
			for (col = 1; col <= COL; ++col)
			{
				if (g_show_map[row][col] == '*')
					++blank_cnt;
					
			}
		}
		printf("%d\n",blank_cnt);
		if (blank_cnt == 10)
		{
			Print(g_mine_map);
			printf("扫雷成功，玩家胜利\n");
			break;
		}
		blank_cnt = 0;
	}
	

}

void Mnue()
{
	int choice = 0;
	printf("=================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=================\n");
	while (1)
	{
		printf("请输入您的选择 1.开始游戏 0.结束游戏\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("开始游戏\n");
			Game();
		}
		else if (choice == 0)
		{
			printf("游戏结束\n");
			break;
		}
		else
			printf("输入错误，只能输入1（开始游戏）  0（退出游戏）\n");
	}
}

int main()
{
	srand((unsigned)time(0));
	Mnue();
	system("pause");
}