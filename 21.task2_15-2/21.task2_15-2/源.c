# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>



typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//约瑟夫环问题
//将每个结构体中的数据放入数值，代表第几只猴子，最后打印出来就是了
int main()
{
	//创建头结点
	int n, m, i;
	struct Node* head, * tail, * q, * p;
	head = (struct Node*)malloc(sizeof(Node));
	head->next = NULL;

	while (1)
	{
		scanf("%d%d", &n, &m);
		if (n == 0 || m == 0)
		{
			printf("输入错误\n");
			break;
		}
		else
		{
			//创建循环链表
			tail = head;
			for (i = 1; i <= n; i++)
			{
				p = (struct Node*)malloc(sizeof(Node));
				p->data = i;
				tail->next = p;
				p->next = head->next;
				tail = p;
			}

			//重置q，p结点
			q = tail;
			p = head->next;
			i = 1;
			while (q != p)
			{
				//判断变量i与m之间的关系				
				if (i == m)
				{
					//删除结点---重置i的值
					i = 1;
					q->next = p->next;
					free(p);
					p = q->next;
				}
				else
				{
					//移动前后结点，i加一
					i++;
					q = p;
					p = p->next;
				}
			}
			printf("%d ", p->data);

		}
	}
	free(head);
	head=NULL;
	
	return 0;
}