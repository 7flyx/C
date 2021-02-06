# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;
    while (scanf("%c", &ch) == 1)
    {
        if (ch == '\n')
            break;
        getchar();
        printf("%c\n", tolower(ch));
    }
    return 0;
}
//int main()
//{
//    char c;
//    while (~scanf("%c", &c) != EOF)
//    {
//        getchar();
//        printf("%c\n", c + 32);
//    }
//    return 0;
//}

//int main()
//{
//	char x;
//	scanf("%c", &x);
//	int a = x + 32;	
//	printf("%c \n", a);
//	return 0;
//}


//#define ¦Ð 3.1415926
//int main()
//{
//    float radii;
//    float a = (float)4 / 3;
//    scanf("%f", &radii);
//    printf("%.3f", ¦Ð * a * radii * radii * radii);
//    return 0;
//}