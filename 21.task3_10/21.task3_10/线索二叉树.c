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

//前序建立二叉树
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
			return; //空间开辟失败
		T->data = ch;
		T->ltag = 0;
		T->rtag = 0; //初始化标志的值

		T->lchild = create(T->lchild); //建立左子树
		T->rchild = create(T->rchild); //建立右子树
	}
	return T;
}

//中序遍历进行线索化
void InThread(BiTree* p)
{
	static BiTree* pre = NULL; //跟p保持前驱后继的关系

	if (p == NULL)
		return;
	InThread(p->lchild); //左子树的线索化

	if (p->lchild == NULL)
	{//没有孩子的情况
		p->ltag = 1;
		p->lchild = pre;
	}
	if (pre != NULL && pre->rchild == NULL)
	{//pre的右指针域为空时，建立后继的关系
		pre->rtag = 1;
		pre->rchild = p;
	}
	pre = p; //pre始终跟着p

	InThread(p->rchild); //右子树的线索化
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
//按照链表的访问操作，进行中序遍历访问
void Print(BiTree* T)
{
	if (T == NULL)
		return;
	while (T->ltag == 0)
		T = T->lchild;
	printf("%c ", T->data);

	while (T->rchild != NULL)
	{
		T = next(T); //寻找后继结点
		printf("%c ", T->data);
	}
	

}

int main()
{
	BiTree* T = { 0 };
	printf("请输入例如(AB#D##C##):");
	T = create(T); //前序建立二叉树
	InThread(T); //中序遍历，进行线索化
	printf("中序遍历后的顺序为:\n");
	Print(T);

	return 0;
}