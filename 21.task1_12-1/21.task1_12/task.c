# define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"



void menu()
{
	printf("***********************************\n");
	printf("*****   1. add      2. del   ******\n");
	printf("*****   3. search   4. modifi******\n");
	printf("*****   5. show     0. exit  ******\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	struct Con con; //����һ��ͨѶ¼���ͣ��൱��һ��ͨѶ¼������con
	Initcontact(&con); //��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			//����ADD�ȳ��������ֵ�������ж�
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFI:
			modifi_contact(&con);
			break;
		case SHOW :
			show_contact(&con);
			break;
		default :
			printf("ѡ�����\n");
			break;
		}
	} while(input);
	return 0;
}