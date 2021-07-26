#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void contractionStr(char str[])
{
	if (str == NULL || !strlen(str))
		return;
	int count = 0;  //计算相同字符的
	int index = 0; //遍历数组的下标
	int p = 0; //重新赋值字符的下标
	int pre = 0;
	while (str[index])
	{
		if (index - 1 >= 0 && str[index] == str[index - 1] || count == 0)
		{
			count++;
			pre = index;
		}
		else
		{
			if (count != 1)
			{
				str[p++] = count + '0';
				str[p++] = str[index - 1];
				str[p] = str[index];
				count = 1;
			} 
			else
			{
				str[++p] = str[index];
			}
		}
		index++;
	}
	if (count != 1)
	{
		str[p++] = count + '0';
		str[p++] = str[pre];
		str[p] = '\0';
	}
	else 
	{
		str[++p] = '\0';
	}
}
int main()
{
	/*
		字符串压缩. 输入字符串只包含 a-z 字母以及结束标志，请编写函数实现对连续出现的相同字符进行压缩,
		例如： ”xxxyyyyz” 压缩后字符串为 ”3x4yz” ， ”yyyyyyy” 压缩后为 ”7y”
	*/
	char str[100] = "xxxyyyzyua";
	contractionStr(str);
	printf(str);
	return 0;
}



//
//void delSpaceOfStr(char str[])
//{
//	if (str == NULL)
//		return;
//	int count = 0; //计算空格的
//	int index = 0;
//	int p = 0;
//	while (str[index] == ' ')
//		index++;
//	while (str[index])
//	{
//		if (str[index] != ' ') {
//			str[p++] = str[index];
//			count = 0;
//		}		
//		else if (count == 0) {
//			str[p++] = str[index];
//			count++;
//		}
//		else {
//			count++;
//		}
//		index++;
//	}
//	if (count != 0)
//		str[--p] = '\0';
//	else
//		str[p] = '\0';
//}
//
//int main()
//{
//	//编写代码完成如下功能：删除字符串首尾的空格，中间的连续空格只留一个，原来字符串的顺序不变。
//	//如 “***** as**** adadq***** ”（*是空格）
//	char str[100] = "     as    adadq     ";
//	delSpaceOfStr(str);
//
//	printf(str);
//	return 0;
//}




//int isTwoConvert(int num)
//{
//	if (num == 0)
//		return 0;
//	int count = 0;
//	while (num != 0)
//	{
//		count++;
//		num -= (num & (~num + 1));
//	}
//	printf("%d", count);
//	if (count == 1)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	//如何判断一个数n是否是2的k次方？
//	//只要二进制中有且只有一个1，就是2的次方得来的
//	int x = 2019;
//	int res = isTwoConvert(x);
//	if (res)
//		printf("%d 是2的k次方得来的!", x);
//	else
//		printf("%d 不是2的k次方得来的!", x);
//	return 0;
//}