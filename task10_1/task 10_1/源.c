# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int line = 0;
	//printf("革命尚未成功，同志仍需努力\n");

	while (line < 100)
	{
		++line;
		printf("%d:革命尚未成功，同志仍需努力\n",line);
		
	}
	if (line >= 100)
		printf("成功\n");
	return 0;	
}
//int main()
//{
//	int a = 0;
//	printf("你会加入比特嘛？（1 or 2）>:\n",a);
//	scanf("%d", &a);
//	if (a == 1)
//		printf("好好学习会有好的结果\n");
//	else
//		printf("你会去卖红薯\n");
//	return 0;
//}
//int main()
//{
//	char arr1[] = "bit";//字符串后面有\0作为结束标志，不做字符串内容
//	char arr2[] = { 'b','i','t' };//没有\0作为结束标志，所以后面的是随机的
//	char arr3[] = { 'b','i','t','\0' };//有了\0，所以结束
//
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	printf("%s\n", arr3);
//	return 0;
//}

//#define MAX(x,y) (x>y?x:y)
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int max = MAX(a, b);
//	
//	printf("max=%d\n", max);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* b = &a;//b存放的是a的地址
//
//	*b = 20;
//
//	printf("%p\n", b);
//	return 0;
//}