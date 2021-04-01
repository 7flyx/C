# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#define MAXVEX 20

typedef struct arcList
{
	int adjvex;  //�ڵ��±�
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int vex, in;  //������Ϣ�����
	struct arcList* firstEdge;
}VEXS;

typedef struct Graph
{
	VEXS vexs[MAXVEX];
	int numArc, numVex;
}Graph;

void create_Graph(Graph* G)
{
	int x, y;
	arcList* e = NULL;
	//�ڽӱ�Ľ���
	printf("�����붥���������:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (int i = 0; i < G->numVex; i++)
	{
		printf("�����붥����Ϣ:");
		scanf("%d", &G->vexs[i].vex);
		G->vexs[i].firstEdge = NULL;
		G->vexs[i].in = 0;
	}

	for (int i = 0; i < G->numArc; i++)
	{ //����ͼ���ڽӱ�
		printf("������(vi,vj)��������±�:");
		scanf("%d%d", &x, &y);

		e = (arcList*)malloc(sizeof(arcList));
		if (!e)
			return;
		e->adjvex = y;
		e->next = G->vexs[x].firstEdge;
		G->vexs[x].firstEdge = e;
		G->vexs[y].in++;
	}
}

int TP_sort(Graph G)
{
	//���������㷨
	//�ҵ����Ϊ0�ĵ㣬��ʼ����ӡ�Լ�ɾ����Ϣ����
	int top = 0;
	int count = 0;
	int stack[MAXVEX] = { 0 };
	arcList* e = NULL;
	for (int i = 0; i < G.numVex; i++)
	{
		if (G.vexs[i].in == 0)
			stack[++top] = i; //��ջ
	}

	while (top != 0)  //�ǿ�ջ
	{
		int tmp = stack[top--];  //��ó�ջ�±�
		printf("v%d ", G.vexs[tmp].vex);
		count++;
		//��ɾ���Ըý��Ϊ��β�Ļ�
		for (e = G.vexs[tmp].firstEdge; e; e = e->next)
		{		
			if (!(--G.vexs[e->adjvex].in))
				stack[++top] = e->adjvex;
		}
	}
	if (count < G.numVex)
		return 0;
	else
		return 1;
}

//�����㷨---AOV��--�ڽӱ����
int main()
{
	Graph G;

	create_Graph(&G);

	if (TP_sort(G))
		printf("��AOV\n");
	else
		printf("����AOV\n");
		return 0;
}