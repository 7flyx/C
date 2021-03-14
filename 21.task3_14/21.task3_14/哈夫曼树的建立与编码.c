# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define n 5   //�ֶ������ж��ٸ����ݶ���Ҳ�����ַ�
#define MAX 10   //����ÿ���ַ����������ֵ
typedef struct
{
	int weight;
	int parents, lchild, rchild;
}HFFmanTree;

typedef struct code
{
	int code[n];
	int start;  //��ʾ�±�
}HFmancode;

void selet(HFFmanTree hfmantree[], int* m1, int* m2, int* x1, int* x2)
{
	int i = 0;
	*m1 = 32767;
	*m2 = 32767;
	*x1 = -1;
	*x2 = -1;
	while (i < 2 * n - 1 && hfmantree[i].weight != -1)
	{
		//Ѱ����С��������ֵ
		if (hfmantree[i].weight < *m1 && hfmantree[i].parents == -1)
		{
			//m1ֵ�ı仯
			*m2 = *m1;
			*m1 = hfmantree[i].weight;
			*x2 = *x1;
			*x1 = i;
		}
		else if (hfmantree[i].weight < *m2 && hfmantree[i].parents == -1)
		{
			*m2 = hfmantree[i].weight;  //�õ���С��Ȩֵ
			*x2 = i;
		}
		i++;
	}
}

void create_Tree(HFFmanTree hfmantree[])
{
	//��������������ݽ��г�ʼ��
	int i, j, m1, m2, x1, x2;
	for (i = 0; i < 2 * n - 1; i++)
	{
		hfmantree[i].parents = -1;
		hfmantree[i].lchild = -1;
		hfmantree[i].rchild = -1;
		hfmantree[i].weight = -1;
	}

	
	for (i = 0; i < n; i++) 
	{
		printf("����������ַ���Ȩֵ:");
		scanf("%d", &hfmantree[i].weight);
	}
		

	for (i = n; i < 2 * n - 1; i++)
	{
		selet(hfmantree, &m1, &m2, &x1, &x2);//�õ���ǰ��ֵ����Сֵ���Լ���Сֵ�Ķ�Ӧ�±�
		hfmantree[i].weight = hfmantree[x1].weight + hfmantree[x2].weight; //�õ��µ�Ȩֵ
		hfmantree[i].lchild = x1;
		hfmantree[i].rchild = x2;
		hfmantree[x1].parents = i;
		hfmantree[x2].parents = i;
	}
	

	//�÷��ص��±���н�������

}


//���������Ľ�������룬��һ���µ�������д洢����
int main()
{
	int i, j, c, p;
	//���� 2*n-1��HFFManTree��С������
	HFFmanTree hfmantree[2 * n - 1] = { 0 };
	//�����洢���������
	HFmancode pass[n], cd;

	create_Tree(hfmantree);

	//���������ı���
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1; //�ַ��ı��볤�����ֻ��n-1λ����
		c = i; //��ʾָ��ԭ�ȵ��ַ�
		p = hfmantree[c].parents;  //ָ��c��˫��
		while (p != -1)
		{
			if (hfmantree[p].lchild == c)
				cd.code[cd.start] = 0; //��������ֵ0
			else
				cd.code[cd.start] = 1;
			cd.start--;
			c = p;
			p = hfmantree[p].parents;
		}

		//����ʱ����cd�����ݷ���pass������
		pass[i] = cd;
	}

	//�������
	for (i = 0; i < n; i++)
	{
		printf("��%d���ַ��ı���Ϊ:",i+1);
		for (j = pass[i].start + 1; j < n; j++)
		{
			printf("%d", pass[i].code[j]);
		}
		printf("\n");
	}
	return 0;
}