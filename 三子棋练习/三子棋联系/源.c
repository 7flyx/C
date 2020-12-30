# define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void menu()
{
	printf("*******************************\n");
	printf("****   1.play   0. exit    ****\n");
	printf("*******************************\n");
}

void game()
{
	char ret;
	char board[ROW][COL] = { 0 };//二维数组
	//1. 给数组赋值空格
	InitBoard(board, ROW, COL);//赋值空格
	//2. 初始化棋盘
	DisplayBoard(board, ROW, COL);
	//3. 走棋
	while (1)
	{
		
		//1. 玩家走棋
		PlayerMove(board, ROW, COL);
		//DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//2. 电脑走棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);  //每次判断的时候，需要重新接受ret的值，如果ret定义的太前了
		if (ret != 'C')                //只能等下次循环过来才能接受到，即就是慢了一步
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了！\n");
	}
	else
	{
		printf("平局!\n");
	}
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
			printf("退出游戏");
				break;
		default :
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}