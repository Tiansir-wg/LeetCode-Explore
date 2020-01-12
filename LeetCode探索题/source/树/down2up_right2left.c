#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

// 主要思想是:采用层次遍历的方式，出队时入栈，访问完毕后栈里的顺序是从上到下，从左往右的
// 逆向输出即可
void down2up_right2left(TreeNode *root){
    if(!root){
        return;
    }
    // 辅助栈
    TreeNode* stack[SIZE];
    int top = -1;
    // 辅助队列
    int head = -1,tail = -1;
    TreeNode* queue[SIZE];

    queue[++head] = root;
    while(head!=tail){
        TreeNode *temp = queue[++tail];
        stack[++top] = temp;
        if(temp->left){
            queue[++head] = temp->left;
        }
        if(temp->right){
            queue[++head] = temp->right;
        }
    }

    while(top!=-1){
        printf("%d\t",stack[top--]->val);
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

    down2up_right2left(r1);
    return 0;
}