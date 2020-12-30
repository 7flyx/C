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
	int x, y;//��������
again:
	printf("�������\n����������:>");
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
			}
			else
			{
				printf("�������ѱ�ռ�ã����������룡\n");
			}
		}
		else
		{
			printf("�Ƿ����꣬���������룡\n");
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
// 1��ʾ���ˣ�0��ʾû��
int NUM(char board[ROW][COL],int row,int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;//����
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int num = NUM(board, ROW, COL);
	for (i = 0; i < row; i++)//����
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][2];
		}
	}
	for (j = 0; j < col; j++)//����
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
		{
			return board[2][j];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[2][0];
	}
	//ƽ�ֺͼ���
	if (num == 1)
	{
		return 'Q';
	}
	return 'C';
}
