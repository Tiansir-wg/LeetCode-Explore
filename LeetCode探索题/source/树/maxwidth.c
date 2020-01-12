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

// 计数方式
int getMaxWidth_1(TreeNode *root){
    
    if(root == NULL){
        return 0;
    }

    // 辅助循环队列
    TreeNode* queue[30];
    int head = -1,tail = -1;

    queue[++head] = root;

    // maxwidth记录最大宽度，count记录每一层的宽度
    int maxWidth = 1,count = 1;

    while(head != tail){
        tail = (tail + 1) % SIZE;
        TreeNode *temp = queue[tail];
        count--;
        if(temp->left){
            head = (head + 1) % SIZE;
            queue[head] = temp->left;
        }
        if(temp->right){
            head = (head + 1) % SIZE;
            queue[head] = temp->right;
        }
        if(count == 0){
            count = (head - tail) % SIZE;
            maxWidth = maxWidth > count ? maxWidth : count;
        }
    }
    return maxWidth;
}

// 指针方式
int getMaxWidth_2(TreeNode *root){
    
    if(root == NULL){
        return 0;
    }

    // 辅助循环队列
    TreeNode* queue[30];
    int head = -1,tail = -1;

    queue[++head] = root;

    // maxwidth记录最大宽度，count记录每一层的宽度
    int maxWidth = 1,count = 0;

    // 分别指向当前行的最后一个元素和下一行的最后一个元素
    TreeNode *rowEnd = root,*nextRowEnd = NULL;

    while(head != tail){
        tail = (tail + 1) % SIZE;
        TreeNode *temp = queue[tail];
        if(temp->left){
            head = (head + 1) % SIZE;
            queue[head] = temp->left;

            // nextRowEnd 指向当前行的最后一个元素
            nextRowEnd = temp->left;
            count++;
        }
        if(temp->right){
            head = (head + 1) % SIZE;
            queue[head] = temp->right;
            
            //nextRowEnd 指向当前行的最后一个元素
            nextRowEnd = temp->right;
            count++;
        }
        if(temp == rowEnd){
            maxWidth = maxWidth > count ? maxWidth : count;
            rowEnd = nextRowEnd;
            count = 0;
        }
    }
    return maxWidth;
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

    printf("%d",getMaxWidth_2(r1));
    return 0;
}
