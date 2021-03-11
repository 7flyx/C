# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct BiTree
{
	char data;
	struct BiTree* rchild, * lchild;
}BiTree;

//指向BiTree的结点，包括了flag
typedef struct BNODE
{
	BiTree* ptr;
	int flag;  //用于表示左子树右子树的访问情况，后序遍历需要该结点，前序中序不需要
}StackNODE;

//栈
typedef struct Stack
{
	BiTree* pb[20]; //模拟栈
	int top;
}Stack;

//入栈
void push(Stack* s, BiTree* p)
{
	if (s->top + 1 == 20)
	{
		printf("栈满!\n");
		return;
	}

	s->top++;
	s->pb[s->top] = p;
}
void push2(StackNODE* s, BiTree* p)
{
	if (s->top + 1 == 20)
	{
		printf("栈满！\n");
		return;
	}

	s->top++;
	s->ptr[s->top] = p;
}
//出栈
void  pop(Stack* s, BiTree** p)
{
	if (s->top == -1)
	{
		printf("栈为空!\n");
		return;
	}

	*p = s->pb[s->top];
	s->top--;
}
StackNODE* pop2(StackNODE* s)
{
	
}

//判断栈空
int isEmpty(Stack s)
{
	if (s.top == -1)
		return 1;
	else
		return 0;
}
int isEmpty2(StackNODE s)
{
	if (s.top == -1)
		return 1;
	else
		return 0;
}

//前序遍历--非递归
void preorder(BiTree* root)
{
	Stack S1;
	S1.top = -1;

	BiTree* p = root;
	while (p != NULL || isEmpty(S1))  //isEmpty是判断栈区是否为空
	{
		while (p != NULL)
		{
			//循环遍历左子树
			push(&S1, p); //存储的是当前树结点的地址
			printf("&c ", p->data);
			p = p->lchild;
		}
		if (!isEmpty(S1))
		{
			//如果栈为空了，则需要出栈，p指针指向右子树
			pop(&S1,&p); //弹出上一次p的结点地址
			p = p->rchild;  //进入右子树
		}
	}
}

//中序遍历--非递归
void Inorder(BiTree* root)
{
	//中序遍历算法与前序差不多，只是在访问结点的语句，在if语句里面
	Stack S2;
	S2.top = -1;
	BiTree* p = root;

	while (p != NULL || isEmpty(S2))
	{
		while (p != NULL)
		{
			push(&S2, p); //入栈
			p = p->lchild; //继续向左子树走
		}
		if (!isEmpty(S2))
		{
			pop(&S2, &p);
			printf("%c ", p->data);
			p = p->rchild; //往右子树走
		}
	}
}

//后序遍历--非递归
void epilogue(BiTree* root)
{
	//后序遍历，与前序中序有所不同，需要设置flag来确定左右子树是否已经遍历过了，如果
	//左右子树都遍历过了，就直接输出

}

//二叉树的前序中序后序遍历算法---非递归
int main()
{
	return 0;
}