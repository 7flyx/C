# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>


void get_nextval(char* T, char* nextval)
{
	int i, j; //�ֱ��ʾָ���������Ӵ�
	i = 1;  //������1��ʼ���㣬Ϊ0�ĵط������ַ����Ĵ�С
	j = 0;

	while (i < T[0])  //i��ֵС���Ӵ����ܳ�
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;

			//�ж��Ƿ�����һ�ε�ֵ���
			if (T[i] != T[j])
				//ʧ��ʱ
				nextval[i] = j;  //ǰ���ֵj���ں����λ��nextval[i]��
			else
				//ƥ��ɹ�ʱ
				nextval[i] = nextval[j];
		}
		else
		{
			j = nextval[j];  //ʧ��ʱ��j��ֵӦ���ݣ����������¸�ֵnextval[j]������ֵ
		}
	}
}

int Index_KMP(char* arr1, char* arr2, int pos)
{
	int i = pos;  //i��Ϊ�������±�ֵ
	int j = 1; //���Ӵ��Ķ���Ԫ�ؿ�ʼ�жϣ���һ��Ԫ�طŵ��Ӵ��ĳ���
	char nextval[255]; //���ڴ��next��ֵ��
	get_nextval(arr2, nextval);
	while (i <= arr1[0] && j <= arr2[0])
	{
		if (j == 0 || arr1[i] == arr2[j])
		{
			//�����ַ���ȵĻ����±�ֵͬʱ�Ⱥ��ƶ�
			i++;
			j++;
		}
		else
		{
			//����ȵ������jֵ���¸�ֵΪ���ʵ�ֵ��iֵ����
			j = nextval[j];
		}
	}
	if (j > arr2[0])
		return i - arr2[0];
	else
		return 0;
}

//kmpģʽƥ���㷨
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

	//�ȼ��� i��=��\0���� j!='\0'
	while (i <= S[0] && j <= T[0])
	{
		if(S[i]==T[j])
		{
			j++;
			i++;
		}
		else
		{
			//iֵ���ݣ�jֵ���´ӵ�һ��Ԫ�ؿ�ʼ
			i = i - j + 2;
			j = 0;
		}
	}
	if (j == '\0')
		return i - T[0];
		//return i-j;  //�õ�����i-j���ַ�֮��ʼ���Ӵ�
						//�����ǵõ����ǵ�i-j���ַ���ʼ�ĵ�һ���ַ�
	else
		return -1;
}