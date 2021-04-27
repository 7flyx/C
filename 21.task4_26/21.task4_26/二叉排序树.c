# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>


typedef struct BiTree
{
	int data;
	struct BiTree* lchild, * rchild;
}BiNode,*BiTree;

int searchBST(BiTree* T, int key, BiTree f, BiTree* p)
{
	//f��ʾ��һ��㣬p��ʾ��ǰ��㣬��Ҫ����ȥ����insertBST�����Ĳ������
	if (!*T)
	{
		*p = f;
		return 0;
	}
	else if ((*T)->data == key)
	{
		*p = *T;
		return 1;
	}
	else if (key < (*T)->data) //��������������
		searchBST(&(*T)->lchild, key, T, p);
	else //��������������
		searchBST(&(*T)->rchild, key, T, p);
}

void insertBST(BiTree* T, int key)
{
	BiTree p, s;
	if (searchBST(T, key, NULL, &p)) //˵�������Ѿ�����������ˣ�����Ҫ�ٽ��в���
	{
		return;
	}
	else //˵��û������ݣ��ͽ��в���
	{
		s = (BiTree)malloc(sizeof(BiNode));
		if (!s) return;
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
	}
}

int Delete(BiTree* T)
{
	BiTree q, s;
	if ((*T)->lchild) //������Ϊ��,�ؽ�������
	{
		q = *T;
		*T = (*T)->rchild;
		free(q);
	}
	else if ((*T)->rchild)
	{
		q = *T;
		*T = (*T)->lchild;
		free(q);
	}
	else //������������Ϊ��
	{
		//��Ȼ������������Ϊ�գ���Ҫ�����������Ĵ�����ֻ���ҵ���ɾ������ֱ��ǰ������
		//�����ϼ���
		q = *T;
		s = (*T)->lchild;
		while (s->rchild)  //�Һ��ӵ�ָ����Ϊ�գ�����ѭ��
		{
			q = s;
			s = s->rchild;
		}
		(*T)->data = s->data;
		if (q != *T)
			q->rchild = s->lchild; //  q������ T����ȣ�˵��s���й�rchild�ģ�rchild�����ݸ��˸���㣬��ʱ
									//�ؽ�q��������
		else
			q->lchild = s->lchild; // ˵��q����ָ��ĸ���㣬Ҳ����˵sû��һ��rchild����ʱ�ؽ�q��������
		free(s);
	}
	return 1;
}

int DelBST(BiTree* T, int key)
{
	//�ݹ�������ҵ���Ҫɾ���Ľ�㣬����delete��������ɾ��
	if (!*T)
		return 0; //û�ҵ���Ԫ��
	else if (key == (*T)->data)
		return Delete(T);
	else if (key < (*T)->lchild) //������
		return DelBST(&(*T)->lchild, key);
	else
		return DelBST(&(*T)->rchild, key);
}

//����������/����������---���Ӳ�����ɾ��
int main()
{
	return 0;
}