# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//int main()
//{
//	int a = 10000;
//	FILE* ps = fopen("test.txt", "wb");  //wb�����Զ����Ƶ���ʽ����  --write binary
//	fwrite(&a, 4, 1, ps);  //�ļ����룬��һ�������������   �ڶ������ڴ�ռ䣬�ֽ�
//	//�����������뼸����������ֵ�����ĸ��������Ŀ���ַ
//	fclose(ps);  //�ļ��ر�
//	ps = NULL;
//	
//	return 0;
//}




//int main()
//{
//	int a = 10000;
//	FILE* ps = fopen("test.txt", "r");  
//
//	/*printf("%c",fgetc(ps));
//	printf("%c", fgetc(ps));
//	printf("%c", fgetc(ps));
//	printf("%c", fgetc(ps));
//	printf("%c", fgetc(ps));*/
//
//
//	fclose(ps);
//	ps = NULL;
//	return 0;
//}




#include<stdio.h>
#include<string.h>
//�ٶ�������ַ�����ֻ������ĸ��*�ţ����д�������Ĺ����ǣ����ַ����е�ǰ��*��ȫ���Ƶ��ַ�����β����
void fun(char* arr)
{
	int n = 0;
	int j = 0;
	int len = strlen(arr);
	int i = 0;
	for (i = 1; i <= len; i++)
	{
		//1.����*�ţ�����ѭ��
		if ((arr[i-1] >= 'a' && arr[i-1] <= 'z') || (arr[i-1] >= 'A' && arr[i-1] <= 'Z'))
			break;
		//�õ�ǰ��*�ŵĸ���    i
	}
	//�ӵ�i��Ԫ�ؿ�ʼ��ȫ����ǰ�ƶ�������Ĳ�*����
	for (n = i-1; n < len; n++)
	{	
		arr[j] = arr[n];
		j++;
	}

	for (n = j; n < len; n++)
		arr[n] = '*';
	printf("%s\n", arr);
}
int main()
{
	char arr[50] = "*****abcd*f*e***";   //->abcd*f*e********
	fun(arr);
	printf("%s", arr);
	return 0;
}