#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void getAbnormalNum(int arr[], int size, int* num1, int* num2)
{
	int eOhasOne = 0;
	int res = 0;
	int i = 0;
	for (i = 0; i < size; i++)
		res ^= arr[i];
	// 异或性质： n ^ n = 0,  0 ^ n = n
	//异或的最后结果，一定是那两个不同的数值异或的结果
	int rightOne = res & (~res + 1); //拿到res这个数，在二进制中，最靠右的1
	for (i = 0; i < size; i++)
		if ((rightOne & arr[i]) != 0)
			eOhasOne ^= arr[i]; //这样异或出来，肯定是不一样的两个数，其中一个
	*num1 = eOhasOne;
	*num2 = res ^ eOhasOne;
}

int main()
{
	/*一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。

		编写一个函数找出这两个只出现一次的数字。*/
	int arr[10] = { 4,5,4,3,3,2,2,1,1,7 };
	int num1 = -1;
	int num2 = -1;
	int size = sizeof(arr) / sizeof(int);
	getAbnormalNum(arr, size, &num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}


//char* my_strncpy(char* dest, const char* src, int num)
//{
//	if (dest == NULL || src == NULL || num < 1)
//		return NULL;
//	char* tmp = dest;
//	while (num-- && (*dest++ = *src++))
//		;
//	*dest = '\0';
//	return tmp;
//}
//
//
//int main()
//{
//	char str1[30] = "hello";
//	my_strncpy(str1, "world - hello c", 15);
//	printf(str1);
//	return 0;
//}




//char* my_strncat(char* dest, const char* sre, int num)
//{
//	if (dest == NULL || sre == NULL || num < 1)
//		return NULL;
//
//	int p1 = 0;
//	int p2 = 0;
//	int k = num;
//	while (dest[p1++] != '\0')
//		;
//
//	p1--;
//
//	while (k--  && (dest[p1++] = sre[p2++]))
//		;
//	dest[p1] = '\0'; //有可能最后没拷贝\0
//	return dest;
//}
//
//int main()
//{
//	char str[30] = "hello ";
//	my_strncat(str, "world", 5);
//	printf(str);
//	return 0;
//}



//int my_atoi(const char* str)
//{
//	if (str == NULL)
//		return 0;
//	int pstr = 0;
//	int res = 0;
//	int flag = 1;
//	while (*(str + pstr) == ' ')
//		pstr++;
//	if (*(str + pstr) == '-')
//	{
//		flag = -1;
//		pstr++;
//	}
//	if (*(str + pstr) == '+')
//		pstr++;
//	while (*(str + pstr) >= '0' && *(str + pstr) <= '9')
//	{
//		res = res * 10 + *(str + pstr) - '0';
//		pstr++;
//	}
//	return flag * res;
//}
//
//int main()
//{
//	char str1[] = "-123";
//	char str2[] = "256";
//	int c = my_atoi(str1) + my_atoi(str2);
//	printf("%d\n", c);
//	return 0;
//}


//typedef struct Node
//{
//	int val;
//	struct Node* next;
//}Node;
//
//
//Node* reverseList(Node* node)
//{
//	if (node != NULL)
//	{
//		Node* pre = NULL;
//		Node* cur = node;
//		Node* next = NULL;
//		while (cur != NULL)
//		{
//			next = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = next;
//		}
//		return pre;
//	}
//}
//
//Node* createNode(int n)
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	Node* cur = head;
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		cur->next = (Node*)malloc(sizeof(Node));
//		cur = cur->next;
//		cur->val = i;
//		cur->next = NULL;
//	}
//	cur = head->next;
//	free(head);
//	return cur;
//}
//
//void print(Node* node)
//{
//	while (node != NULL)
//	{
//		printf("%d ", node->val);
//		node = node->next;
//	}
//}
//void delList(Node* node)
//{
//	Node* next = NULL;
//	while (node != NULL)
//	{
//		next = node->next;
//		free(node);
//		node = next;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Node* node = createNode(n);
//	print(node);
//	printf("\n");
//	node = reverseList(node);
//	print(node);
//	delList(node);
//	return 0;
//}