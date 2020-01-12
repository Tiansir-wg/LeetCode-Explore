#include <stdio.h>
#include <stdlib.h>
#define  SIZE 20

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;
void getAncestor(TreeNode *root, int x){
      // 栈
      int top = -1;
      TreeNode* stack[SIZE];

      TreeNode *pos = root;

      // 最近访问的节点
      TreeNode *lastVisited = NULL;

      while(pos || top!=-1){
            // 当前节点不空且不是指定节点，继续向左寻找
            if(pos && pos->val!=x){
                  stack[++top] = pos;
                  pos = pos->left;
            }
            // 当前节点时指定节点，则栈里的元素都是其祖先节点
            else if(pos){
                  if(top == -1){
                        printf("当前节点是根节点,没有祖先\n");
                  }
                  while(top > -1){
                        printf("%d ",stack[top--]->val);
                  }
                  return;
            }
            // 当前节点为空
            else if(!pos){
                  pos = stack[top];
                  // 右子树存在且未被访问
                  if(pos->right && lastVisited != pos->right){
                        pos = pos->right;
                  }
                  // 右子树不存在或已经访问过，访问当前节点并出栈
                  else{
                        pos = stack[top--];
                        lastVisited = pos;
                        pos = NULL;
                  }
            }
      }
      printf("节点不存在\n");
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

    getAncestor(r1,1);
    return 0;
}


