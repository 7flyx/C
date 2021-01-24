# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';   //空格，表示棋盘为空白
		}
	}
}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)   //行
	{
		//打印一行的数据
		int j = 0;
		for (j = 0; j < col; j++)  //列
		{
			// 打印每一列的数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}			
		}
		printf("\n");
		if (i < row - 1)   //这个if语句 防止最后一行的下划线问题
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家走棋:>\n");
	
	while (1)
	{
		
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入！\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}


void CompterMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走棋:>\n");
	int x = 0;
	int y = 0;
again:
	x = rand() % row;  //取模，把横纵坐标控制在0--2之间
	y = rand() % col;  //引用rand这个随机值，得引用srand和<stdlib.h>
	if (board[x][y] == ' ')
	{
		board[x][y] = '#';
	}
	else
	{
		goto again;
	}
}

int NUM(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;  //没满，返回0表示没满
			}
		}
	}
	return 1;//满了，返回1表示满了
}


//判断哪方赢了或是平局
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int num = NUM(board, ROW, COL);
	for (i = 0; i < row; i++)
	{//判断向横数据是否相等
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{//判断纵向数据是否相等
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断对角线是否相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
	{
		return board[0][2];
	}
	if (0 == num)
	{
		return 'C';
	}
	return 'Q';
}
