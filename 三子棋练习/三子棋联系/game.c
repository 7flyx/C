# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}



void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;//横纵坐标
again:
	printf("玩家走棋\n请输入坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
			}
			else
			{
				printf("该坐标已被占用，请重新输入！\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入！\n");
			goto again;
		}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
again:	
	x = rand() % 3;
	y = rand() % 3;

	if (board[x][y] == ' ')
	{
		board[x][y] = '#';
	}
	else
	{
		goto again;
	}
}
// 1表示满了，0表示没满
int NUM(char board[ROW][COL],int row,int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int num = NUM(board, ROW, COL);
	for (i = 0; i < row; i++)//横向
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][2];
		}
	}
	for (j = 0; j < col; j++)//纵向
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
		{
			return board[2][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[2][0];
	}
	//平局和继续
	if (num == 1)
	{
		return 'Q';
	}
	return 'C';
}
