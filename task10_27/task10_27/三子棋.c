# define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("****  1.play  0.exit  ****\n");
	printf("**************************\n");
}


void game()
{
	
	//1.创建二维数组接收
	char board[ROW][COL] = { 0 };
	int ret = 0;
	//2. 初始化棋盘
	chessboard1(board, ROW, COL);//赋值空格
	//3. 打印棋盘
	chessboard2(board, ROW, COL);
	while (1)
	{	
		//4. 玩家走棋
		PlayerMove(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//5. 电脑走棋
		DisPlayMove(board, ROW, COL);
		chessboard2(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜你，你赢了!\n");
	}
	else if(ret == '#')
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
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}