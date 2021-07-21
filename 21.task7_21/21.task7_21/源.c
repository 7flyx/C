//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdlib.h>
//#include <stdio.h>
//
//
//int main()
//{
//    //还是申请10个int类型的内存空间
//    int* arr = (int*)calloc(10, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc"); //calloc开辟空间的话，会返回NULL
//        return 1;
//    }
//
//    //不做赋值运算，直接输出刚开辟的空间，看是否是已经初始化为0了
//    int i = 0;
//    for (i = 0; i < 10; i++)
//        printf("%d ", *(arr + i));
//
//    //记得释放空间
//    free(arr);
//    return 0;
//}
//
//
//
////int main()
////{
////    //开辟10个int类型的空间
////    int* arr = (int*)malloc(10 * sizeof(int)); //切记这里给的大小，是10  *  int（4个字节）
////    int i = 0;
////    if (arr == NULL)
////    {
////        perror("malloc"); //有可能，malloc开辟空间失败，则malloc会返回NULL
////        return 1;
////    }
////
////    for (i = 0; i < 10; i++)
////        *(arr + i) = i;
////
////    for (i = 0; i < 10; i++)
////        printf("%d ", *(arr + i));
////
////    //记得释放所开辟的空间
////    free(arr);
////    return 0;
////}