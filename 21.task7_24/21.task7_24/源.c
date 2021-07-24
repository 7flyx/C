#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define OFFSETOF(structName, memoryName) (int)&(((structName*)0)->memoryName)

struct S
{
	int val;
	char x;
	struct S* next;
};

int main()
{
	//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
	//计算偏移量，肯东是一个位置的地址减去结构体第一个变量的地址
	//将结构体的第一个变量的地址 转换为0，再去调用哪个成员，减去首地址即可
	printf("%d\n", OFFSETOF(struct S, next));
	return 0;
}




//#define SWAP(n) ((((n) & 0xaaaaaaaa) >> 1) + (((n) & 0x55555555) << 1))
////分别取出偶数为的值和奇数位的值，一个向左移动一位，一个向右移动一位
//
//int main()
//{
//	//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//
//	int x = 10;
//	printf("%d\n", SWAP(x));
//	return 0;
//}



//int main()
//{
//	int i, x, y;
//	i = x = y = 0;
//	do {
//		++i;
//		if (i % 2)
//			x += i,
//			i++;
//		y += i++;
//	} while (i <= 7);
//	printf("%d %d %d", i, x, y);
//}



//
//int calculateRange(int arr[], int L, int R, int k, int* newRight) {
//	//返回的是1,就是相等的情况
//	//返回0，就是左下标 右走一步
//	int tmpR = R;
//	while (L <= R)
//	{
//		if (arr[L] + arr[R] == k){
//			*newRight = R;
//			return 1;
//		} else if (R + 1 <= tmpR && (arr[L] + arr[R - 1]) < k && (arr[L] + arr[R + 1]) > k) {
//			break;//既不大于，也不小于的，说明left数，不得行
//		} else if (arr[L] + arr[R] > k) {
//			*newRight = R; //记录上次的右边值，以防下次使用
//			R = L + ((R - L) >> 1);
//		} else {
//			if (R + 1 > tmpR) //防止，k这个数，一开始就是太大，导致死循环
//				break;
//			R = R + (((*newRight) - R) >> 1);
//		}	
//	}
//	return 0;
//}
//int getSumOfTwoNum(int arr[], int len, int k, int* x, int* y) {
//	//查找两个数的和为k，又是有序数组，二分法考虑。可以实现时间复杂度到O（N)
//	int left = 0;
//	int right = len - 1;
//	int newRight = right;
//	while (left < right) {
//		if (calculateRange(arr, left, right, k, &newRight)){// 确定范围 
//			*x = left;
//			*y = newRight;
//			return left != newRight;
//		} else  { //说明此时左边的值，匹配不到，需要更换
//			left++;
//			right = newRight;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,3,5,7,8,10,26,40,50,55 };
//	int len = sizeof(arr) / sizeof(int);
//	int k = 50;
//	int x = -1;
//	int y = -1;
//	if (getSumOfTwoNum(arr, len, k, &x, &y))
//		printf("%d %d\n", x, y);
//	else
//		printf("没找到两个数值和为 %d 的\n", k);
//
//	char ch = -1;
//	printf("%d\n", ch);
//
//
//	return 0;
//}




//void foo(int b[][3])
//{
//	++b;
//	b[1][1] = 9;
//}
//void main()
//{
//	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	foo(a);
//	printf("%d", a[2][1]);
//}


//double my_pow(int x, int y)
//{
//	if (y == 0 && x != 0)
//		return 1;
//	else if (x == 0)
//		return 0;
//
//	double res = 1;
//	int tmp = 0;
//	if (y < 0)
//		tmp = -y;
//	else
//		tmp = y;
//	while (tmp--)
//		res *= (double)x;
//
//	if (y < 0)
//		return (1 / res);
//	return res;
//}
//
//int main()
//{
//	int x = 2;
//	int y = -1;
//	printf("%.2lf\n",my_pow(x, y));
//	return 0;
//}


//int main()
//{
//	unsigned short sht = 0;
//	sht--;
//	printf("%d", sht);
//	return 0;
//}



//typedef struct Node
//{
//	int val;
//	struct Node* next;
//}Node;
//
//Node* findMidNode(Node* node)
//{
//	if (node == NULL)
//		return NULL;
//	Node* fast = node->next;
//	Node* slow = node;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}
//
//int main()
//{
//	//返回一个单链表的中间结点
//	Node* node = (Node*)malloc(sizeof(Node));
//	if (!node)
//		return 1;
//	Node* tmp = findMidNode(node); //奇数结点，返回中间。偶数结点返回中上结点
//	if (tmp != NULL)
//		printf("%d\n", tmp->val);
//	free(node);
//	return 0;
//}


//int main()
//{
//	int x = 1, y = 012;
//	printf("%d", y * x++);
//	return 0;
//}



//int isPalindromicNum(int n)
//{
//	//先转换为字符串
//	char str[100] = { 0 };
//	int index = 0;
//	while (n != 0)
//	{
//		str[index++] = (n % 10) + '0';
//		n /= 10;
//	}
//	int left = 0;
//	int right = index - 1;
//	while (left <= right)
//	{
//		if (str[left] != str[right])
//			return 0;
//		left++;
//		right--;
//	}
//	return 1;
//}
//
//
//int main()
//{
//	//判断一个数，是不是回文数
//	int n = 0;
//	scanf("%d", &n);
//	
//	if (isPalindromicNum(n))
//		printf("%d是回文数!", n);
//	else
//		printf("%d不是回文数!", n);
//	return 0;
//}