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
	//ǰ�����
	if (T == NULL)
		return; //��Ϊ��
	//�ȴ�ӡ������
	printf("%d", T->data);  
	preorder(T->lchild);
	preorder(T->rchild);
}

void epilogue(Link_two* T)
{
	//�������
	if (T == NULL)
		return; //��Ϊ��
	//�����ң����ӡ
	epilogue(T->lchild);
	epilogue(T->rchild);
	printf("%d", T->data);
}

void inorder(Link_two* T)
{
	//�������
	if (T == NULL)
		return; //��Ϊ��
	//�����ٴ�ӡ������
	inorder(T->lchild);
	printf("%d", T->data);
	inorder(T->rchild);
}

//��������
int main()
{

	return 0;
}