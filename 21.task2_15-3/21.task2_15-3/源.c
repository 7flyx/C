# define _CRT_SECURE_NO_WARNINGS 

#include "����ʽ�ӷ�.h"


int main()
{

	Link headA = (Link)malloc(sizeof(Node));
	headA->next = NULL;


	Link headB = (Link)malloc(sizeof(Node));
	headB->next = NULL;
	//д��������ʽ��������洢
	Input_Num(headA);
	show_Num(headA);
	Input_Num(headB);
	//show_Num(headB);

	Add_Num(headA, headB);
	//�ͷ�headB�Ŀռ�
	free(headB);
	headB = NULL;

	Link p = headA->next;
	printf("�ϲ�֮��ĵ�ʽΪ��\n");
	while (p)
	{
		printf("%d %d\n", p->coefficient, p->exponent);
		p = p->next;
	}

	return 0;
}