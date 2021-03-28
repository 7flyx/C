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
	//邻接矩阵
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int weight;
	int numVex, numArc;
}Graph;

void create_Graph(Graph* G)
{
	int i, x, y, w;
	printf("请输入顶点数与边数:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (i = 0; i > G->numVex; i++)  //顶点信息
	{
		printf("请输入顶点信息:");
		scanf("%d", G->vexs[i]);
	}

	for (i = 0; i < G->numVex; i++) //二维数组初始化
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
		printf("请输入(vi,vj)顶点的下标以及权值：");
		scanf("%d%d%d", &x, &y, &w);
		G->arc[x][y] = w;
		G->arc[y][x] = w;
	}
	printf("\n");
}

void InitEdge(Edge edge[],Graph* G)
{
	//先输入数据，再进行排序算法
	int i, j, tmp, x = 0;

	for (i = 0; i < G->numVex; i++)
	{
		for (j = 0; j <= i; j++) //因为是对称图形，所以不需要全部遍历
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

	//排序算法--冒泡
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
		f = parent[f];  //循环，一直往下走，连续的
	return f;
}

void MSTree_kls(Graph* G)
{
	//克鲁斯卡尔算法，在于对边进行判断---边集数组
	int i, n, m, num;
	int parent[15];  //用于判断是否形成回路---实则就是判断树的根结点，看是否为同一个连通分量
	Edge edge[MAXEDGE];  //边集数组

	//对边集数组进行初始化，以及按照权值，进行升序的排列
	InitEdge(edge,G);

	for (i = 0; i < MAXVEX; i++)
		parent[i] = 0;

	for (num = 0, i = 0; i < G->numArc; i++)
	{
		n = Find(parent, edge[i].begin); //起始点
		m = Find(parent, edge[i].end);  //终止点
		if (n != m)
		{
			parent[n] = m; //将 终止点 放到parent数组 起始点的位置
			printf("(%d,%d)%d\n", edge[i].begin, edge[i].end, edge[i].weight);
			num++;
			if (num == G->numVex - 1)
				return; //提前退出
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