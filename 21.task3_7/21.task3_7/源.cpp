# define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdbool.h>
//typedef int DataType;
//
//
//DataType enQueue(DataType* T)
//{
//
//}
//bool Queue_empty(DataType* T)
//{
//
//}
//DataType outQueue(DataType* T)
//{
//
//}
//层序遍历
//1.判断树是否为空
//2. 结点元素入队
//
//循环判断条件，队列不为空
//3. 再判断左子树是否为空，不为空就入队
//4. 再判断右子树是否为空，不为空就入队
//
//void CX_traverse(DataType* T)
//{
//	if (T)
//		return;  //树为空
//	DataType q;
//	enQueue(T);  //入队
//	while (Queue_empty(T)) //队列不为空，循环继续
//	{
//		q = outQueue(T);  //出队
//		printf("%d", q);  //访问
//
//		假装T已经是树结构体
//		if (T->lchild)
//			enQueue(T->lchild);  //左子树
//		if (T->rchild)
//			enQueue(T->rchild);  //右子树
//	}
//}
//int main()
//{
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>


int i = 0; //全局变量，用于数组的访问

#define MAXSIZE 100
typedef struct BiTree
{
	char data;
	struct BiTree* lchild, *rchild;
}BiTree;

typedef struct arr
{
	//一维数组结点
	char data;
	int lchild;
	int rchild;
}ANODE;
//建立二叉树---与遍历差不多
//也分为前序 后序 中序 层序建立二叉树
void createTree_Q(BiTree** T)
{
	//'#'为空树
	//参数部分为二级指针，理清楚逻辑，为什么是二级指针？
	//前序建立
	char ch = 0;
	printf("请输入字符：");
	scanf(" %c", &ch);
	//getchar();  //输入缓冲区问题，有\n的原因
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree*)malloc(sizeof(BiTree));
		if (!(*T))
			return;
		(*T)->data = ch;
		createTree_Q(&(*T)->lchild); //创建左子树
		createTree_Q(&(*T)->rchild); //创建右子树
	}
}

//计算二叉树的深度
int DepthTree(BiTree* bt)
{
	//首先定义左子树的深度lt，和右子树的深度rt
	//递归调用函数，每次调用后，深度都应该加一
	//直到树结点为空时，返回0
	int lt = 0;
	int rt = 0;
	if (bt)
	{
		lt = DepthTree(bt->lchild) + 1;
		rt = DepthTree(bt->rchild) + 1;
	}
	return lt > rt ? lt : rt;
}

//求二叉树中的叶子结点数
void LeftCount(BiTree* T, int* num)
{
	if (T)
	{
		//不为空，进来
		//当左右孩子都是空时，即就是叶子结点
		if (T->lchild == NULL && T->rchild == NULL)
		{
			*num = *num + 1;
		}
		else
		{
			LeftCount(T->lchild, num);
			LeftCount(T->rchild, num);
		}
	}
}


//未写完
//void shift_arr(BiTree* T, ANODE *arr)
//{
//	//实则还是前序问题，将每次遍历的数据依次放入数组里面
//	if (!T)
//		return; //树为空
//
//	arr[i++].data = T->data;
//	if (T->lchild != NULL)
//		(arr[i - 1]).lchild = 2 * i;
//	if (T->rchild != NULL)
//		arr[i - 1].rchild = 2 * i + 1;
//
//	//再调用左子树与右子树
//	shift_arr(T->lchild , arr);
//	shift_arr(T->rchild , arr);
//}
int main()
{
	int count = 0;  //用于存储叶子的结点数
	//创建二叉树
	BiTree* tree = (BiTree*)malloc(sizeof(BiTree));
	ANODE arr[MAXSIZE] = { 0 };
	createTree_Q(&tree);
	//shift_arr(tree, arr);
	/*int j = 0;
	for (j = 0; i < i; j++)
	{
		printf("%c %d %d\n", arr[j].data, arr[j].lchild, arr[j].rchild);
	}*/
	

	//计算叶子结点的个数
	LeftCount(tree, &count);
	printf("叶子结点数为%d\n", count);
	//计算二叉树的深度
	printf("二叉树的深度是%d\n", DepthTree(tree));
	return 0;
}