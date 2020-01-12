#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
// 树节点
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

// 递归方式
int getMaxDepthRecursion(TreeNode *root){
    if(!root){
        return 0;
    }

    int leftHeight = getMaxDepthRecursion(root->left);
    int rightHeight = getMaxDepthRecursion(root->right);
    return (leftHeight < rightHeight ? rightHeight : leftHeight) + 1;
}

// 层序遍历方式
int getMaxDepthLevel(TreeNode *root){
    int depth = 0;
    if(root == NULL){
        return depth;
    }

    // 辅助队列
    int head = -1,tail = -1;
    TreeNode* queue[SIZE];

    queue[++head] = root;
    
    // 用于标记每一行的末尾和下一行的末尾
    TreeNode *thisEnd = root,*nextEnd = NULL;

    while(head != tail){
        tail = (tail+1) % SIZE;
        TreeNode *temp = queue[tail];
        if(temp->left){
            head = (head + 1) % SIZE;
            queue[head] = temp->left;
            nextEnd = temp->left;
        }
        if(temp->right){
            head = (head + 1) % SIZE;
            queue[head] = temp->right;
            nextEnd = temp->right;
        }
        if(temp == thisEnd){
            thisEnd = nextEnd;
            // 每行结束时深度加一
            depth++;
        }
    }
    return depth;
}


int main(){
    TreeNode *r1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r4 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r5 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *r6 = (TreeNode*)malloc(sizeof(TreeNode));


    r1->left = r2;
    r1->right = r3;
    r1->data = 1;

    r2->left = r4;
    r2->right = r5;
    r2->data = 2;

    r3->left = NULL;
    r3->right = r6;
    r3->data = 3;

    r4->left = NULL;
    r4->right = NULL;
    r4->data = 4;

    r5->left = NULL;
    r5->right = NULL;
    r5->data = 5;

    r6->left = NULL;
    r6->right = NULL;
    r6->data = 5;

    printf("%d",getMaxDepthLevel(r1));
    return 0;
}