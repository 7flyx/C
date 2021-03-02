# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>


void get_nextval(char* T, char* nextval)
{
	int i, j; //分别表示指向主串和子串
	i = 1;  //主串从1开始计算，为0的地方放入字符串的大小
	j = 0;

	while (i < T[0])  //i的值小于子串的总长
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;

			//判断是否与上一次的值相等
			if (T[i] != T[j])
				//失配时
				nextval[i] = j;  //前面的值j放在后面的位置nextval[i]处
			else
				//匹配成功时
				nextval[i] = nextval[j];
		}
		else
		{
			j = nextval[j];  //失配时，j的值应回溯，即就是重新赋值nextval[j]处的数值
		}
	}
}

int Index_KMP(char* arr1, char* arr2, int pos)
{
	int i = pos;  //i作为主串的下标值
	int j = 1; //从子串的二个元素开始判断，第一个元素放的子串的长度
	char nextval[255]; //用于存放next的值，
	get_nextval(arr2, nextval);
	while (i <= arr1[0] && j <= arr2[0])
	{
		if (j == 0 || arr1[i] == arr2[j])
		{
			//两个字符相等的话，下标值同时先后移动
			i++;
			j++;
		}
		else
		{
			//不相等的情况下j值重新赋值为合适的值，i值不变
			j = nextval[j];
		}
	}
	if (j > arr2[0])
		return i - arr2[0];
	else
		return 0;
}

//kmp模式匹配算法
int main()
{
	char arr1[9] = "7abcdefg";
	char arr2[7] = "5bcdef";

	Index_KMP(arr1, arr2, 1);

	return 0;
}


int BF_Find(char* S, char* T)
{
	int i = 1;
	int j = 1;

	//等价于 i！=‘\0’和 j!='\0'
	while (i <= S[0] && j <= T[0])
	{
		if(S[i]==T[j])
		{
			j++;
			i++;
		}
		else
		{
			//i值回溯，j值重新从第一个元素开始
			i = i - j + 2;
			j = 0;
		}
	}
	if (j == '\0')
		return i - T[0];
		//return i-j;  //得到的是i-j个字符之后开始的子串
						//并不是得到的是第i-j个字符开始的第一个字符
	else
		return -1;
}