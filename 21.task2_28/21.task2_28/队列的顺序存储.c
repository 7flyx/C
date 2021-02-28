# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100

typedef struct DATA
{
	int data[MAXSIZE];  //数组，这里表示一个队列，顺序
	int front;  //表示  指向队列的第一个元素
	int rear;  //表示  指向队列的最后一个元素
}DATA;
void enter_DATA(DATA* test, int x)
{
	//首先判断队列是否满了
	if ((test->rear + 1) % MAXSIZE == test->front)
	{
		printf("对列已经满了");
		return;
	}

	//没满，就在（尾指针）的位置放入元素
	test->data[test->rear] = x;
	test->rear = (test->rear + 1) % MAXSIZE;
}
void export_DATA(DATA* test, int* m)
{
	//首先判断队列是否为空
	if (test->front == test->rear)
	{
		printf("队列为空!\n");
		return;
	}

	//没空，就取出当前front位置的元素
	*m = test->data[test->front];
	test->front = (test->front + 1) % MAXSIZE;
}
int main()
{
	//队列的顺序存储--为了判断队列是否满了，通常是把队列浪费一块空间，作为判断是否满了的条件
	//当（rear+1）% MAXSIZE 时，如果等于 front ，此时说明就满了
	int x = 2020;
	int m = 0;  //用于存放出队列时的数据
	int length = 0;
	DATA* test = (DATA*)malloc(sizeof(DATA));
	if (!test)
	{
		printf("开辟空间失败！\n");
		return 0;
	}

	//初始化空队列-----从下标为0的地方开始
	test->front = 0;
	test->rear = 0;

	//入队列
	enter_DATA(test,x);
	//出队列
	export_DATA(test, &m);

	//计算循环队列的长度---(屁股-脑壳+总长)%总长
	length = (test->rear - test->front + MAXSIZE) & MAXSIZE; 

	free(test);
	test = NULL;
	return 0;
}