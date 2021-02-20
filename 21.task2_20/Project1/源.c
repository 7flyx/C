# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int dataType;
typedef struct Stack
{
	dataType* base;
	dataType* top;
	int stacksize;
}sqstack;

void Initstack(sqstack* s)
{
	s->base = (dataType*)malloc(sizeof(dataType) * MAXSIZE);
	if (!s->base)
	{
		printf("�ڴ濪��ʧ��\n");
		return;
	}
	s->stacksize = MAXSIZE;
	s->top = s->base;
}

int In(char ch)
{
	//�ж��ǲ��ǲ�����---  +-*/()=
	switch (ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '=':
		return 1;
	default :
		return 0;
	}
}


//int GetTop(sqstack* optr, dataType* value)
//{
//	//�ж�ջ�Ƿ�Ϊ��
//	if (optr->base == optr->top)
//	{
//		printf("GetTop : stack is full\n");
//		return 0;
//	}
//	*value = *(optr->top-1);
//	return 1;
//}
dataType GetTop(sqstack* s)
{
	if (s->base == s->top)
	{
		printf("Stack is empty!\n");
		printf("Unable to fetch top stack element!\n");
		return;
	}
	return *(s->top - 1);  //��Ҫ��1����Ϊ������ʱ���������ʵģ�����ʱ��ָ��ָ�����һ��Ԫ�ص�ƨ�ɵ�
}

char Precede(char theta1, char theta2)
{
	int i, j;
	char option[7][7] = {// +   -   *   /   (   )   = 
					 {'>','>','<','<','<','>','>'},
					 {'>','>','<','<','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'<','<','<','<','<','=','0'},
					 {'>','>','>','>','0','>','>'},
					 {'<','<','<','<','<','0','='} };

	switch (theta1)
	{
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '=': i = 6; break;
	default :
		printf("theta1ֵ��Ч!\n");
		break;
	}

	switch (theta2)
	{
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '=': j = 6; break;
	default:
		printf("theta2ֵ��Ч!\n");
		break;
	}

	return (option[i][j]);
}



void push(sqstack* s, dataType value)
{
	//�����ж�ջ�Ƿ�����
	if (s->top - s->base == s->stacksize)
	{
		printf("push: stack is full\n");
		return;
	}
	//�ȷ���Ԫ�أ����ƶ�ָ�� 
	*s->top = value;
	s->top++;
}

void pop(sqstack* s, dataType* elem)
{
	//�����ж�ջ�Ƿ�Ϊ��
	if (s->base == s->top)
	{
		printf("pop: stack is full\n");
		return;
	}
	//������Ԫ�أ����ƶ�ָ��
	*elem = *(s->top - 1);  //�ر�ע����ô��ȡ���һ��ջ����Ԫ��
	s->top--;
	
}

dataType Operate(dataType a, dataType theta, dataType b)
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': 
		if (b != 0)
			return a / b;
		else
		{
			printf("Divisor can not Be zero!\n");
			exit(0);
		}
	}
	printf("�������\n");
	return EOF;
}

int EXPRESSION(char exp[])
{
	sqstack OPND, OPTR;  //������ջ��������ջ
	dataType a, b, x, x1, x2, theta, tmp;

	//ջ��ʼ��
	Initstack(&OPND);
	Initstack(&OPTR);
	push(&OPTR, '='); //������ջ��ǰ����=��

	char ch = 0;
	int i = 0; //����������±�
	//1.�ж��ǲ��������ǲ�����

	ch = exp[i++];

	while (ch != '='|| GetTop(&OPTR) != '=')
	{
		if (In(ch)) //�ǲ�����
		{
			//�ж����ȼ���������ջ���ǳ�ջ
			switch (Precede(GetTop(&OPTR), ch))
			{
			case '<':  //��ջ
				push(&OPTR, ch);
				ch = exp[i++];
				break;
			case '>':  //��ջ
				pop(&OPTR, &theta);
				pop(&OPND, &b);
				pop(&OPND, &a);

				//����a��b֮���ֵ
				tmp = Operate(a, theta, b);
				push(&OPND, tmp);
				//if (tmp != EOF)
				//{
				//	push(&OPND, tmp);
				//	//push(&OPTR, ch);				
				//}
				break;
			case '=':  //����������ջ��Ԫ��
				pop(&OPTR, &x);
				ch = exp[i++];
				break;
			}
		}
		else if (isdigit(ch))  //�ǲ�����
		{
			x1 = ch - '0';
			x2 = x1;
			push(&OPND, x1);
			ch = exp[i++];
			while (isdigit(ch)) //���ǲ��������鲢
			{
				pop(&OPND, &x);  //���ȵ����ϴν�ȥ����ֵ
				x1 = ch - '0';
				x2 = 10 * x2 + x1;
				push(&OPND, x2);
				ch = exp[i++];
			}

		}
		else if (ch == '=') //�ǿո�
		{
			while (ch == '=')
			{
				ch = exp[i++];  //�ַ�����ƶ�
			}
		}
		else  //�ǷǷ��ַ�
		{
			printf("�Ƿ��ַ�!\n");
			exit(0);
		}
		//GetTop(&OPTR, &x);
	}
	return GetTop(&OPND);
}



int main()
{
	char exp[MAXSIZE];
	int x = 0;
	printf("please enter expression(=�Ž���):");
	gets(exp);

	x = EXPRESSION(exp);

	printf("%s%d\n", exp, x);
	return 0;
}