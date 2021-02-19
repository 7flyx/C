# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define Maxsize 100

typedef int dataType;
typedef struct Stack
{
	dataType* top;
	dataType* base;
	int stacksize;
}sqstack;

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

int push_in(sqstack* s, dataType value)
{
	if (s->top - s->base == s->stacksize)
	{
		printf("Stack is full!\n");
		return;
	}
	*s->top = value; //"*s->top++=value;"
	s->top++;
	return;
}

int pop_out(sqstack* s, dataType* elem)
{
	if (s->base == s->top)
	{
		printf("Stack is empty!");
		return;
	}
	s->top--;
	*elem = *s->top;  //"*elem=*--s->top;"
	return;
}

dataType GetTop(sqstack* s)
{
	if (s->base == s->top)
	{
		printf("Stack is empty!\n");
		printf("Unable to fetch top stack element!\n");
		return;
	}
	return *(s->top - 1);
}

char Precede(char theta1, char theta2)
{
	int i, j;
	char pre[7][7] = {// +   -   *   /   (   )   = 
					 {'>','>','<','<','<','>','>'},
					 {'>','>','<','<','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'>','>','>','>','<','>','>'},
					 {'<','<','<','<','<','=','0'},
					 {'>','>','>','>','0','>','>'},
					 {'<','<','<','<','<','0','='} };

	switch (theta1) {
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '=': i = 6; break;
	}
	switch (theta2) {
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '=': j = 6; break;
	}
	return(pre[i][j]);
}

int Operate(int a, char theta, int b)
{
	int result;

	switch (theta) {
	case'+':return a + b;
	case'-':return a - b;
	case'*':return a * b;
	case'/':             //�жϳ����Ƿ�Ϊ0��������Ϊ�㷵�ش�����ʾ                       
		if (b != 0)
			return a / b;
		else
		{
			printf("Divisor can not Be zero!\n");
			exit(0);
		}
	}

}

int In(char c) //�ж��Ƿ�Ϊ������������������1�������Ƿ���0
{
	switch (c) {
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

int evaluateExpression(char exp[])
{
	sqstack OPND, OPTR; //������ջ�������ջ
	dataType a, b, theta, x, X1, X2;  /* a��b��theta����Operate����
									X���ڴ�Ŷ���ĳ�ջ�ַ�
									X1,X2���ڹ鲢 */
	char ch; //��ȡ�ַ��ı���
	int i = 0; //ָ���ű��ʽ������±�ָ�루��ʵ����������ָ�룬���������±꣩

	create(&OPND); //��������ʼ��������ջOPND
	create(&OPTR); //��������ʼ�������ջOPTR
	push_in(&OPTR, '='); //�Ƚ���=����ѹ��OPTRջ�����ʽҲ�����ԡ�=��������

	ch = exp[i++]; //ch��ȡ�ַ������һ��Ԫ�أ�����ָ��i����һλ


	while (ch != '=' || GetTop(&OPTR) != '=') //���ʽû��ɨ����ϻ�OPTR��ջ����Ϊ��=��
	{
		if (In(ch)) //�ж�ch�Ƿ�Ϊ������
		{
			switch (Precede(GetTop(&OPTR), ch))//�Ƚ�ch����OPTRջ��Ԫ�ص����ȼ�
			{
			case'<':
				push_in(&OPTR, ch);
				ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
				break;

			case'>':
				pop_out(&OPTR, &theta);
				pop_out(&OPND, &b);
				pop_out(&OPND, &a);
				push_in(&OPND, Operate(a, theta, b));
				break;

			case'=':
				pop_out(&OPTR, &x);
				ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ
				break;
			}

		}

		else if (isdigit(ch)) //�ж��Ƿ�Ϊ����
		{
			X1 = ch - '0'; //���ַ���ʽת��Ϊ����
			push_in(&OPND, X1);
			X2 = X1;
			ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ

			while (isdigit(ch)) //�ж���һλ�Ƿ�������
			{
				X1 = ch - '0';
				X2 = 10 * X2 + X1; //�鲢��X2
				pop_out(&OPND, &x);
				push_in(&OPND, X2);
				ch = exp[i++]; //��ȡ��һλ�ַ�����ָ�����ƫ��һλ

			}
		}

		else if (ch == ' ') //�ж��Ƿ�Ϊ�ո�
		{
			while (ch == ' ') //�������ɸ��ո�
			{
				ch = exp[i++]; //���Կո�ֱ��ȡ��һλ
			}

		}

		else //�����������������֮һ����Ϊ�Ƿ��ַ�
		{
			printf("Input has illegal characters!\n");
			printf("Please enter again.\n");
			exit(0); //���ش�����ʾ
		}
	}
	return(GetTop(&OPND)); //��󷵻ز�����ջ��Ϊ������
}

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
