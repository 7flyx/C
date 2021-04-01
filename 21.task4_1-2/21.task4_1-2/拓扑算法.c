# define _CRT_SECURE_NO_WARNINGS 


#include <stdio.h>
#define MAXVEX 20

typedef struct arcList
{
	int adjvex;  //节点下标
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int vex, in;  //顶点信息与入度
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
	//邻接表的建立
	printf("请输入顶点数与边数:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (int i = 0; i < G->numVex; i++)
	{
		printf("请输入顶点信息:");
		scanf("%d", &G->vexs[i].vex);
		G->vexs[i].firstEdge = NULL;
		G->vexs[i].in = 0;
	}

	for (int i = 0; i < G->numArc; i++)
	{ //有向图的邻接表
		printf("请输入(vi,vj)两顶点的下标:");
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
	//拓扑排序算法
	//找到入度为0的点，开始做打印以及删除信息工作
	int top = 0;
	int count = 0;
	int stack[MAXVEX] = { 0 };
	arcList* e = NULL;
	for (int i = 0; i < G.numVex; i++)
	{
		if (G.vexs[i].in == 0)
			stack[++top] = i; //入栈
	}

	while (top != 0)  //非空栈
	{
		int tmp = stack[top--];  //获得出栈下标
		printf("v%d ", G.vexs[tmp].vex);
		count++;
		//并删除以该结点为弧尾的弧
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

//拓扑算法---AOV网--邻接表完成
int main()
{
	Graph G;

	create_Graph(&G);

	if (TP_sort(G))
		printf("是AOV\n");
	else
		printf("不是AOV\n");
		return 0;
}