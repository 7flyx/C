# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <assert.h>


char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	//首先保存p1 p2的地址，不能改变p1 2的内容
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;
	while (*cur)  //目的地的字符串为\0时，跳出循环
	{
		//1. 首先将新的地址赋给cur和s2
		s2 = (char*)p2; //保证每次循环时，是从第一个字符开始判断的
		s1 = cur;   //保证下次循环的时候，是从上次开始判断的下一个字符从新开始循环判断

		//2. 开始判断--三个判断条件 两个字符串不等于\0，和*s1与*s2的内容相等
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}

		//3. 判断源头的字符是不是\0，如果是的话，说明该字符串找到了，返回目的地  的地址
		if (*s2 == '\0')
			return cur;
		
		//如果目的地的字符串被查找完了，即就是目的地字符串都找到\0了，整个函数都还没返回
		//说明，目的地字符串找不到，返回空指针即可
		if (&s1 == '\0')
			return NULL;

		//4.上面的循环都没走的话，目的地字符串，地址向后走，继续查找
		cur++;
	}
	// 5. 整个循环走完后，还没找到，说明没有，返回空指针即可
	return NULL;
}

//实现strstr的函数
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdef";
	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL)
		printf("该字符串没有找到！\n");
	else
		printf("%s\n", ret);
	return 0;
}