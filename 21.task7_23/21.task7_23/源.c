#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


int main()
{
	//判断一个数，是不是回文数
	int n = 0;
	scanf("%d", &n);
	isPalindromicNum(aoit(n));
	return 0;
}


//int main()
//{
//
//	int arr[] = { 6,7,8,9,10 };
//	int* ptr = arr;
//	*(ptr++) += 123;
//	printf("%d,%d", *ptr, *(++ptr));
//
//	return 0;
//}


//struct student {
//	char name[10];
//	int age;
//	char gender;
//}std[3], * p = std;
//
//int main()
//{
//	scanf("%s", *std[0].name);
//	return 0;
//}




//void delSameChar(char str[], char dict[])
//{
//	int len = strlen(str);
//	int index = 0;
//	int i = 0;
//	int count = 0; //共删除了几个字符，需要向前移动几个字符的位置
//	for (i = 0; i < len; i++)
//	{
//		if (dict[str[i]] != 0)
//		{
//			str[index] = str[i + 1];
//			count++;
//		}
//		else
//		{
//			str[index] = str[index + count]; //移动过几个字符，则中间就差了几个字符的位置
//			index++;
//		}		
//	}
//	str[index] = '\0';
//}
//
//int main()
//{
//	char dict[127] = { 0 };
//	char str1[30] = "They are students.";
//	char str2[30] = "aeiou";
//	int size = sizeof(str2) - 1;
//	int i = 0;
//	for (i = 0; i < size; i++)
//		dict[str2[i]]++;
//
//	delSameChar(str1, dict);
//	printf(str1);
//	return 0;
//}


//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//} 
//int main()
//{
//	printf("%d\n", f(1));
//	return 0;
//}




//void getAbnormalNums(int arr[], int size, int* res1, int* res2)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//		(*res1) ^= arr[i];
//
//	int rightOne = (*res1) & (~(*res1) + 1); //得到这个数，二进制中最靠右的1
//	int tmp = 0;
//	for (i = 0; i < size; i++)
//		if ((arr[i] & rightOne) != 0) //不等于0，即就是说，在rightOne位置，都有1，有可能就是那个奇数个的数
//			tmp ^= arr[i];
//	*res2 = (*res1) ^ tmp;
//	*res1 = tmp;
//}
//
//int main()
//{
//	//一个整形数组里，只有两个数，出现了奇数个。其余的数都是偶数个。求这两个奇数个的数
//	int arr[] = { 1,3,5,7,1,3,5,9 };
//	int size = sizeof(arr) / sizeof(int);
//	int res1 = 0;
//	int res2 = 0;
//	getAbnormalNums(arr, size, &res1, &res2);
//	printf("%d %d\n", res1, res2);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int* cur = arr[8];
//	printf("%d\n", p - arr);
//	
//	return 0;
//}


//int getRepeatChar(char str[], char dict[])
//{
//	if (str == NULL)
//		return -1;
//	int len = strlen(str);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (!dict[str[i]])
//			dict[str[i]]++;
//		else
//			return str[i];
//	}
//	return -1;
//}
//int main()
//{
//	char dictionaries[127] = { 0 };
//	char str[30] = { "qywyer23tdd" };
//	char ch = getRepeatChar(str, dictionaries);
//	if (ch == -1)
//		printf("没有重复的字符!");
//	else
//		printf("%c\n", ch);
//	return 0;
//}


//
//int main()
//{
//	//unsigned char a = 0xA5;
//	//unsigned char b = ~a >> 4 + 1; //有个整形提升，先将a提升int，再取反
//	//unsigned char c = ~a;
//	//printf("%d\n", c);
//	//printf("%d\n", b);
//
//	
//	const int i = 0;
//	int* j = (int*)&i;
//	*j = 1;
//	printf("%d,%d", i, *j);
//
//	return 0;
//}