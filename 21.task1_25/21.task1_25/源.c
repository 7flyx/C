# define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//		return 0;
//	//д�ļ�
//	fputs("hello bit", pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	char arr[100] = { 0 };
//	if (pf == NULL)
//		return 0;
//	//���ļ�
//
//	fgets(arr, 5, pf);  //fgets���Զ���ĩβ�Ÿ�\n��ռ��һ���ֽڵĿռ�
//	printf("%s\n", arr);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


int main()
{
	char arr[1024] = { 0 };

	/*fgets(arr, 1024, stdin);
	fputs(arr, stdout);*/

	//�ȼ���  gets��puts��ֻ���÷��е㲻һ����������õ���׼�������
	gets(arr);
	puts(arr);

	return 0;
}