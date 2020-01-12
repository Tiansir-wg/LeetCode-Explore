#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 树节点
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

bool symmetric(TreeNode *left,TreeNode *right){

    // 两个节点都为空是对称的
    if(!left && !right){
        return true;
    }

    // 只有一个节点为空或两节点都不空但不相等是不对称的
    if(!left || !right || left->data != right->data){
        return false;
    }

    // 继续判断两个节点对称位置的节点
    return symmetric(left->left,right->right) 
    && symmetric(left->right,right->left);
}

bool isSymmetricTree(TreeNode *root){
    if(root == NULL){
        return true;
    }
    return symmetric(root->left,root->right);
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
    r2->right = NULL;
    r2->data = 2;

    r3->left = NULL;
    r3->right = r5;
    r3->data = 2;

    r4->left = NULL;
    r4->right = NULL;
    r4->data = 4;

    r5->left = NULL;
    r5->right = NULL;
    r5->data = 4;

    printf("%d",isSymmetricTree(r1));
    return 0;
}

