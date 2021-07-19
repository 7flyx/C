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
//	//先遍历一遍链表 k--
//	int size = 0;
//	Node* cur = head;
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		k--;
//	}
//
//	if (k > 0)
//		return -1; //说明链表的结点数，不够k个
//	if (k == 0)
//		return head->val; //刚好是第一个结点
//
//	//k < 0 的情况
//	//不妨设 x为整个链表的长度，x - k，就是倒数第k个结点的   前一个结点
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
//		int tmp = x & (~x + 1); //拿到x这个数，在二进制中最右边的1
//		x -= tmp;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	//写一个函数求，求 unsigned int 型变量 x 在内存中二进制 1 的个数
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
//	//斐波那契数，非递归
//	//自底向上，迭代
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
    //循环遍历一次，看有几个空格，就要扩容要2 * i个空格的空间
    int i = 0;
    int index = 0; //指向柔性数组
    int count = 0;
    int size = sizeof(arr);
    for (i = 0; i < size; i++)
        if (arr[i] == ' ')
            count++;
    //在C语言中，不能动态开辟数组空间，只能考虑柔性数组
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
//        printf("该数组有%d这个数\n", k);
//    else
//        printf("该数组没有%d这个数\n", k);
//
//    char arr[10] = "string";
//    return 0;
//}