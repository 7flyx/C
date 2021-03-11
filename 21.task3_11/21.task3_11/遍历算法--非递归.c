# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct BiTree
{
	char data;
	struct BiTree* rchild, * lchild;
}BiTree;

//ָ��BiTree�Ľ�㣬������flag
typedef struct BNODE
{
	BiTree* ptr;
	int flag;  //���ڱ�ʾ�������������ķ�����������������Ҫ�ý�㣬ǰ��������Ҫ
}StackNODE;

//ջ
typedef struct Stack
{
	BiTree* pb[20]; //ģ��ջ
	int top;
}Stack;

//��ջ
void push(Stack* s, BiTree* p)
{
	if (s->top + 1 == 20)
	{
		printf("ջ��!\n");
		return;
	}

	s->top++;
	s->pb[s->top] = p;
}
void push2(StackNODE* s, BiTree* p)
{
	if (s->top + 1 == 20)
	{
		printf("ջ����\n");
		return;
	}

	s->top++;
	s->ptr[s->top] = p;
}
//��ջ
void  pop(Stack* s, BiTree** p)
{
	if (s->top == -1)
	{
		printf("ջΪ��!\n");
		return;
	}

	*p = s->pb[s->top];
	s->top--;
}
StackNODE* pop2(StackNODE* s)
{
	
}

//�ж�ջ��
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

//ǰ�����--�ǵݹ�
void preorder(BiTree* root)
{
	Stack S1;
	S1.top = -1;

	BiTree* p = root;
	while (p != NULL || isEmpty(S1))  //isEmpty���ж�ջ���Ƿ�Ϊ��
	{
		while (p != NULL)
		{
			//ѭ������������
			push(&S1, p); //�洢���ǵ�ǰ�����ĵ�ַ
			printf("&c ", p->data);
			p = p->lchild;
		}
		if (!isEmpty(S1))
		{
			//���ջΪ���ˣ�����Ҫ��ջ��pָ��ָ��������
			pop(&S1,&p); //������һ��p�Ľ���ַ
			p = p->rchild;  //����������
		}
	}
}

//�������--�ǵݹ�
void Inorder(BiTree* root)
{
	//��������㷨��ǰ���ֻ࣬���ڷ��ʽ�����䣬��if�������
	Stack S2;
	S2.top = -1;
	BiTree* p = root;

	while (p != NULL || isEmpty(S2))
	{
		while (p != NULL)
		{
			push(&S2, p); //��ջ
			p = p->lchild; //��������������
		}
		if (!isEmpty(S2))
		{
			pop(&S2, &p);
			printf("%c ", p->data);
			p = p->rchild; //����������
		}
	}
}

//�������--�ǵݹ�
void epilogue(BiTree* root)
{
	//�����������ǰ������������ͬ����Ҫ����flag��ȷ�����������Ƿ��Ѿ��������ˣ����
	//�����������������ˣ���ֱ�����

}

//��������ǰ�������������㷨---�ǵݹ�
int main()
{
	return 0;
}