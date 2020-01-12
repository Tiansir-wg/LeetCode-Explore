// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
#include <stdio.h>
#include <stdlib.h>
void moveZeroes_v1(int* nums, int numsSize){
    // 记录非0元素的位置
    int k = 0;
    for(int i = 0;i < numsSize;i++){
        if(nums[i]!=0){
            nums[k++] = nums[i];
        }
    }

    while(k < numsSize){
        nums[k++] = 0;
    }
}

void moveZeroes_v2(int* nums, int numsSize){
    // 记录0元素的个数
    int k = 0;
    for(int i = 0;i < numsSize;i++){
        if(nums[i] == 0){
            k++;
        }else{
            nums[i - k] = nums[i];
        }
    }

    for(int i = numsSize - k + 1;i < numsSize;i++){
        nums[i] = 0;
    }
}

int main(){
    int count;
    scanf("%d",&count);
    int *nums = (int*)malloc(sizeof(int) * count);
    for(int i = 0;i < count;i++){
        scanf("%d",&nums[i]);
    }

    moveZeroes_v2(nums,count);
    for(int i = 0;i < count;i++){
        printf("%d",nums[i]);
    }
    return 0;
}