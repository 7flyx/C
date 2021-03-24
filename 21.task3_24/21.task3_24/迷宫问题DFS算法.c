# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define M 8
#define N 8
#define DX 8
#define DY 8  //destination 出口坐标


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
		printf("栈已满!\n");
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
		printf("栈为空1\n");
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
	int line, col, x, y, di;  //line,col临时横纵坐标，试探下一坐标
	tmp.x = 1; tmp.y = 1; tmp.di = -1;  //坐标起始地点，即入口

	//计算tmp在board的数据，并将坐标存入栈中
	board[tmp.x][tmp.y] = 0;  //表示已经走过了
	InStack(S, tmp);
	while (!Is_Empty(S))
	{
		//首先是出栈操作，即坐标回溯
		OutStack(S, &tmp);
		//接下来就是进行四个方向的移动
		x = tmp.x; y = tmp.y; di = 0;
		
		while (di < 4)
		{
			line = x + directory[di].x;
			col = y + directory[di].y;
			if (board[line][col] == 0)
			{
				tmp.x = line; //此处的tmp赋值运算只是为了入栈而准备
				tmp.y = col;
				tmp.di = di;
				InStack(S, tmp);
				x = line; y = col;  //xy的值也应随着改变，继续往下走
				board[line][col] = -1;

				if (tmp.x == DX && tmp.y == DY)
					return 1;  //到达终点
				else
					di = 0;  //新起点，方向重新归0
			}
			else
			{
				di++;  //调整方向
			}
		}
	}
	return 0;
}

void Print_Stack(Stack S)
{
	int ptr = 0;  //指向栈底
	for (ptr = 0; ptr <= S.top; ptr++)
		printf("(%d , %d)\n", S.arr[ptr].x, S.arr[ptr].y);
}

//迷宫
//1.创建迷宫 2.建立方向表，
//3.DFS算法，运用堆栈的特性，去一个一个的方向去尝试
//4.如果提前到达终点就退出，如果堆栈为空，则说明迷宫没有路径
//暂时还有一个bug，在3,2处，转折，栈区在出栈后，栈顶指针减1了，后面就进行了更改
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
		//倒序打印栈中的元素
		Print_Stack(S);
	}
	else
	{
		//没有路径可以走出迷宫
		printf("该迷宫没有出路!\n");
	}
	return 0;
}