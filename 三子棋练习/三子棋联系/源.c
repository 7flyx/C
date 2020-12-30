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
	char board[ROW][COL] = { 0 };//��ά����
	//1. �����鸳ֵ�ո�
	InitBoard(board, ROW, COL);//��ֵ�ո�
	//2. ��ʼ������
	DisplayBoard(board, ROW, COL);
	//3. ����
	while (1)
	{
		
		//1. �������
		PlayerMove(board, ROW, COL);
		//DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//2. ��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);  //ÿ���жϵ�ʱ����Ҫ���½���ret��ֵ�����ret�����̫ǰ��
		if (ret != 'C')                //ֻ�ܵ��´�ѭ���������ܽ��ܵ�������������һ��
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else
	{
		printf("ƽ��!\n");
	}
}


int main()
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
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
				break;
		default :
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}