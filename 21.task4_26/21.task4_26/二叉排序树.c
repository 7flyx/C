# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>


typedef struct BiTree
{
	int data;
	struct BiTree* lchild, * rchild;
}BiNode,*BiTree;

int searchBST(BiTree* T, int key, BiTree f, BiTree* p)
{
	//f表示上一结点，p表示当前结点，需要返回去，做insertBST函数的插入操作
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
	else if (key < (*T)->data) //进入左子树查找
		searchBST(&(*T)->lchild, key, T, p);
	else //进入右子树查找
		searchBST(&(*T)->rchild, key, T, p);
}

void insertBST(BiTree* T, int key)
{
	BiTree p, s;
	if (searchBST(T, key, NULL, &p)) //说明树中已经有这个数据了，不需要再进行插入
	{
		return;
	}
	else //说明没这个数据，就进行插入
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
	if ((*T)->lchild) //左子树为空,重接右子树
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
	else //左右子树均不为空
	{
		//既然左右子树均不为空，需要保持整棵树的次序，则只需找到被删除结点的直接前驱或后继
		//连接上即可
		q = *T;
		s = (*T)->lchild;
		while (s->rchild)  //右孩子的指针域为空，结束循环
		{
			q = s;
			s = s->rchild;
		}
		(*T)->data = s->data;
		if (q != *T)
			q->rchild = s->lchild; //  q与根结点 T不相等，说明s是有过rchild的，rchild的数据给了根结点，此时
									//重接q的右子树
		else
			q->lchild = s->lchild; // 说明q还是指向的根结点，也就是说s没有一个rchild，此时重接q的左子树
		free(s);
	}
	return 1;
}

int DelBST(BiTree* T, int key)
{
	//递归操作，找到需要删除的结点，调用delete函数进行删除
	if (!*T)
		return 0; //没找到该元素
	else if (key == (*T)->data)
		return Delete(T);
	else if (key < (*T)->lchild) //左子树
		return DelBST(&(*T)->lchild, key);
	else
		return DelBST(&(*T)->rchild, key);
}

//二叉排序树/二叉搜索树---增加查找与删除
int main()
{
	return 0;
}