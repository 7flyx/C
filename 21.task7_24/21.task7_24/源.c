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
	//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
	//����ƫ�������϶���һ��λ�õĵ�ַ��ȥ�ṹ���һ�������ĵ�ַ
	//���ṹ��ĵ�һ�������ĵ�ַ ת��Ϊ0����ȥ�����ĸ���Ա����ȥ�׵�ַ����
	printf("%d\n", OFFSETOF(struct S, next));
	return 0;
}




//#define SWAP(n) ((((n) & 0xaaaaaaaa) >> 1) + (((n) & 0x55555555) << 1))
////�ֱ�ȡ��ż��Ϊ��ֵ������λ��ֵ��һ�������ƶ�һλ��һ�������ƶ�һλ
//
//int main()
//{
//	//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
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
//	//���ص���1,������ȵ����
//	//����0���������±� ����һ��
//	int tmpR = R;
//	while (L <= R)
//	{
//		if (arr[L] + arr[R] == k){
//			*newRight = R;
//			return 1;
//		} else if (R + 1 <= tmpR && (arr[L] + arr[R - 1]) < k && (arr[L] + arr[R + 1]) > k) {
//			break;//�Ȳ����ڣ�Ҳ��С�ڵģ�˵��left����������
//		} else if (arr[L] + arr[R] > k) {
//			*newRight = R; //��¼�ϴε��ұ�ֵ���Է��´�ʹ��
//			R = L + ((R - L) >> 1);
//		} else {
//			if (R + 1 > tmpR) //��ֹ��k�������һ��ʼ����̫�󣬵�����ѭ��
//				break;
//			R = R + (((*newRight) - R) >> 1);
//		}	
//	}
//	return 0;
//}
//int getSumOfTwoNum(int arr[], int len, int k, int* x, int* y) {
//	//�����������ĺ�Ϊk�������������飬���ַ����ǡ�����ʵ��ʱ�临�Ӷȵ�O��N)
//	int left = 0;
//	int right = len - 1;
//	int newRight = right;
//	while (left < right) {
//		if (calculateRange(arr, left, right, k, &newRight)){// ȷ����Χ 
//			*x = left;
//			*y = newRight;
//			return left != newRight;
//		} else  { //˵����ʱ��ߵ�ֵ��ƥ�䲻������Ҫ����
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
//		printf("û�ҵ�������ֵ��Ϊ %d ��\n", k);
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
//	//����һ����������м���
//	Node* node = (Node*)malloc(sizeof(Node));
//	if (!node)
//		return 1;
//	Node* tmp = findMidNode(node); //������㣬�����м䡣ż����㷵�����Ͻ��
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
//	//��ת��Ϊ�ַ���
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
//	//�ж�һ�������ǲ��ǻ�����
//	int n = 0;
//	scanf("%d", &n);
//	
//	if (isPalindromicNum(n))
//		printf("%d�ǻ�����!", n);
//	else
//		printf("%d���ǻ�����!", n);
//	return 0;
//}