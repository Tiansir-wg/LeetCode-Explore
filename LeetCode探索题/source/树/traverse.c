#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

// 前序递归遍历
void preTraverseRecursion(TreeNode *root){
    if(!root){
        return;
    }
    printf("%d",root->val);
    preTraverseRecursion(root->left);
    preTraverseRecursion(root->right);
}

// 中序递归遍历
void inTraverseRecursion(TreeNode *root){
    if(!root){
        return;
    }
    inTraverseRecursion(root->left);
    printf("%d",root->val);
    inTraverseRecursion(root->right);
}

// 后序递归遍历
void postTraverseRecursion(TreeNode *root){
    if(!root){
        return;
    }
    postTraverseRecursion(root->left);
    postTraverseRecursion(root->right);
    printf("%d",root->val);
}

// 前序非递归遍历
void preTraverseNonRecursion(TreeNode *root){

    if(!root){
        return;
    }
    // 辅助栈
    int top = -1;
    TreeNode* stack[SIZE];

    stack[++top] = root;

    while(top!=-1){
        TreeNode *temp = stack[top--];
        printf("%d ",temp->val);
        if(temp->right){
            stack[++top] = temp->right;
        }
        if(temp->left){
            stack[++top] = temp->left;           
        }
    }
}

// 中序非递归遍历
void inTraverseNonRecursion(TreeNode *root){
    if(!root){
        return;
    }
    // 辅助栈
    int top = -1;
    TreeNode* stack[SIZE];

    // 当前节点
    TreeNode *pos = root;

    while(pos || top!=-1){
        if(pos){
            stack[++top] = pos;
            pos = pos->left;
        }else{
            pos = stack[top--];
            printf("%d",pos->val);
            pos = pos->right;
        }
    }
}

// 后序非递归遍历
void postTraverseNonRecursion(TreeNode *root){
    if(!root){
        return;
    }
    // 辅助栈
    int top = -1;
    TreeNode* stack[SIZE];
    // 当前访问的节点
    TreeNode *pos = root;
    // 记录上一步访问的节点,据此确定下一步是访问根节点还是访问右子树
    TreeNode *lastVisited = NULL;
    while(pos || top!=-1){
        // 当前节点不空则一直访问到最左边
        if(pos){
            stack[++top] = pos;
            pos = pos->left;
        }else{
            pos = stack[top];
            // 当前节点有右孩子且未被访问，则转到右子树
            if(pos->right && pos->right != lastVisited){
                pos = pos->right;
                stack[++top] = pos;
                pos = pos->left;
            }
            // 没有右子树或右子树已访问，则访问当前节点
            else{
                pos = stack[top--];
                lastVisited = pos;
                printf("%d ",pos->val);
                pos = NULL;
            }
        }
    }
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
    r1->val = 1;

    r2->left = r4;
    r2->right = r5;
    r2->val = 2;

    r3->left = NULL;
    r3->right = r6;
    r3->val = 3;

    r4->left = NULL;
    r4->right = NULL;
    r4->val = 4;

    r5->left = NULL;
    r5->right = NULL;
    r5->val = 5;

    r6->left = NULL;
    r6->right = NULL;
    r6->val = 6;

    postTraverseNonRecursion(r1);
    return 0;
}