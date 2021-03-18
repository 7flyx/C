# define _CRT_SECURE_NO_WARNINGS 



#include <stdio.h>
#define MAXVEX 10   //最大顶点数
#define INTMAX 32767   //表示无穷大

//无向图邻接矩阵的创建：用二维数组表示两个顶点之间的关系，如果有权值的话，直接输入权值
//没有权值的，用1代表两个顶点之间有连接关系

typedef char dataType;
typedef struct
{
	dataType vexs[MAXVEX];  //顶点数组
	int arc[MAXVEX][MAXVEX];  //看做边，也有权值
	int vertexNum, arcNum;  //顶点数和边的个数  
}Graph;

//创建邻接矩阵
void createGraph(Graph* G)
{
	printf("请输入顶点数和边数:");
	scanf("%d%d", &G->vertexNum, &G->arcNum);

	//输入每个顶点的信息
	for (int i = 0; i < G->vertexNum; i++)
	{
		getchar();
		printf("请输入顶点的信息:");
		scanf(" %c", &G->vexs[i]);
	}
		

	//初始化二维数组里面的信息，如果是网图，则应定义“无穷大”
	for (int i = 0; i < G->vertexNum; i++)
		for (int j = 0; j < G->vertexNum; j++)
			G->arc[i][j] = INTMAX;

	//输入矩阵中，边的权值
	int i, j, tmp;
	for (int k = 0; k < G->arcNum; k++)
	{		
		printf("请输入(i，j)这行列之间的权值:");
		scanf("%d%d%d", &i, &j, &tmp);

		//放入对应行列之间的权值
		G->arc[i][j] = tmp;
		G->arc[j][i] = tmp;  //从矩阵左上到右下，两边是对应的，对于无向图来说，有向图可能不是对称的
	}

}

int main()
{
	Graph G;
	createGraph(&G);
	return 0;
}