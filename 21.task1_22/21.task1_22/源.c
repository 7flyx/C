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




int main()
{
	int a = 10000;
	FILE* ps = fopen("test.txt", "r");  

	/*printf("%c",fgetc(ps));
	printf("%c", fgetc(ps));
	printf("%c", fgetc(ps));
	printf("%c", fgetc(ps));
	printf("%c", fgetc(ps));*/


	fclose(ps);
	ps = NULL;
	return 0;
}
