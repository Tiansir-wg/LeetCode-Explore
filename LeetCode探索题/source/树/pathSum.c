#include <stdio.h>
#include <stdlib.h>
#define  SIZE 20

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

// 打印指定路径和的所有路径
void getPathOfSum(TreeNode *root,int sum){
    if(root == NULL){
        return;
    }

    // 辅助栈
    int top = -1;
    TreeNode* stack[SIZE];

    TreeNode *pos = root;

    // 最近访问的节点
    TreeNode *lastVisited = NULL;

    // 临时记录路径和
    int temp = 0;

    while(pos || top!=-1){

        // 当前节点不空，入栈，更新路径和
        if(pos){
            temp += pos->val;
            stack[++top] = pos;

            // 如果是叶节点且路径和等于指定值则可以打印一条路径
            if(!pos->left && !pos->right && temp == sum){
                for(int i = 0;i <= top;i++){
                    printf("%d ",stack[i]->val);
                }
                printf("\n");
            }

            // 向左访问
            pos = pos->left;

        }else{
            pos = stack[top];
            // 右子树存在且未被访问则访问右节点
            if(pos->right != NULL && pos->right!=lastVisited){
                pos = pos->right;
            }
            // 右子树不存在或已经访问过，访问当前节点并出栈，将路径和还原
            else{
                top--;
                temp -= pos->val;
                lastVisited = pos;
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
    r6->val = 3;

    getPathOfSum(r1,7);
    return 0;
}
