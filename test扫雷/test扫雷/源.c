//# define _CRT_SECURE_NO_WARNINGS 
//
//#include"扫雷.h"
//
//
//void menu()
//{
//	printf("*********************************\n");
//	printf("********1.play   0.exit**********\n");
//	printf("*********************************\n");
//}
//void game()
//{
//	//雷的信息存储
//	char mine[ROWS][COLS] = { 0 };
//	char show[ROWS][COLS] = { 0 };
//	//初始化雷的信息
//	Initboard(mine, ROWS, COLS, '0');
//	Initboard(show, ROWS, COLS, '*');
//	///打印棋盘
//	displayboard(mine, ROW, COL);
//	displayboard(show, ROW, COL);
//	//布置雷
//	Setmine(mine, ROW, COL);
//	displayboard(mine, ROW, COL);
//	//扫雷
////Findmine(mine, show, ROW, COL);
//}
//void test()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("退出游戏\n");
//			break;
//		case 1:
//			game();
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}


int main()
{
	int password = 201611;
	int pass = 0;
	printf("请输入密码:>");
	scanf("%d", &pass);
	int i = 3;
	while (i--)
	{
		if (pass == password)
		{
			printf("密码正确\n");
			break;
		}	
		else if(i >= 1)
		{
			printf("请重新输入:>");
			scanf("%d", &pass);
		}
	}
	if (i == 0)
		printf("冻结\n");
	return 0;
}