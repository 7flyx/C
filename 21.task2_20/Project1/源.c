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
		printf("内存开辟失败\n");
		return;
	}
	s->stacksize = MAXSIZE;
	s->top = s->base;
}

int In(char ch)
{
	//判断是不是操作符---  +-*/()=
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
//	//判断栈是否为空
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
	return *(s->top - 1);  //需要减1，因为解引用时，是向后访问的，而此时的指针指向最后一个元素的屁股的
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
		printf("theta1值无效!\n");
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
		printf("theta2值无效!\n");
		break;
	}

	return (option[i][j]);
}



void push(sqstack* s, dataType value)
{
	//首先判断栈是否满了
	if (s->top - s->base == s->stacksize)
	{
		printf("push: stack is full\n");
		return;
	}
	//先放入元素，再移动指针 
	*s->top = value;
	s->top++;
}

void pop(sqstack* s, dataType* elem)
{
	//首先判断栈是否为空
	if (s->base == s->top)
	{
		printf("pop: stack is full\n");
		return;
	}
	//先拿走元素，再移动指针
	*elem = *(s->top - 1);  //特别注意怎么读取最后一个栈顶的元素
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
	printf("计算出错\n");
	return EOF;
}

int EXPRESSION(char exp[])
{
	sqstack OPND, OPTR;  //操作数栈，操作符栈
	dataType a, b, x, x1, x2, theta, tmp;

	//栈初始化
	Initstack(&OPND);
	Initstack(&OPTR);
	push(&OPTR, '='); //操作符栈提前放入=号

	char ch = 0;
	int i = 0; //用于数组的下标
	//1.判断是操作符还是操作数

	ch = exp[i++];

	while (ch != '='|| GetTop(&OPTR) != '=')
	{
		if (In(ch)) //是操作符
		{
			//判断优先级，看是入栈还是出栈
			switch (Precede(GetTop(&OPTR), ch))
			{
			case '<':  //入栈
				push(&OPTR, ch);
				ch = exp[i++];
				break;
			case '>':  //出栈
				pop(&OPTR, &theta);
				pop(&OPND, &b);
				pop(&OPND, &a);

				//计算a与b之间的值
				tmp = Operate(a, theta, b);
				push(&OPND, tmp);
				//if (tmp != EOF)
				//{
				//	push(&OPND, tmp);
				//	//push(&OPTR, ch);				
				//}
				break;
			case '=':  //消除操作符栈顶元素
				pop(&OPTR, &x);
				ch = exp[i++];
				break;
			}
		}
		else if (isdigit(ch))  //是操作数
		{
			x1 = ch - '0';
			x2 = x1;
			push(&OPND, x1);
			ch = exp[i++];
			while (isdigit(ch)) //还是操作数，归并
			{
				pop(&OPND, &x);  //首先弹出上次进去的数值
				x1 = ch - '0';
				x2 = 10 * x2 + x1;
				push(&OPND, x2);
				ch = exp[i++];
			}

		}
		else if (ch == '=') //是空格
		{
			while (ch == '=')
			{
				ch = exp[i++];  //字符向后移动
			}
		}
		else  //是非法字符
		{
			printf("非法字符!\n");
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
	printf("please enter expression(=号结束):");
	gets(exp);

	x = EXPRESSION(exp);

	printf("%s%d\n", exp, x);
	return 0;
}