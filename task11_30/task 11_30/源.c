# define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void game()
{
	char show[ROWS][COLS] = { 0 };//��ʾ��ӡǰ�������
	char mine[ROWS][COLS] = { 0 };
	int bomb = ROW * COL - BOMB_NUM;

	Initboard(show, ROWS, COLS, '0');//��ʼ������
	Initboard(mine, ROWS, COLS, '*');

	PrintBoard(mine, ROW, COL);//��ӡ����
	//PrintBoard(show, ROW, COL);

	SetBoard(show, ROW, COL);//����
	PrintBoard(show, ROW, COL);

again:
	PlayerBoard(show,mine,ROWS,COLS);//���ɨ��
	PrintBoard(mine, ROW, COL); 
	if (bomb > 0)
	{
		goto again;
	}
	else
	{
		printf("��ϲ��ɨ�׳ɹ�!\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!!\n");
			break;
		default :
			printf("ѡ���������������!!\n");
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

