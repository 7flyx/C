//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdlib.h>
//#include <stdio.h>
//
//
//int main()
//{
//    //��������10��int���͵��ڴ�ռ�
//    int* arr = (int*)calloc(10, sizeof(int));
//    if (arr == NULL)
//    {
//        perror("calloc"); //calloc���ٿռ�Ļ����᷵��NULL
//        return 1;
//    }
//
//    //������ֵ���㣬ֱ������տ��ٵĿռ䣬���Ƿ����Ѿ���ʼ��Ϊ0��
//    int i = 0;
//    for (i = 0; i < 10; i++)
//        printf("%d ", *(arr + i));
//
//    //�ǵ��ͷſռ�
//    free(arr);
//    return 0;
//}
//
//
//
////int main()
////{
////    //����10��int���͵Ŀռ�
////    int* arr = (int*)malloc(10 * sizeof(int)); //�м�������Ĵ�С����10  *  int��4���ֽڣ�
////    int i = 0;
////    if (arr == NULL)
////    {
////        perror("malloc"); //�п��ܣ�malloc���ٿռ�ʧ�ܣ���malloc�᷵��NULL
////        return 1;
////    }
////
////    for (i = 0; i < 10; i++)
////        *(arr + i) = i;
////
////    for (i = 0; i < 10; i++)
////        printf("%d ", *(arr + i));
////
////    //�ǵ��ͷ������ٵĿռ�
////    free(arr);
////    return 0;
////}