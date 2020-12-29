# define _CRT_SECURE_NO_WARNINGS 



#include "game.h"



void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}

}

void Printboard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	for (i = 0; i < cols - 1; i++)
	{
		printf("%d ", i);//打印列号
	}
	printf("\n");
	for (i = 1; i < rows - 1; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}


void Setboard(char board[ROWS][COLS], int row, int col)
{
	//void srand(unsigned seed);
	int x, y;
	int i = 0;
	i = MAX_set;
	while (i)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			i--;
		}
		
	}
}

int get_set(char mine[ROWS][COLS], int x, int y)
{
	return mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x - 1][y] +
		mine[x + 1][y] - 8 * '0';
}


Self_action(int x)
{
	int n = rand() % 3;
	switch (n)
	{
	case 1:
		x += 1;
		break;
	case 2:
		x -= 1;
		break;
	case 0:
		x += 0;
		break;
	default:
		break;
	}
	return x;
}

void Playerboard(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	int x, y;
	int ret = ROW * COL - MAX_set;
	while (ret)
	{
		
	again:
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x < rows - 1 && y >= 1 && y < cols - 1)
		{
			if (mine[x][y] == '1')
			{
				//炸死
				Printboard(mine, ROWS, COLS);
				printf("游戏结束！\n");
				break;
			}
			else
			{
				//没炸死
			agains:
				show[x][y] = get_set(mine, x, y) + '0';
				if (show[x][y] == '0')
				{
					x = Self_action(x);
					y = Self_action(y);
					goto agains;
				}
				else
				{
					Printboard(show, ROWS, COLS);
				}
			}
		}
		else
		{
			printf("坐标非法，请重新输入！!");
			goto again;
		}
		int n = Check_board(show, ROW, COL);
		ret -= n;
		if (ret == ROW * COL - MAX_set)
		{
			printf("恭喜你，你赢了！\n");
		}
	}	
}


int Check_board(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] != '*')
				;
			else
				count++;
		}
	}
	return count;
}