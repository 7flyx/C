# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

typedef struct Node
{
	int data;  //������
	struct Node* next; //ָ����
}*Link,node;


//����---ͷ�巨
Link LinkLastList(int arr[10])
{
	//����ͷ���
	Link head_p = (Link)malloc(sizeof(node));
	head_p->next = NULL;

	//ѭ������һ���
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		Link note = (Link)malloc(sizeof(node));
		note->data = arr[i];
		note->next = head_p->next;
		head_p->next = note;
		
	}
	return head_p; //����ͷ����ָ����
}

//����---β�巨
Link LinkLastList(int arr[10])
{
	//����ͷ���
	Link head = (Link)malloc(sizeof(node));
	head->next = NULL;
	Link rear = head;  //����һ��β���

	//ѭ��
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		Link note = (Link)malloc(sizeof(node));
		note->data = arr[i];
		note->next = NULL; //β����ָ���򸳿�ֵ���������������ѭ��
		rear->next = note;  //��β����ָ�������note
		rear = note;  //����β����ֵ
	}

	return head; //����ͷ���ĵ�ַ
}


//ɾ��ĳ������
int DeleteList(Link head, int x)
{
	//1.���ȿ��Ƿ�Ϊ�ձ�
	if (head == NULL || head->next == NULL)
		return 0;  

	//2.����ǰ���㣬p��q
	Link p = head->next; //ָ���һ���
	Link q = head; //ָ��ǰһ���

	//3. ѭ�����ң��ҵ���ɾ����㲢����1
	while (p != NULL)
	{
		//�ж��Ƿ����
		if (p->data == x)
		{
			q->next = p->next;
			free(p);
			return 1;
		}
		else
		{
			q = p;
			p = p->next;  //p��q��ֵ����һ�����
		}
	}

	//ѭ�����˵��û�ҵ�
	return 0;
}

int main()
{
	//������---ͷ�巨
	int arr[10] = { 1,3,4,5,6,7,8,3,8,2 };
	node head = { 0 };
	Link ps = LinkLastList(arr); //���շ��ص�ͷ����ָ����

	DeleteList(3);// ɾ���������е�ĳ����
	return 0;
}