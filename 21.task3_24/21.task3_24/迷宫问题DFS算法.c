# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define M 8
#define N 8
#define DX 8
#define DY 8  //destination ��������


typedef struct
{
	int x;
	int y;
	int di;
}BOX;

typedef struct
{
	BOX arr[30];
	int top;
}Stack;


void InStack(Stack* S, BOX tmp)
{
	if (S->top == 29)
	{
		printf("ջ����!\n");
		return;
	}
	S->top++;
	S->arr[S->top].x = tmp.x;
	S->arr[S->top].y = tmp.y;
	S->arr[S->top].di = tmp.di;
}

void OutStack(Stack* S, BOX* tmp)
{
	if (S->top == -1)
	{
		printf("ջΪ��1\n");
		return;
	}
	tmp->x = S->arr[S->top].x;
	tmp->y = S->arr[S->top].y;
	tmp->di = S->arr[S->top].di;
	S->top--;
}

int Is_Empty(Stack* S)
{
	if (S->top == -1)
		return 1;
	else
		return 0;
}

int DFSTreverse(int board[][N + 2], Stack* S, BOX directory[4])
{
	BOX tmp;
	int line, col, x, y, di;  //line,col��ʱ�������꣬��̽��һ����
	tmp.x = 1; tmp.y = 1; tmp.di = -1;  //������ʼ�ص㣬�����

	//����tmp��board�����ݣ������������ջ��
	board[tmp.x][tmp.y] = 0;  //��ʾ�Ѿ��߹���
	InStack(S, tmp);
	while (!Is_Empty(S))
	{
		//�����ǳ�ջ���������������
		OutStack(S, &tmp);
		//���������ǽ����ĸ�������ƶ�
		x = tmp.x; y = tmp.y; di = 0;
		
		while (di < 4)
		{
			line = x + directory[di].x;
			col = y + directory[di].y;
			if (board[line][col] == 0)
			{
				tmp.x = line; //�˴���tmp��ֵ����ֻ��Ϊ����ջ��׼��
				tmp.y = col;
				tmp.di = di;
				InStack(S, tmp);
				x = line; y = col;  //xy��ֵҲӦ���Ÿı䣬����������
				board[line][col] = -1;

				if (tmp.x == DX && tmp.y == DY)
					return 1;  //�����յ�
				else
					di = 0;  //����㣬�������¹�0
			}
			else
			{
				di++;  //��������
			}
		}
	}
	return 0;
}

void Print_Stack(Stack S)
{
	int ptr = 0;  //ָ��ջ��
	for (ptr = 0; ptr <= S.top; ptr++)
		printf("(%d , %d)\n", S.arr[ptr].x, S.arr[ptr].y);
}

//�Թ�
//1.�����Թ� 2.���������
//3.DFS�㷨�����ö�ջ�����ԣ�ȥһ��һ���ķ���ȥ����
//4.�����ǰ�����յ���˳��������ջΪ�գ���˵���Թ�û��·��
//��ʱ����һ��bug����3,2����ת�ۣ�ջ���ڳ�ջ��ջ��ָ���1�ˣ�����ͽ����˸���
int main()
{
	int board[10][10] = { 1,1,1,1,1,1,1,1,1,1 ,
   1,0,0,1,0,0,0,1,0,1 ,
   1,0,0,1,0,0,0,1,0,1,
   1,0,0,0,0,1,1,0,0,1,
   1,0,1,1,1,0,0,0,0,1,
   1,0,0,0,1,0,0,0,0,1,
   1,0,1,0,0,0,1,0,0,1,
   1,0,1,1,1,0,1,1,0,1,
   1,1,0,0,0,0,0,0,0,1,
   1,1,1,1,1,1,1,1,1,1 };
	Stack S;
	S.top = -1;
	BOX directory[4] = { {0,1},{1,0},{0,-1},{-1,0} };

	if (DFSTreverse(board, &S, directory))
	{
		//�����ӡջ�е�Ԫ��
		Print_Stack(S);
	}
	else
	{
		//û��·�������߳��Թ�
		printf("���Թ�û�г�·!\n");
	}
	return 0;
}