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
		printf("ÇëÊäÈëÃÜÂë:>");
		scanf("%s", password2);
		if (strcmp(password2, password1) == 0)
		{
			printf("µÇÂ½³É¹¦£¡\n");
			break;
		}
		else if (i < 2)
		{
			printf("ÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡\n");
		}
		else
		{
			printf("ÃÜÂë´íÎó£¡ÇëÉÔºóÔÙÊÔ£¡\n");
		}
	}
	

	return 0;
}