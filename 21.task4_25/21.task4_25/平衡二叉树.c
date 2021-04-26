# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#define RH -1 //右高
#define EH 0 //相等
#define LH +1 //左高

typedef struct BiTree
{
	int data;
	int bf;  //平衡因子
	struct BiTree* lchild, * rchild;
}BiNode, *BiTree;

//左旋转--bf为负
void L_Rotate(BiTree* T)
{
	BiTree R;
	R = (*T)->rchild;
	(*T)->rchild = R->lchild;  //R的左孩子要赋值给T结点的右孩子，保持孩子一直是只有两个
	R->lchild = *T; //此时R的左孩子再指向T结点
	*T = R; //将R结点该为T结点，作为根结点
}
//右旋转--bf为正
void R_Rotate(BiTree* T)
{
	BiTree L;
	L = (*T)->lchild;
	(*T)->lchild = L->rchild; //将L的右孩子赋值给T结点的左孩子
	L->rchild = *T; //此时L的左孩子指向T结点
	*T = L; //将L结点设置为根结点
}

//左子树的旋转--左平衡旋转处理
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild; //拿到根结点的左孩子
	switch (L->bf)
	{
	case LH:  //整个函数是左子树的旋转，即就是这个子树根的bf为  1，在这个子树的左孩子的bf也是 1，
				//也就是说，两个bf的正负相同，只做单一的右旋操作
		(*T)->bf = L->bf = EH;
		R_Rotate(T);  //右旋转
		break;
	case RH:  //这里即就是L与T的bf值正负不一样，要做两个次旋转
		Lr = L->rchild;  //整个数是左边多，既然bf值相反，这个结点的右边数多呗
		switch (Lr->bf)
		{
			//值得注意的是：这里的LH与RH是的改动，可以说是对称的  LH 改根，RH 改根孩
		case LH:
			(*T)->bf = RH;  //根的bf改为右高
			L->bf = EH;  //根的左孩子的bf为 相等 0
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;  //根的bf相等  0
			L->bf = LH; //根的左孩子 的bf改为左高
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);   //先左旋转，再右旋转
		R_Rotate(T);
	}
}

//右子树的旋转--右平衡旋转处理
void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild; //左子树树根
	switch (R->bf)
	{
	case LH: //根结点与该结点的bf正负不一样，需要做双旋转处理
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:  //LH 改根孩，RH 改根
			(*T) ->bf = EH; //根的bf值该为左高
			R->bf = RH;  //根的右孩子的bf该为相等  0
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case RH:
			(*T)->bf = LH;
			R->bf = EH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	case RH:  //本身整颗树就是右边高了，此时这个结点也是右边高，bf值正负相等，只做单左旋转
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	}
}

//平衡二叉树，是在二叉排序树的基础上进行的优化--优化的是查找数据时候的效率
//平衡因子--（-1,0,1）三个数--左子树减去右子树的深度值，正顺负逆（转动）
int main()
{
	return 0;
}


