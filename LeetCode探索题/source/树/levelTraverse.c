#include<stdio.h>
#include<stdlib.h>
// 队列大小
#define SIZE 30
// 树节点
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

int* levelTraverse(TreeNode *root,int returnSize){
    if(root == NULL){
        return NULL;
    }

    // 返回节点数据数组
    int* ret = (int*)malloc(sizeof(int) * returnSize);
    if(ret == NULL){
        return NULL;
    }

    // 辅助循环队列
    TreeNode* queue[30];
    int top = -1,tail = -1;

    queue[++top] = root;

    int pos = 0;

    while(top != tail){
        tail = (tail + 1) % SIZE;
        TreeNode *temp = queue[tail];
        ret[pos++] = temp->data;
        if(temp->left){
            top = (top + 1) % SIZE;
            queue[top] = temp->left;
        }
        if(temp->right){
            top = (top + 1) % SIZE;
            queue[top] = temp->right;
        }
    }

    return ret;
}

int main(){
    TreeNode *r1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r4 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r5 = (TreeNode*)malloc(sizeof(TreeNode));

    r1->left = r2;
    r1->right = r3;
    r1->data = 1;

    r2->left = r4;
    r2->right = r5;
    r2->data = 2;

    r3->left = NULL;
    r3->right = NULL;
    r3->data = 3;

    r4->left = NULL;
    r4->right = NULL;
    r4->data = 4;

    r5->left = NULL;
    r5->right = NULL;
    r5->data = 5;

    int *arr = levelTraverse(r1,5);
    for(int i = 0;i < 5;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}