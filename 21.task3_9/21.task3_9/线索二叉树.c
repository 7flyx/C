# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	char data;
	struct BiTree* rchild, * lchild;
	int rtag, ltag;
}BiTree;
void create(BiTree** T)
{
	char ch;
	scanf("%c", &ch);  

	if (ch == '#')
		*T = NULL; //����
	else
	{
		*T = (BiTree*)malloc(sizeof(BiTree));
		if (!*T)
			return; //�ڴ濪��ʧ��
		create(&(*T)->lchild);  //�ݹ��ٴε���������
		if ((*T)->lchild) //������
			(*T)->ltag = 0;

		create(&(*T)->rchild); //�ݹ��ٴε���������
		if ((*T)->rchild)  //���Һ���
			(*T)->rtag = 0;
	}
}

BiTree* pre = NULL;
void InitThread(BiTree** T)
{

	//����������ʱ���Ѿ���һ���ֵ�rtag��ltag��ֵ��
	if ((*T) == NULL)
		return;
	InitThread(&(*T)->lchild);  //������

	if ((*T)->lchild == NULL) //û�к��ӣ���ֵǰ��
	{
		(*T)->ltag = 1;
		(*T)->lchild = pre;
	}
	if (pre!=NULL && pre->rchild == NULL)//û�к��ӣ���ֵ���
	{
		pre->rtag = 1;
		pre->rchild = (*T);  //����ָ�룬���Ƚ�����
	}
	pre = (*T);  //����ǰ���Ĺ�ϵ

	InitThread(&(*T)->rchild); //������
}

int visit(char x)
{
	printf("%c ", x);
	return 1;
}

void print_Tree(BiTree* T)
{
	//ѭ���������ж����������ջ��߱�������
	if (T == NULL)
	{
		printf("��Ϊ��\n");
		return;
	}
	BiTree* p = T;
	while (p != T) //���һ��������ָ����Ϊ��
	{
		while (p->ltag == 0)
			p = p->lchild;

		visit(p->data);

		//ѭ����ӡ��ָ���������
		while (p->rtag == 1 && p->rchild != T)
		{
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
}



void InThreading(BiTree** head, BiTree* T)
{
	*head = (BiTree*)malloc(sizeof(BiTree));
	if (!*head)
		return;


	(*head)->ltag = 0; //������
	(*head)->lchild = T;

	(*head)->rtag = 1; //û�Һ��ӣ����ֱ��ָ����
	(*head)->rchild = (*head);

	if (T == NULL)
		(*head)->lchild = (*head); //������ǿյģ���ָ��ֱ��ָ���Լ�
	else
	{
		(*head)->lchild = T;
		pre = (*head);
		InitThread(&T);//�������õĶ����������������������
		pre->rchild = (*head);
		pre->rtag = 1;
		(*head)->rchild = pre;
	}
}

int main()
{
	BiTree* head,*Tree; //TreeΪ����headΪͷ��㣬��Ҫָ������

	//ǰ����������
	printf("�����룺");
	create(&Tree); //ͷ������ָ����ָ������
	InThreading(&head, Tree); //�����õĸ�������ͷ�������

	printf("���Ϊ��\n");//���������������
	print_Tree(head);
	
	
	return 0;
}