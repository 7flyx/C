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
	//������ά����
	char mine[ROWS][COLS] = { 0 };//����
	char show[ROWS][COLS] = { 0 };

	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//��ӡ����
	//Printboard(mine, ROWS, COLS);
	Printboard(show, ROWS, COLS);

	//�Զ�����
	Setboard(mine, ROW, COL);
	//Printboard(mine, ROWS, COLS);

	//ɨ��
	Playerboard(mine, show, ROWS, COLS);	
}

void tast()
{
	int input;
	srand((unsigned int)time(NULL));
	
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ�׿�ʼ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
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