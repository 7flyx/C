# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>


int main()
{
	int i = 0;
	char password1[] = { 123456 };
	char password2[] = { 0 };
	
	
	for (i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", password2);
		if (strcmp(password2, password1) == 0)
		{
			printf("��½�ɹ���\n");
			break;
		}
		else if (i < 2)
		{
			printf("����������������룡\n");
		}
		else
		{
			printf("����������Ժ����ԣ�\n");
		}
	}
	

	return 0;
}