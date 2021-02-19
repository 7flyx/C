# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define Maxsize 100  //�����������ʽ����󳤶�--�ֽ�

typedef int dataType;
//typedef struct stack
//{
//	baseType* base;  //����ͬ�����͵�ָ�룬����malloc���ٿռ�����
//	baseType* top;
//	int stacksize;  //ջ�Ĵ�С
//}sqstack;

typedef struct Stack
{
	dataType* top;
	dataType* base;
	int stacksize;
}sqstack;

//void creata(sqstack* OPTR)
//{
//	OPTR->base = (baseType*)malloc(MAXSIZE * sizeof(baseType));  //����һ��ռ䣬˳��ջ
//	if (!OPTR->base)
//	{
//		printf("���ٿռ�ʧ�ܣ�\n");
//		return;
//	}
//	OPTR->top = OPTR->base;
//	OPTR->stacksize = MAXSIZE;
//	return;
//}
void create(sqstack* s)
{
	s->base = (dataType*)malloc(Maxsize * sizeof(dataType));
	if (!s->base)
	{
		printf("Space allocation failed!\n");
		return;
	}
	s->top = s->base;
	s->stacksize = Maxsize;
	return;
}

void push_in(sqstack* OPTR, dataType s)
{
	//�ж�ջ�Ƿ�����
	if (OPTR->top - OPTR->base == OPTR->stacksize)
	{
		printf("stack is full!\n");
		return;
	}
	*(OPTR->base) = s;
	OPTR->top++; //ָ������ƶ�
	return;
}
//int push_in(sqstack* s, dataType value)
//{
//	if (s->top - s->base == s->stacksize)
//	{
//		printf("Stack is full!\n");
//		return;
//	}
//	*s->top = value; //"*s->top++=value;"
//	s->top++;
//	return;
//}

void pop(sqstack* OPTR, dataType* elem)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (OPTR->base == OPTR->top)
	{
		printf("popջΪ��!\n");
		return;
	}
	OPTR->top--;
	*elem = *(OPTR->top);
}
//int pop_out(sqstack* s, dataType* elem)
//{
//	if (s->base == s->top)
//	{
//		printf("Stack is empty!");
//		return;
//	}
//	s->top--;
//	*elem = *s->top;  //"*elem=*--s->top;"
//	return;
//}

dataType GetTop(sqstack* OPTR)
{
	if (OPTR->base == OPTR->top)
	{
		printf("GetTopջΪ��!\n");
		return;
	}
	return *(OPTR->top - 1);

}
//dataType GetTop(sqstack* s)
//{
//	if (s->base == s->top)
//	{
//		printf("Stack is empty!\n");
//		printf("Unable to fetch top stack element!\n");
//		return;
//	}
//	return *(s->top - 1);
//}

//��ά����洢�ж�����
char Precede(char q1, char q2)
{
	int i, j;
	//�жϲ��������ȼ��ı��
	char option[7][7] = {
					 {'>','>','<','<','<','>','>'},
					 {'>','>','<','<','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'<','<','<','<','<','=','0'},
					 {'>','>','>','>','0','>','>'},
					 {'<','<','<','<','<','0','='}
	};
	switch (q1) {
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '=': i = 6; break;
	}
	switch (q2) {
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '=': j = 6; break;
	}
	return (option[i][j]);
}
//char Precede(char theta1, char theta2)
//{
//	int i, j;
//	char pre[7][7] = {// +   -   *   /   (   )   = 
//					 {'>','>','<','<','<','>','>'},
//					 {'>','>','<','<','<','>','>'},
//					 {'>','>','>','>','<','>','>'},
//					 {'>','>','>','>','<','>','>'},
//					 {'<','<','<','<','<','=','0'},
//					 {'>','>','>','>','0','>','>'},
//					 {'<','<','<','<','<','0','='} };
//
//	switch (theta1) {
//	case '+': i = 0; break;
//	case '-': i = 1; break;
//	case '*': i = 2; break;
//	case '/': i = 3; break;
//	case '(': i = 4; break;
//	case ')': i = 5; break;
//	case '=': i = 6; break;
//	}
//	switch (theta2) {
//	case '+': j = 0; break;
//	case '-': j = 1; break;
//	case '*': j = 2; break;
//	case '/': j = 3; break;
//	case '(': j = 4; break;
//	case ')': j = 5; break;
//	case '=': j = 6; break;
//	}
//	return(pre[i][j]);
//}

dataType calculate(dataType a, char theta, dataType b)
{
	//int result;
	switch (theta)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
		{
			printf("����Ϊ0\n"); exit(0);
		}
		return a / b;
	default :
		break;
	}
}
//int Operate(int a, char theta, int b)
//{
//	int result;
//
//	switch (theta) {
//	case'+':return a + b;
//	case'-':return a - b;
//	case'*':return a * b;
//	case'/':             //�жϳ����Ƿ�Ϊ0��������Ϊ�㷵�ش�����ʾ                       
//		if (b != 0)
//			return a / b;
//		else
//		{
//			printf("Divisor can not Be zero!\n");
//			exit(0);
//		}
//	}
//
//}

int In(char ch)
{
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
	default:
		return 0;
	}
}
//int In(char c) //�ж��Ƿ�Ϊ������������������1�������Ƿ���0
//{
//	switch (c) {
//	case '+':
//	case '-':
//	case '*':
//	case '/':
//	case '(':
//	case ')':
//	case '=':
//		return 1;
//	default:
//		return 0;
//	}
//}

int Expression(char arr[])
{
	char ch = 0;
	int i = 0; //����������±�
	dataType a, b, theta, x1, x2, x; //ab���ں�����ֵ���㣬x���ڴ�Ŷ���ĳ�ջ���ݣ�x1x2�������鲢
	//��ֵջ�������ջ
	sqstack OPTR, OPND; //������ջ�Ͳ�����ջ

	//��ʼ��ջ
	create(&OPTR);  //������ջ
	create(&OPND); //������ջ
	push_in(&OPTR, '='); //����=��

	//��arr��������ݷ���ջ��
	ch = arr[i++];
	while (ch != '=' || GetTop(&OPTR) != '=')
	{
		//�ж������ֻ��ǲ����������߷Ƿ��ַ�
		if (In(ch))//�ǲ�����
		{
			//�ж����ȼ������Ƿ���ջ�У����ǳ�ջ����
			switch (Precede(GetTop(&OPTR), ch))
			{
			case '>':  //�������㣬�����·���ջ��
				pop(&OPND, &b);
				pop(&OPND, &a);
				pop(&OPTR, &theta);
				//����ý��
				push_in(&OPND, calculate(a, theta, b));
				//ch = arr[i++];
				break;
			case '<':  //ֱ�ӷ���ջ��
				push_in(&OPTR, ch);
				ch = arr[i++];
				break;
			case '=':  //����ջ����Ԫ��
				pop(&OPTR, &x);
				ch = arr[i++];
				break;
			default:
				break;
			}

		}
		else if (ch == ' ') //�ո�
		{
			while (ch == ' ')
			{
				ch = arr[i++];
			}
		}
		else if (isdigit(ch))  //����
		{
			x1 = ch - '0'; //�õ�����
			push_in(&OPND, x1);  //��ջ
			x2 = x1;
			ch = arr[i++];

			while (isdigit(ch))
			{
				x1 = ch - '0';
				x2 = 10 * x2 + x1;  //�鲢
				pop(&OPND, &x); //���ϴδ洢����ȡ����
				push_in(&OPND, x2); //���´���
				ch = arr[i++];
			}

		}
		else
		{
			//�Ƿ��ַ�
			printf("���ʽ������!\n");
			exit(0);
		}
	}

	return GetTop(&OPND);

}
//int evaluateExpression(char exp[])
//{
//	sqstack OPND, OPTR; //������ջ�������ջ
//	dataType a, b, theta, x, X1, X2;  /* a��b��theta����Operate����
//									X���ڴ�Ŷ���ĳ�ջ�ַ�
//									X1,X2���ڹ鲢 */
//	char ch; //��ȡ�ַ��ı���
//	int i = 0; //ָ���ű��ʽ������±�ָ�루��ʵ����������ָ�룬���������±꣩
//
//	create(&OPND); //��������ʼ��������ջOPND
//	create(&OPTR); //��������ʼ�������ջOPTR
//	push_in(&OPTR, '='); //�Ƚ���=����ѹ��OPTRջ�����ʽҲ�����ԡ�=��������
//
//	ch = exp[i++]; //ch��ȡ�ַ������һ��Ԫ�أ�����ָ��i����һλ
//
//
//	while (ch != '=' || GetTop(&OPTR) != '=') //���ʽû��ɨ����ϻ�OPTR��ջ����Ϊ��=��
//	{
//		if (In(ch)) //�ж�ch�Ƿ�Ϊ������
//		{
//			switch (Precede(GetTop(&OPTR), ch))//�Ƚ�ch����OPTRջ��Ԫ�ص����ȼ�
//			{
//			case'<':
//				push_in(&OPTR, ch);
//				ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//				break;
//
//			case'>':
//				pop_out(&OPTR, &theta);
//				pop_out(&OPND, &b);
//				pop_out(&OPND, &a);
//				push_in(&OPND, Operate(a, theta, b));
//				break;
//
//			case'=':
//				pop_out(&OPTR, &x);
//				ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//				break;
//			}
//
//		}
//
//		else if (isdigit(ch)) //�ж��Ƿ�Ϊ����
//		{
//			X1 = ch - '0'; //���ַ���ʽת��Ϊ����
//			push_in(&OPND, X1);
//			X2 = X1;
//			ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//
//			while (isdigit(ch)) //�ж���һλ�Ƿ�������
//			{
//				X1 = ch - '0';
//				X2 = 10 * X2 + X1; //�鲢��X2
//				pop_out(&OPND, &x);
//				push_in(&OPND, X2);
//				ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
//
//			}
//		}
//
//		else if (ch == ' ') //�ж��Ƿ�Ϊ�ո�
//		{
//			while (ch == ' ') //�������ɸ��ո�
//			{
//				ch = exp[i++]; //���Կո�ֱ��ȡ��һλ
//			}
//
//		}
//
//		else //�����������������֮һ����Ϊ�Ƿ��ַ�
//		{
//			printf("Input has illegal characters!\n");
//			printf("Please enter again.\n");
//			exit(0); //���ش�����ʾ
//		}
//	}
//	return(GetTop(&OPND)); //��󷵻ز�����ջ��Ϊ������
//}


//int main()
//{
//	char arr[Maxsize] = { 0 };
//	int i = 0;
//	printf("Please Enter Expression:");
//
//
//	gets(arr);
//	i = Expression(arr);
//	printf("\n");
//	printf("%s%d\n", arr, i);
//	return 0;
//}
int main()
{

	char exp[100]; //����һ���ַ��������ڴ洢���ʽ
	int result;
	printf("Please Enter Expression:");
	gets(exp); //����scanf����%s����exp����Ҳ����
	result = evaluateExpression(exp);
	printf("\n");
	printf("%s%d\n", exp, result);

	return 0;
}