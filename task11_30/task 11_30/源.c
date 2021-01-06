# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void game()
{
	char show[ROWS][COLS] = { 0 };//显示打印前后的数据
	char mine[ROWS][COLS] = { 0 };
	int bomb = ROW * COL - BOMB_NUM;

	Initboard(show, ROWS, COLS, '0');//初始化棋盘
	Initboard(mine, ROWS, COLS, '*');

	PrintBoard(mine, ROW, COL);//打印棋盘
	//PrintBoard(show, ROW, COL);

	SetBoard(show, ROW, COL);//埋雷
	PrintBoard(show, ROW, COL);

again:
	PlayerBoard(show,mine,ROWS,COLS);//玩家扫雷
	PrintBoard(mine, ROW, COL); 
	if (bomb > 0)
	{
		goto again;
	}
	else
	{
		printf("恭喜你扫雷成功!\n");
	}
}
void menu()
{
	printf("***********************\n");
	printf("******   1. play  *****\n");
	printf("******   0. exit  *****\n");
	printf("***********************\n");

}
void tast()
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
			game();
			break;
		case 0:
			printf("退出游戏!!\n");
			break;
		default :
			printf("选择错误，请重新输入!!\n");
			break;
		}
	} while (input);

	return 0;
}


int main()
{
	tast();
	return 0;
}

