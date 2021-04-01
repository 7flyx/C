#include <stdio.h>

#define MAXVEX 20
#define INF 32767

typedef struct Graph
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numArc,numVex;
}Graph;


void create_Graph(Graph* G)
{
	int i,j;
	printf("请输入顶点数与边数:");
	scanf("%d%d",&G->numVex,&G->numArc);

	for(i=0;i<G->numVex;i++)
	{
		printf("请输入顶点信息:");
		scanf("%d",&G->vexs[i]);
		for(j=0;j<G->numVex;j++)
		{
			if(i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INF;
		}
	}

		G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 

	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;

	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;

	G->arc[7][8]=4;
	for(i = 0;i<G->numVex;i++)
	{
		//printf("请输入(vi,vj)两顶点之间的权值w:");
	//	scanf("%d%d%d",&x,&y,&w);
	
	//	G->arc[x][y] = w;  //出度
		for(j=0;j<G->numVex;j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void short_path(Graph G, int Dest[][MAXVEX], int Path[][MAXVEX])
{
	//两个数组的初始化
	int i,j,k;
	for(i=0;i<G.numVex;i++)
	{
		for(j=0;j<G.numVex;j++)
		{
			Dest[i][j] = G.arc[i][j];
			Path[i][j] = j;
		}
	}

	//三层主循环
	for(k =0;k<G.numVex;k++)  //中转点
		for(i=0;i<G.numVex;i++) //源点
			for(j=0;j<G.numVex;j++) //终点
			{
				if(Dest[i][k] + Dest[k][j] < Dest[i][j])
				{
					Dest[i][j] = Dest[i][k] + Dest[k][j];
					Path[i][j] = Path[i][k];
				}
			}
}

int main()
{
	Graph G;
	int v,w,k;
	int Dest[MAXVEX][MAXVEX];
	int Path[MAXVEX][MAXVEX];
	create_Graph(&G);

	short_path(G,Dest,Path);


	//打印Path数组中的路径节点
	for(v=0;v<G.numVex;v++)
	{
		for(w=v+1;w<G.numVex;w++)
		{
		
			printf("v%d,v%d  weight:%d\n",v,w,Dest[v][w]); 
			k = Path[v][w];
			printf("%d",v); //打印源点
			while(k != w)
			{
				printf(" -> %d",k); //中转点
				k = Path[k][w];
			}
			printf(" ->%d\n",w);  //打印终点

		}
		printf("\n");
	}
	return 0;
}