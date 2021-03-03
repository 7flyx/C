#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define T_length 9
#define S_length 12



void GetNext(char* T, int* next)
{
	int j = -1;//ָ��  ǰ׺
	int i = 0;  //ָ�� ��׺
	next[0] = -1;

	while (i < T_length)
	{
		if (j == -1 || T[j] == T[i])
		{
			i++;
			j++;
			if (T[j] != T[i])
				next[i] = j;  //i��j���ƺ������ƥ�䣬��ʱnext[i]���ͷ���j��ֵ
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
	int i = pos;  //ָ���������±�ֵ
	int j = 0;  //ָ���Ӵ����±�ֵ
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
			//ƥ��ʧ��ʱ----iֵ������
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
	//kmpģʽƥ���㷨
	char arr1[T_length] = "DABCDABD"; //�Ӵ�
	char arr2[S_length] = "ABCDABCDABD"; //����
	int i = 3;
 	int pos = KMP_find(arr2, arr1, 3);
	
	printf("�ڵ�%d���ַ����濪ʼ ", pos);
		  

	return 0;
}


