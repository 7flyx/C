# define _CRT_SECURE_NO_WARNINGS 
#include "Student.h"

void InputStudent(Link node)
{
	printf("����������:>");
	scanf("%s", node->data.name);
	printf("������ѧ��:>");
	scanf("%s", node->data.studentID);
}

void add_student(Link head)
{
	//�½���㣬��������
	Link node = (Link)malloc(sizeof(Node));
	//node->next  δ��ʼ��
	InputStudent(node);

	//����q��p����ʾָ��ǰһ���ͺ�һ���
	Link q = head;
	Link p = head->next;

	//��ѧ�Ŵ�С�����������
	while (p != NULL)
	{
		//�ж�ѧ�Ŵ�С
		if (strcmp(node->data.studentID , p->data.studentID) <= 0 )
		{
			//����
			node->next = q->next;
			q->next = node;
			printf("��ӳɹ�\n");
			return; //��ǰ�˳�
		}
		else
		{
			//q��pָ�������
			q = p;
			p = p->next;
		}
	}

	//p=NULLʱ��ֱ�Ӳ��뼴��
	q->next = node;
	node->next = NULL;
	printf("��ӳɹ�\n");
}

void clear_list(Link head)
{
	//ָ��ǰ�����ָ��
	//Link q = head; //ͷ���
	Link p = head->next; //ָ���һ�����
	           
	while (p != NULL)
	{	                                 
		head->next = p->next;
		free(p);
		p = head->next;
	}
	printf("��ճɹ�\n");
}


void show_student(Link head)
{
	Link p = head->next;
	printf("%s\t%s\n","����","ѧ��");
	while (p != NULL)
	{
		printf("%s\t%s\n", p->data.name, p->data.studentID);
		p = p->next;
	}
}


void dele_student(Link head)
{
	//����ǰ����
	Link q = head;
	Link p = head->next;


	//������Ҫɾ����ѧ������
	Link node = (Link)malloc(sizeof(Node));
	InputStudent(node);
	//ѭ���жϲ�ɾ��
	while (p != NULL)
	{
		if (strcmp(node->data.studentID, p->data.studentID) == 0)
		{
			//ɾ��
			q->next = p->next;
			free(p);
			printf("ɾ���ɹ�\n");
			return;
		}
		else
		{
			//ָ�����
			q = p;
			p = p->next;
		}
	}

	//ѭ����󣬾���û������˵���Ϣ
	printf("û�ҵ���ѧ����Ϣ\n");
}

void sear_student(Link head)
{
	//ǰ����
	Link q = head;
	Link p = head->next;

	//������Ҫ���ҵ�ѧ������
	Link node = (Link)malloc(sizeof(Node));
	InputStudent(node);
	//ѭ���ж�
	while (p != NULL)
	{
		if (strcmp(node->data.studentID, p->data.studentID) == 0)
		{
			//�ҵ���
			printf("%s\t%s\n", "����", "ѧ��");
			printf("%s\t%s\n", p->data.name, p->data.studentID);
			return;
		}
		else if(strcmp(node->data .name , p->data .name ) == 0)
		{
			//�ҵ���
			printf("%s\t%s\n", "����", "ѧ��");
			printf("%s\t%s\n", p->data.name, p->data.studentID);
		}
		else
		{
			//ָ�����
			q = p;
			p = p->next;
		}
	}

}


void modi_strdent(Link head)
{
	//ǰ����
	Link q = head;
	Link p = head->next;

	//������Ҫ�޸ĵ�ѧ����Ϣ
	Link node = (Link)malloc(sizeof(Node));
	printf("��������Ҫ���޸ĵ�ѧ����Ϣ\n");
	InputStudent(node);
	//ѭ���ж�
	while (p != NULL)
	{
		if (strcmp(node->data.studentID, p->data.studentID) == 0)
		{
			//�ҵ���
			printf("������������Ϣ!\n");
			printf("����������:>");
			scanf("%s", p->data.name);
			printf("������ѧ��:>");
			scanf("%s", p->data.studentID);
			printf("�޸ĳɹ�\n");
			return;
		}
		else
		{
			//ָ�����
			q = p;
			p = p->next;
		}
	}
}

void statis_student(Link head)
{
	//ǰ����
	Link q = head;
	Link p = head->next;
	int count = 0;

	while (p != NULL)
	{
		count += 1;
		q = p;
		p = p->next;
	}
	printf("����%dλѧ����Ϣ\n", count);
}