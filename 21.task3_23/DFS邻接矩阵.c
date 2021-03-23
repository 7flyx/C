#include <stdio.h>

#define MAXVEX 10  //最大顶点数


//全局变量
int visited[MAXVEX];  //用于标记该顶点是否被访问过


typedef struct 
{
	int vexs[MAXVEX]; //顶点数组
	int arc[MAXVEX][MAXVEX]; //二维数组，表示边的关系
	int numVex,numArc;  //顶点数与边数
}Graph;

void create_Graph(Graph* G)
{
	int i,j;
	//首先输入顶点数与边数
	printf("请输入顶点数与边数:");
	scanf("%d%d",&G->numVex,&G->numArc);

	//输入顶点数组的信息
	for(i=0;i< G->numVex;i++)
	{
		printf("请输入顶点信息:");
		scanf("%d",&G->vexs[i]);
	}
		

	//初始化二维数组的信息
	for(i=0;i< G->numArc;i++)
	{
		for(j=0;j< G->numArc;j++)
			G->arc[i][j] = 0;
	}

	//输入顶点之间边的关系
	for(i=0;i<G->numArc;i++)
	{
		int x,y;
		printf("请输入(vi,vj)两点说明两者之间有关系(注：vi vj是对应的下标):");
		scanf("%d%d",&x,&y);

		G->arc[x][y] = 1;
		G->arc[y][x] = 1;  //邻接矩阵具有对称性
	}
}

void DFS(Graph G,int i)
{
	int j;
	visited[i] = 1;
	printf("%d ",G.vexs[i]);

	for(j=0;j<G.numVex ;j++)
		if(G.arc [i][j] == 1 && !visited[j])  //此时形参i作为一行，在这一行进行j值的判断，相当于在这个函数中，行不变，进行j值的变换
			DFS(G,j);
}

void DFSTreverse(Graph G)
{
	int i;
	for(i=0;i<G.numVex ;i++)
		visited[i] = 0;  //初始化数组，表示没有被访问过

	for(i=0;i<G.numVex ;i++)
		if(!visited[i])
			DFS(G,i);  //没有被访问过，直接调用DFS函数进行遍历操作
}



//邻接矩阵的DFS深度优先遍历
int main()
{
	Graph G;
	create_Graph(&G);

	//进行深度优先遍历，打印出顶点的信息
	//进行DFS遍历，需要两个函数
	DFSTreverse(G);


	return 0;
}