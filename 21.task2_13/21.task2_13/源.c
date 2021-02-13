# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

typedef struct Node
{
	int data;  //数据域
	struct Node* next; //指针域
}*Link,node;


//链表---头插法
Link LinkLastList(int arr[10])
{
	//创建头结点
	Link head_p = (Link)malloc(sizeof(node));
	head_p->next = NULL;

	//循环到下一结点
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		Link note = (Link)malloc(sizeof(node));
		note->data = arr[i];
		note->next = head_p->next;
		head_p->next = note;
		
	}
	return head_p; //返回头结点的指针域
}

//链表---尾插法
Link LinkLastList(int arr[10])
{
	//创建头结点
	Link head = (Link)malloc(sizeof(node));
	head->next = NULL;
	Link rear = head;  //创建一个尾结点

	//循环
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		Link note = (Link)malloc(sizeof(node));
		note->data = arr[i];
		note->next = NULL; //尾结点的指针域赋空值，以免后续出现死循环
		rear->next = note;  //将尾结点的指针域放入note
		rear = note;  //更新尾结点的值
	}

	return head; //返回头结点的地址
}


//删除某项数据
int DeleteList(Link head, int x)
{
	//1.首先看是否为空表
	if (head == NULL || head->next == NULL)
		return 0;  

	//2.定义前后结点，p，q
	Link p = head->next; //指向后一结点
	Link q = head; //指向前一结点

	//3. 循环查找，找到后删除结点并返回1
	while (p != NULL)
	{
		//判断是否相等
		if (p->data == x)
		{
			q->next = p->next;
			free(p);
			return 1;
		}
		else
		{
			q = p;
			p = p->next;  //p、q的值往下一结点走
		}
	}

	//循环完后，说明没找到
	return 0;
}

int main()
{
	//单链表---头插法
	int arr[10] = { 1,3,4,5,6,7,8,3,8,2 };
	node head = { 0 };
	Link ps = LinkLastList(arr); //接收返回的头结点的指针域

	DeleteList(3);// 删除单链表中的某数据
	return 0;
}