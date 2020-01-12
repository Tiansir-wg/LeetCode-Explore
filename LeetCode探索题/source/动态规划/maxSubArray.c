// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组
// （子数组最少包含一个元素），返回其最大和。
#include <stdio.h>
#include <stdlib.h>
// 动态规划思想
int maxSubArray(int* nums, int numsSize){
    if(!nums || numsSize <= 0){
        return 0;
    }
    // 动态规划辅助数组，dp[i]表示以第i位置字符结束的
    // 最大子序和
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    if(!dp){
        return 0;
    }
    dp[0] = nums[0];

    // 如果当前元素值加上前面元素的最大和比自身值大，则其和作为新的最大和，否则当前元素
    // 单独作为一个子序列
    for(int i = 1;i < numsSize;i++){
         dp[i] = nums[i] < dp[i - 1] + nums[i] ? dp[i - 1] + nums[i] : nums[i];
    }

    // 寻找最大和
    int maxSum = dp[0];
    for(int j = 1;j < numsSize;j++){
        if(dp[j] > maxSum){
            maxSum = dp[j];
        }
    }
    return maxSum;
}