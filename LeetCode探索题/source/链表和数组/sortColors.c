// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
// 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

#include <stdio.h>
// 计数排序方式
void sortColors_v1(int* nums, int numsSize){
    int temp[3] = {0,0,0};
    for(int i = 0;i < numsSize;i++){
        temp[nums[i]]++;
    }
    int index = 0;
    for(int j = 0;j < 3;j++){
        while(temp[j]!=0){
            nums[index++] = j;
            temp[j]--;
        }
    }
}

// 双指针方式
void sortColors_v2(int* nums, int numsSize){
    // 从最左边和最右边开始扫描
    int left = 0,right = numsSize - 1;

    // 跳过左侧连续的0
    while(left < right && nums[left] == 0){
        left++;
    }
    // 跳过右侧连续的2
    while(left < right && nums[right] == 2){
        right--;
    }

    // 指针left始终指向左侧第一个非0，right始终指向右侧第一个非2
    for(int i = left;i <= right;i++){
        // 遇到0将其与left指向的非0元素交换,此时从left交换过来的一定是
        // 1,所以直接从下一个i比较即可
        if(nums[i] == 0){
            int temp = nums[i];
            nums[i] = nums[left];
            nums[left] = temp;
            left++;
        }
        // 遇到2将其与right指向的非2元素交换，此时right交换过来的
        // 可能是1或0,所以i需要回退再比较一次
        else if(nums[i] == 2){
            int temp = nums[i];
            nums[i] = nums[right];
            nums[right] = temp;
            right--;
            i--;
        }
    }
}
