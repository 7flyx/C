# define _CRT_SECURE_NO_WARNINGS 



#include <stdio.h>

int main()
{

	int x = 0;
	int i = 0;
	printf("请输入成绩：");
	scanf("%d", &x);

	if (x >= 90 && x <= 100)
		i = 1;
	else if (x >= 80 && x < 90)
		i = 2;
	else if (x >= 70 && x < 80)
		i = 3;
	else if (x >= 60 && x < 70)
		i = 4;
	else
		i = 0;

	switch (i)
	{
	case 1:
		printf("A");
		break;
	case 2:
		printf("B");
		break;
	case 3:
		printf("C");
		break;
	case 4:
		printf("D");
		break;
	default:
		printf("E，不及格");
		break;
	}
	return 0;
}

//斐波那契查找法，运用黄金分割的思想，生成一个斐波那契数列，将数列的最大值，要比被查找的数组size-1大即可
//例如，a[11],斐波那契数列的最大数要大于11-1，即就是大于10，这就是斐波那契数列的大小的建立

int F[20];  //全局的斐波那契数组
int Fbi_Serch(int a[], int size, int key)
{
	int low, high, i, k, mid;
	k = 0;
	low = 0; //代表数组的第一个元素
	high = size - 1;  //代表数组的最后一个元素

	while (size > F[k] - 1)  //定位size在斐波那契数组的位置，即就是数组的大小在斐波那契数列的哪个位置
		k++;
	for (i = size; i < F[k] - 1; i++) 
	{
		//在上面while循环中计算出k的值，此处需要填充被查找数组中最后一个元素的
		//例如：数组的最后一个元素为99，而数组的大小为10，而k的值为13，则数组下标为11和12处需要填充
		a[i] = a[size];  //可能会导致越界访问，需要考虑数组的大小问题
	}

	//接下来就是类似于普通二分法的查找，有些细节问题不同而已
	while (low <= high)
	{
		mid = low + F[k - 1] - 1; //确定mid的值，与普通二分法不同，黄金分割点
		if (a[mid] > key)
		{
			high = mid - 1;
			k -= 1; //k值需要减1
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
			k -= 2;  //此处的k需要减2，与上面的不同
		}
		else //相等的情况
		{
			if (mid <= size)
				return mid;  //如果此时的mid值在原数组size的范围类，说明是查找成功了
			else
				return size;  //mid值不在原数组size的范围类，即就是在后面补充的位置上。就返回最后一个元素的下标
		}
	}
	return 0; //没有找到的情况，直接返回0
	
}