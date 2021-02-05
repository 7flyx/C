# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

long add_num(int a, int n)
{
	if (n == 1)	
		return a;	
	else		
		return a + 10 * add_num(a, n - 1);
}
int main()
{
	int a, n;
	long num = 0;
	scanf("%d%d", &a, &n);
	while (n)
	{
		 long j = add_num(a, n);
		 num = j + num;	  //保留了上次计算的结果，也就是所以的数值都加起来了
		 if (n > 1)  //打印加法的等式
			 printf("%ld+", j);
		 else
			 printf("%ld", j);
		 n--;		
	}	
	printf("=%ld\n", num);
	return 0;
}



//int main()
//{
//    int year, month, date;
//    scanf("%4d%2d%2d", &year, &month, &date);
//
//    printf("year=%d\n", year);
//    printf("month=%02d\n", month);
//    printf("date=%2d\n", date);
//
//    return 0;
//}


