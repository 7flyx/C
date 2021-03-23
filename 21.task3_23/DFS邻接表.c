#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 10

int visited[MAXVEX];  //全局变量


//邻接表的三大件：边表，顶点表，顶点数组的封装
typedef struct arcList 
{
	int vexs_num;  //该节点在顶点数组的下标
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int data; //顶点的存储区
	arcList* firstNode;  //指向第一个节点
}VEXS;

typedef struct Graph
{
	VEXS vexs[MAXVEX];
	int numVex,numArc;
}Graph;

void create_Graph(Graph* G)
{
	int i,x,y;
	arcList* e = NULL;  //建立临时的边表
	//输入顶点数与边数
	printf("请输入顶点数与边数:");
	scanf("%d%d",&G->numVex,&G->numArc);

	//输入相应的顶点信息
	for(i=0;i<G->numVex;i++)
	{
		printf("请输入顶点信息:");
		scanf("%d",&G->vexs[i]);
		G->vexs[i].firstNode = NULL;
	}

	//输入相应的边的关系，如果有权值，应重新定义结构体，将权值的数据放入顶点数组中，并定义正无穷的参数
	for(i=0;i<G->numArc;i++)
	{
		printf("请输入(vi,vj)两顶点之间的关系（注：此处是数组的下标值）:");
		scanf("%d%d",&x,&y);

		e = (arcList*)malloc(sizeof(arcList));
		if(!e)
			return;
		e->vexs_num = x;
		e->next = G->vexs[y].firstNode;
		G->vexs[y].firstNode = e;

		e = (arcList*)malloc(sizeof(arcList));
		if(!e)
			return;
		e->vexs_num = y;
		e->next = G->vexs[x].firstNode;
		G->vexs[x].firstNode = e;
		//无向图才有两次malloc的创建，而有向图则只有一个，即就是出度或者入度
	}
}

void DFS(Graph G,int i)
{
	arcList* p = NULL;
	visited[i] = 1;  //标志更改
	printf("%d ",G.vexs[i]);

	p = G.vexs[i].firstNode;

	while(p)
	{
		if(!visited[p->vexs_num])
			DFS(G,p->vexs_num);
		p = p->next;
	}
}

void DFSTreverse(Graph G)
{
	int i;
	//进行visited数组的初始化
	for(i=0;i<G.numVex;i++)
		visited[i] = 0; 

	//进行遍历
	for(i=0;i<G.numVex;i++)
		if(!visited[i])
			DFS(G,i);
}


//无向图邻接表的深度遍历
int main()
{
	Graph G;

	create_Graph(&G);

	//无向图的深度遍历---邻接表的存储
	DFSTreverse(G);


	return 0;
}