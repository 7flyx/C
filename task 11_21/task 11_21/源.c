# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int arr[10], i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
		arr[i] = rand() % 100 + 1;//生成100以内的10个数值
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10 - i; j++)  //用i来控制j，达到第几个元素的调用目的
		{
			if (arr[j + 1] > arr[j])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}
