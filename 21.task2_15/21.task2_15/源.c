# define _CRT_SECURE_NO_WARNINGS 
#include "Student.h"

void menu()
{
	printf("* * * * * * * ��  �� * * * * * * *\n");
	printf("    1 ����ѧ����Ϣ   2 ɾ��ѧ����Ϣ\n");
	printf("    3 ����ѧ����Ϣ   4 �޸�ѧ����Ϣ\n");
	printf("    5 ��ʾѧ����Ϣ   6 ͳ��ѧ������\n");
	printf("    0 �˳�ϵͳ\n");
	printf("* * * * * * * * * * * * * * * * * *\n");
}

int main()
{
	//����ͷ���
	Link head = (Link)malloc(sizeof(Node));
	head->next = NULL;

	//�˵�������ϵͳ�Ȳ���
	int input = 0;
	do
	{
		menu(); 
		printf("��ѡ�����:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_student(head);
			break;
		case DELETE:
			dele_student(head);
			break;
		case SEARCH:
			sear_student(head);
			break;
		case MODIFIY:
			modi_strdent(head);
			break;
		case SHOW:
			show_student(head);
			break;
		case STATISTICS:
			statis_student(head);
			break;
		case EXIT:
			//����������ͷſռ�
			clear_list(head);
			break;
		}
	} while (input);


	return 0;
}