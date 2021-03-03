#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define T_length 9
#define S_length 12



void GetNext(char* T, int* next)
{
	int j = -1;//指向  前缀
	int i = 0;  //指向 后缀
	next[0] = -1;

	while (i < T_length)
	{
		if (j == -1 || T[j] == T[i])
		{
			i++;
			j++;
			if (T[j] != T[i])
				next[i] = j;  //i和j后移后，如果不匹配，此时next[i]处就放入j的值
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP_find(char* S, char* T, int pos)
{
	int i = pos;  //指向主串的下标值
	int j = 0;  //指向子串的下标值
	int next[20];
	

	GetNext(T, next);

	while (j < T_length && i < S_length)
	{
		if (j == -1 || T[j] == S[i])
		{
			i++;
			j++;
		}
		else
		{
			//匹配失败时----i值不回溯
			j = next[j];
		}
	}
	if (j >= T_length)
		return i - T_length;
	else
		return -1;
}

int main()
{
	//kmp模式匹配算法
	char arr1[T_length] = "DABCDABD"; //子串
	char arr2[S_length] = "ABCDABCDABD"; //主串
	int i = 3;
 	int pos = KMP_find(arr2, arr1, 3);
	
	printf("在第%d个字符后面开始 ", pos);
		  

	return 0;
}


