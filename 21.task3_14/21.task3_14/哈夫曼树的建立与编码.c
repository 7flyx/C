# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define n 5   //手动定义有多少个数据对象，也就是字符
#define MAX 10   //定义每个字符的最长编码数值
typedef struct
{
	int weight;
	int parents, lchild, rchild;
}HFFmanTree;

typedef struct code
{
	int code[n];
	int start;  //表示下标
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
		//寻找最小的两个数值
		if (hfmantree[i].weight < *m1 && hfmantree[i].parents == -1)
		{
			//m1值的变化
			*m2 = *m1;
			*m1 = hfmantree[i].weight;
			*x2 = *x1;
			*x1 = i;
		}
		else if (hfmantree[i].weight < *m2 && hfmantree[i].parents == -1)
		{
			*m2 = hfmantree[i].weight;  //得到最小的权值
			*x2 = i;
		}
		i++;
	}
}

void create_Tree(HFFmanTree hfmantree[])
{
	//将数组里面的数据进行初始化
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
		printf("请输入各个字符的权值:");
		scanf("%d", &hfmantree[i].weight);
	}
		

	for (i = n; i < 2 * n - 1; i++)
	{
		selet(hfmantree, &m1, &m2, &x1, &x2);//得到当前数值的最小值，以及最小值的对应下标
		hfmantree[i].weight = hfmantree[x1].weight + hfmantree[x2].weight; //得到新的权值
		hfmantree[i].lchild = x1;
		hfmantree[i].rchild = x2;
		hfmantree[x1].parents = i;
		hfmantree[x2].parents = i;
	}
	

	//用返回的下标进行结点的生成

}


//哈夫曼树的建立与编码，用一个新的数组进行存储数据
int main()
{
	int i, j, c, p;
	//创建 2*n-1个HFFManTree大小的数组
	HFFmanTree hfmantree[2 * n - 1] = { 0 };
	//声明存储编码的数组
	HFmancode pass[n], cd;

	create_Tree(hfmantree);

	//哈夫曼树的编码
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1; //字符的编码长度最多只有n-1位数字
		c = i; //表示指向原先的字符
		p = hfmantree[c].parents;  //指向c的双亲
		while (p != -1)
		{
			if (hfmantree[p].lchild == c)
				cd.code[cd.start] = 0; //左子树赋值0
			else
				cd.code[cd.start] = 1;
			cd.start--;
			c = p;
			p = hfmantree[p].parents;
		}

		//将临时数组cd的数据放入pass数组中
		pass[i] = cd;
	}

	//输出编码
	for (i = 0; i < n; i++)
	{
		printf("第%d个字符的编码为:",i+1);
		for (j = pass[i].start + 1; j < n; j++)
		{
			printf("%d", pass[i].code[j]);
		}
		printf("\n");
	}
	return 0;
}