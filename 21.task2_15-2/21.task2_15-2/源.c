# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>



typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//Լɪ������
//��ÿ���ṹ���е����ݷ�����ֵ������ڼ�ֻ���ӣ�����ӡ����������
int main()
{
	//����ͷ���
	int n, m, i;
	struct Node* head, * tail, * q, * p;
	head = (struct Node*)malloc(sizeof(Node));
	head->next = NULL;

	while (1)
	{
		scanf("%d%d", &n, &m);
		if (n == 0 || m == 0)
		{
			printf("�������\n");
			break;
		}
		else
		{
			//����ѭ������
			tail = head;
			for (i = 1; i <= n; i++)
			{
				p = (struct Node*)malloc(sizeof(Node));
				p->data = i;
				tail->next = p;
				p->next = head->next;
				tail = p;
			}

			//����q��p���
			q = tail;
			p = head->next;
			i = 1;
			while (q != p)
			{
				//�жϱ���i��m֮��Ĺ�ϵ				
				if (i == m)
				{
					//ɾ�����---����i��ֵ
					i = 1;
					q->next = p->next;
					free(p);
					p = q->next;
				}
				else
				{
					//�ƶ�ǰ���㣬i��һ
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