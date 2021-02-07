# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//题目：计算两个int类型的数值，二进制数中，不同的位（bit）的个数


//int count_num2(int x, int y)
//{
//	//按位异或的角度来解决
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((x >> i) ^ (y >> i) == 1)
//			count++;
//	}
//	return count;
//}
//0011   3
//0110   6
//1001   9

//1010   10 
//1111   15


int count_num2(int n, int m) {
	int re = m ^ n;//  第一次之后，每次都要移位，所以用re表示剩余的，
	int sum = 0;
	//while (re) {
	//	if ((re & 1) == 1) {
	//		//re & 1如果re最低位是1，则结果等于1，表示该位不同sum++；
	//		sum++;
	//	}
	//	re = re >> 1;//向右移位

	//}
	//return sum;
	return re;
}
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);

	int count = count_num2(x, y);

	printf("不同位的个数为:%d\n", count);
	printf("%d\n", count);

	return 0;
}







//解法一：按位与的运用
//int count_num(int x)
//{
//	int count = 0;
//	int n = 0;
//	for (n = 0; n < 32; n++)
//	{
//		if (((x >> n) & 1) == 1)
//			count++;
//	}
//	return count;
//}




//解法二：高效解法-----  x=x&(x-1)
//x=13

//1101  x
//1100  x-1
//1100  新x
//1011  x-1
//1000  新x
//0111  x-1
//0000  新x

//总结：每一个按位与(x-1)，能够消掉这个二进制数的最后一个1
//算法实现
//int count_num(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		x = x & (x - 1);
//		count++;
//	}
//	return count;
//}
//
//
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int count = count_num(input);
//
//	printf("有%d个\n",count);
//	return 0;
//}



//无符号数，理清楚负数是怎么转换为无符号数的
//int count_a_one(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (1 == n % 2)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count = count_a_one(a);
//
//	printf("%d\n", count);
//
//	return 0;
//}



//int count_input_one(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (1 ==((n >> i) & 1))  //注意各大符号的优先性与结合性
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int input = 0;
//	printf("请输入数值：>");
//	scanf("%d", &input);
//	int count = count_input_one(input);
//	printf("%d\n", count);
//	
//	return 0;
//}
