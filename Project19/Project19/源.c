#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10
#define DEFAULT_MINE_COUNT 10

char g_show_map[ROW + 2][COL + 2];
char g_mine_map[ROW + 2][COL + 2];

int Menu()
{
	int choice = 0;
	printf("===============\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("请输入您的选择（0或1）：\n");
	scanf("%d", &choice);
	return choice;
}

void Init(char g_show_map[ROW + 2][COL + 2], char g_mine_map[ROW + 2][COL + 2])
{
	for (int row = 0; row < ROW + 2; row++)
	{
		for (int col = 0; col < COL + 2; col++)
			g_show_map[row][col] = '*';
	}
	for (int row = 0; row < ROW + 2; row++)
	{
		for (int col = 0; col < COL + 2; col++)
			g_mine_map[row][col] = '0';
	}
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count > 0)
	{
		int row = rand() % 10 + 1;
		int col = rand() % 10 + 1;
		if (g_mine_map[row][col] == '1')
			continue;
		g_mine_map[row][col] = '1';
		--mine_count;
	}

}

void Displaymap(char map[ROW + 2][COL + 2])
{
	printf("    ");
	for (int i = 1; i <= COL; ++i)
		printf("%d ", i);
	printf("\n");
	printf("   ---------------------\n");
	printf("\n");
	for (int row = 1; row <= ROW; ++row)
	{
		printf("%2d| ", row);
		for (int col = 1; col <= COL; ++col)
			printf("%c ", map[row][col]);
		printf("\n");
	}
}

void Updatemap(char g_show_map[ROW + 2][COL + 2], char g_mine_map[ROW + 2][COL + 2], int row, int col)
{
	int mine_cnt = (g_mine_map[row - 1][col - 1] - '0') + (g_mine_map[row - 1][col] - '0')
		+ (g_mine_map[row][col - 1] - '0') + (g_mine_map[row][col + 1] - '0')
		+ (g_mine_map[row + 1][col - 1] - '0') + (g_mine_map[row + 1][col] - '0')
		+ (g_mine_map[row + 1][col + 1] - '0') + (g_mine_map[row - 1][col + 1] - '0');
	g_show_map[row][col] = '0' + mine_cnt;
	if (g_show_map[row][col] == '0')
	{
		int tmp1 = 0, tmp2 = 0;
		tmp1 = row; tmp2 = col;
		for (row = tmp1 - 1; row <= tmp1 + 1; ++row)
		{
			if (row  <1 || row >10)
			{
				continue;
			}
			for (col = tmp2 - 1; col <= tmp2 + 1; ++col)
			{
				if (col <1 || col > 10)
				{
					continue;
				}
				 mine_cnt = (g_mine_map[row - 1][col - 1] - '0') + (g_mine_map[row - 1][col] - '0')
					+ (g_mine_map[row][col - 1] - '0') + (g_mine_map[row][col + 1] - '0')
					+ (g_mine_map[row + 1][col - 1] - '0') + (g_mine_map[row + 1][col] - '0')
					+ (g_mine_map[row + 1][col + 1] - '0') + (g_mine_map[row - 1][col + 1] - '0');
				g_show_map[row][col] = '0' + mine_cnt;
	
			}
		}
	}

}

void Game()
{
	int blank_cnt = 0;
	srand((unsigned)time(0));
	Init(g_show_map, g_mine_map);
	Displaymap(g_show_map);
	while (1)
	{
		int row = 0, col = 0;
		printf("请输入要掀开位置的坐标：\n");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{
			printf("输入错误，请重新输入坐标：\n");
			continue;
		}
		if (g_mine_map[row][col] == '1')
		{
			Displaymap(g_mine_map);
			printf("踩雷了，游戏结束\n");
			break;
		}

		Updatemap(g_show_map, g_mine_map, row, col);
		Displaymap(g_show_map);
		printf("\n");
		blank_cnt = 0;
		for (row = 1; row <= ROW; ++row)
		{
			for (col = 1; col <= COL; ++col)
			{
				if (g_show_map[row][col] != '*')
				{
					++blank_cnt;
					if (blank_cnt == ROW * COL - DEFAULT_MINE_COUNT)
					{
						Displaymap(g_mine_map);
						printf("扫雷成功，游戏结束\n");
						break;
					}
				}
			}
		}
		printf("\n");
	}

}

void Start()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 0)
		{
			printf("游戏结束\n");
			break;
		}

		Game();
	}
}
int main()
{
	Start();
	system("pause");
}