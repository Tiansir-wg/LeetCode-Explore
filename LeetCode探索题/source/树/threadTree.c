#include <stdio.h>
#include <stdlib.h>
// 线索/孩子
#define THREAD 1
#define CHILD 0

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  int leftTag,rightTag;
}TreeNode;

// 中序创建线索二叉树，参数是根节点指针和前驱节点
void inThread(TreeNode *root,TreeNode *pre){
    if(root){
        inThread(root->left,pre);
        if(!root->left){
            root->left = pre;
            root->leftTag = THREAD;
        }

        if(pre && !pre->right){
            pre->right = root;
            pre->rightTag = THREAD;
        }
        pre = root;
        inThread(root->right,pre);
    }
}

// 获取当前根节点对应树的中序遍历第一个节点
TreeNode* getFirstNode(TreeNode *root){
    TreeNode *temp = root;
    // 一直到最左边节点
    while(temp && temp->leftTag == CHILD){
        temp = temp->left;
    }
    return temp;
}

// 获取当前节点中序遍历的下一个节点
TreeNode* nextNode(TreeNode *root){
    if(root == NULL){
        return NULL;
    }
    //  当前节点有右孩子，则需要访问到右孩子树的最左边节点
    if(root->rightTag == CHILD){
        return getFirstNode(root->right);
    }
    // 如果当前节点有右线索，直接返回右线索即可
    else{
        return root->right;
    }
}

// 中序遍历线索二叉树
void inTraverse(TreeNode *root){
    for(TreeNode *p = getFirstNode(root);p!=NULL;p = nextNode(p)){
        printf("%d\n",p->val);
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
    r1->leftTag = CHILD;
    r1->rightTag = CHILD;

    r2->left = r4;
    r2->right = r5;
    r2->val = 2;
    r2->leftTag = CHILD;
    r2->rightTag = CHILD;

    r3->left = NULL;
    r3->right = r6;
    r3->val = 3;
    r3->leftTag = CHILD;
    r3->rightTag = CHILD;

    r4->left = NULL;
    r4->right = NULL;
    r4->val = 4;
    r4->leftTag = CHILD;
    r4->rightTag = CHILD;

    r5->left = NULL;
    r5->right = NULL;
    r5->val = 5;
    r5->leftTag = CHILD;
    r5->rightTag = CHILD;

    r6->left = NULL;
    r6->right = NULL;
    r6->val = 3;
    r6->leftTag = CHILD;
    r6->rightTag = CHILD;

    TreeNode *pre = NULL;
    inThread(r1,pre);
    
    pre->right = NULL;
    pre->rightTag = THREAD;
    inTraverse(r1);
    return 0;
}