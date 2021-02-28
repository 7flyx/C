# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>


typedef struct QNODE  
{
	int data; //数据域
	struct QNODE* next; //指针域
}QNODE;
typedef struct
{
	QNODE* front;
	QNODE* rear; //队头，队尾指针
}LinkP;
void enter_QNODE(LinkP* q, int x)
{
	//链式存储，不存在满的情况
	QNODE* s = (QNODE*)malloc(sizeof(QNODE));
	if (!s)
	{
		printf("s开辟失败\n");
		return;
	}

	s->data = x;
	s->next = NULL;
	q->rear->next = s;

	q->rear = s; //移动队尾指针
}
void export_QNODE(LinkP* q, int* m)
{
	//首先判断队列是否为空
	if (q->front == q->rear)
	{
		printf("队列为空\n");
		return;
	}

	QNODE* tmp = q->front->next;  //q->front  指向的是头结点
	*m = tmp->data;
	q->front->next = tmp->next;

	//删除后，还应判断是不是头尾指针重合了
	if (q->rear == tmp)
	{
		//说明我们删除的是最后一个元素，应将尾指针重新赋值成head
		q->rear = q->front;
	}
	free(tmp);
}
int main()
{
	//头结点----指向队头
	int x = 520;  
	int m = 0;
	QNODE* head = (QNODE*)malloc(sizeof(QNODE));
	if (!head)
	{
		printf("head:开辟失败!\n");
		return;
	}
	LinkP* p = (LinkP*)malloc(sizeof(LinkP));
	if (!p)
	{
		printf("LinkP  开辟失败\n");
		return;
	}
	//初始化头尾指针
	p->front = head;
	p->rear = head;

	//入队列
	enter_QNODE(p, x);

	//出队列
	export_QNODE(p, &m);
	return 0;
}