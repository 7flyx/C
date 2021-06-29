#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20  //整棵树最大的结点数，用于开辟数组当栈使用


struct Node
{
	char val;
	struct Node* left, * right;
};

typedef struct Node Node;
void in(Node* root)
{
    Node* arr[MAXSIZE] = { 0 };
    int size = 0; //用于指向arr数组，也是用于表示这个数组还有几个元素
    while (size != 0 || root != NULL)
    {
        if (root != NULL)
        {
            arr[size++] = root;
            root = root->left;  //继续往左子树走
        }
        else
        {
            //此时root为空，说明来到了左子树的最底部，此时输出栈顶元素，root往右子树走即可
            printf("%c ", arr[--size]->val);
            root = arr[size]->right;
        }
    }
}

void pre(Node* root)
{
    if (root == NULL)
        return;

    Node* arr[MAXSIZE] = { 0 }; //模拟栈
    int size = 0; //代表此时栈有多少元素
    arr[size++] = root;
    while (size != 0)
    {
        Node* node = arr[--size];
        printf("%c ", node->val);
        //先压入右孩子，再压入左孩子。这样在弹出的时候才是  先弹出左孩子 然后才是右孩子
        //头  左   右
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

    Node* stack1[MAXSIZE] = { 0 }; //主要栈
    Node* stack2[MAXSIZE] = { 0 };  //辅助栈
    int size1 = 0; //主要栈：代表数组的元素个数
    int size2 = 0; //辅助栈: 代表数组的元素个数
    stack1[size1++] = root;
    while (size1 != 0)
    {
        Node* node = stack1[--size1];
        stack2[size2++] = node; //暂时存入辅助栈

        //先压入左孩子，再压入右孩子
        if (node->left != NULL)
            stack1[size1++] = node->left;
        if (node->right != NULL)
            stack1[size1++] = node->right;
    }

    //输出辅助栈的数据即可
    while (size2-- != 0)
        printf("%c ", stack2[size2]->val);
}

Node* createTree(char arr[], int* cur)
{
    if (arr[*cur] == '#') //只是建立二叉树时的一种标志
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
    //回收全部malloc开辟的内存
    //左右头的顺序，后序遍历删除
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
//	//快速排序
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	qsort(arr, 10, sizeof(arr[0]), int_cmp);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}