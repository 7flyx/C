#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 10  //最大顶点数


int visited[MAXVEX];


typedef struct arcList
{
	int vexs_num;  //节点信息在顶点数组的下标
	struct arcList* next;
}arcList;

typedef struct VEXS
{
	int vex;
	arcList* firstEdge;  //指向第一个边表的指针
}VEXS;

typedef struct Graph
{
	VEXS vexs[MAXVEX];
	int numVex,numArc;
}Graph;

typedef struct Queue
{
	int num[20];  //保存visited数组的数据
	int top;
}Queue;


void create_Graph(Graph* G)
{
	int i,x,y;
	arcList* e = NULL;
	//首先输入顶点数与边数
	printf("请输入顶点数与边数:");
	scanf("%d%d",&G->numVex,&G->numArc);

	//输入顶点信息与firstEdge指针的初始化
	for( i=0;i<G->numVex;i++)
	{
		printf("请输入顶点信息:");
		scanf("%d",&G->vexs[i].vex);
		G->vexs[i].firstEdge = NULL;
	}

	//输入边的信息，建立单链表
	for(i=0;i<G->numArc ;i++)
	{
		printf("请输入(vi,vj)两顶点之间的下标：");
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

		//同样的，无向图，需要两次malloc来表示关系，而有向图只需要一次，即就是入度或者出度
	}
}

void InQueue(Queue* Q, int i)
{
	if(Q->top == 10)
	{
		printf("队列已满!\n");
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
	//建立队列，临时变量
	int i;
	arcList* p;
	Queue Q;
	Q.top = -1;  //初始化

	for(i=0;i<G.numVex;i++)
		visited[i] = 0;
	for(i=0;i<G.numVex ;i++)  //判断全部的顶点
	{
		
		if(!visited[i])
		{
				// 首先访问第一个数据
			visited[i] = 1;
			printf("%d ",G.vexs [0].vex);
			InQueue(&Q,i);  //入队

			while(!is_Empty(&Q))  //非空队列
			{
				//首先出队，然后判断该节点是否被访问过，未访问，直接访问即可
				OutQueue(&Q,&i);  //出队
				p = G.vexs [i].firstEdge ;  //得到单链表的第一个节点
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


//邻接表的三大件：边表，顶点，和顶点数组
//邻接表的BFS算法---首先得理解什么是BFS算法，类似于树中的层序遍历，一层一层的往下走
int main()
{

	Graph G;

	create_Graph(&G);

	BFSTreverse(G);


	return 0;
}