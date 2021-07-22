#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <climits>
#include <stdlib.h>


#define MAX_SIZE 30
typedef struct Record
{
	int val;
	int sum; //这个字符的总和
	int times; //记录进入栈的时间
}Record;

typedef struct myStack
{
	Record data[MAX_SIZE];
	int index;
}myStack;

void stackPush(myStack* stack, Record data)
{
	stack->data[stack->index++] = data;
}

Record stackPop(myStack* stack)
{
	if (stack->index == 0)
	{
		printf("栈为空");
		exit(0);
	}
	stack->index--;
	return stack->data[stack->index];
}

int stackIsEmpty(myStack* stack)
{
	if (stack->index == 0)
		return 1;
	return 0;
}

Record stackPeek(myStack* stack)
{
	if (stack->index == 0)
	{
		printf("stack is empty.");
		exit(0);
	}
	return stack->data[stack->index - 1];
}
int getFirstNum(char str[], myStack* stack, myStack* help)
{
	if (str == NULL)
		return ' ';

	int len = strlen(str);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		//单调栈结构
		while (!stackIsEmpty(stack) && stackPeek(stack).val > str[i])
			stackPush(help, stackPop(stack)); //暂时放入help栈
		if (!stackIsEmpty(stack) && stackPeek(stack).val == str[i])
		{
			int sum = stackPop(stack).sum + 1;
			Record node = { str[i], sum, 0 };
			stackPush(stack, node);
		}
		else
		{
			Record tmp = { str[i], 1, i };
			stackPush(stack, tmp);
		}
		while (!stackIsEmpty(help))
			stackPush(stack, stackPop(help)); //重新返回stack栈
	}
	Record res = { 0 };
	int times = -1;
	while (!stackIsEmpty(stack))
	{
		if (stackPeek(stack).sum != 1)
			stackPop(stack);
		else if (times < stackPeek(stack).times)
			res = stackPop(stack);
		else
			stackPop(stack);
	}
	return res.val;
}
int main()
{
	myStack* stack = (myStack*)malloc(sizeof(myStack));
	if (stack == NULL)
		return 1;
	stack->index = 0;
	myStack* help = (myStack*)malloc(sizeof(myStack));
	if (help == NULL)
	{
		free(stack);
		return 1;
	}
	help->index = 0;
	char str[] = "abaccdeff";
	int res = getFirstNum(str, stack, help);
	printf("%c\n", res);

	free(stack);
	free(help);
	return 0;
}


//int main() 
//{ 
//	char a[1000];
//	int i; 
//	for (i = 0; i < 1000; i++) 
//	{
//		a[i] = (char)(-1 - i);
//	}
//	printf("%d\n", strlen(a));
//	return 0;
//}


//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int* p = arr;
//	p += 2;
//	printf("%d\n", *++p);
//	return 0;
//}


////#pragma pack(4)
//union Un
//{
//	short s[5];
//	long long  n;
//};
////#pragma pack()
//
//
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}



//int getSubArrMax(int arr[], int size)
//{
//	if (arr == NULL || size < 1)
//	{
//		perror("NULL or size < 1, error");
//		return -1;
//	}
//
//	int tmpMax = arr[0];
//	int max = tmpMax;
//	int i = 0;
//	for (i = 1; i < size; i++)
//	{
//		tmpMax += arr[i];
//		if (tmpMax < arr[i])
//			tmpMax = arr[i];
//		if (max < tmpMax)
//			max = tmpMax;
//	}
//	return max;
//}
//
//int main()
//{
//	int arr[] = { 1,-2,3,10,-4,7,2,-5 };
//	int size = sizeof(arr) / sizeof(int);
//	int max = getSubArrMax(arr, size);
//	printf("%d\n", max);
//}


//int main() 
//{ 
//	int a, x;
//	for (a = 0, x = 0; a <= 1 && !x++; a++)
//	{
//		a++;
//	}
//
//	printf("%d %d\n", a, x); 
//	printf("%d\n", 4 & 4);
//	return 0;
//}




//void Func(char str_arg[10])
//{ 
//	int m = sizeof(str_arg);
//	int n = strlen(str_arg); 
//	printf("%d\n", m);
//	printf("%d\n", n); 
//}
//int main(void)
//{ 
//	char str[] = "Hello";
//
//	Func(str);
//	return 0;
//}





//int getMaxVotes(int arr[], int size)
//{
//	if (arr == NULL || size < 1)
//		return -1;
//
//	int votes = 1; //票数
//	int x = arr[0]; //众数
//	int i = 0; 
//	for (i = 1; i < size; i++)
//	{
//		if (votes == 0)
//			x = arr[i], votes++;
//		else if (arr[i] == x)
//			votes++;
//		else if (arr[i] != x)
//			votes--;
//	}
//	return x;
//}
//int main()
//{
//	//求数组中出现次数超过一半的数组
//	//摩尔投票法
//	int arr[10] = { 1,2,3,2,2,1,2,6,2,2 };
//	int size = sizeof(arr) / sizeof(int);
//	printf("%d\n", getMaxVotes(arr, size));
//	return 0;
//}



//int getMinNum(int arr[], int size, int k)
//{
//	if (arr == NULL || k < 1)
//		return 0;
//	int min = INT_MAX;
//	int i = 0;
//	for (i = 0; i < k && i < size; i++)
//	{
//		if (arr[i] < min)
//			min = arr[i];
//	}
//	return min;
//}
//
//int main()
//{
//	int a[] = { 11,22,3,44,32,1,67,89,56,433,890 };
//	int k = 5;
//	int size = sizeof(a) / sizeof(int);
//	printf("%d \n", getMinNum(a, size, k));
//
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));
//
//	unsigned long ulA = 0x11000000;
//	printf("%#x\n", ulA);
//	printf("%#x\n", *(unsigned char*)&ulA);
//	return 0;
//}