# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void del(char s[])
{
	int i = 0;
	int p = 1, h = 0; //hΪ��дs����λ�ã�p���ڱ�ʶǰһ���ַ��Ƿ�Ϊ�ո�
	
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
		if (s[i] == ' ')  //�ǿո�
		{
			if (p == 0) //��һ�� ���ǿո񣬶���ǰs[i]�õ���ȴ�ǿո񣬾Ͱ��ƶ���hλ�ò��ո�
				s[h++] = ' ';
			p = 1;
		}
		else  //���ǿո�
		{
			p = 0; //pΪ0�������ǿո�
			s[h++] = s[i];  //��Ȼ���ǿո񣬾Ͱ�Ԫ����ǰ��
		}
		i++;
	}
	if (s[h - 1] == ' ') //��\0����������־
		s[h - 1] = '\0';
	else
		s[h] = '\0';
}

int main()
{
	char arr[50];
	printf("������:");
	gets(arr);
	del(arr);
	printf("%s\n", arr);
	return 0;
}