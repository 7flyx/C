# define _CRT_SECURE_NO_WARNINGS 
#include "表达式求值运算.h"







//
//
//int main()
//{
//	double i1 = 0.0;  //i个任务
//	int i2 = 0;
//	int m = 0;  //去路上花费的时间，单位分钟
//	int m_sum = 4 * 60;  //4小时----单位分钟
//	scanf("%d", &m);//输入需要花费的时间
//	i1 = (double)(m_sum - m)/5.0;
//	i2 = (int)i1;
//	if (i1 == i2)
//	{
//		//说明小数和整数相等，任务数减1
//		printf("%d\n", i2 - 1);
//	}
//	else
//	{
//		printf("%d\n", i2);
//	}
//	return 0;
//}



//int main()
//{
//	//25题
//	
//	unsigned long long count = 1; //表示当前一个格子小麦的总数
//	unsigned long long sum = 1;  //所有格子的总和
//	int i = 0;
//	//第一个格子放一粒，后面还有63个格子
//	for (i = 1; i < 64; i++)
//	{
//		//循环64次---每一个格子比上一个格子多一倍
//		//例如：1-2-4-8-16，就是2倍的关系
//		count *= 2;
//		sum += count;
//
//	}
//
//
//	printf("64个格子，需要赏赐%e粒麦子\n",sum);
//	
//	return 0;
//}