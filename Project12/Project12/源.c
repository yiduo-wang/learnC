#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define OUT 0
#define IN 1
#define ROW 3
#define COL 3
g_board[ROW][COL];
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

BubbleSort(int* arr, int size)
{
//从前往后找最大
	int bound = size - 1;
	for (; bound > 0; bound--)
	{
		int cul = 0;
		for (; cul < bound; cul++)
		{
			if (arr[cul]>arr[cul + 1])
			{
				Swap(&arr[cul], &arr[cul + 1]);
			}
		}
	}
//	从后往前找最小
//	int bound = 0;
//	for (; bound < size - 1; bound++)
//	{
//		int cul = size - 1;
//		for (; cul>bound; cul--)
//		{
//			if (arr[cul] < arr[cul - 1])
//				Swap(&arr[cul], &arr[cul - 1]);
//		}
//	}

}
//三子棋规则：
//1.棋盘（全局变量）
//2.玩家和电脑

void Init()
{
	srand((unsigned)time(0));
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
			g_board[row][col] = ' ';
	}
}

void Print()
{
	printf("____________\n");
	for (int row = 0; row < ROW; row++)
	{
		printf("| %c | %c | %c |\n", g_board[row][0], g_board[row][1], g_board[row][2]);
		printf("|___|___|___|\n");
	}
	printf("\n");
}

void PlayerMove()
{
	int col = 0, row = 0;
	printf("请玩家落子\n");
	printf("请玩家输入坐标：（row，col)\n");
	while (1)
	{
		scanf("%d %d", &row , &col);
		if (row<0 || row>ROW || col<0 || col>COL)
		{
			printf("输入坐标有误，请玩家重新输入坐标：\n"); 
			continue;
		}
		if (g_board[row][col] != ' ')
		{
			printf("此处已有棋子，请重新输入坐标\n");
			continue;
		}
		g_board[row][col] = ' X';
		break;
	}
	
}

char CheckWinner()
{
	int col = 0, row = 0;
	for (row=0; row < ROW; row++)
	{
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2] && g_board[row][0] != ' ')
			return g_board[row][0];
	}
	for (col=0; col < COL; col++)
	{
	if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col] && g_board[0][col] != ' ')
		return g_board[0][col];
	}
	if (g_board[0][0] == g_board[1][1] && g_board[0][0] == g_board[2][2] && g_board[0][0] != ' ')
		return g_board[0][0];
	if (g_board[0][2] == g_board[1][1] && g_board[0][2] == g_board[2][0] && g_board[0][2] != ' ')
		return g_board[0][2];
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if (g_board[row][col] == ' ')
			{
				return ' ';
				break;
			}
		}	
	}
	if (col==row)
		return 'Q';
}

void ComputerMove()
{
	printf("请电脑落子:\n");
	while (1)
	{
		int row = 0, col = 0;
		 row = rand() % ROW ;
		 col = rand() % COL ;
		 printf("%d,%d\n", row, col);
		if (g_board[row][col] != ' ')
		{
			printf("此处已经有棋子，请电脑重新落子：\n");
			continue;
		}
		g_board[row][col] = 'O';
		break;
	}
}

int main()
{
	 char winner;
	//初始化棋盘
	Init();
	Print();
	while(1)
	{
		PlayerMove();
		Print();
		winner = CheckWinner();
		if (winner != ' ')
		{
			Print();
			break;
		}
		ComputerMove();
		Print();
		winner = CheckWinner();
		if (winner != ' ')
		{
			Print();
			break;
		}
	}
	if (winner == 'X')
		printf("玩家获胜\n");
	if (winner == 'O')
		printf("电脑获胜\n");
	if (winner == 'Q')
		printf("平局\n");

	//int arr[] = { 9, 5, 2, 7 };
	//int size = (sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, size);
	//for (int i = 0; i < size ;i++)
	//	printf("%d\t", arr[i]);
	system("pause");
}