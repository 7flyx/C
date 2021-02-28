# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>


typedef struct QNODE  
{
	int data; //������
	struct QNODE* next; //ָ����
}QNODE;
typedef struct
{
	QNODE* front;
	QNODE* rear; //��ͷ����βָ��
}LinkP;
void enter_QNODE(LinkP* q, int x)
{
	//��ʽ�洢���������������
	QNODE* s = (QNODE*)malloc(sizeof(QNODE));
	if (!s)
	{
		printf("s����ʧ��\n");
		return;
	}

	s->data = x;
	s->next = NULL;
	q->rear->next = s;

	q->rear = s; //�ƶ���βָ��
}
void export_QNODE(LinkP* q, int* m)
{
	//�����ж϶����Ƿ�Ϊ��
	if (q->front == q->rear)
	{
		printf("����Ϊ��\n");
		return;
	}

	QNODE* tmp = q->front->next;  //q->front  ָ�����ͷ���
	*m = tmp->data;
	q->front->next = tmp->next;

	//ɾ���󣬻�Ӧ�ж��ǲ���ͷβָ���غ���
	if (q->rear == tmp)
	{
		//˵������ɾ���������һ��Ԫ�أ�Ӧ��βָ�����¸�ֵ��head
		q->rear = q->front;
	}
	free(tmp);
}
int main()
{
	//ͷ���----ָ���ͷ
	int x = 520;  
	int m = 0;
	QNODE* head = (QNODE*)malloc(sizeof(QNODE));
	if (!head)
	{
		printf("head:����ʧ��!\n");
		return;
	}
	LinkP* p = (LinkP*)malloc(sizeof(LinkP));
	if (!p)
	{
		printf("LinkP  ����ʧ��\n");
		return;
	}
	//��ʼ��ͷβָ��
	p->front = head;
	p->rear = head;

	//�����
	enter_QNODE(p, x);

	//������
	export_QNODE(p, &m);
	return 0;
}