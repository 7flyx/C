# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	int data;
	struct BiTree* lchild, *rchild;
}BiNode,*BiTree;

//创建数据，建立树结构
int insertBST(BiTree* T, int key)
{
	BiTree p,s;
	//在建立树的时候先判断树中是否已经有这个数据了
	//searchBST函数，一直判断这个数据是否已经存储过了，二是返回p的指针，用于直接存储
	if (!searchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiNode));
		if (!s) return 0;
		s->data = key;
		s->lchild = s->rchild = NULL;

		if (!p)
			//为空树的时候，此时这个结点就是根结点了
			*T = s;
		else if (key < p->data)
			//需要存储的数据元素比当前的结点元素要小，所以存储在该结点的左边
			p->lchild = s;
		else
			//相反的就是比当前结点的元素大，存储在右边
			p->rchild = s;
	}
	else
		return 0;  //说明树中已经有对应的数据元素了
		
	return 1;
}

//查找数据----查找key，找到后将key结点的地址赋值给p指针，并返回1
//f指向当前结点的双亲结点，即就是上一个结点
int searchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		//说明树为空，或者是没有找到该数据
		*p = f; 
		return 0;
	}
	else if (key == T->data)
	{
		//找到了
		*p = T;  //保存当前结点的地址
		return 1;
	}
	else if (key < T->data)
	{
		//说明数据在此根结点的左边--则递归调用左子树
		return searchBST(T->lchild, key, T, p);
	}
	else
	{
		//否则递归调用右子树--值得注意的是，这里的第三个参数传递的是当前的结点T
		return searchBST(T->rchild, key, T, p);
	}
}

int Delete(BiTree* p)
{
	//删除结点分为几种情况
	//1. 被删除的结点下面只有一个孩子（左或右孩子）
	//2. 被删除的结点下面有两个孩子（左右孩子均存在）
	BiTree q, s;
	//分别判断左右子树是否为空
	if ((*p)->lchild == NULL)
	{
		q = *p;  //首先保存当前结点的地址
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
		//有左右子树的情况
		//需要找到当前结点的直接前驱或直接后继
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s; //p指针保持不变，q指针一直跟着s指针走，s指针就是去寻找前驱结点，q与s之间相差了一个
			s = s->rchild;  //一直寻找最右边的数据，最后一个即就是这个结点的直接前驱
		}
			
		(*p)->data = s->data;  //将前驱的值直接覆盖给当前结点

		//拼接左右子树
		if (q != (*p))
			q->rchild = s->lchild; //重接q的右子树，q表示s的上一个结点
		else
			q->lchild = s->lchild;  //重接q的左子树，此时的q与p指向的是同一块区域
		free(s);
		return 1;
	}
}

//删除数据---根据查找函数里面的p指针来确定需要删除对象的位置（结点的地址）
int deleteBST(BiTree* T, int key)
{
	if (!*T)
		return 0; //没有这个数据
	else
	{
		if (key == (*T)->data)
			return Delete(T);
		else if (key < (*T)->data)
			return deleteBST(&(*T)->lchild, key);
		else
			return deleteBST(&(*T)->rchild, key);  //递归调用，找=找需要删除的数据的结点
	}
}

//二叉排序树
//根据给出的数据进行排序算法的实现
int main()
{
	int arr[10] = { 20,30,40,10,50,82,62,66,95,100 };
	BiTree head = (BiTree)malloc(sizeof(BiNode));
	if (!head)
		return 0;  //开辟失败，直接返回
	head->lchild = head->rchild = NULL;

	int i = 0;
	for (i = 0; i < 10; i++)
		insertBST(&head,arr[i]); //创建二叉排序树

	return 0;
}