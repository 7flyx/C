#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void contractionStr(char str[])
{
	if (str == NULL || !strlen(str))
		return;
	int count = 0;  //������ͬ�ַ���
	int index = 0; //����������±�
	int p = 0; //���¸�ֵ�ַ����±�
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
		�ַ���ѹ��. �����ַ���ֻ���� a-z ��ĸ�Լ�������־�����д����ʵ�ֶ��������ֵ���ͬ�ַ�����ѹ��,
		���磺 ��xxxyyyyz�� ѹ�����ַ���Ϊ ��3x4yz�� �� ��yyyyyyy�� ѹ����Ϊ ��7y��
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
//	int count = 0; //����ո��
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
//	//��д����������¹��ܣ�ɾ���ַ�����β�Ŀո��м�������ո�ֻ��һ����ԭ���ַ�����˳�򲻱䡣
//	//�� ��***** as**** adadq***** ����*�ǿո�
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
//	//����ж�һ����n�Ƿ���2��k�η���
//	//ֻҪ������������ֻ��һ��1������2�Ĵη�������
//	int x = 2019;
//	int res = isTwoConvert(x);
//	if (res)
//		printf("%d ��2��k�η�������!", x);
//	else
//		printf("%d ����2��k�η�������!", x);
//	return 0;
//}