// 去除排序数组中的重复元素
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize){
    if(!nums || numsSize <=0){
        return numsSize;
    }

    for(int i = 0;i < numsSize;i++){
        int j;

        // 寻找第一个不相同的元素
        for(j = i + 1;j < numsSize && nums[j] == nums[i];j++){

        }
        if(j - i  == 1){
            continue;
        }

        // 将后面的元素向前移动
        for(int k = j;k < numsSize;k++){
            nums[k - j + i + 1] = nums[k];
        }

        // 修改数组长度
        numsSize-= (j - i - 1);
    }

    return numsSize;
}

int main(){
    int s[] = {1,1,2,3,4,5,5,5,5,6,7,8,9,9};
    int length = removeDuplicates(s,sizeof(s) / sizeof(int));

    for(int i = 0;i < length;i++){
        printf("%d ",s[i]);
    }
    return 0;
}

