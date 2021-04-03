# define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>
#define MAXVEX 20
//全局变量
int* stack2, top2, * etv, * ltv;  //栈，栈顶指针，两个事件发生时间数组



typedef struct arcList
{
	int adjvex, weight;
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int data, in; //入度数
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
	printf("请输入顶点数与边数:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (int i = 0; i < G->numVex; i++)  //顶点表的初始化
	{
		printf("请输入顶点信息:");
		scanf("%d", &G->vexs[i].data);
		G->vexs[i].in = 0;
		G->vexs[i].firstEdge = NULL;
	}

	for (int i = 0; i < G->numArc; i++)
	{
		printf("请输入(vi,vj)顶点下标以及权值(出度):");
		scanf("%d%d%d", &x, &y, &w);

		//建立边表-单链表
		e = (arcList*)malloc(sizeof(arcList));
		if (!e)
			return;
		e->weight = w;
		G->vexs[y].in++; //入度加1
		e->next = G->vexs[x].firstEdge;
		e->adjvex = y;
		G->vexs[x].firstEdge = e;
	}
}

int TP_sort(Graph G)
{
	//寻找入度为0的结点，并入栈
	int stack[MAXVEX] = { 0 };
	arcList* e = NULL;
	int top = -1;
	int tmp,count = 0;
	top2 = -1;

	for (int i = 0; i < G.numVex; i++)
		if (G.vexs[i].in == 0)
			stack[++top] = G.vexs[i].in;

	stack2 = (int*)malloc(G.numVex * sizeof(int));  //顺序存储，拓扑排序后的结果
	if (!stack2)
		return;
	etv = (int*)malloc(G.numVex * sizeof(int));
	if (!etv)
		return;
	for (int i = 0; i < G.numVex; i++)
		etv[i] = 0;  //数组初始化

	for (int i = 0; i < G.numVex; i++)
	{
		while (top != -1)  //非空栈
		{
			tmp = stack[top--];
			count++;
			//printf("v%d ", G.vexs[tmp].data);  //访问操作，亦可以是其他操作
			stack2[++(top2)] = tmp;

			for (e = G.vexs[tmp].firstEdge; e; e = e->next)
			{
				if (!(--G.vexs[e->adjvex].in))
					stack[++top] = e->adjvex;
				if (etv[tmp] + e->weight > etv[e->adjvex])  //起点+权值 > 终点
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
	//根据stack2栈的数据，倒推出ltv数组的值
	ltv = (int*)malloc(G.numVex * sizeof(int));
	if (!ltv)
		return;
	for (int i = 0; i < G.numVex; i++)
		ltv[i] = etv[G.numVex - 1];  //将ltv数组的数据，全部初始化为etv数组的最终数值

	//计算ltv数组的值
	while ((top2) != -1)
	{
		tmp = stack2[(top2)--];
		for (e = G.vexs[tmp].firstEdge; e; e = e->next)
		{
			if (ltv[e->adjvex] - e->weight < ltv[tmp])
				ltv[tmp] = ltv[e->adjvex] - e->weight;
		}
	}

	//根据etv和ltv。计算出ete和lte，当这两者相等时，该节点就是关键路径结点
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

//关键路径---最早、最晚活动开始时间，最早、最晚事件开始时间
//	etv-ltv(earliest/latest time of vextex)	  ete-lte(earliest/latest time of edge)
//拿到邻接表数据，先进行拓扑排序，再进行这四个数组的计算与推导，最后ete与lte的数据相同时的
//点，即就是关键路径
int main()
{
	Graph G;
	create_Graph(&G);
	if (TP_sort(G))
		crux_path(G);
	else
		printf("非AOE网\n");
	return 0;
}