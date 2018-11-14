#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//规则：
//三个字连成一条线获胜
//电脑和玩家
//玩家输入坐标，电脑随意下在无子的地方

#define ROW 3
#define COL 3
char g_board[ROW][COL];

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
			printf("| %c | %c | %c |\n", g_board[row][0],g_board[row][1],g_board[row][2]);
		    printf("|___|___|___|\n");
	}
	printf("\n");
}

void PlayerMove()
{
	printf("请玩家落子\n");
	printf("请玩家输入坐标：（row，col）\n");
	int row, col;
	while (1)
	{
		scanf("%d,%d", &row, &col);
		if (row<0 || row>ROW || col<0 || col>COL)
		{
			printf("输入坐标有误，请玩家重新输入坐标：\n");
			continue;
		}
		if (g_board[row][col] != ' ')
		{
			printf("当前位置有棋子，请玩家重新输入坐标：\n");
			continue;
		}
		g_board[row][col] = 'X';
		break;
	}

}

void ComputerMove()
{
	printf("请电脑落子\n");
	while (1)
	{
		//srand((unsigned)time(0)); 不能在这个循环里设置随机种子，因为continue执行的速度太快，1sdou都不会到，所以时间戳没有改变，所以随机种子不会变
		int row = 0, col = 0;
		row = rand() % ROW;
		col = rand() % COL;
		printf("%d,%d\n", row, col);
		if (g_board[row][col] != ' ')
		{
			printf("当前位置有棋子，请电脑重新输入坐标：\n");
			continue;
		}
		g_board[row][col] = 'O';
		break;
	}

}

char CheakWinner()
{
	int row = 0, col = 0;;
	//检查行、列、对角线是否全为‘X’或全为‘O’
	//检查行：
	for (row = 0; row < ROW; row++)
	{
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2] && g_board[row][0] != ' ')
			return g_board[row][0];
	}
	//检查列：
	for (col = 0; col < COL; col++)
	{
		if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col] && g_board[0][col] != ' ')
			return g_board[0][col];
	}
	//检查两条对角线：
	if (g_board[0][0] == g_board[1][1] && g_board[0][0] == g_board[2][2] && g_board[0][0] != ' ')
		return g_board[0][0];
	if (g_board[0][2] == g_board[1][1] && g_board[0][2] == g_board[2][0] && g_board[0][2] != ' ')
		return g_board[0][2];
	//判定是否和棋：
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
	if (row == col)
		return 'Q';

}

int main()
{
	//棋盘初始化
	Init();
	char winner;
	while (1)
	{
		//打印一个棋盘
		Print();
		//玩家落子
		PlayerMove();
		winner = CheakWinner();
		//输出 'X' 玩家获胜
		//输出‘ ’胜负未分继续游戏
		//输出 'Q' 表示和棋
		if (winner != ' ')
		{
			Print();
			break;
		}
		ComputerMove();
		//输出 'O' 电脑获胜
		//输出‘ ’胜负未分继续游戏
		//输出 'Q' 表示和棋
		winner = CheakWinner();
		if (winner != ' ')
		{
			Print();
			break;
		}
	}
	if (winner == 'X')
		printf("玩家获胜\n");
	if (winner == 'Q')
		printf("平局\n");
	if (winner == 'O')
		printf("电脑获胜\n");
	system("pause");
}