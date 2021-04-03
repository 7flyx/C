# define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>
#define MAXVEX 20
//ȫ�ֱ���
int* stack2, top2, * etv, * ltv;  //ջ��ջ��ָ�룬�����¼�����ʱ������



typedef struct arcList
{
	int adjvex, weight;
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int data, in; //�����
	arcList* firstEdge;
}VEXS;

typedef struct Graph
{
	VEXS vexs[MAXVEX];
	int numArc, numVex;
}Graph;


void create_Graph(Graph* G)
{
	int x, y, w;
	arcList* e = NULL;
	printf("�����붥���������:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (int i = 0; i < G->numVex; i++)  //�����ĳ�ʼ��
	{
		printf("�����붥����Ϣ:");
		scanf("%d", &G->vexs[i].data);
		G->vexs[i].in = 0;
		G->vexs[i].firstEdge = NULL;
	}

	for (int i = 0; i < G->numArc; i++)
	{
		printf("������(vi,vj)�����±��Լ�Ȩֵ(����):");
		scanf("%d%d%d", &x, &y, &w);

		//�����߱�-������
		e = (arcList*)malloc(sizeof(arcList));
		if (!e)
			return;
		e->weight = w;
		G->vexs[y].in++; //��ȼ�1
		e->next = G->vexs[x].firstEdge;
		e->adjvex = y;
		G->vexs[x].firstEdge = e;
	}
}

int TP_sort(Graph G)
{
	//Ѱ�����Ϊ0�Ľ�㣬����ջ
	int stack[MAXVEX] = { 0 };
	arcList* e = NULL;
	int top = -1;
	int tmp,count = 0;
	top2 = -1;

	for (int i = 0; i < G.numVex; i++)
		if (G.vexs[i].in == 0)
			stack[++top] = G.vexs[i].in;

	stack2 = (int*)malloc(G.numVex * sizeof(int));  //˳��洢�����������Ľ��
	if (!stack2)
		return;
	etv = (int*)malloc(G.numVex * sizeof(int));
	if (!etv)
		return;
	for (int i = 0; i < G.numVex; i++)
		etv[i] = 0;  //�����ʼ��

	for (int i = 0; i < G.numVex; i++)
	{
		while (top != -1)  //�ǿ�ջ
		{
			tmp = stack[top--];
			count++;
			//printf("v%d ", G.vexs[tmp].data);  //���ʲ��������������������
			stack2[++(top2)] = tmp;

			for (e = G.vexs[tmp].firstEdge; e; e = e->next)
			{
				if (!(--G.vexs[e->adjvex].in))
					stack[++top] = e->adjvex;
				if (etv[tmp] + e->weight > etv[e->adjvex])  //���+Ȩֵ > �յ�
					etv[e->adjvex] = etv[tmp] + e->weight;
			}
		}
	}
	if (count < G.numVex)
		return 0;
	return 1;
}

void crux_path(Graph G)
{
	int tmp, ete, lte;
	arcList* e = NULL;
	//����stack2ջ�����ݣ����Ƴ�ltv�����ֵ
	ltv = (int*)malloc(G.numVex * sizeof(int));
	if (!ltv)
		return;
	for (int i = 0; i < G.numVex; i++)
		ltv[i] = etv[G.numVex - 1];  //��ltv��������ݣ�ȫ����ʼ��Ϊetv�����������ֵ

	//����ltv�����ֵ
	while ((top2) != -1)
	{
		tmp = stack2[(top2)--];
		for (e = G.vexs[tmp].firstEdge; e; e = e->next)
		{
			if (ltv[e->adjvex] - e->weight < ltv[tmp])
				ltv[tmp] = ltv[e->adjvex] - e->weight;
		}
	}

	//����etv��ltv�������ete��lte�������������ʱ���ýڵ���ǹؼ�·�����
	for (int i = 0; i < G.numVex; i++)
	{
		for (e = G.vexs[i].firstEdge; e; e = e->next)
		{
			ete = etv[i];
			//lte = ltv[]
			lte = ltv[e->adjvex] - e->weight;
			if (ete == lte)
				printf("<v%d,v%d> length:%d ,", G.vexs[i].data, G.vexs[e->adjvex].data, e->weight);
		}
	}

}

//�ؼ�·��---���硢������ʼʱ�䣬���硢�����¼���ʼʱ��
//	etv-ltv(earliest/latest time of vextex)	  ete-lte(earliest/latest time of edge)
//�õ��ڽӱ����ݣ��Ƚ������������ٽ������ĸ�����ļ������Ƶ������ete��lte��������ͬʱ��
//�㣬�����ǹؼ�·��
int main()
{
	Graph G;
	create_Graph(&G);
	if (TP_sort(G))
		crux_path(G);
	else
		printf("��AOE��\n");
	return 0;
}