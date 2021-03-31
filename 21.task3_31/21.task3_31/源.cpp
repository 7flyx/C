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
	printf("�����붥���������:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (int i = 0; i < G->numVex; i++)
	{
		printf("�����붥����Ϣ:");
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
		/*printf("������(vi,vj)������֮���Ȩֵ(����):");
		scanf("%d%d%d", &x, &y, &w);
		G->arc[x][y] = w;*/
		for (int j = 0; j < G->numVex; j++)
			G->arc[j][i] = G->arc[i][j];
		
	}
}

void shout_path(Graph G, int(*DITE)[MAXVEX], int(*PATH)[MAXVEX])
{
	//��������ĳ�ʼ��
	for (int i = 0; i < G.numVex; i++)
	{
		for (int j = 0; j < G.numVex; j++)
		{
			DITE[i][j] = G.arc[i][j]; //������DITE��i����j��
			PATH[i][j] = j;
		}
	}

	//��ѭ��
	for(int k=0;k<G.numVex ;k++)
		for(int v=0;v<G.numVex ;v++)
			for (int w = 0; w < G.numVex; w++)
			{//kΪ��ת�㣬vΪ��㣬wΪ�յ�
				//�ж�����֮���Ƿ񾭹���ת�㣬���и��̵�·��
				if (DITE[v][k] + DITE[k][w] < DITE[v][w])
				{
					DITE[v][w] = DITE[v][k] + DITE[k][w];
					PATH[v][w] = PATH[v][k];  //·������PATH�����������ַ�������ʽ���д洢
				}
			}
}

//���·��--���������㷨
//���������飬һ��dite�洢���ж���֮����СȨֵ���ܺ�--dite[v][w]=dite[v][k]+dite[k][w]
//һ��path���飬���ڴ洢��������֮���·��--path[v][w]=path[v][k]
int main()
{
	Graph G;
	int k;
	int DITE[MAXVEX][MAXVEX];
	int PATH[MAXVEX][MAXVEX];

	create_Graph(&G);

	shout_path(G, DITE, PATH);

	//·������Ĵ�ӡPATH
	for (int v = 0; v < G.numVex; v++) //���
	{
		for (int w = v + 1; w < G.numVex; w++) //�յ�
		{
			printf("V%d,V%d,weight %d\n", v, w, DITE[v][w]);
			k = PATH[v][w];  //Ŀ�����һ����ת��
			printf("%d", v); //Դ��/���
			while (k != w)
			{
				printf(" ->%d", k);  //��ת��
				k = PATH[k][w];
			}
			printf(" ->%d\n", w);  //�յ�
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
//	int flag = 0; //�ж��ϰ벿��
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
//		//��ʱm����2��---m���ھ������и���
//		m = m - 2; 
//		for (int i = 0; i < m / 2 + 1; i++)
//		{
//			//�ϰ벿��
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