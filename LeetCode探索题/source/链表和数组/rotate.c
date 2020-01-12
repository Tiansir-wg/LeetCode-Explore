// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
#include <stdio.h>
#include <stdlib.h>
// 方法一:时间换空间
void rotate_v1(int* nums, int numsSize, int k){
    // k = 0或 k是数组大小的倍数时旋转前后一样，直接返回
    if(!nums || numsSize <= 1 || k == 0 || (k % numsSize == 0)){
        return;
    }

    // 临时数组，时间复杂度为O(n)，空间复杂度为O(n)
    int *temp = (int*)malloc(sizeof(int) * numsSize);
    if(!temp){
        return;
    }
    for(int i = 0;i < numsSize;i++){
        temp[(i + k) % numsSize] = nums[i];
    }
    for(int j = 0;j < numsSize;j++){
        nums[j] = temp[j];
    }
    free(temp);
}

// 每次移动一位，移动k次
// 时间复杂度为O(kn),空间复杂度为O(1)
void rotate_v2(int* nums, int numsSize, int k){
    if(!nums || numsSize <= 1 || k == 0 || (k % numsSize == 0)){
        return;
    }
    for(int i = 0;i < k % numsSize;i++){
        int temp  = nums[numsSize - 1];
        for(int j = numsSize - 2;j >= 0;j--){
            nums[j+1] = nums[j];
        }
        nums[0] = temp;
    }
}

// 方法三:通过三次旋转实现,首先将整个数组转置，再将 0 ~ k - 1 和 k ~ n - 1 之间的
// 部分转置
// 时间复杂度为O(n),空间复杂度为O(1)

void reverse(int* nums,int left,int right){
    while(left < right){
        nums[left] = nums[left] ^ nums[right];
        nums[right] = nums[right] ^ nums[left];
        nums[left] = nums[left] ^ nums[right];
        left++;
        right--;
    }
}
void rotate_v3(int* nums, int numsSize, int k){
    if(!nums || numsSize <= 1 || k == 0 || (k % numsSize == 0)){
        return;
    }
    k %= numsSize;
    reverse(nums,0,numsSize - 1);
    reverse(nums,0,k - 1);
    reverse(nums,k,numsSize - 1);
}
 