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
	
	//1.������ά�������
	char board[ROW][COL] = { 0 };
	int ret = 0;
	//2. ��ʼ������
	chessboard1(board, ROW, COL);//��ֵ�ո�
	//3. ��ӡ����
	chessboard2(board, ROW, COL);
	while (1)
	{	
		//4. �������
		PlayerMove(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//5. ��������
		DisPlayMove(board, ROW, COL);
		chessboard2(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬��Ӯ��!\n");
	}
	else if(ret == '#')
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
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}