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


//����ת
void L_Rotate(BiTree* T)
{
	BiTree R;
	R = (*T)->rchild;
	(*T)->rchild = R->lchild;
	R->lchild = *T;
	*T = R;
}
//����ת
void R_Rotate(BiTree* T)
{
	BiTree L;
	L = (*T)->lchild;
	(*T)->lchild = L->rchild;
	L->rchild = *T;
	*T = L;
}

//��������ƽ����ת
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)
	{
	case LH:   //�����������������ת������������bfΪ1����ʱL->bfҲ��1��ͬ�ţ���������
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:  //�����ʱ����������ת����ǰ������L��bfΪ-1����ͬ�ţ���Ҫ��������ת����
				//��ȻbfΪ-1������������
		Lr = L->rchild;
		switch (Lr->bf)
		{ //�˴�����case�������ֻ���޸���Ӧ����bfֵ
		case LH: //�����㣬����Lr��ߣ���ø�Ϊ�Ҹ�
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH: //������,����LrΪ�Ҹߣ�������ĺ��Ӹ�Ϊ���
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		//case ����������������ת
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
		break;
	}
}
//����������ƽ�⴦������Ҫ��˫������ʱ����Rl��Lr����bfֵʱ����Ҫ����������Ϊ�ο�
//����Ϊ��������ƽ����ת������ʱLr->bfȴ��RH��-1���������㣨T����bf��ͬ�ţ��ĸ����ӣ�L����bfֵΪLH����ǰ���RHֵ�෴
//���ͬ�ţ�Lr->bf = LH������ø���T����bfΪ�෴ֵ��RH��
//��������ƽ����ת
void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild;
	switch (R->bf)
	{//������EH��ȵ�����������ȣ��Ͳ��������
	case LH:  //����������Ϊ�ұ߸ߣ���ǰ���Ϊ��ߣ�bfֵ��ͬ�ţ�����˫������
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:  //����㱾�����Ҹߣ���ǰ���Ϊ��ߣ���ĸ����ӵ�bf
			R->bf = RH;
			(*T)->bf = EH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case RH:  //����㱾�����Ҹߣ� ��ǰ���Ҳ���Ҹߣ���ĸ���bf
			(*T)->bf = LH;
			R->bf = EH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	case RH: //����������Ϊ�Ҹߣ���ǰ�����Ҳ���Ҹߣ�ͬ�ţ�����������
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	}
}

//int* taller �����ж����Ƿ񡰳��ߡ���
int insertAVL(BiTree* T, int key, int* taller)
{
	if (!*T)  //����������û��key�������ʱ���ͽ����µ����ݣ�������
	{
		*T = (BiTree)malloc(sizeof(BiNode));
		if (!*T) return 0;
		(*T)->bf = EH;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->data = key;
		*taller = 1;  //1Ϊ�����ˣ�0 �����û�г���
		return 1;
	}
	else if (key < (*T)->data)  //����������
	{
		if (!insertAVL(&(*T)->lchild, key, taller))  //��û������ͽ���
		{
			*taller = 0;
			return 0;
		}
		if (*taller) //������������
		{
			switch ((*T)->bf) //ֱ���жϵ��Ǹ����
			{
			case LH:  //ԭ������ߣ������ֳ����ˣ�����Ҫ������������ƽ����ת����
				LeftBalance(T);
				*taller = 0;  //ƽ�⴦��֮�󣬾��൱�� ��û�����ˡ�
				break;
			case EH:  //ԭ����һ���ߵģ�*T��->bf = 0�����ڳ����ˣ�ƽ������û����1			
				(*T)->bf = LH; //
				*taller = 1;
				break;
			case RH:  //ԭ�����ұ߸ߣ�������߳����ˣ�����������Ϊһ����
				(*T)->bf = EH;
				*taller = 0;
				break;
			}
		}
	}
	else  //����������
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
			case LH:  //ԭ������߸��ˣ������ұ߳����ˣ�����������һ����
				(*T)->bf = EH;
				*taller = 0;
				break;
			case EH:  //ԭ����һ���ߣ������ұ߳����ˣ������ǣ�*T��-> bf = -1
				(*T)->bf = RH;
				*taller = 1;
				break;
			case RH:  //ԭ�����ұ߸ߣ������ұ��ֳ����ˣ���Ҫ������������ƽ����ת
				RightBalance(T);
				*taller = 0;
				break;
			}
		}
	}
}

void printAVL(BiTree* T)
{
	//�������������
	if (!*T)
		return;
	printAVL(&(*T)->lchild);
	printf("%d ", (*T)->data);
	printAVL(&(*T)->rchild);
}

void DelAVL(BiTree* T)
{
	//ǰ�洴�����ڴ�ռ䣬���л���---�������
	if (!*T)
		return;
	DelAVL(&(*T)->lchild);

	//ɾ������
	BiTree tmp = (*T)->rchild; //������Ҫ�����Һ��ӵ�ָ��
	free(*T);
	DelAVL(&tmp);
}

//ƽ��������Ĵ�����ʹ��
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