# define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void menu()
{
	printf("****************************\n");
	printf("***** 1. play  0. exit *****\n");
	printf("****************************\n");
}

void game()
{
	int ret = 0;
	srand((unsigned int)time(NULL));  //用时间戳，产生随机值
	char board[ROW][COL] = { 0 };//创建二维数组接收字符
	//1. 初始化棋盘
	InitBoard(board, ROW, COL);
	//2. 打印棋盘
	DisplayBoard(board, ROW, COL);
	//3. 下棋
	while (1)
	{
		
		//1. 玩家走棋
		PlayerMove(board, ROW, COL);
		//DisplayBoard(board, ROW, COL);//打印棋盘
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//2. 电脑走棋
		CompterMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//打印棋盘
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜你，你赢了！\n");
	}
	else if (ret == '#')
	{
		printf("不好意思，你输了！\n");
	}
	else
	{
		printf("不错哦，平局！\n");
	}

}

int main()
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
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}