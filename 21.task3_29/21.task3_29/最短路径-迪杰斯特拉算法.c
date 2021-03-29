# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define MAXVEX 20
#define INF 32767


//#include <stdio.h>
//int main()
//{
//	int i, temp = 0, j = 0;
//	int a[10] = { 2,5,8,9,6,4,3,1,7,8 };
//	for (i = 0; i < 9; i++)
//	{
//		for (j = 0; j < 9 - i; j++) {
//			if (a[j] > a[j + 1]) {
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//
//		}	
//	}
//	for(i=0;i<10;i++)
//		printf("%d", a[i]);
//
//	return 0;
//}

typedef struct Graph
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numArc, numVex;
}Graph;

void create_Graph(Graph* G)
{
	int i, j, x, y, w;
	printf("�����붥���������:");
	scanf("%d%d", &G->numVex, &G->numArc);

	for (i = 0; i < G->numVex; i++)
	{
		printf("�����붥����Ϣ:");
		scanf("%d", &G->vexs[i]);
		for (j = 0; j < G->numVex; j++)  //һ���ʼ����ά����
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INF;
		}
	}

	//����ͼ���ڽӾ���
	for (i = 0; i < G->numArc; i++)
	{
		printf("������(vi,vj)������±��Լ�Ȩֵ�����ȣ�:");
		scanf("%d%d%d", &x, &y, &w);
		G->arc[x][y] = w;
		//G->arc[y][x] = w;
	}
}

void Print_path(int path[], int k, int num)
{
	//�������е����ݣ�����һ���µ����飬�ٴӺ��濪ʼ����
	int tmp[MAXVEX], n = 0, m = k;

	while (num--)
	{
		tmp[n++] = path[k];
		k = path[k];		
	}
	for (int i = n - 2; i >= 0; i--)  //ѭ����num�Σ���n��num����������һ�Σ��ټ���n�������Ӻ��һ��
		//����Ϊ2��
		printf("%d ", tmp[i]);
	printf("%d ", m);  //k������������һ���յ�--�򲢴���path����
}

void minPath(Graph G, int num)

{
	//s���顢dite���顢path����
	int s[MAXVEX] = { 0 };  //�洢��Щ��㱻���ʹ�
	int dite[MAXVEX], path[MAXVEX]; //dite�洢��ǰ�е�����Ȩֵ��path�洢������һ�����±�
	int i, sum, k, min;

	s[num] = 1; //1�����Ѿ����ʹ���0���෴

	for (i = 0; i < G.numVex; i++)
	{
		//��k�е�Ȩֵ��ʼ��
		dite[i] = G.arc[num][i];
		if (dite[i] == INF)
			path[i] = -1;  //����������
		else
			path[i] = num;
	}
	sum = 1;
	k = num;
	while (sum < G.numVex)  //�Զ�������Ϊ�ж�����
	{
		min = INF;
		for (i = 0; i < G.numVex; i++)
		{
			//�õ���ǰ�е���СȨֵ
			if (!s[i] && G.arc[num][i] < min)
			{
				min = G.arc[num][i];  //�洢��СȨֵ
				k = i;  //�洢��СȨֵ�յ���±�
			}
		}
		s[k] = 1;
		num = k;  //����num��ֵ��Ϊ����һ��ѭ����׼��

		//�ж������Сֵ��dite����Ȩֵ�Ĵ�С��ϵ
		for (i = 0; i < G.numVex; i++)
		{
			if (!s[i] && (dite[k] + G.arc[k][i] < dite[i]))
			{
				dite[i] = dite[k] + G.arc[k][i];  //����ʱ��СȨֵ����ֵ��dite����
				path[i] = k;
			}
		}
		sum++;
	}
	//�����ӡ��path���飬�����Ǵ�ӡ��Դ�㵽�յ��·��
	Print_path(path, k, sum -1); //kΪѭ�����һ��ʱ,k�������һ���յ�
}

//���·��-�Ͻ�˹�����㷨---����С��������prim�㷨��������
//s��dite��path�������飬s�����ʾ�Ѿ����ʹ��Ľ��
//dite�����ʾ��ǰ��һ�е�����Ȩֵ--path���飬��ʾÿ������У���һ������λ�ã��±꣩
int main()
{
	Graph G;
	int k = 0;  //Դ��
	create_Graph(&G);

	//�������·��
	minPath(G, k);
	return 0;
}