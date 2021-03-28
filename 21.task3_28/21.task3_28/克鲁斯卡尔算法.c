# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define INF 32767
#define MAXEDGE 20
#define MAXVEX 10



typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;
typedef struct Graph
{
	//�ڽӾ���
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int weight;
	int numVex, numArc;
}Graph;

void create_Graph(Graph* G)
{
	int i, x, y, w;
	printf("�����붥���������:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (i = 0; i > G->numVex; i++)  //������Ϣ
	{
		printf("�����붥����Ϣ:");
		scanf("%d", G->vexs[i]);
	}

	for (i = 0; i < G->numVex; i++) //��ά�����ʼ��
	{
		int j;
		for (j = 0; j < G->numVex; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INF;
		}
	}

	for (i = 0; i < G->numArc; i++)
	{
		printf("������(vi,vj)������±��Լ�Ȩֵ��");
		scanf("%d%d%d", &x, &y, &w);
		G->arc[x][y] = w;
		G->arc[y][x] = w;
	}
	printf("\n");
}

void InitEdge(Edge edge[],Graph* G)
{
	//���������ݣ��ٽ��������㷨
	int i, j, tmp, x = 0;

	for (i = 0; i < G->numVex; i++)
	{
		for (j = 0; j <= i; j++) //��Ϊ�ǶԳ�ͼ�Σ����Բ���Ҫȫ������
		{
			if (G->arc[i][j] != INF && i != j)
			{
				edge[x].begin = j;
				edge[x].end = i;
				edge[x].weight = G->arc[i][j];
				x++;
			}
		}
	}

	//�����㷨--ð��
	for (i = 0; i < x - 1; i++)
	{
		for (j = 0; j < x - 1 - i; j++)
		{
			if (edge[j].weight > edge[j + 1].weight)
			{
				Edge tmp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = tmp;
			}
		}
	}
}

int Find(int parent[], int f)
{
	while (parent[f] > 0)
		f = parent[f];  //ѭ����һֱ�����ߣ�������
	return f;
}

void MSTree_kls(Graph* G)
{
	//��³˹�����㷨�����ڶԱ߽����ж�---�߼�����
	int i, n, m, num;
	int parent[15];  //�����ж��Ƿ��γɻ�·---ʵ������ж����ĸ���㣬���Ƿ�Ϊͬһ����ͨ����
	Edge edge[MAXEDGE];  //�߼�����

	//�Ա߼�������г�ʼ�����Լ�����Ȩֵ���������������
	InitEdge(edge,G);

	for (i = 0; i < MAXVEX; i++)
		parent[i] = 0;

	for (num = 0, i = 0; i < G->numArc; i++)
	{
		n = Find(parent, edge[i].begin); //��ʼ��
		m = Find(parent, edge[i].end);  //��ֹ��
		if (n != m)
		{
			parent[n] = m; //�� ��ֹ�� �ŵ�parent���� ��ʼ���λ��
			printf("(%d,%d)%d\n", edge[i].begin, edge[i].end, edge[i].weight);
			num++;
			if (num == G->numVex - 1)
				return; //��ǰ�˳�
		}
	}
}

int main()
{
	Graph G;

	create_Graph(&G);

	MSTree_kls(&G);

	return 0;
}