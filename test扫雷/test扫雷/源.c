//# define _CRT_SECURE_NO_WARNINGS 
//
//#include"ɨ��.h"
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
//	//�׵���Ϣ�洢
//	char mine[ROWS][COLS] = { 0 };
//	char show[ROWS][COLS] = { 0 };
//	//��ʼ���׵���Ϣ
//	Initboard(mine, ROWS, COLS, '0');
//	Initboard(show, ROWS, COLS, '*');
//	///��ӡ����
//	displayboard(mine, ROW, COL);
//	displayboard(show, ROW, COL);
//	//������
//	Setmine(mine, ROW, COL);
//	displayboard(mine, ROW, COL);
//	//ɨ��
////Findmine(mine, show, ROW, COL);
//}
//void test()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		case 1:
//			game();
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
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
	printf("����������:>");
	scanf("%d", &pass);
	int i = 3;
	while (i--)
	{
		if (pass == password)
		{
			printf("������ȷ\n");
			break;
		}	
		else if(i >= 1)
		{
			printf("����������:>");
			scanf("%d", &pass);
		}
	}
	if (i == 0)
		printf("����\n");
	return 0;
}