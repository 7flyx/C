# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void menu()
{
	printf("*******************************\n");	
	printf("*****  1. paly   0. exit  *****\n");
	printf("*******************************\n");
}
void game()
{
	int ret = 0;
	srand((unsigned int)time(NULL));
	//创建二维数组存储
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家走棋
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑走棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("你赢了！\n");
	}
	else if (ret == '#')
	{
		printf("你输了！\n");
	}
	else
	{
		printf("平局！\n");
	}
}


void tast()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default :
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}


int main()
{
	tast();
	return 0;
}