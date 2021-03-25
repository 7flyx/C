#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 10  //��󶥵���


int visited[MAXVEX];


typedef struct arcList
{
	int vexs_num;  //�ڵ���Ϣ�ڶ���������±�
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int vex;
	arcList* firstEdge;  //ָ���һ���߱��ָ��
}VEXS;

typedef struct Graph
{
	VEXS vexs[MAXVEX];
	int numVex,numArc;
}Graph;

typedef struct Queue
{
	int num[20];  //����visited���������
	int top;
}Queue;


void create_Graph(Graph* G)
{
	int i,x,y;
	arcList* e = NULL;
	//�������붥���������
	printf("�����붥���������:");
	scanf("%d%d",&G->numVex,&G->numArc);

	//���붥����Ϣ��firstEdgeָ��ĳ�ʼ��
	for( i=0;i<G->numVex;i++)
	{
		printf("�����붥����Ϣ:");
		scanf("%d",&G->vexs[i].vex);
		G->vexs[i].firstEdge = NULL;
	}

	//����ߵ���Ϣ������������
	for(i=0;i<G->numArc ;i++)
	{
		printf("������(vi,vj)������֮����±꣺");
		scanf("%d%d",&x,&y);

		e = (arcList*)malloc(sizeof(arcList));
		if(!e)
			return;
		e->vexs_num = x;
		e->next = G->vexs[y].firstEdge ;
		G->vexs[y].firstEdge = e;

		e = (arcList*)malloc(sizeof(arcList));
		if(!e)
			return;
		e->vexs_num = y;
		e->vexs_num = G->vexs[x].firstEdge ;
		G->vexs [x].firstEdge = e;

		//ͬ���ģ�����ͼ����Ҫ����malloc����ʾ��ϵ��������ͼֻ��Ҫһ�Σ���������Ȼ��߳���
	}
}

void InQueue(Queue* Q, int i)
{
	if(Q->top == 10)
	{
		printf("��������!\n");
		return;
	}
	Q->top++;
	Q->num[Q->top] = i;
}

void OutQueue(Queue* Q,int* i)
{
	*i = Q->num[Q->top];
	Q->top--;
}

int is_Empty(Queue* Q)
{
	if(Q->top == -1)
		return 1;
	else
		return 0;
}

void BFSTreverse(Graph G)
{
	//�������У���ʱ����
	int i;
	arcList* p;
	Queue Q;
	Q.top = -1;  //��ʼ��

	for(i=0;i<G.numVex;i++)
		visited[i] = 0;
	for(i=0;i<G.numVex ;i++)  //�ж�ȫ���Ķ���
	{
		
		if(!visited[i])
		{
				// ���ȷ��ʵ�һ������
			visited[i] = 1;
			printf("%d ",G.vexs [0].vex);
			InQueue(&Q,i);  //���

			while(!is_Empty(&Q))  //�ǿն���
			{
				//���ȳ��ӣ�Ȼ���жϸýڵ��Ƿ񱻷��ʹ���δ���ʣ�ֱ�ӷ��ʼ���
				OutQueue(&Q,&i);  //����
				p = G.vexs [i].firstEdge ;  //�õ�������ĵ�һ���ڵ�
				while(p)
				{
					if(!visited[p->vexs_num])
					{
						visited[p->vexs_num] = 1;
						printf("%d ",G.vexs[p->vexs_num].vex);
						InQueue(&Q,p->vexs_num);
					}
					p = p->next;
				}
			}
		}
	}
}


//�ڽӱ����������߱����㣬�Ͷ�������
//�ڽӱ��BFS�㷨---���ȵ����ʲô��BFS�㷨�����������еĲ��������һ��һ���������
int main()
{

	Graph G;

	create_Graph(&G);

	BFSTreverse(G);


	return 0;
}