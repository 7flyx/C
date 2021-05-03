# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del(char s[])
{
	int i = 0;
	int p = 1, h = 0; //h为重写s串的位置，p用于标识前一个字符是否为空格
	
	//while (1)
	//{
	//	if (arr[0] != ' ')
	//		break;
	//	i = 0;
	//	while (arr[i])
	//	{
	//		arr[i] = arr[i + 1];
	//		i++;
	//	}
	//}

	while (s[i])
	{
		if (s[i] == ' ')  //是空格
		{
			if (p == 0) //上一个 不是空格，而当前s[i]拿到的却是空格，就把移动的h位置补空格
				s[h++] = ' ';
			p = 1;
		}
		else  //不是空格
		{
			p = 0; //p为0，代表不是空格
			s[h++] = s[i];  //既然不是空格，就把元素往前拿
		}
		i++;
	}
	if (s[h - 1] == ' ') //补\0，做结束标志
		s[h - 1] = '\0';
	else
		s[h] = '\0';
}

int main()
{
	char arr[50];
	printf("请输入:");
	gets(arr);
	del(arr);
	printf("%s\n", arr);
	return 0;
}