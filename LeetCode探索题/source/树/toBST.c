// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

// 采用二分法
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
}TreeNode;

TreeNode* toTree(int arr[],int left,int right){
  if(left <= right){
    int mid = (left + right) / 2;
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = arr[mid];
    root->left = toTree(arr,left,mid - 1);
    root->right = toTree(arr,mid + 1,right);
    return root;
  }else{
    return NULL;
  }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
  if(nums == NULL || numsSize <= 0){
    return NULL;
  }
  return toTree(nums,0,numsSize - 1);
}
int main(){
  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  TreeNode *root = sortedArrayToBST(arr,10);
  return 0;
}