# define _CRT_SECURE_NO_WARNINGS 

# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#include <stdlib.h>
#define LH 1
#define EH 0
#define RH -1

typedef struct BiTree
{
	int data;
	int bf;
	struct BiTree* lchild, * rchild;
}BiNode, * BiTree;


//左旋转
void L_Rotate(BiTree* T)
{
	BiTree R;
	R = (*T)->rchild;
	(*T)->rchild = R->lchild;
	R->lchild = *T;
	*T = R;
}
//右旋转
void R_Rotate(BiTree* T)
{
	BiTree L;
	L = (*T)->lchild;
	(*T)->lchild = L->rchild;
	L->rchild = *T;
	*T = L;
}

//左子树的平衡旋转
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)
	{
	case LH:   //本身就是左子树的旋转，即这个根结点bf为1，此时L->bf也是1，同号，做单右旋
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:  //本身就时左子树的旋转，当前这个结点L的bf为-1，不同号，需要做两次旋转处理
				//既然bf为-1，则还有右子树
		Lr = L->rchild;
		switch (Lr->bf)
		{ //此处三个case语句做的只是修改相应结点的bf值
		case LH: //插入结点，导致Lr左高，则该根为右高
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH: //插入结点,导致Lr为右高，则根结点的孩子该为左高
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		//case 语句外面才是两次旋转
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
		break;
	}
}
//左右子树的平衡处理，当需要做双旋处理时，在Rl或Lr结点的bf值时，需要将整棵树作为参考
//例如为左子树的平衡旋转，若此时Lr->bf却是RH（-1），与根结点（T）的bf不同号，改根孩子（L）的bf值为LH，与前面的RH值相反
//如果同号（Lr->bf = LH），则该根（T）的bf为相反值（RH）
//右子树的平衡旋转
void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild;
	switch (R->bf)
	{//不存在EH相等的情况，如果相等，就不会进来了
	case LH:  //本身整棵树为右边高，当前结点为左高，bf值不同号，则做双旋处理
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:  //根结点本身是右高，当前结点为左高，则改根孩子的bf
			R->bf = RH;
			(*T)->bf = EH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case RH:  //根结点本身是右高， 当前结点也是右高，则改根的bf
			(*T)->bf = LH;
			R->bf = EH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	case RH: //本身整棵树为右高，当前结点呢也是右高，同号，做单旋处理
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	}
}

//int* taller 用于判断树是否“长高”了
int insertAVL(BiTree* T, int key, int* taller)
{
	if (!*T)  //空树或者是没有key这个数据时，就建立新的数据，连接上
	{
		*T = (BiTree)malloc(sizeof(BiNode));
		if (!*T) return 0;
		(*T)->bf = EH;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->data = key;
		*taller = 1;  //1为长高了，0 则就是没有长高
		return 1;
	}
	else if (key < (*T)->data)  //进入左子树
	{
		if (!insertAVL(&(*T)->lchild, key, taller))  //还没插入结点就进入
		{
			*taller = 0;
			return 0;
		}
		if (*taller) //整体是左子树
		{
			switch ((*T)->bf) //直接判断的是根结点
			{
			case LH:  //原来是左高，现在又长高了，所以要进入左子树的平衡旋转处理
				LeftBalance(T);
				*taller = 0;  //平衡处理之后，就相当于 “没长高了”
				break;
			case EH:  //原来是一样高的（*T）->bf = 0，现在长高了，平衡因子没超过1			
				(*T)->bf = LH; //
				*taller = 1;
				break;
			case RH:  //原来是右边高，现在左边长高了，即就是现在为一样高
				(*T)->bf = EH;
				*taller = 0;
				break;
			}
		}
	}
	else  //进入右子树
	{
		if (!insertAVL(&(*T)->rchild, key, taller))
		{
			*taller = 0;
			return 0;
		}
		if (*taller)
		{
			switch ((*T)->bf)
			{
			case LH:  //原来是左边高了，现在右边长高了，即就是现在一样高
				(*T)->bf = EH;
				*taller = 0;
				break;
			case EH:  //原本是一样高，现在右边长高了，即就是（*T）-> bf = -1
				(*T)->bf = RH;
				*taller = 1;
				break;
			case RH:  //原本是右边高，现在右边又长高了，需要进行右子树的平衡旋转
				RightBalance(T);
				*taller = 0;
				break;
			}
		}
	}
}

void printAVL(BiTree* T)
{
	//中序遍历二叉树
	if (!*T)
		return;
	printAVL(&(*T)->lchild);
	printf("%d ", (*T)->data);
	printAVL(&(*T)->rchild);
}

void DelAVL(BiTree* T)
{
	//前面创建的内存空间，进行回收---中序遍历
	if (!*T)
		return;
	DelAVL(&(*T)->lchild);

	//删除操作
	BiTree tmp = (*T)->rchild; //首先需要保存右孩子的指针
	free(*T);
	DelAVL(&tmp);
}

//平衡二叉树的创建与使用
int main()
{
	int taller = 0;
	int arr[10] = { 20,30,40 };
	BiTree T = NULL;
	for (int i = 0; i < 3; i++)
		insertAVL(&T, arr[i], &taller);

	printAVL(&T);
	DelAVL(&T);
	return;
}