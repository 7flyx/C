#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//typedef struct Node
//{
//	int val;
//	struct Node* next;
//}Node;
//
//int countBackward(Node* head, int k)
//{
//	if (head == NULL || k < 1)
//		return -1;
//
//	//�ȱ���һ������ k--
//	int size = 0;
//	Node* cur = head;
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		k--;
//	}
//
//	if (k > 0)
//		return -1; //˵������Ľ����������k��
//	if (k == 0)
//		return head->val; //�պ��ǵ�һ�����
//
//	//k < 0 �����
//	//������ xΪ��������ĳ��ȣ�x - k�����ǵ�����k������   ǰһ�����
//	cur = head;
//	while (++k != 0)
//		cur = head->next;
//	return cur->next->val; 
//}
//
//int main()
//{
//	Node* head = NULL;
//	printf("%d\n", countBackward(head, 3));
//	return 0;
//}



 
// 
//int main() 
//{ 
//	char arr[2][4]; 
//	strcpy((char*)arr, "you");
//	strcpy(arr[1], "me"); 
//	arr[0][3] = '&';
//	printf("%s\n", arr);
//	return 0;
//}


 

//int countOneFoNum(unsigned int x)
//{
//	int count = 0;
//	while (x != 0)
//	{
//		int tmp = x & (~x + 1); //�õ�x��������ڶ����������ұߵ�1
//		x -= tmp;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	//дһ���������� unsigned int �ͱ��� x ���ڴ��ж����� 1 �ĸ���
//	unsigned int x = 2019;
//	printf("%d\n", countOneFoNum(x));
//	return 0;
//}



//int fun(int x, int y) 
//{
//	static int m = 0; 
//	static int i = 2;
//	i += m + 1;
//	m = i + x + y;
//	return m;
//}
//void main()
//{ 
//	int j = 4; int m = 1; int k;
//	k = fun(j, m);
//	printf("%d,", k); 
//	k = fun(j, m); 
//	printf("%d\n", k); 
//	return;
//}


//#define F(X,Y) ((X)+(Y))
//int main()
//{
//	int a = 3,b = 4;
//	printf("%d\n",F(a++, b++)); 
//}



//int main()
//{
//	//쳲����������ǵݹ�
//	//�Ե����ϣ�����
//	int n = 0;
//	scanf("%d", &n);
//	int pre = 1; //n = 1
//	int cur = 1; //n = 2
//	int i = 0;
//	if (n > 2)
//	{
//		for (i = 3; i <= n; i++)
//		{
//			int last = pre + cur;
//			pre = cur;
//			cur = last;
//		}
//		printf("%d\n", cur);
//	}
//	else
//		printf("1\n");
//
//	return 0;
//}








typedef struct arrays
{
    char c;
    int arr[0];
}arrays;
int main()
{
    char arr[] = "abc defgx yz";
    //ѭ������һ�Σ����м����ո񣬾�Ҫ����Ҫ2 * i���ո�Ŀռ�
    int i = 0;
    int index = 0; //ָ����������
    int count = 0;
    int size = sizeof(arr);
    for (i = 0; i < size; i++)
        if (arr[i] == ' ')
            count++;
    //��C�����У����ܶ�̬��������ռ䣬ֻ�ܿ�����������
    arrays* array = (arrays*)malloc(sizeof(arrays) + sizeof(char) * count + size);
    for (i = 0; i < size + 2 * count; i++)
    {
        if (arr[i] != ' ')
            array->arr[index++] = arr[i];
        else
        {
            array->arr[index++] = '%';
            array->arr[index++] = '2';
            array->arr[index++] = '0';
        }
    }
    for (i = 0; i < size + 2 * count; i++)
        printf("%c", array->arr[i]);

	free(array);
    return 0;
}



//int findNum(int arr[4][4], int row, int col, int k)
//{
//    int r = 0;
//    int c = col - 1;
//    while (r < row && c >= 0)
//    {
//        if (arr[r][c] < k)
//            r++;
//        else if (arr[r][c] > k)
//            c--;
//        else
//            return 1;
//    }
//    return 0;
//}
//
//int main()
//{
//    int arr[4][4] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
//    int k = 0;
//    if (findNum(arr, 4, 4, k))
//        printf("��������%d�����\n", k);
//    else
//        printf("������û��%d�����\n", k);
//
//    char arr[10] = "string";
//    return 0;
//}