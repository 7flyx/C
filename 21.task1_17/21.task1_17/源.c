# define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
//
//struct s
//{
//	int n;
//	int arr[];//�������飬Ҳ������������,�ں���ʹ�õ�ʱ�򣬴���malloc�Ⱥ�������ʹ��
//}stu;
//
//int main()
//{
//	struct s* ps = (struct s*)malloc(sizeof(struct s) + 5 * sizeof(int));
//
//
//	free(ps);
//	return 0;
//}

//
//#include <stdio.h>
//struct str {
//    int len;
//    char s[0];
//};
//
//struct foo {
//    struct str* a;
//};
//
//int main(int argc, char** argv) {
//    struct foo f = { 0 };
//    if (f.a->s) {
//        printf(f.a->s);
//    }
//    return 0;
//}


struct S
{
	int n;
	int arr[];
	//����������ڵ�����
	// 1.��ֿ���������ָ�루int* arr����˵�� �ܹ������������ڴ�ռ䣬�Թ�cpu�Ŀ��ٷ���
	//��������CPU��������ڴ��ȡ���ݣ�CPU->�Ĵ���->���ٻ�����->�ڴ�->Ӳ��
};

int main()
{
	struct S* s = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
	int i = 0;
	s->n = 100;

	for (i = 0; i < 10; i++)
	{
		s->arr[i] = i;
		printf("%d ", s->arr[i]);
	}
	
	return 0;
}