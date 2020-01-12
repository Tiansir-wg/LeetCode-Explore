// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

#include<stdio.h>

int singleNumber(int* nums, int numsSize){
	int result = 0;
	for(int i = 0; i < numsSize;i ++){
		result^=nums[i];
	}
	return result;

}

int main(){

	int arr[] = {4,1,2,1,2};

	int result = singleNumber(arr,5);

	printf("%d",result);




	return 0;
}