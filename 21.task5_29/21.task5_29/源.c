#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <String.h>

int IsRotateString(char arr1[], char arr2[])
{
	//�Ͻ�һ�㻰�����ж��Ƿ�ΪNULL��C���ԾͲ�����
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0; //��һ������ֱ�ӷ���0
	int rotateNum = 0;
	for (rotateNum = 0; rotateNum < len1; rotateNum++) //��0��ʼ����һû��ת��
	{
		//�õ�arr2������ѭ����rotateNum�������ַ����бȽ�
		int i = 0; //arr2���±�
		int j = 0; //arr1���±�
		for (i = rotateNum; j < len1; i = (++i + len1) % len1)
		{
			if (arr1[j] == arr2[i])
				j++;
			else
				break;
		}
		if (j == len1)
			return 1; //˵��ƥ������
	}
	return 0; //����ѭ�����ˣ���ô��ǰ�˳�����������û��

}
int main()
{
	//ѭ�����У�ÿ����ǰ ǰ��һ����ѭ�������жϼ��ɣ��ַ����೤����ѭ�����Σ�ʱ�临�Ӷ�O(N^2)
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	printf("����������:");
	gets(arr1);
	printf("��������ת�Ӵ�:");
	gets(arr2);
	
	if (IsRotateString(arr1,arr2))
		printf("�Ǹ��ַ�������ת�Ӵ�\n");
	else
		printf("���Ǹ��ַ�������ת�Ӵ�\n");
	return 0;
}



//void reverse(char arr[], int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	//�����ַ���
//	//�ⷨһ�� ���ı�ԭ���ַ����Ĵ洢˳����ѭ�����У���ת���Σ��ʹӵڼ����ַ���ʼ˳����ʣ�ѭ������һ�μ���
//	//�ⷨ���� ��Ҫ�ı�ԭ���ַ�����ʵ�ʴ洢˳��
//	char arr[20] = { 0 };
//	gets(arr);
//
//	//�ⷨһ��ѭ������
//	int len = strlen(arr);
//	int rotateNum = 0;
//	printf("����������ת����:");
//	scanf("%d", &rotateNum);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%c ", arr[rotateNum]);
//		rotateNum = (++rotateNum + len) % len;
//	}
//	
//	//�ⷨ����������ת��
//	//reverse(arr, 0, len - 1); //�������鷭ת
//	//reverse(arr, 0, len - 1 - rotateNum); //��ת���
//	//reverse(arr, len - rotateNum, len - 1);
//	//for (i = 0; i < len; i++)
//	//	printf("%c ", arr[i]);
//
//	return 0;
//}






//int Find(int arr[][4], int row, int col, int targer)
//{
//	if (row == 4 || col == -1)
//		return -1; //û�ҵ�
//	if (arr[row][col] == targer)
//		return arr[row][col];
//	else if (arr[row][col] > targer)
//		return Find(arr, row, col - 1, targer);
//	else
//		return Find(arr, row + 1, col, targer);
//}
//
//int main()
//{
//	//���Ͼ���
//	//�����Ͻǿ�����һ�Ŷ�����������������С�ڵ��ڸ������������ڵ��ڸ����ݹ��˼����
//	int arr[4][4] = {
//		{1,2,8,9} ,
//		{2,4,9,12},
//		{4,7,10,13},
//		{6,8,11,15}
//	};
//	int row = 0; //��
//	int col = 3; //��
//	int targer = 7;//��������
//	int num = Find(arr, row, col,targer);
//	printf("num = %d\n", num);
//	return 0;
//}



//int main()
//{
//	//������ı��ʳ����������ˣ�ÿ���˶������ʣ�ÿ���˶��ڵ�һ������ķ�Χ�ڣ�ֻ��һ��������
//	int a, b, c, d, e;
//	for(a=1;a <= 5;a++)
//		for(b = 1; b <= 5; b++)
//			for(c = 1; c <= 5; c++)
//				for(d = 1; d <= 5; d++)
//					for(e = 1; e <= 5; e++)
//						if (((b == 2) + (a == 3) == 1)
//							&& ((b == 2) + (e == 4) == 1)
//							&& ((c == 1) + (d == 4) == 1)
//							&& ((c == 5) + (d == 3) == 1)
//							&& ((b == 4) + (a == 1) == 1)
//							&&(a*b*c*d*e == 120))
//						{
//							
//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						}
//
//	return 0;
//}




//int main()
//{
//	//�ж�������
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//			printf("%c\n", killer);
//	}
//
//	return 0;
//}





//int triangle(int i, int j)
//{
//	if (j == 1 || i == j)
//		return 1;
//	return triangle(i - 1, j) + triangle(i - 1, j - 1);
//
//}
//
//int main()
//{
//	//��ӡ������ǣ��ݹ�ĽǶ�
//	int n = 0;
//	scanf("%d", &n);
//	int i, j;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%3d", triangle(i, j));
//		}
//		printf("\n");
//	}
//	return 0;
//}