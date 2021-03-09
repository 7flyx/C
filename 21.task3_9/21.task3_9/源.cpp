//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
//
//typedef struct BiTree
//{
//	//线索二叉树结点---线索二叉链表
//	char data;
//	struct BiTree* lchild, * rchild;
//	int ltag, rtag;  //ltag 左指针域的标志，rtag表示右指针域的标志
//}BiTree;
//
//
//void InitThread(BiTree* head)
//{
//	//线索二叉树的如何进行线索化----明确这颗树是以什么方式进行遍历的，前序后序中序与层序
//	//循环判断的条件：不为空树，或者最后一个结点的右指针域也等于头结点后，循环结束
//	//所以需要两个变量，一个保存头结点的地址，一个用于循环时用
//	static BiTree* pre = NULL;  //全局变量---始终指向刚刚访问过的结点
//	if (head)  //递归终止条件
//		return;
//		//始终保持这颗树的创建顺序--中序
//		InitThread(head->lchild); //左子树
//
//		if (!head->lchild)
//		{
//			//ltag赋值0，表示该结点没有孩子树，
//			head->ltag = 1;
//			head->lchild = pre;  //该指针域指向前驱
//		}
//		if (pre!=NULL && (!pre->rchild))  //前驱没有右孩子
//		{
//			pre->rtag = 1;
//			pre->rchild = head;  //前驱结点的右孩子指针，指向当前的结点head
//		}
//		pre = head;  //始终保持前驱的关系
//
//		InitThread(head->rchild); //右子树
//	
//
//}
//
////二叉树的创建--- 一级指针的方法，函数需要返回malloc函数创建地址的指针
//BiTree* Create_Tree(BiTree* T)
//{
//	//引入了虚结点的概念---#----中序创建二叉树
//	char ch = 0;
//	printf("请输入字符：");
//	scanf(" %c", &ch);
//	if (ch == '#')
//		T = NULL;
//	else
//	{	
//		T = (BiTree*)malloc(sizeof(BiTree));  //访问操作--根
//		if (!T)
//		{
//			printf("内存开辟失败!\n");
//			exit(0);
//		}
//		
//		//递归进入该结点左孩子和右孩子哦	
//		T->lchild = Create_Tree(T->lchild);  //左子树
//		T->data = ch;
//		T->ltag = 0;
//		T->rtag = 0;
//		T->rchild = Create_Tree(T->rchild);  //右子树
//	}
//	return T;  //返回当前开辟空间的指针
//}
//
//void InorderTraverse(BiTree* T)
//{
//	//线索二叉树的遍历---
//	//递归终止条件:空树或者遍历结束时
//	BiTree* p = T->lchild; //p指向根结点
//	while (T != p)
//	{
//		while (p->ltag == 0)
//		{
//			//当ltag等于0时，循环到中序遍历的第一个结点处
//			p = p->lchild;
//		}
//		printf("%c ", p->data);
//
//		//从这第一个结点开始打印
//		while (p->rtag == 1 && p->rchild != T)
//		{
//			p = p->rchild;
//			printf("%c ", p->data);
//		}
//
//		p = p->rchild;  //再去右子树进行打印
//	}
//}
//
////void InOrderTraverse_Thr(BiTree* T)
////{
////	BiTree* p;
////	p = T->lchild; /* p指向根结点 */
////	while (p != T)
////	{ /* 空树或遍历结束时,p==T */
////		while (p->ltag == 0)
////			p = p->lchild;
////		if (!visit(p->data)) /* 访问其左子树为空的结点 */
////			return;
////		while (p->rtag == 1 && p->rchild != T)
////		{
////			p = p->rchild;
////			visit(p->data); /* 访问后继结点 */
////		}
////		p = p->rchild;
////	}
////	return OK;
////}
//
////线索二叉树，实则跟双链表的形式差不多，也有头结点指向整颗树的根结点
////树根结点的右指针域指向的是整棵树  中序遍历  的最后一个结点
////--------------------------------------------------------------
////遍历之后的最后一个结点的右指针域指向的是 头结点
////遍历之后的第一个结点的左指针域也是指向 头结点
//int main()
//{
//	BiTree* head = (BiTree*)malloc(sizeof(BiTree));
//	if (!head)
//		return 0; //开辟空间失败
//
//	//创建二叉树
//	Create_Tree(head->lchild );
//	//二叉树的线索化
//	InitThread(head);
//	//线索二叉树的遍历
//	InorderTraverse(head);
//	return 0;
//}