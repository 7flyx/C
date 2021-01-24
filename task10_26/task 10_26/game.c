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
			board[i][j] = ' ';   //�ո񣬱�ʾ����Ϊ�հ�
		}
	}
}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)   //��
	{
		//��ӡһ�е�����
		int j = 0;
		for (j = 0; j < col; j++)  //��
		{
			// ��ӡÿһ�е�����
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}			
		}
		printf("\n");
		if (i < row - 1)   //���if��� ��ֹ���һ�е��»�������
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

	printf("�������:>\n");
	
	while (1)
	{
		
		printf("����������:>");
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ռ�ã����������룡\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}


void CompterMove(char board[ROW][COL], int row, int col)
{
	printf("��������:>\n");
	int x = 0;
	int y = 0;
again:
	x = rand() % row;  //ȡģ���Ѻ������������0--2֮��
	y = rand() % col;  //����rand������ֵ��������srand��<stdlib.h>
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
				return 0;  //û��������0��ʾû��
			}
		}
	}
	return 1;//���ˣ�����1��ʾ����
}


//�ж��ķ�Ӯ�˻���ƽ��
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int num = NUM(board, ROW, COL);
	for (i = 0; i < row; i++)
	{//�ж���������Ƿ����
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{//�ж����������Ƿ����
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�ж϶Խ����Ƿ����
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
