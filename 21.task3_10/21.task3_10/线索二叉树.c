# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
typedef char datatype;

typedef struct BiTree
{
	datatype data;
	struct BiTree* rchild, * lchild;
	int ltag, rtag;
}BiTree;

//ǰ����������
BiTree* create(BiTree* T)
{
	datatype ch = 0;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (BiTree*)malloc(sizeof(BiTree));
		if (!T)
			return; //�ռ俪��ʧ��
		T->data = ch;
		T->ltag = 0;
		T->rtag = 0; //��ʼ����־��ֵ

		T->lchild = create(T->lchild); //����������
		T->rchild = create(T->rchild); //����������
	}
	return T;
}

//�����������������
void InThread(BiTree* p)
{
	static BiTree* pre = NULL; //��p����ǰ����̵Ĺ�ϵ

	if (p == NULL)
		return;
	InThread(p->lchild); //��������������

	if (p->lchild == NULL)
	{//û�к��ӵ����
		p->ltag = 1;
		p->lchild = pre;
	}
	if (pre != NULL && pre->rchild == NULL)
	{//pre����ָ����Ϊ��ʱ��������̵Ĺ�ϵ
		pre->rtag = 1;
		pre->rchild = p;
	}
	pre = p; //preʼ�ո���p

	InThread(p->rchild); //��������������
}


BiTree* next(BiTree* tmp)
{
	if (tmp->rtag == 1)
	{
		tmp = tmp->rchild;
	}
	else
	{
		tmp = tmp->rchild;
		while (tmp->ltag == 0)
			tmp = tmp->lchild;
	}
	return tmp;
}
//��������ķ��ʲ��������������������
void Print(BiTree* T)
{
	if (T == NULL)
		return;
	while (T->ltag == 0)
		T = T->lchild;
	printf("%c ", T->data);

	while (T->rchild != NULL)
	{
		T = next(T); //Ѱ�Һ�̽��
		printf("%c ", T->data);
	}
	

}

int main()
{
	BiTree* T = { 0 };
	printf("����������(AB#D##C##):");
	T = create(T); //ǰ����������
	InThread(T); //�������������������
	printf("����������˳��Ϊ:\n");
	Print(T);

	return 0;
}