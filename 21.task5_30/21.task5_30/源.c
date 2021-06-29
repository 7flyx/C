#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20  //���������Ľ���������ڿ������鵱ջʹ��


struct Node
{
	char val;
	struct Node* left, * right;
};

typedef struct Node Node;
void in(Node* root)
{
    Node* arr[MAXSIZE] = { 0 };
    int size = 0; //����ָ��arr���飬Ҳ�����ڱ�ʾ������黹�м���Ԫ��
    while (size != 0 || root != NULL)
    {
        if (root != NULL)
        {
            arr[size++] = root;
            root = root->left;  //��������������
        }
        else
        {
            //��ʱrootΪ�գ�˵������������������ײ�����ʱ���ջ��Ԫ�أ�root���������߼���
            printf("%c ", arr[--size]->val);
            root = arr[size]->right;
        }
    }
}

void pre(Node* root)
{
    if (root == NULL)
        return;

    Node* arr[MAXSIZE] = { 0 }; //ģ��ջ
    int size = 0; //�����ʱջ�ж���Ԫ��
    arr[size++] = root;
    while (size != 0)
    {
        Node* node = arr[--size];
        printf("%c ", node->val);
        //��ѹ���Һ��ӣ���ѹ�����ӡ������ڵ�����ʱ�����  �ȵ������� Ȼ������Һ���
        //ͷ  ��   ��
        if (node->right != NULL)
            arr[size++] = node->right;
        if (node->left != NULL)
            arr[size++] = node->left;
    }
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    Node* stack1[MAXSIZE] = { 0 }; //��Ҫջ
    Node* stack2[MAXSIZE] = { 0 };  //����ջ
    int size1 = 0; //��Ҫջ�����������Ԫ�ظ���
    int size2 = 0; //����ջ: ���������Ԫ�ظ���
    stack1[size1++] = root;
    while (size1 != 0)
    {
        Node* node = stack1[--size1];
        stack2[size2++] = node; //��ʱ���븨��ջ

        //��ѹ�����ӣ���ѹ���Һ���
        if (node->left != NULL)
            stack1[size1++] = node->left;
        if (node->right != NULL)
            stack1[size1++] = node->right;
    }

    //�������ջ�����ݼ���
    while (size2-- != 0)
        printf("%c ", stack2[size2]->val);
}

Node* createTree(char arr[], int* cur)
{
    if (arr[*cur] == '#') //ֻ�ǽ���������ʱ��һ�ֱ�־
        return NULL;
    Node* root = (Node*)malloc(sizeof(Node));
    root->val = arr[*cur];
    (*cur)++;
    root->left = createTree(arr, cur);
    (*cur)++;
    root->right = createTree(arr, cur);
    return root;
}

void delTree(Node* root)
{
    //����ȫ��malloc���ٵ��ڴ�
    //����ͷ��˳�򣬺������ɾ��
    if (root == NULL)
        return;
    delTree(root->left);
    delTree(root->right);
    free(root);
    root = NULL;
}

int main()
{
    char arr[] = { 'a', 'b' ,'e','#','#','f','#' ,'#' , 'c','#' ,'#' };
    int index = 0;
    Node* root = createTree(arr, &index);
    //in(root);
    //pre(root);
    postorder(root);
    delTree(root);
    return 0;
}








//int int_cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}

//int main()
//{
//	double hi = 0.0;
//	double sum = 0.0;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%lf", &hi);
//		sum = sum + hi;
//	}
//	double avg = sum / 5;
//	printf("%.2lf\n", avg);
//	return 0;
//}

//
//int main()
//{
//	//��������
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	qsort(arr, 10, sizeof(arr[0]), int_cmp);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}