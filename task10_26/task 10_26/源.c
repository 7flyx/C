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
	srand((unsigned int)time(NULL));  //��ʱ������������ֵ
	char board[ROW][COL] = { 0 };//������ά��������ַ�
	//1. ��ʼ������
	InitBoard(board, ROW, COL);
	//2. ��ӡ����
	DisplayBoard(board, ROW, COL);
	//3. ����
	while (1)
	{
		
		//1. �������
		PlayerMove(board, ROW, COL);
		//DisplayBoard(board, ROW, COL);//��ӡ����
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//2. ��������
		CompterMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//��ӡ����
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("������˼�������ˣ�\n");
	}
	else
	{
		printf("����Ŷ��ƽ�֣�\n");
	}

}

int main()
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
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}