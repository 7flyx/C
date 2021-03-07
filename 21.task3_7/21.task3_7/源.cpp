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
//�������
//1.�ж����Ƿ�Ϊ��
//2. ���Ԫ�����
//
//ѭ���ж����������в�Ϊ��
//3. ���ж��������Ƿ�Ϊ�գ���Ϊ�վ����
//4. ���ж��������Ƿ�Ϊ�գ���Ϊ�վ����
//
//void CX_traverse(DataType* T)
//{
//	if (T)
//		return;  //��Ϊ��
//	DataType q;
//	enQueue(T);  //���
//	while (Queue_empty(T)) //���в�Ϊ�գ�ѭ������
//	{
//		q = outQueue(T);  //����
//		printf("%d", q);  //����
//
//		��װT�Ѿ������ṹ��
//		if (T->lchild)
//			enQueue(T->lchild);  //������
//		if (T->rchild)
//			enQueue(T->rchild);  //������
//	}
//}
//int main()
//{
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>


int i = 0; //ȫ�ֱ�������������ķ���

#define MAXSIZE 100
typedef struct BiTree
{
	char data;
	struct BiTree* lchild, *rchild;
}BiTree;

typedef struct arr
{
	//һά������
	char data;
	int lchild;
	int rchild;
}ANODE;
//����������---��������
//Ҳ��Ϊǰ�� ���� ���� ������������
void createTree_Q(BiTree** T)
{
	//'#'Ϊ����
	//��������Ϊ����ָ�룬������߼���Ϊʲô�Ƕ���ָ�룿
	//ǰ����
	char ch = 0;
	printf("�������ַ���");
	scanf(" %c", &ch);
	//getchar();  //���뻺�������⣬��\n��ԭ��
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree*)malloc(sizeof(BiTree));
		if (!(*T))
			return;
		(*T)->data = ch;
		createTree_Q(&(*T)->lchild); //����������
		createTree_Q(&(*T)->rchild); //����������
	}
}

//��������������
int DepthTree(BiTree* bt)
{
	//���ȶ��������������lt���������������rt
	//�ݹ���ú�����ÿ�ε��ú���ȶ�Ӧ�ü�һ
	//ֱ�������Ϊ��ʱ������0
	int lt = 0;
	int rt = 0;
	if (bt)
	{
		lt = DepthTree(bt->lchild) + 1;
		rt = DepthTree(bt->rchild) + 1;
	}
	return lt > rt ? lt : rt;
}

//��������е�Ҷ�ӽ����
void LeftCount(BiTree* T, int* num)
{
	if (T)
	{
		//��Ϊ�գ�����
		//�����Һ��Ӷ��ǿ�ʱ��������Ҷ�ӽ��
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


//δд��
//void shift_arr(BiTree* T, ANODE *arr)
//{
//	//ʵ����ǰ�����⣬��ÿ�α������������η�����������
//	if (!T)
//		return; //��Ϊ��
//
//	arr[i++].data = T->data;
//	if (T->lchild != NULL)
//		(arr[i - 1]).lchild = 2 * i;
//	if (T->rchild != NULL)
//		arr[i - 1].rchild = 2 * i + 1;
//
//	//�ٵ�����������������
//	shift_arr(T->lchild , arr);
//	shift_arr(T->rchild , arr);
//}
int main()
{
	int count = 0;  //���ڴ洢Ҷ�ӵĽ����
	//����������
	BiTree* tree = (BiTree*)malloc(sizeof(BiTree));
	ANODE arr[MAXSIZE] = { 0 };
	createTree_Q(&tree);
	//shift_arr(tree, arr);
	/*int j = 0;
	for (j = 0; i < i; j++)
	{
		printf("%c %d %d\n", arr[j].data, arr[j].lchild, arr[j].rchild);
	}*/
	

	//����Ҷ�ӽ��ĸ���
	LeftCount(tree, &count);
	printf("Ҷ�ӽ����Ϊ%d\n", count);
	//��������������
	printf("�������������%d\n", DepthTree(tree));
	return 0;
}