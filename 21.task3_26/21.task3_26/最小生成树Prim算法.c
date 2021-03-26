# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#define MAXVEX 10
#define INF 32767

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVex, numArc;
}Graph;

void MSTree(Graph G)
{
	//������������Ҫ�ı����Լ���������
	int min, j, k, i;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];

	//��ʼ������һ����㣬�������±�Ϊ0������
	lowcost[0] = 0;  //���ɱ������飬Ϊ0 �������Ǵ����������Ѿ����ʹ���
	adjvex[0] = 0;

	//Ϊlowcost������г�ʼ�������±�Ϊ1�ĵط���ʼ
	for (j = 1; j < G.numVex; j++)
	{
		lowcost[j] = G.arc[0][j];  //�õ���0��ȫ����Ȩֵ,���˵�0��
		adjvex[j] = 0;  //ȫ����ʼ��Ϊ0
	}

	//����������ȥ�жϳ��˵�0���⣬�����е�Ȩֵ�����ҽ����жϣ�������ϵ�ǰlowcost��������С�ģ����滻
	for (i = 1; j < G.numVex; j++)
	{
		min = INF;  //�������ʼ�����ж�
		k = 0;
		for (j = 1; j < G.numVex; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)  //lowcost��ֵ��Ϊ0����С��min
			{
				min = G.arc[k][j];  //�õ���СȨֵ
				k = j; //�õ���СȨֵ��Ӧ������±�
			}
		}

		printf("(%d,%d)\n", adjvex[k], k);
		lowcost[k] = 0;  //�����Ѿ����ʹ���

		for (j = 1; j < G.numVex; j++)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}

//������С������������ĸ�����ڽӾ����ת����һ�еĸ�Դ���ô��ڽӾ�����ڽӱ�ʼ
//Prim�㷨��������������adjVex��lowcost��adjVex���ڴ洢������Ϣ����lowcost���ڴ洢Ȩֵ�ģ����磺��һ�� �����е�Ȩֵ��
//������������
int main()
{

	return 0;
}