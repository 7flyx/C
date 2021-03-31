# define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#define MAXVEX 20
#define INF 32767

typedef struct Graph
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numArc, numVex;
}Graph;

void create_Graph(Graph* G)
{
	int x, y, w;
	printf("请输入顶点数与边数:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (int i = 0; i < G->numVex; i++)
	{
		printf("请输入顶点信息:");
		scanf("%d", &G->vexs[i]);
		for (int j = 0; j < G->numVex; j++)
		{
			if (i != j)
				G->arc[i][j] = INF;
			else
				G->arc[i][j] = 0;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;
	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;
	G->arc[3][4] = 2;
	G->arc[3][6] = 3;
	G->arc[4][5] = 3;

	G->arc[4][6] = 6;
	G->arc[4][7] = 9;
	G->arc[5][7] = 5;
	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

	for (int i = 0; i < G->numArc; i++)
	{
		/*printf("请输入(vi,vj)两顶点之间的权值(出度):");
		scanf("%d%d%d", &x, &y, &w);
		G->arc[x][y] = w;*/
		for (int j = 0; j < G->numVex; j++)
			G->arc[j][i] = G->arc[i][j];
		
	}
}

void shout_path(Graph G, int(*DITE)[MAXVEX], int(*PATH)[MAXVEX])
{
	//两个数组的初始化
	for (int i = 0; i < G.numVex; i++)
	{
		for (int j = 0; j < G.numVex; j++)
		{
			DITE[i][j] = G.arc[i][j]; //类似于DITE【i】【j】
			PATH[i][j] = j;
		}
	}

	//主循环
	for(int k=0;k<G.numVex ;k++)
		for(int v=0;v<G.numVex ;v++)
			for (int w = 0; w < G.numVex; w++)
			{//k为中转点，v为起点，w为终点
				//判断两点之间是否经过中转点，会有更短的路径
				if (DITE[v][k] + DITE[k][w] < DITE[v][w])
				{
					DITE[v][w] = DITE[v][k] + DITE[k][w];
					PATH[v][w] = PATH[v][k];  //路径数组PATH，还可以用字符串的形式进行存储
				}
			}
}

//最短路径--弗洛伊德算法
//用两个数组，一个dite存储所有顶点之间最小权值的总和--dite[v][w]=dite[v][k]+dite[k][w]
//一个path数组，用于存储两个顶点之间的路径--path[v][w]=path[v][k]
int main()
{
	Graph G;
	int k;
	int DITE[MAXVEX][MAXVEX];
	int PATH[MAXVEX][MAXVEX];

	create_Graph(&G);

	shout_path(G, DITE, PATH);

	//路径数组的打印PATH
	for (int v = 0; v < G.numVex; v++) //起点
	{
		for (int w = v + 1; w < G.numVex; w++) //终点
		{
			printf("V%d,V%d,weight %d\n", v, w, DITE[v][w]);
			k = PATH[v][w];  //目标最后一个中转点
			printf("%d", v); //源点/起点
			while (k != w)
			{
				printf(" ->%d", k);  //中转点
				k = PATH[k][w];
			}
			printf(" ->%d\n", w);  //终点
		}
		printf("\n");
	}
	return 0;
}



//int main()
//{
//
//	int sum = 0;
//	int num, ch, m;
//	int flag = 0; //判断上半部分
//	scanf("%d %c", &num, &ch);
//
//	if (num >= 1 && num < 7)
//	{
//		printf("%c\n",ch);
//		printf("%d\n", num - 1);
//	}		
//	else
//	{
//		for (m = 3;; m += 2)
//		{
//			if (2 * m + sum - 1 > num)
//				break;
//			sum += 2 * m;
//		}
//
//		//此时m多了2个---m现在就是行列个数
//		m = m - 2; 
//		for (int i = 0; i < m / 2 + 1; i++)
//		{
//			//上半部分
//			for (int x = 0; x < i; x++)
//				printf(" ");
//			for (int j = 0; j < m - 2 * i; j++)				
//				printf("%c", ch);
//			printf("\n");
//		}
//
//		for (int i = 0; i < m / 2; i++)
//		{
//			for (int j = 0; j < m / 2 - i - 1; j++)
//				printf(" ");
//			for (int j = 0; j < 3 + 2 * i; j++)
//				printf("%c", ch);
//			printf("\n");
//		}
//		printf("%d\n", num - sum - 1);
//	}
//	return 0;
//}