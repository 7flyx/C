# define _CRT_SECURE_NO_WARNINGS 

#include "多项式加法.h"

void Input_Num(Link head)
{
	printf("前者代表系数，后者代表指数!!!\n");
	printf("以 0 0结束输入\n");
	int m, n;
	while (1)
	{
		printf("请输入两个数字:>");
		scanf("%d%d",&m, &n);
		if (m == 0 && n == 0)
			break;
		Link note = (Link)malloc(sizeof(Node));
		note->next = NULL;
		note->coefficient = m;
		note->exponent = n;
		//前后结点
		Link q = head;
		Link p = head->next;


		while ((p != NULL) && (note->exponent <= p->exponent))
		{
			if (note->coefficient == 0)
			{
				free(note);
				note = NULL;
				break;
			}
			else if (note->exponent == p->exponent)
			{
				//系数相加
				p->coefficient += note->coefficient;
				free(note);
				note = NULL;
				break;
			}
			else
			{
				//结点指针后移
				p = p->next;
			}
		}

		if (note != NULL)
		{
			p = head->next;
			//插入链表
			while (p != NULL)
			{
				if (note->exponent > p->exponent)
				{
					//插入
					note->next = q->next;
					q->next = note;
					break;
				}
				else
				{
					//结点指针移动
					q = p;
					p = p->next;
				}
			}
			if (p == NULL)
				q->next = note;
		}
		
			
		}
		
}


void show_Num(Link head)
{
	Link p = head->next;
	while (p != NULL)
	{
		printf("%d %d\n", p->coefficient, p->exponent);
		p = p->next;
	}
}



void Add_Num(Link headA, Link headB)
{
	//将新的数据存入headA链表里

	Link qa, pa, qb, pb;  //分别创建两个结点指针
	qa = headA;
	pa = headA->next;
	qb = headB;
	pb = headB->next;

	while (pb != NULL)
	{
		if (pa->exponent == pb->exponent)
		{
			//系数相加
			(pa->coefficient) += pb->coefficient;
			qb->next = pb->next;
			free(pb);
			pb = qb->next;

			//同时移动headA的结点指针
			qa = pa;
			pa = pa->next;
		} 
		else if (pa->exponent > pb->exponent)
		{
			//headB的链表结点后移
			qa = pa;
			pa = pa->next;
		}
		else 
		{
			//插入headA链表中
			Link tmp = pb; //临时存储pb的值
			pb->next = qa->next;
			qa->next = pb;
			pb = tmp->next;
			headB->next = pb;
		}

	}

}