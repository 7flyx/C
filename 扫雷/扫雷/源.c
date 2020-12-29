# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"

void menu()
{
	printf("********************\n");
	printf("****   1.  play ****\n");
	printf("****   0.  exit ****\n");
	printf("********************\n");
}

void game()
{
	//创建二维数组
	char mine[ROWS][COLS] = { 0 };//埋雷
	char show[ROWS][COLS] = { 0 };

	//初始化数组
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//打印棋盘
	//Printboard(mine, ROWS, COLS);
	Printboard(show, ROWS, COLS);

	//自动埋雷
	Setboard(mine, ROW, COL);
	//Printboard(mine, ROWS, COLS);

	//扫雷
	Playerboard(mine, show, ROWS, COLS);	
}

void tast()
{
	int input;
	srand((unsigned int)time(NULL));
	
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷开始！\n");
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			break;
		}


	} while (input);
}

int main()
{
	tast();
	return 0;
}