# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

//汉诺塔问题
void move(char c1, char c2)
{
	printf("%c -> %c\n", c1, c2);
}
void hanoi(int n, char x, char y, char z)
{
	if (1 == n)
		move(x, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}
}

int main()
{
	int n = 0;
	printf("请输入盘子数:");
	scanf("%d", &n);
	char a = 'a';
	char b = 'b';
	char c = 'c';
	hanoi(n, a, b, c);
	return 0;
}


//int main()
//{
//	int arr[10] = { 3,1,2,4,5 };
//	printf("%p\n", &arr[0]);
//	printf("%p\n", arr);//数组名本省就是一个地址，也就是说数组在需要访问地址的时候，并不需要 &操作符
//	printf("%d\n", *arr);
//	//*间接访问操作符（数组）在进行打印的时候，只是打印了该数组的第一个元素而已
//	return 0;
//}


//int main()
//{
//	int a = 4;
//	int b = (++a) + (++a);//第一次自增a=5，第二次自增a=6，此时a=6，再才开始加法，赋值给b
//	//此处是a自己先自增完后，再才开始赋值给b
// 	printf("%d \n", b);
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8} };
//	//二维数组的访问依然是用下标来访问
//	//只不过是行和列的下标一起表示
//	int h = 0;//行
//	for (h = 0; h < 3; h++)
//	{
//		int l = 0;//列
//		for (l = 0; l < 4; l++)
//		{
//			printf("%d ", arr[h][l]);
//			//当打印的行列并没有赋值时，打印的就是0
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int arr[3][4] = { 1,2,3,4,5,6,7,8,9 };//二维数组
//	//     行  列
//	int arr2[][4] = { {1,2,3,4},{5,6,7,8} };
//	//二维数组的行能够省略，列不能省略，
//	int arr3[1][5] = { 1,2,3,4,5 };
//
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };// 一维数组
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i,&arr[i]);//数组在内存中是连续存放的。
//	//因为是int类型，所以每个元素的地址相差4
//
//	}
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abc";//a b c \0
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));//4	
//	printf("%d\n", sizeof(arr2));//3
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//随机值
//
//	return 0;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3 };//不完全初始化
//	char arr4[] = "abcdef";//7
//	printf("%d\n", sizeof(arr4));//7个元素--char 7*1=7.。。。（包括了\0）
//	//sizeof是计算arr4的所占空间的大小
//	printf("%d\n", strlen(arr4));//6
//	//strlen  求字符串长度---‘\0’之前的字符个数
//	return 0;
//}