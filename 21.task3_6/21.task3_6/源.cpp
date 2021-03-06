# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
typedef int ElemType;

typedef struct Link_two
{
	ElemType data;
	struct Link_two* lchild,*rchild;
}Link_two;


void preorder(Link_two* T)
{
	//前序遍历
	if (T == NULL)
		return; //数为空
	//先打印后左右
	printf("%d", T->data);  
	preorder(T->lchild);
	preorder(T->rchild);
}

void epilogue(Link_two* T)
{
	//后序遍历
	if (T == NULL)
		return; //树为空
	//先左右，后打印
	epilogue(T->lchild);
	epilogue(T->rchild);
	printf("%d", T->data);
}

void inorder(Link_two* T)
{
	//中序遍历
	if (T == NULL)
		return; //树为空
	//先左，再打印，再右
	inorder(T->lchild);
	printf("%d", T->data);
	inorder(T->rchild);
}

//二叉链表
int main()
{

	return 0;
}