# define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"


void menu()
{
	printf("*******************************\n");
	printf("*****  1.add      2.del   *****\n");
	printf("*****  3.search   4.modifi*****\n");
	printf("*****  5.show     6.sort  *****\n");
	printf("*****  7. save    0.exit  *****\n");
	printf("*******************************\n");
}
int main()
{
	//����ͨѶ¼
	struct Con con;
	//��ʼ��ͨѶ¼
	Initcontact(&con);
	int input = 0;
	do
	{
		menu();
		//printf("��ѡ����:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			sear_contact(&con);
			break;
		case MODIFI:
			modi_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//�ͷ�malloc���ٵ��ڴ�ռ�
			Save_contact(&con);
			DestroyCapacity(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		case SAVE:
			Save_contact(&con);
			break;
		default :
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}