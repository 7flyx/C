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
		*T = NULL; //虚结点
	else
	{
		*T = (BiTree*)malloc(sizeof(BiTree));
		if (!*T)
			return; //内存开辟失败
		create(&(*T)->lchild);  //递归再次调用左子树
		if ((*T)->lchild) //有左孩子
			(*T)->ltag = 0;

		create(&(*T)->rchild); //递归再次调用右子树
		if ((*T)->rchild)  //有右孩子
			(*T)->rtag = 0;
	}
}

BiTree* pre = NULL;
void InitThread(BiTree** T)
{

	//建立二叉树时，已经将一部分的rtag和ltag赋值了
	if ((*T) == NULL)
		return;
	InitThread(&(*T)->lchild);  //左子树

	if ((*T)->lchild == NULL) //没有孩子，赋值前驱
	{
		(*T)->ltag = 1;
		(*T)->lchild = pre;
	}
	if (pre!=NULL && pre->rchild == NULL)//没有孩子，赋值后继
	{
		pre->rtag = 1;
		pre->rchild = (*T);  //二级指针，需先解引用
	}
	pre = (*T);  //保持前驱的关系

	InitThread(&(*T)->rchild); //右子树
}

int visit(char x)
{
	printf("%c ", x);
	return 1;
}

void print_Tree(BiTree* T)
{
	//循环结束的判断条件是树空或者遍历完了
	if (T == NULL)
	{
		printf("树为空\n");
		return;
	}
	BiTree* p = T;
	while (p != T) //最后一个结点的右指针域为空
	{
		while (p->ltag == 0)
			p = p->lchild;

		visit(p->data);

		//循环打印右指针域的数据
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


	(*head)->ltag = 0; //有左孩子
	(*head)->lchild = T;

	(*head)->rtag = 1; //没右孩子，后继直接指向本身
	(*head)->rchild = (*head);

	if (T == NULL)
		(*head)->lchild = (*head); //如果树是空的，左指针直接指向自己
	else
	{
		(*head)->lchild = T;
		pre = (*head);
		InitThread(&T);//将建立好的二叉树进行中序遍历线索化
		pre->rchild = (*head);
		pre->rtag = 1;
		(*head)->rchild = pre;
	}
}

int main()
{
	BiTree* head,*Tree; //Tree为树，head为头结点，需要指向根结点

	//前序建立二叉树
	printf("请输入：");
	create(&Tree); //头结点的左指针域指向根结点
	InThreading(&head, Tree); //将建好的根结点接入头结点里面

	printf("输出为：\n");//进行中序遍历操作
	print_Tree(head);
	
	
	return 0;
}