#include <stdio.h>
#include <stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0,right = numsSize - 1;

    // 返回数组，保存第一次出现和最后一次出现的索引
    int *ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = -1;
    ret[1] = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        // 目标数在mid左边
        if(nums[mid] > target){
            right = mid - 1;
        }
        // 目标数在mid右边
        else if(nums[mid] < target){
            left = mid + 1;
        }

        // 当前数等于目标数，还需要继续向左边查找第一个，向右边查找最后一个
        else{
            // 左边第一个
            while(nums[mid] == target && mid >= left){
                mid--;
            };
            ret[0] = mid + 1;
            int mid = (left + right) / 2;
            // 右边最后一个
            while(nums[mid] == target && mid <= right){
                mid++;
            }
            ret[1] = mid - 1;
            break;
        }

    }
    return ret;
}

int main(){
    int arr[] = {1,2,3,4,4,4,4,4,4,5,5,5,6,7};
    int length = 2;
    int *res = searchRange(arr,sizeof(arr) / sizeof(int),0,&length);
    for(int i = 0;i < length;i++){
        printf("%d ",res[i]);
    }
    return 0;
}