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
	//������ά����洢
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
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
		printf("��Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("�����ˣ�\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}
}


void tast()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default :
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}


int main()
{
	tast();
	return 0;
}