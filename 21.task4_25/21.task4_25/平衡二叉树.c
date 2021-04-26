# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#define RH -1 //�Ҹ�
#define EH 0 //���
#define LH +1 //���

typedef struct BiTree
{
	int data;
	int bf;  //ƽ������
	struct BiTree* lchild, * rchild;
}BiNode, *BiTree;

//����ת--bfΪ��
void L_Rotate(BiTree* T)
{
	BiTree R;
	R = (*T)->rchild;
	(*T)->rchild = R->lchild;  //R������Ҫ��ֵ��T�����Һ��ӣ����ֺ���һֱ��ֻ������
	R->lchild = *T; //��ʱR��������ָ��T���
	*T = R; //��R����ΪT��㣬��Ϊ�����
}
//����ת--bfΪ��
void R_Rotate(BiTree* T)
{
	BiTree L;
	L = (*T)->lchild;
	(*T)->lchild = L->rchild; //��L���Һ��Ӹ�ֵ��T��������
	L->rchild = *T; //��ʱL������ָ��T���
	*T = L; //��L�������Ϊ�����
}

//����������ת--��ƽ����ת����
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild; //�õ�����������
	switch (L->bf)
	{
	case LH:  //��������������������ת�������������������bfΪ  1����������������ӵ�bfҲ�� 1��
				//Ҳ����˵������bf��������ͬ��ֻ����һ����������
		(*T)->bf = L->bf = EH;
		R_Rotate(T);  //����ת
		break;
	case RH:  //���Ｔ����L��T��bfֵ������һ����Ҫ����������ת
		Lr = L->rchild;  //����������߶࣬��Ȼbfֵ�෴����������ұ�������
		switch (Lr->bf)
		{
			//ֵ��ע����ǣ������LH��RH�ǵĸĶ�������˵�ǶԳƵ�  LH �ĸ���RH �ĸ���
		case LH:
			(*T)->bf = RH;  //����bf��Ϊ�Ҹ�
			L->bf = EH;  //�������ӵ�bfΪ ��� 0
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;  //����bf���  0
			L->bf = LH; //�������� ��bf��Ϊ���
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);   //������ת��������ת
		R_Rotate(T);
	}
}

//����������ת--��ƽ����ת����
void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild; //����������
	switch (R->bf)
	{
	case LH: //�������ý���bf������һ������Ҫ��˫��ת����
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:  //LH �ĸ�����RH �ĸ�
			(*T) ->bf = EH; //����bfֵ��Ϊ���
			R->bf = RH;  //�����Һ��ӵ�bf��Ϊ���  0
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
	case RH:  //���������������ұ߸��ˣ���ʱ������Ҳ���ұ߸ߣ�bfֵ������ȣ�ֻ��������ת
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	}
}

//ƽ������������ڶ����������Ļ����Ͻ��е��Ż�--�Ż����ǲ�������ʱ���Ч��
//ƽ������--��-1,0,1��������--��������ȥ�����������ֵ����˳���棨ת����
int main()
{
	return 0;
}


