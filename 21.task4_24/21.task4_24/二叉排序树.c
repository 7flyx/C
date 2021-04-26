# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	int data;
	struct BiTree* lchild, *rchild;
}BiNode,*BiTree;

//�������ݣ��������ṹ
int insertBST(BiTree* T, int key)
{
	BiTree p,s;
	//�ڽ�������ʱ�����ж������Ƿ��Ѿ������������
	//searchBST������һֱ�ж���������Ƿ��Ѿ��洢���ˣ����Ƿ���p��ָ�룬����ֱ�Ӵ洢
	if (!searchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiNode));
		if (!s) return 0;
		s->data = key;
		s->lchild = s->rchild = NULL;

		if (!p)
			//Ϊ������ʱ�򣬴�ʱ��������Ǹ������
			*T = s;
		else if (key < p->data)
			//��Ҫ�洢������Ԫ�رȵ�ǰ�Ľ��Ԫ��ҪС�����Դ洢�ڸý������
			p->lchild = s;
		else
			//�෴�ľ��Ǳȵ�ǰ����Ԫ�ش󣬴洢���ұ�
			p->rchild = s;
	}
	else
		return 0;  //˵�������Ѿ��ж�Ӧ������Ԫ����
		
	return 1;
}

//��������----����key���ҵ���key���ĵ�ַ��ֵ��pָ�룬������1
//fָ��ǰ����˫�׽�㣬��������һ�����
int searchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		//˵����Ϊ�գ�������û���ҵ�������
		*p = f; 
		return 0;
	}
	else if (key == T->data)
	{
		//�ҵ���
		*p = T;  //���浱ǰ���ĵ�ַ
		return 1;
	}
	else if (key < T->data)
	{
		//˵�������ڴ˸��������--��ݹ����������
		return searchBST(T->lchild, key, T, p);
	}
	else
	{
		//����ݹ����������--ֵ��ע����ǣ�����ĵ������������ݵ��ǵ�ǰ�Ľ��T
		return searchBST(T->rchild, key, T, p);
	}
}

int Delete(BiTree* p)
{
	//ɾ������Ϊ�������
	//1. ��ɾ���Ľ������ֻ��һ�����ӣ�����Һ��ӣ�
	//2. ��ɾ���Ľ���������������ӣ����Һ��Ӿ����ڣ�
	BiTree q, s;
	//�ֱ��ж����������Ƿ�Ϊ��
	if ((*p)->lchild == NULL)
	{
		q = *p;  //���ȱ��浱ǰ���ĵ�ַ
		*p = (*p)->rchild;
		free(q);
	}
	else if ((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else
	{
		//���������������
		//��Ҫ�ҵ���ǰ����ֱ��ǰ����ֱ�Ӻ��
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s; //pָ�뱣�ֲ��䣬qָ��һֱ����sָ���ߣ�sָ�����ȥѰ��ǰ����㣬q��s֮�������һ��
			s = s->rchild;  //һֱѰ�����ұߵ����ݣ����һ���������������ֱ��ǰ��
		}
			
		(*p)->data = s->data;  //��ǰ����ֱֵ�Ӹ��Ǹ���ǰ���

		//ƴ����������
		if (q != (*p))
			q->rchild = s->lchild; //�ؽ�q����������q��ʾs����һ�����
		else
			q->lchild = s->lchild;  //�ؽ�q������������ʱ��q��pָ�����ͬһ������
		free(s);
		return 1;
	}
}

//ɾ������---���ݲ��Һ��������pָ����ȷ����Ҫɾ�������λ�ã����ĵ�ַ��
int deleteBST(BiTree* T, int key)
{
	if (!*T)
		return 0; //û���������
	else
	{
		if (key == (*T)->data)
			return Delete(T);
		else if (key < (*T)->data)
			return deleteBST(&(*T)->lchild, key);
		else
			return deleteBST(&(*T)->rchild, key);  //�ݹ���ã���=����Ҫɾ�������ݵĽ��
	}
}

//����������
//���ݸ��������ݽ��������㷨��ʵ��
int main()
{
	int arr[10] = { 20,30,40,10,50,82,62,66,95,100 };
	BiTree head = (BiTree)malloc(sizeof(BiNode));
	if (!head)
		return 0;  //����ʧ�ܣ�ֱ�ӷ���
	head->lchild = head->rchild = NULL;

	int i = 0;
	for (i = 0; i < 10; i++)
		insertBST(&head,arr[i]); //��������������

	return 0;
}