# define _CRT_SECURE_NO_WARNINGS 

#include "����ʽ�ӷ�.h"

void Input_Num(Link head)
{
	printf("ǰ�ߴ���ϵ�������ߴ���ָ��!!!\n");
	printf("�� 0 0��������\n");
	int m, n;
	while (1)
	{
		printf("��������������:>");
		scanf("%d%d",&m, &n);
		if (m == 0 && n == 0)
			break;
		Link note = (Link)malloc(sizeof(Node));
		note->next = NULL;
		note->coefficient = m;
		note->exponent = n;
		//ǰ����
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
				//ϵ�����
				p->coefficient += note->coefficient;
				free(note);
				note = NULL;
				break;
			}
			else
			{
				//���ָ�����
				p = p->next;
			}
		}

		if (note != NULL)
		{
			p = head->next;
			//��������
			while (p != NULL)
			{
				if (note->exponent > p->exponent)
				{
					//����
					note->next = q->next;
					q->next = note;
					break;
				}
				else
				{
					//���ָ���ƶ�
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
	//���µ����ݴ���headA������

	Link qa, pa, qb, pb;  //�ֱ𴴽��������ָ��
	qa = headA;
	pa = headA->next;
	qb = headB;
	pb = headB->next;

	while (pb != NULL)
	{
		if (pa->exponent == pb->exponent)
		{
			//ϵ�����
			(pa->coefficient) += pb->coefficient;
			qb->next = pb->next;
			free(pb);
			pb = qb->next;

			//ͬʱ�ƶ�headA�Ľ��ָ��
			qa = pa;
			pa = pa->next;
		} 
		else if (pa->exponent > pb->exponent)
		{
			//headB�����������
			qa = pa;
			pa = pa->next;
		}
		else 
		{
			//����headA������
			Link tmp = pb; //��ʱ�洢pb��ֵ
			pb->next = qa->next;
			qa->next = pb;
			pb = tmp->next;
			headB->next = pb;
		}

	}

}