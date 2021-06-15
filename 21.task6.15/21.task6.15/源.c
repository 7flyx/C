#include <stdio.h>
#include <assert.h>


//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf(" %x\n", a.k);
//    return 0;
//}


//void* my_memmove(void* dest, const void* src, int count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	//需要判断的是向前移动还是向后移动
//	char* p1 = (char*)dest;
//	char* p2 = (char*)src; 
//	if (p1 < p2) { //从后向前移动
//		while (count--) {
//			*p1 = *p2;
//			p1++;
//			p2++;
//		}
//	}
//	else { //从前向后拷贝
//		while (count--) {
//			*(p1 + count) = *(p2 + count);
//		}
//	}
//	return dest;
//}
//int main()
//{
//	//实现memmove函数
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_memmove(arr1+2, arr1, 20); //从arr1+2移动arr1，拷贝20个字节
//	int i = 0;
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr1[i]);
//	return 0;
//}

//void* my_memcpy(void* dest,const void* src, int count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	char* p1 = (char*)dest;
//	char* p2 = (char*)src;
//	while (count--)
//	{
//		*p1 = *p2;
//		p1++;
//		p2++;
//	}
//	return dest;
//}

//int main()
//{
//	//实现memcpy函数
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//	int i = 0;
//	for (; i < 10; i++)
//		printf("%d ", arr2[i]);
//	return 0;
//}

int getMax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 10;
	int b = 20;
	int max = 0;
	max = getMax(10, 20);
	printf("%d\n", max);
	return 0;
}