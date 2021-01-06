# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void Initboard(char show[ROWS][COLS], int rows, int cols,char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			show[i][j] = set;
		}
	}
}
void PrintBoard(char mine[ROWS][COLS], int row, int col)
{
	int i,j;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%d ", i + 1);
		for (j = 0; j < col; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
}

void SetBoard(char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int bomb = BOMB_NUM;
	while (bomb)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (show[x][y] == '0')
		{
			show[x][y] = '1';
			bomb--;
		}	
	}
}



int get_show(char show[ROWS][COLS], int x, int y)
{
	return show[x - 1][y] +
		show[x - 1][y - 1] +
		show[x][y - 1] +
		show[x + 1][y - 1] +
		show[x + 1][y] +
		show[x + 1][y + 1] +
		show[x][y + 1] +
		show[x - 1][y + 1] - 8 * '0';
}
void PlayerBoard(char show[ROWS][COLS], char mine[ROWS][COLS], int rows, int cols)
{
	int x,y;
again:	
	printf("�������������:>");
	scanf("%d%d", &x, &y);
	if ((x - 1) >= 0 && (x - 1) < rows && (y - 1) >= 0 && (y - 1) < cols)
	{
		//����Ϸ�
		if (show[x - 1][y - 1] == '1')
		{
			printf("�Բ����㱻ը���ˣ�\n");
		}
		else
		{
			//����һ����ֵ�����׵�����
			mine[x - 1][y - 1] = get_show(show,x, y) + '0';
		}
	}
	else
	{
		//����Ƿ�
		printf("����Ƿ�������������!\n");
		goto again;
	}
}